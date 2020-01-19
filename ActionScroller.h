#ifndef ACTIONSCROLLER_H_INCLUDED
#define ACTIONSCROLLER_H_INCLUDED

#include "ui/UIScrollView.h"
#include "ui/UIButton.h"

class ActionScroller: public cocos2d::ui::ScrollView {
public:
    CREATE_FUNC(ActionScroller);
    static ActionScroller* createActionScroller();
    bool init();

    void addAction(Node* action);

    void setPosition(const cocos2d::Vec2& position);
    void setSideOffset(const cocos2d::Vec2& offset);

    bool onCloseButtonTouched(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
private:
    void recalculateSize(cocos2d::Node* newAction);

    cocos2d::ui::Button* _closeButton;
    cocos2d::Vec2 _contextOffset;
    cocos2d::Vec2 _sideOffset;
};

#endif // ACTIONSCROLLER_H_INCLUDED
