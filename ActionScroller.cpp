#include "ActionScroller.h"

ActionScroller* ActionScroller::createActionScroller() {
    return ActionScroller::create();
}

bool ActionScroller::init() {
    if(!cocos2d::ui::ScrollView::init()) return false;

    setScrollBarEnabled(false);

    _contextOffset = cocos2d::Vec2::ZERO;
    _closeButton = cocos2d::ui::Button::create("close.png");
    _closeButton->setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);
    _closeButton->setPosition(cocos2d::Vec2::ZERO);
    _closeButton->addTouchEventListener(CC_CALLBACK_2(ActionScroller::onCloseButtonTouched, this));

    return true;
}

void ActionScroller::addChild(Node* child) {
    cocos2d::ui::ScrollView::addChild(child);

    child->setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);
    child->setPosition(getPosition() + cocos2d::Vec2(_contextOffset.x, 0));
    _contextOffset.x += child->getContentSize().width;
    setInnerContainerSize(cocos2d::Size(std::max(_contextOffset.x, getContentSize().width), getContentSize().height));

    _closeButton->setPosition(getPosition() + getContentSize());
}

void ActionScroller::setParent(cocos2d::Node* parent) {
    cocos2d::ui::ScrollView::setParent(parent);
    if(parent != nullptr) parent->addChild(_closeButton);
}

void ActionScroller::removeFromParent() {
    cocos2d::ui::ScrollView::removeFromParent();
    _closeButton->removeFromParent();
}

void ActionScroller::removeFromParentAndCleanup(bool cleanup) {
    cocos2d::ui::ScrollView::removeFromParentAndCleanup(cleanup);
    _closeButton->removeFromParentAndCleanup(cleanup);
}

void ActionScroller::setPosition(const cocos2d::Vec2& position) {
    cocos2d::ui::ScrollView::setPosition(position);
    _closeButton->setPosition(position + getContentSize());
}

bool ActionScroller::onCloseButtonTouched(cocos2d::Ref* ref,
                                          cocos2d::ui::Widget::TouchEventType type) {
    if(type == cocos2d::ui::Widget::TouchEventType::ENDED) {
        removeFromParentAndCleanup(true);
    }

    return true;
}
