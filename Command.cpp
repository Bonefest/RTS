#include "Command.h"
#include "MessageBox.h"

ShowObjectInformation::ShowObjectInformation(cocos2d::Node* uiLayer,
                                             NetworkObject* object) {
    setUILayer(uiLayer);
    setObject(object);
}

void ShowObjectInformation::setUILayer(cocos2d::Node* uiLayer) {
    _uiLayer = uiLayer;
}

void ShowObjectInformation::setObject(NetworkObject* object) {
    _object = object;
}

void ShowObjectInformation::execute() {
    if(_uiLayer != nullptr && _object != nullptr) {
        createMessageBox();
    }
}

void ShowObjectInformation::createMessageBox() {
    MessageBox* messageBox = MessageBox::createBox(_object->getName(), cocos2d::Size(200, 400));
    messageBox->setOffsetX(25.0f);
    messageBox->addElement(_object->getSprite(), MessageBox::AlignPosition::CENTER);
    cocos2d::Label* descriptionLabel = cocos2d::Label::createWithTTF(_object->getDescription(),
                                                                     "fonts/arial.ttf", 16);
    descriptionLabel->setMaxLineWidth(messageBox->getContentSize().width * 0.8f);
    messageBox->addElement(descriptionLabel);

    messageBox->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    messageBox->setPosition(visibleSize * 0.5);

    messageBox->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
    messageBox->setBackGroundColorOpacity(128);
    messageBox->setBackGroundColor(cocos2d::Color3B(128, 128, 128));

    _uiLayer->addChild(messageBox);
}
