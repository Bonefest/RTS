#ifndef ACTION_H_INCLUDED
#define ACTION_H_INCLUDED

#include <string>

#include "cocos2d.h"
#include "ui/UIButton.h"
#include "Command.h"

#include <memory>

class Action: public cocos2d::Node {
public:
    static Action* createAction(const std::string& iconName,
                                const std::string& title,
                                const std::string& useButtonImageName="");

    virtual bool init(const std::string& iconName,
                      const std::string& title,
                      const std::string& useButtonImageName);

    void setCommand(std::shared_ptr<Command> command);

    virtual bool onIconClicked(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    virtual bool onUseButtonClicked(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);

    void setMaxTitleWidth(float width);
private:
    bool isInitialized();
    void allignElements();
    void calculateContentSize();

    cocos2d::ui::Button* _icon;
    cocos2d::Label* _title;
    cocos2d::ui::Button* _useButton;

    std::shared_ptr<Command> _command;
};

#endif // ACTION_H_INCLUDED
