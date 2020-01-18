#include "MessageBox.h"
#include "ConfigLoader.h"

MessageBox* MessageBox::createBox(const std::string& title, const cocos2d::Size& size) {
    MessageBox* messageBox = new MessageBox();
    if(messageBox->init()) {
        messageBox->autorelease();

        if(size.height != 0 && size.width != 0) {
            messageBox->setContentSize(size);
            messageBox->setInnerContainerSize(size);
        }

        messageBox->setTitle(title);

        return messageBox;
    } else {
        delete messageBox;
        messageBox = nullptr;
        return messageBox;
    }
}

bool MessageBox::init() {
    if(!cocos2d::ui::ScrollView::init()) {
        return false;
    }

    _offset.x = 0;
    _offset.y = 20.0f;
    _verticalElementOffset = 20.0f;

    setDirection(Direction::VERTICAL);
    setScrollBarEnabled(false);

    generateAcceptButton();

    setContentSize(ConfigLoader::getInstance()->getSize("MessageBox_default_size"));
    setInnerContainerSize(getContentSize());

    cocos2d::Color4B backgroundColor = ConfigLoader::getInstance()->getColor("MessageBox_background_color");
    setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
    setBackGroundColorOpacity(backgroundColor.a);
    setBackGroundColor(cocos2d::Color3B(backgroundColor));

    return true;
}

void MessageBox::setTitle(const std::string& title) {
    cocos2d::Label* titleLabel = cocos2d::Label::createWithTTF(title,
                                                               ConfigLoader::getInstance()->getString("MessageBox_font"),
                                                               ConfigLoader::getInstance()->getInteger("MessageBox_fontsize"));
    titleLabel->setAlignment(cocos2d::TextHAlignment::CENTER,
                             cocos2d::TextVAlignment::CENTER);

    addElement(titleLabel, CENTER);
}

void MessageBox::generateAcceptButton() {
    _acceptButton = cocos2d::ui::Button::create();
    addChild(_acceptButton);

    _acceptButton->setTitleText("Accept");
    _acceptButton->addTouchEventListener(CC_CALLBACK_2(MessageBox::onAcceptButtonTouched, this));
    _acceptButton->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE_BOTTOM);
    updateAcceptButtonPosition();
}

bool MessageBox::onAcceptButtonTouched(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type) {
    if(type == cocos2d::ui::Widget::TouchEventType::ENDED) {
        removeFromParentAndCleanup(true);
    }

    return true;
}

void MessageBox::addElement(cocos2d::Node* element, AlignPosition align) {
    addChild(element);
    alignElement(element, align);
    _offset.y += element->getContentSize().height + _verticalElementOffset;

    updateAcceptButtonPosition();
}


void MessageBox::alignElement(cocos2d::Node* element, AlignPosition align) {
    switch(align) {
    case LEFT:
    {
        element->setAnchorPoint(cocos2d::Vec2::ANCHOR_TOP_LEFT);
        element->setPosition(_offset.x, getContentSize().height - _offset.y);
    }
    break;
    case CENTER:
    {
        element->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE_TOP);
        element->setPosition(getContentSize().width * 0.5f,
                             getContentSize().height - _offset.y);
    }
    break;
    case RIGHT:
    {
        element->setAnchorPoint(cocos2d::Vec2::ANCHOR_TOP_RIGHT);
        element->setPosition(0, getContentSize().height - _offset.y);
    }
    break;
    }
}

void MessageBox::updateAcceptButtonPosition() {
    _acceptButton->setPosition(cocos2d::Vec2(getContentSize().width * 0.5f,
                                         getContentSize().height - getInnerContainerSize().height));

}

void MessageBox::setOffsetX(float offset) {
    _offset.x = offset;
}
