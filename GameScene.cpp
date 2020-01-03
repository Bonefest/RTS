#include "GameScene.h"

GameScene* GameScene::createScene() {
    return GameScene::create();
}

bool GameScene::init() {
    if(!cocos2d::Scene::init()) return false;

    if(!gridDrawer.init(this, cocos2d::Color4F::WHITE, cocos2d::Vec2::ZERO, cocos2d::Size(32, 32), 24, 24))
        return false;



    scheduleUpdate();
    return true;
}



void GameScene::render(cocos2d::Renderer* renderer, const cocos2d::Mat4& eyeTransform, const cocos2d::Mat4* eyeProjection) {
    cocos2d::Scene::render(renderer, eyeTransform, eyeProjection);
    gridDrawer.draw();
}

void GameScene::update(float delta) {

    getDefaultCamera()->setPosition(getDefaultCamera()->getPosition() + cocos2d::Vec2(50, 50)*delta);

}
