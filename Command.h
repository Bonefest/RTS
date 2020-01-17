#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <string>

class Command {
public:
    virtual void execute() = 0;
    virtual const std::string& getInfo() = 0;
    virtual const std::string& getCommandName() = 0;
    //virtual void showInfo() - чтобы мы могли создавать в коммандах не только текстовый вывод информации, но и произвольный
};

class NullCommand: public Command {
public:
    void execute() { }
    const std::string& getInfo() { "Null command"; }
    const std::string& getCommandName() { return getInfo(); }
};


#include "NetworkObject.h"
class ShowObjectInformation: public Command {
public:
    ShowObjectInformation(cocos2d::Node* uiLayer, NetworkObject* object);

    virtual void execute();

    void setObject(NetworkObject* object);
    void setUILayer(cocos2d::Node* uiLayer);
private:
    void createMessageBox();

    cocos2d::Node* _uiLayer;
    NetworkObject* _object;
};

#endif // COMMAND_H_INCLUDED
