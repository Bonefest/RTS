#include "Action.h"

Action* Action::createAction(const std::string& iconName,
                             const std::string& title,
                             const std::string& useButtonImageName) {
    Action* action = new Action;
    if(action && action->init(iconName, title, useButtonImageName)) {
        action->autorelease();
        return action;
    } else {
        delete action;
        action = nullptr;
        return nullptr;
    }
}

bool Action::init(const std::string& iconName,
                  const std::string& title,
                  const std::string& useButtonImageName) {
    if(!cocos2d::Node::init()) return false;

    //TODO: iconName + "_selected", iconName + "_disabled" or "" if not found
    _icon = cocos2d::ui::Button::create(iconName, "", "", cocos2d::ui::Widget::TextureResType::PLIST);
    if(_icon == nullptr) return false;

    //TODO: action font configuration with json
    _title = cocos2d::Label::createWithTTF(title, "fonts/arial.ttf", 16);
    if(_title == nullptr) return false;

    _useButton = cocos2d::ui::Button::create(useButtonImageName == ""?"use.png":useButtonImageName, "", "", cocos2d::ui::Widget::TextureResType::PLIST);
    //_useButton->setTitleText(" USE ");
    if(_useButton == nullptr) return false;

    addChild(_icon);
    addChild(_title);
    addChild(_useButton);

    //TODO: json config
    setMaxTitleWidth(150.0f);

    _icon->addTouchEventListener(CC_CALLBACK_2(Action::onIconClicked, this));
    _useButton->addTouchEventListener(CC_CALLBACK_2(Action::onUseButtonClicked, this));

    return true;
}

void Action::calculateContentSize() {
    float height = std::max(std::max(_icon->getContentSize().height,
                                     _title->getContentSize().height),
                                     _useButton->getContentSize().height) - getPositionY();
    float width = _useButton->getPositionX() + _useButton->getContentSize().width - getPositionX();
    setContentSize(cocos2d::Size(width, height));

}

void Action::setMaxTitleWidth(float width) {
    if(!isInitialized()) return;

    _title->setMaxLineWidth(width);
    allignElements();
    calculateContentSize();
}

void Action::allignElements() {
    if(!isInitialized()) return;

    _icon->setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);
    _icon->setPosition(cocos2d::Vec2(getPosition() + cocos2d::Vec2(0, (_title->getContentSize().height - _icon->getContentSize().height) / 2)));

    _title->setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);
    _title->setPosition(getPosition() + cocos2d::Vec2(2*_icon->getContentSize().width, 0));

    _useButton->setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);
    _useButton->setPosition(cocos2d::Vec2(_icon->getPositionX() + _title->getMaxLineWidth() + 32, _icon->getPositionY()));
}

bool Action::isInitialized() {
    return (_icon != nullptr && _title != nullptr && _useButton != nullptr);
}
