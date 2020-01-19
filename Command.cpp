#include "Command.h"
#include "MessageBox.h"
#include "ConfigLoader.h"

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
    MessageBox* messageBox = MessageBox::createBox(_object->getName());
    //messageBox->addElement(_object->getSprite(), MessageBox::AlignPosition::CENTER);
    cocos2d::Label* descriptionLabel = cocos2d::Label::createWithTTF(_object->getDescription(),
                                                                     ConfigLoader::getInstance()->getString("MessageBox_font"),
                                                                     ConfigLoader::getInstance()->getInteger("MessageBox_fontsize"));
    descriptionLabel->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);
    descriptionLabel->setAlignment(cocos2d::TextHAlignment::CENTER,
                                   cocos2d::TextVAlignment::CENTER);
    descriptionLabel->setMaxLineWidth(messageBox->getContentSize().width * 0.8f);
    messageBox->addElement(descriptionLabel, MessageBox::AlignPosition::CENTER);

    messageBox->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    messageBox->setPosition(visibleSize * 0.5);

    _uiLayer->addChild(messageBox);
}
