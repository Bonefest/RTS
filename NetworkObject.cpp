#include "NetworkObject.h"

bool NetworkObject::initWithJson(nlohmann::json& json) {

}

std::shared_ptr<NetworkObject> NetworkObject::clone() {
    std::shared_ptr<NetworkObject> object = std::make_shared<NetworkObject>();

    object->_name = _name;
    object->_description = _description;

    object->_cost = _cost;
    object->_defense = _defense;
    object->_maximalHP = _maximalHP;

    object->_sprite = cocos2d::Sprite::createWithTexture(_sprite->getTexture());
    _sprite->getParent()->addChild(object->_sprite);

    return object;
}

void NetworkObject::onSerialize(RakNet::VariableDeltaSerializer* serializer) {

}

void NetworkObject::onDeserialize(RakNet::VariableDeltaSerializer* serializer) {

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
