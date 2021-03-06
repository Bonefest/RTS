#ifndef NETWORKOBJECT_H_INCLUDED
#define NETWORKOBJECT_H_INCLUDED

#include <string>
#include "cocos2d.h"
#include "json.hpp"
#include "../RakNet/Source/VariableDeltaSerializer.h"
#include "../RakNet/Source/ReplicaManager3.h"

#include "NetworkObjectReplica.h"
#include "ui/UIButton.h"

#include <memory>
//
//struct ObjectData {
//    double cost;
//    double defense;
//    double maximalHP;
//    double currentHP;
//    Type type;
//};

class NetworkObject {
public:
    virtual ~NetworkObject();
    virtual bool initWithJson(nlohmann::json& json);

    virtual void onSerialize(RakNet::VariableDeltaSerializer* serializer);
    virtual void onDeserialize(RakNet::VariableDeltaSerializer* serializer);

    void setName(const std::string& name);
    inline const std::string& getName() const { return _name; }

    void setDescription(const std::string& description);
    inline const std::string& getDescription() const { return _description; }

    void setCost(double cost);
    double getCost() const { return _cost; }

    void setDefense(double defense);
    double getDefense() const { return _defense; }

    void setMaximalHP(double maximalHP);
    double getMaximalHP() const { return _maximalHP; }

    void setHP(double hp);
    double getHP() const { return _currentHP; }

    void setPosition(const cocos2d::Vec2& position);
    inline const cocos2d::Vec2& getPosition() const;

    void addActionName(const std::string& actionName);

    void setActionNames(const std::vector<std::string>& actions);
    const std::vector<std::string>& getActionNames() const { return _actionNames; }

    void clearActions() { _actionNames.clear(); }

    virtual void onTouchBegan(cocos2d::Ref* ref) { }
    virtual void onTouchEnded(cocos2d::Ref* ref) { }
    virtual void onTouchCancelled(cocos2d::Ref* ref) { }
    virtual void onTouchMoved(cocos2d::Ref* ref) { }

    void addToScene(cocos2d::Node* scene) {
        scene->addChild(_button);
    }

    cocos2d::ui::Button* getButton() { return _button; }

private:
    bool onTouch(cocos2d::Ref*, cocos2d::ui::Widget::TouchEventType type);

    cocos2d::ui::Button* _button;

    std::string _name;
    std::string _description;

    RakNet::Replica3Composite<NetworkObjectReplica> _replica;
    //std::vector<Action*> actions;
    //std::map<std::string, Animation*> animations;

    std::vector<std::string> _actionNames;

    double _cost;
    double _defense;
    double _maximalHP;
    double _currentHP;
};


#endif // NETWORKOBJECT_H_INCLUDED
