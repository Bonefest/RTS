#ifndef ACTIONFACTORY_H_INCLUDED
#define ACTIONFACTORY_H_INCLUDED

#include "Action.h"
#include "NetworkObject.h"
#include <string>

class ActionFactory {
public:
    Action* createAction(const std::string& actionName, NetworkObject* object);
};

#endif // ACTIONFACTORY_H_INCLUDED
