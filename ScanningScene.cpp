#include "ScanningScene.h"

ScanningScene* ScanningScene::createScene() {
    return ScanningScene::create();
}

bool ScanningScene::init() {
    if(!cocos2d::Scene::init()) return false;

    visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    if(!initRakNet()) return false;

    if(!initUI()) return false;

    return true;
}

bool ScanningScene::initRakNet() {
    peer = RakNet::RakPeerInterface::GetInstance();

    RakNet::SocketDescriptor descriptor(65000, 0);
    peer->Startup(2, &descriptor, 1);

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

    showAvailableServersButton = cocos2d::ui::Button::create();
    showAvailableServersButton->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE_RIGHT);
    showAvailableServersButton->setTitleFontSize(26.0f);
    showAvailableServersButton->setTitleText("Show available servers");
    showAvailableServersButton->setPosition(cocos2d::Vec2(visibleSize.width * 0.9, visibleSize.height * 0.7));
    showAvailableServersButton->addTouchEventListener()

    addChild(portField);
    addChild(createServerButton);
    addChild(showAvailableServersButton);

    return true;
}

void ScanningScene::onShowAvailableServersTouched(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
    cocos2d::log("touched");
}
