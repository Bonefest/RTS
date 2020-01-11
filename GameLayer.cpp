#include "GameLayer.h"
#include "GameClassesManager.h"
#include "ActionScroller.h"
#include "MediaManager.h"
#include "Action.h"

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
    scroller->setContentSize(cocos2d::Size(150, 64));
    scroller->setDirection(ActionScroller::Direction::VERTICAL);
    scroller->addChild(Action::createAction("Action_Build.png", "Upgrade building bla bla bla bla bla"));
    scroller->addChild(Action::createAction("Action_Attack.png", "Attack selected unit"));
    scroller->addChild(Action::createAction("Action_Attack.png", "Attack selected unit"));

    //addChild(action);

//    scroller->addChild(cocos2d::Sprite::create("HelloWorld.png"));
//    scroller->addChild(cocos2d::Sprite::create("HelloWorld.png"));
//    scroller->addChild(cocos2d::Sprite::create("HelloWorld.png"));
    scroller->setPosition(cocos2d::Vec2(196, 196));
    scroller->setScrollBarEnabled(false);
    addChild(scroller);

    return true;
}

void GameLayer::draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& mat4, uint32_t flag) {
    cocos2d::ui::ScrollView::draw(renderer, mat4, flag);
    gridDrawer.draw();
}
