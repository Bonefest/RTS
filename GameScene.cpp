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
    addChild(_uiLayer, 2);

    if(!initGameLayer()) return false;

    if(!initTerrainGenerator()) return false;

    if(!initMenuButtons()) return false;

    //DEBUG
    _debugDrawer = cocos2d::DrawNode::create();
    addChild(_debugDrawer);
    scheduleUpdate();

    return true;
}


bool GameScene::initGameLayer() {
    _gameLayer = GameLayer::createGameLayer();
    if(_gameLayer == nullptr) return false;

    cocos2d::Size cellSize = ConfigLoader::getInstance()->getSize("Grid_size");
    int hnumber = ConfigLoader::getInstance()->getInteger("Grid_hnumber");
    int vnumber = ConfigLoader::getInstance()->getInteger("Grid_vnumber");

    _gameLayer->setContentSize(cocos2d::Size(0.8*visibleSize));
    _gameLayer->setPosition(0.1*visibleSize);
    _gameLayer->setInnerContainerSize(cocos2d::Size( (hnumber + 4) * cellSize.width,
                                                     (vnumber + 4) * cellSize.height));  //TODO: загрузка конфигурации из json
    _gameLayer->setInnerContainerPosition(_gameLayer->getInnerContainerSize() * 0.5f);
    _gameLayer->setTag(TAGS::GAME_LAYER_TAG);
    addChild(_gameLayer);

    return true;
}

bool GameScene::initTerrainGenerator() {
    if(!_terrainGenerator.init()) return false;

    _terrainGenerator.setObjectLimit(80);
    _terrainGenerator.setGameLayer(_gameLayer);
    _terrainGenerator.generate();

    return true;
}

bool GameScene::initMenuButtons() {
    _enableGridButton = cocos2d::ui::Button::create("Action_Enablegrid.png","", "",
                                                cocos2d::ui::Widget::TextureResType::PLIST);
    if(_enableGridButton == nullptr) return false;

    _enableGridButton->setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_RIGHT);
    _enableGridButton->setPosition(cocos2d::Vec2(visibleSize.width, 0));
    _enableGridButton->addTouchEventListener(CC_CALLBACK_2(GameScene::onGridButtonTouched, this));
    _enableGridButton->setEnabled(false);
    _enableGridButton->setVisible(false);

    _disableGridButton = cocos2d::ui::Button::create("Action_Disablegrid.png","", "",
                                                    cocos2d::ui::Widget::TextureResType::PLIST);
    if(_disableGridButton == nullptr) return false;
    _disableGridButton->setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_RIGHT);
    _disableGridButton->setPosition(cocos2d::Vec2(visibleSize.width, 0));
    _disableGridButton->addTouchEventListener(CC_CALLBACK_2(GameScene::onGridButtonTouched, this));

    addChild(_enableGridButton);
    addChild(_disableGridButton);

    return true;
}

bool GameScene::onGridButtonTouched(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type) {
    if(type == cocos2d::ui::Widget::TouchEventType::ENDED) {
        _enableGridButton->setEnabled(!_enableGridButton->isEnabled());
        _enableGridButton->setVisible(!_enableGridButton->isVisible());
        _disableGridButton->setEnabled(!_disableGridButton->isEnabled());
        _disableGridButton->setVisible(!_disableGridButton->isVisible());

        _gameLayer->setGridEnabled(_disableGridButton->isEnabled());
    }
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
