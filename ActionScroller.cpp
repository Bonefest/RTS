#include "ActionScroller.h"
#include "ConfigLoader.h"

ActionScroller* ActionScroller::createActionScroller() {
    return ActionScroller::create();
}

bool ActionScroller::init() {
    if(!cocos2d::ui::ScrollView::init()) return false;

    setScrollBarEnabled(false);

    _contextOffset = cocos2d::Vec2::ZERO;
    _closeButton = cocos2d::ui::Button::create("close.png", "", "", TextureResType::PLIST);
    _closeButton->setAnchorPoint(cocos2d::Vec2::ANCHOR_TOP_RIGHT);
    _closeButton->setPosition(cocos2d::Vec2::ZERO);
    _closeButton->setContentSize(ConfigLoader::getInstance()->getSize("Action_default_size"));
    _closeButton->addTouchEventListener(CC_CALLBACK_2(ActionScroller::onCloseButtonTouched, this));
    addChild(_closeButton);

    setSideOffset(ConfigLoader::getInstance()->getVec2("Action_side_offset"));

    cocos2d::Color4B backgroundColor = ConfigLoader::getInstance()->getColor("Action_background_color");
    setBackGroundColorType(cocos2d::ui::ScrollView::BackGroundColorType::SOLID);
    setBackGroundColor(cocos2d::Color3B(backgroundColor));
    setBackGroundColorOpacity(backgroundColor.a);

    return true;
}

void ActionScroller::addAction(Node* child) {
    addChild(child);

    child->setAnchorPoint(cocos2d::Vec2::ANCHOR_TOP_LEFT);
    child->setPosition(cocos2d::Vec2(_sideOffset.x, getContentSize().height -
                                                   (_contextOffset.y + _sideOffset.y)));
    _contextOffset.y += child->getContentSize().height;
    recalculateSize(child);

    _closeButton->setPosition(getContentSize());
}

void ActionScroller::recalculateSize(cocos2d::Node* newAction) {
    cocos2d::Size newContentSize = getContentSize();
    newContentSize.width = std::max(newContentSize.width, newAction->getContentSize().width +
                                                          _closeButton->getContentSize().width +
                                                          2*_sideOffset.x);
    cocos2d::Size newInnerContainerSize = newContentSize;
    newInnerContainerSize.height = std::max(_contextOffset.y + _sideOffset.y, newInnerContainerSize.height);

    setContentSize(newContentSize);
    setInnerContainerSize(newInnerContainerSize);
}

void ActionScroller::setPosition(const cocos2d::Vec2& position) {
    cocos2d::ui::ScrollView::setPosition(position);
    _closeButton->setPosition(getContentSize());
}

void ActionScroller::setSideOffset(const cocos2d::Vec2& offset) {
    _sideOffset = offset;
}

bool ActionScroller::onCloseButtonTouched(cocos2d::Ref* ref,
                                          cocos2d::ui::Widget::TouchEventType type) {
    if(type == cocos2d::ui::Widget::TouchEventType::ENDED) {
        removeFromParentAndCleanup(true);
    }

    return true;
}
