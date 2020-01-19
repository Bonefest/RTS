#include "NetworkObject.h"

NetworkObject::~NetworkObject() {
    _button->removeFromParentAndCleanup(true);
}

bool NetworkObject::initWithJson(nlohmann::json& json) {
    //TODO: проверка на корректность и соответственно возврат true/false

    setDescription(json["Description"]);
    setCost(json["Cost"]);
    setDefense(json["Defense"]);
    setMaximalHP(json["MaximalHP"]);

    addActionName("ShowInfo");
    setActionNames(json["Actions"]);
    _button = cocos2d::ui::Button::create(json["Sprite"], "", "", cocos2d::ui::Button::TextureResType::PLIST);
    _button->addTouchEventListener(CC_CALLBACK_2(NetworkObject::onTouch, this));

    return true;
}

bool NetworkObject::onTouch(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type) {
    switch(type) {
    case cocos2d::ui::Widget::TouchEventType::BEGAN: onTouchBegan(ref); return true;
    case cocos2d::ui::Widget::TouchEventType::ENDED: onTouchEnded(ref); return true;
    case cocos2d::ui::Widget::TouchEventType::CANCELED: onTouchCancelled(ref); return true;
    case cocos2d::ui::Widget::TouchEventType::MOVED: onTouchMoved(ref); return true;
    }

    return false;
}

void NetworkObject::onSerialize(RakNet::VariableDeltaSerializer* serializer) {

}

void NetworkObject::onDeserialize(RakNet::VariableDeltaSerializer* serializer) {

}

void NetworkObject::setName(const std::string& name) {
    _name = name;
}

void NetworkObject::setDescription(const std::string& description)  {
    _description = description;
}

void NetworkObject::setCost(double cost) {
    _cost = cost;
}

void NetworkObject::setDefense(double defense) {
    _defense = defense;
}

void NetworkObject::setMaximalHP(double maximalHP) {
    _maximalHP = maximalHP;
}

void NetworkObject::setHP(double hp) {
    _currentHP = hp;
}

void NetworkObject::setPosition(const cocos2d::Vec2& position) {
    _button->setPosition(position);
}

const cocos2d::Vec2& NetworkObject::getPosition() const {
    return _button->getPosition();
}

void NetworkObject::addActionName(const std::string& name) {
    _actionNames.push_back(name);
}

void NetworkObject::setActionNames(const std::vector<std::string>& actions) {
    for(auto& name: actions) {
        _actionNames.push_back(name);
    }
}
