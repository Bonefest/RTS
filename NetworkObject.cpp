#include "NetworkObject.h"

NetworkObject& NetworkObject::operator=(const NetworkObject& object) {
    if(this == &object) return *this;

    _name = object._name;
    _description = object._description;

    _cost = object._cost;
    _defense = object._defense;
    _maximalHP = object._maximalHP;
    _sprite = cocos2d::Sprite::createWithSpriteFrame(object._sprite->getSpriteFrame());
}

bool NetworkObject::initWithJson(nlohmann::json& json) {
    //TODO: проверка на корректность и соответственно возврат true/false

    setDescription(json["Description"]);
    setCost(json["Cost"]);
    setDefense(json["Defense"]);
    setMaximalHP(json["MaximalHP"]);
    _sprite = cocos2d::Sprite::create(json["Sprite"]);

    return true;
}

std::shared_ptr<NetworkObject> NetworkObject::clone() {
    std::shared_ptr<NetworkObject> object = std::make_shared<NetworkObject>();

    *object = *this;
    if(_sprite->getParent())
        _sprite->getParent()->addChild(_sprite);

    return object;
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
    _sprite->setPosition(position);
}

const cocos2d::Vec2& NetworkObject::getPosition() const {
    return _sprite->getPosition();
}
