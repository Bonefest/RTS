#ifndef ACTIONSCROLLER_H_INCLUDED
#define ACTIONSCROLLER_H_INCLUDED

#include "ui/UIScrollView.h"
#include "ui/UIButton.h"

class ActionScroller: public cocos2d::ui::ScrollView {
public:
    CREATE_FUNC(ActionScroller);
    static ActionScroller* createActionScroller();
    bool init();

    void addChild(Node* child);
    void setParent(cocos2d::Node* parent);

    void removeFromParent();
    void removeFromParentAndCleanup(bool cleanup);

    void setPosition(const cocos2d::Vec2& position);

    bool onCloseButtonTouched(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
private:
    cocos2d::ui::Button* _closeButton;
    cocos2d::Vec2 _contextOffset;
};

#endif // ACTIONSCROLLER_H_INCLUDED
