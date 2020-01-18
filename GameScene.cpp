#include "GameScene.h"
#include "GameClassesManager.h"
#include "MediaManager.h"
#include "ConfigLoader.h"
#include "GameLayer.h"
#include "Globals.h"

GameScene* GameScene::createScene() {
    return GameScene::create();
}

bool GameScene::init() {
    if(!cocos2d::Scene::init()) return false;

    visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    if(!GameClassesManager::getInstance()->parseJsonFile("classes.json")) return false;
    MediaManager::getInstance()->loadSpritesheet("sheet.plist");

    ConfigLoader::getInstance()->loadConfig("config.json");

    _uiLayer = cocos2d::Node::create();
    _uiLayer->setTag(TAGS::UI_LAYER_TAG);
    addChild(_uiLayer);

    if(!initGameLayer()) return false;


    //DEBUG
    _debugDrawer = cocos2d::DrawNode::create();
    addChild(_debugDrawer);
    scheduleUpdate();

    return true;
}


bool GameScene::initGameLayer() {
    _gameLayer = GameLayer::createGameLayer();
    if(_gameLayer == nullptr) return false;

    _gameLayer->setContentSize(cocos2d::Size(0.8*visibleSize));
    _gameLayer->setPosition(0.1*visibleSize);
    _gameLayer->setInnerContainerSize(cocos2d::Size(27 * 32, 27 * 32));  //TODO: загрузка конфигурации из json
    _gameLayer->setInnerContainerPosition(_gameLayer->getInnerContainerSize() * 0.5f);
    _gameLayer->setTag(TAGS::GAME_LAYER_TAG);
    addChild(_gameLayer);

    return true;
}

bool GameScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {
    return true;
}

void GameScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) {
    cocos2d::Vec2 mover = (touch->getStartLocation() - touch->getLocation()) * 0.05;
    getDefaultCamera()->setPosition(getDefaultCamera()->getPosition() + mover);

}

void GameScene::update(float delta) {
    _debugDrawer->clear();
    _debugDrawer->drawRect(_gameLayer->getPosition(),
                           cocos2d::Vec2(_gameLayer->getContentSize()) + _gameLayer->getPosition(),
                           cocos2d::Color4F::WHITE);


}
