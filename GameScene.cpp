#include "GameScene.h"
#include "NetworkObject.h"

GameScene* GameScene::createScene() {
    return GameScene::create();
}

bool GameScene::init() {
    if(!cocos2d::Scene::init()) return false;

    if(!gridDrawer.init(this, cocos2d::Color4F::WHITE, cocos2d::Vec2::ZERO, cocos2d::Size(32, 32), 24, 24))
        return false;

    //if(!classesGenerator.init("classes.json")) return false;

    cocos2d::EventListenerTouchOneByOne* listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    //listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
    listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    scheduleUpdate();
    return true;
}


bool GameScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {
    return true;
}

void GameScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) {
    cocos2d::Vec2 mover = (touch->getStartLocation() - touch->getLocation()) * 0.05;
    getDefaultCamera()->setPosition(getDefaultCamera()->getPosition() + mover);

}


void GameScene::render(cocos2d::Renderer* renderer, const cocos2d::Mat4& eyeTransform, const cocos2d::Mat4* eyeProjection) {
    cocos2d::Scene::render(renderer, eyeTransform, eyeProjection);
    gridDrawer.draw();
}

void GameScene::update(float delta) {
    cocos2d::Vec2 cameraPosition = getDefaultCamera()->getPosition();
    cameraPosition.x = std::max(-3*32.0f, cameraPosition.x);
    cameraPosition.x = std::min(27*32.0f, cameraPosition.x);

    cameraPosition.y = std::max(-3*32.0f, cameraPosition.y);
    cameraPosition.y = std::min(27*32.0f, cameraPosition.y);

    getDefaultCamera()->setPosition(cameraPosition);


}
