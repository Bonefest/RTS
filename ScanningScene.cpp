#include "ScanningScene.h"
#include "../RakNet/Source/MessageIdentifiers.h"

ScanningScene* ScanningScene::createScene() {
    return ScanningScene::create();
}

bool ScanningScene::init() {
    if(!cocos2d::Scene::init()) return false;

    if(!initRakNet()) return false;

    visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    messageTimer = 0.0f;

    if(!initUI()) return false;

    scheduleUpdate();
    return true;
}

bool ScanningScene::initRakNet() {

    peer = RakNet::RakPeerInterface::GetInstance();
    RakNet::SocketDescriptor descriptor;
    peer->Startup(1, &descriptor, 1);

    return true;
}

bool ScanningScene::initUI() {
    portField = cocos2d::ui::TextField::create("port","fonts/arial.ttf", 26);
    portField->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE_RIGHT);
    portField->setPosition(cocos2d::Vec2(visibleSize.width * 0.9, visibleSize.height * 0.8));
    portField->setMaxLength(6);
    portField->setMaxLengthEnabled(true);

    createServerButton = cocos2d::ui::Button::create();
    createServerButton->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE_RIGHT);
    createServerButton->setTitleFontSize(26.0f);
    createServerButton->setTitleText("Create server");
    createServerButton->setPosition(cocos2d::Vec2(visibleSize.width * 0.9, visibleSize.height * 0.75));
    createServerButton->addTouchEventListener(CC_CALLBACK_2(ScanningScene::onCreateServerTouched, this));

    showAvailableServersButton = cocos2d::ui::Button::create();
    showAvailableServersButton->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE_RIGHT);
    showAvailableServersButton->setTitleFontSize(26.0f);
    showAvailableServersButton->setTitleText("Show available servers");
    showAvailableServersButton->setPosition(cocos2d::Vec2(visibleSize.width * 0.9, visibleSize.height * 0.7));
    showAvailableServersButton->addTouchEventListener(CC_CALLBACK_2(ScanningScene::onShowAvailableServersTouched, this));

    messagesText = cocos2d::ui::Text::create("","fonts/arial.ttf", 26);
    messagesText->setAnchorPoint(cocos2d::Vec2(cocos2d::Vec2::ANCHOR_TOP_LEFT));
    messagesText->setPosition(cocos2d::Vec2(visibleSize.width*0.1, visibleSize.height*0.8));

    addChild(portField);
    addChild(createServerButton);
    addChild(showAvailableServersButton);
    addChild(messagesText);

    messageQueue.setMaximalMessageCount(10);

    return true;
}

void ScanningScene::onCreateServerTouched(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
    if(type == cocos2d::ui::Widget::TouchEventType::BEGAN) {
        int port = atoi(portField->getString().c_str());
        cocos2d::log("%d", port);
        if(port < 60000 || port > 61000) {
            messageQueue.addNewMessage("Unable to create server with port " + std::to_string(port));
            return;
        }

        peer->Shutdown(0);

        RakNet::SocketDescriptor descriptor(port, 0);
        peer->Startup(2, &descriptor, 1);
        peer->SetMaximumIncomingConnections(2);

        if(peer->IsActive()) messageQueue.addNewMessage("Server has been created successfully!");

    }
}

void ScanningScene::onShowAvailableServersTouched(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
    if(type == cocos2d::ui::Widget::TouchEventType::BEGAN) {
        messageQueue.addNewMessage("Searching ...");
        broadcastLAN();
    }
}

void ScanningScene::broadcastLAN() {
    for(int i = 60000; i < 61000; ++i) {
        peer->Ping("255.255.255.255", i, true);
    }
}

void ScanningScene::update(float delta) {
    messageTimer += delta;
    if(messageTimer > 0.03f) {
        messagesText->setString(messageQueue.generateMessageLabel());
        messageTimer = 0.0f;
    }

    processPackets();
}

void ScanningScene::processPackets() {
    RakNet::Packet* packet;
    for(packet = peer->Receive(); packet; peer->DeallocatePacket(packet), packet = peer->Receive()) {
        switch(packet->data[0]) {
        case ID_UNCONNECTED_PONG: onServerFound(packet); break;
        }
    }
}

void ScanningScene::onServerFound(RakNet::Packet* packet) {
    messageQueue.addNewMessage(std::string("Found: ") + packet->systemAddress.ToString());
}
