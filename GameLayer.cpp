#include "GameLayer.h"
#include "GameClassesManager.h"
#include "ActionScroller.h"

GameLayer* GameLayer::createGameLayer() {
    return GameLayer::create();
}

bool GameLayer::init() {
    if(!cocos2d::ui::ScrollView::init()) return false;

    setDirection(Direction::BOTH);
    setScrollBarEnabled(false);

    if(!gridDrawer.init(this, cocos2d::Color4F::WHITE, cocos2d::Vec2(64, 64), cocos2d::Size(32, 32), 24, 24))
        return false;


    ActionScroller* scroller = ActionScroller::createActionScroller();
    scroller->setContentSize(cocos2d::Size(320, 64));
    scroller->setDirection(ActionScroller::Direction::HORIZONTAL);
    scroller->addChild(cocos2d::Sprite::create("HelloWorld.png"));
    scroller->addChild(cocos2d::Sprite::create("HelloWorld.png"));
    scroller->addChild(cocos2d::Sprite::create("HelloWorld.png"));
    scroller->addChild(cocos2d::Sprite::create("HelloWorld.png"));
    scroller->addChild(cocos2d::Sprite::create("HelloWorld.png"));
    scroller->setPosition(cocos2d::Vec2(0, 0));
    scroller->setScrollBarEnabled(false);
    addChild(scroller);

    return true;
}

void GameLayer::draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& mat4, uint32_t flag) {
    cocos2d::ui::ScrollView::draw(renderer, mat4, flag);
    gridDrawer.draw();
}
