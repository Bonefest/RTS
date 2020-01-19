#include "Building.h"
#include "ActionScroller.h"
#include "Globals.h"
#include "ActionFactory.h"

void Building::onTouchEnded(cocos2d::Ref* ref) {
    ActionScroller* actionScroller = ActionScroller::createActionScroller();
    actionScroller->setContentSize(cocos2d::Size(100, 200));
    actionScroller->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);
    actionScroller->setTag(UI_ACTION_SCROLLER);

    ActionFactory actionFactory;
    for(const std::string& actionName: getActionNames()) {
        Action* action = actionFactory.createAction(actionName, this);
        actionScroller->addAction(action);
        cocos2d::log("%s", actionName.c_str());
    }

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    actionScroller->setPosition(visibleSize * 0.5f);

    cocos2d::Node* uiLayer = cocos2d::Director::getInstance()->getRunningScene()->getChildByTag(TAGS::UI_LAYER_TAG);
    uiLayer->removeChildByTag(UI_ACTION_SCROLLER, true);
    uiLayer->addChild(actionScroller);
}
