#include "BackgroundTerrainGenerator.h"
#include "ConfigLoader.h"
#include "Globals.h"

BackgroundTerrainGenerator::BackgroundTerrainGenerator():_layer(nullptr) { }

bool BackgroundTerrainGenerator::init() {
    _objectFrameNames = ConfigLoader::getInstance()->get<std::vector<std::string>>("Terrain_objects");
    return true;
}

void BackgroundTerrainGenerator::setGameLayer(cocos2d::ui::ScrollView* layer) {
    _layer = layer;
}

void BackgroundTerrainGenerator::setObjectLimit(int limit) {
    _maximalObjectCount = limit;
}

void BackgroundTerrainGenerator::setSpawnChance(double chance) {
    _spawnChance = chance;
}

void BackgroundTerrainGenerator::generate() {
    cocos2d::Size layerSize = _layer->getInnerContainerSize();
    for(int i = 0; i < _maximalObjectCount; ++i) {
        cocos2d::Sprite* newObject = generateNewObject();
        newObject->setPosition(cocos2d::Vec2(cocos2d::random(0.0f, layerSize.width),
                                             cocos2d::random(0.0f, layerSize.height)));

        _layer->addChild(newObject);
    }
}

cocos2d::Sprite* BackgroundTerrainGenerator::generateNewObject() {
    cocos2d::Sprite* sprite = cocos2d::Sprite::createWithSpriteFrameName(_objectFrameNames[cocos2d::random(std::size_t(0), _objectFrameNames.size() - 1 )]);
    sprite->setTag(TERRAIN_OBJECT);
    return sprite;
}
