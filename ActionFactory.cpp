#include "ActionFactory.h"
#include "Command.h"
#include "Globals.h"

Action* ActionFactory::createAction(const std::string& actionName, NetworkObject* object) {
    //TODO: json configuration
    if(actionName == "ShowInfo") {
        Action* action = Action::createAction("Action_info.png", "Show info");
        action->setCommand(std::make_shared<ShowObjectInformation>(cocos2d::Director::getInstance()->getRunningScene()->getChildByTag(UI_LAYER_TAG), object));
        cocos2d::log("%s", actionName.c_str());
        return action;
    }

    Action* nullAction = Action::createAction("close.png", "Null action", "close.png");
    nullAction->setCommand(std::make_shared<NullCommand>());
    return nullAction;
}
