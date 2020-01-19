#include "GameLayer.h"
#include "GameClassesManager.h"
#include "MediaManager.h"
#include "ConfigLoader.h"
#include "MessageBox.h"
#include "Globals.h"

GameLayer* GameLayer::createGameLayer() {
    return GameLayer::create();
}

bool GameLayer::init() {
    if(!cocos2d::ui::ScrollView::init()) return false;

    setDirection(Direction::BOTH);
    setScrollBarEnabled(false);

    if(!gridDrawer.init(this, cocos2d::Color4F::WHITE,
                        cocos2d::Vec2(64, 64),
                        ConfigLoader::getInstance()->getSize("Grid_size"),
                        ConfigLoader::getInstance()->getInteger("Grid_hnumber"),
                        ConfigLoader::getInstance()->getInteger("Grid_vnumber"))) {
        return false;
    }

    setBackGroundColorType(BackGroundColorType::SOLID);
    setBackGroundColor(cocos2d::Color3B(51, 255, 51));

    world.setGameLayer(this);
    world.initWorld();

    //cocos2d::Director::getInstance()->getRunningScene()->getChildByTag(TAGS::UI_LAYER_TAG)->addChild(messageBox);
    return true;
}

void GameLayer::draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& mat4, uint32_t flag) {
    cocos2d::ui::ScrollView::draw(renderer, mat4, flag);
    gridDrawer.draw();
}

void GameLayer::setGridEnabled(bool enabled) {
    gridDrawer.setVisible(enabled);
}
