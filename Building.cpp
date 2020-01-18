#include "Building.h"
#include "ActionScroller.h"
#include "Globals.h"

void Building::onTouchEnded(cocos2d::Ref* ref) {
    ActionScroller* actionScroller = ActionScroller::createActionScroller();

    for(const std::string& actionName: actions) {
        Action* action = ActionFactory(actionName);
        actionScroller->addChild(action);
    }

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    actionScroller->setPosition(visibleSize * 0.5f);

    cocos2d::Node* uiLayer = cocos2d::Director::getInstance()->getRunningScene()->getChildByTag(TAGS::UI_LAYER_TAG);
    uiLayer->removeChildByTag(UI_ACTION_SCROLLER, true);
    uiLayer->addChild(actionScroller);
}
