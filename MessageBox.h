#ifndef MESSAGEBOX_H_INCLUDED
#define MESSAGEBOX_H_INCLUDED

#include "cocos2d.h"
#include "ui/UIScrollView.h"
#include "ui/UIButton.h"


class MessageBox : public cocos2d::ui::ScrollView {
public:
    enum AlignPosition {LEFT, CENTER, RIGHT};

    CREATE_FUNC(MessageBox);
    static MessageBox* createBox(const std::string& title, const cocos2d::Size& size = cocos2d::Size::ZERO);
    bool init();

    void addElement(cocos2d::Node* element, AlignPosition align = LEFT);
    void setTitle(const std::string& title);
    void setOffsetX(float offset);
    void setVerticalElementOffset(float offset);

    bool onAcceptButtonTouched(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    //void setEnabledAcceptButton;
private:
    void generateAcceptButton();
    void alignElement(cocos2d::Node* element, AlignPosition align);
    void updateAcceptButtonPosition();

    cocos2d::ui::Button* _acceptButton;

    cocos2d::Vec2 _offset;
    float _verticalElementOffset;
};


#endif // MESSAGEBOX_H_INCLUDED
