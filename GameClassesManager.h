#ifndef GAMECLASSESMANAGER_H_INCLUDED
#define GAMECLASSESMANAGER_H_INCLUDED

#include <string>
#include <map>

#include "json.hpp"
#include "cocos2d.h"

#include "Building.h"
#include "Unit.h"

class GameClassesManager {
public:
    static GameClassesManager* getInstance();

    bool parseJsonFile(const std::string& fileName);

    std::shared_ptr<NetworkObject> getUnit(const std::string& unitClassName);
    std::shared_ptr<NetworkObject> getBuilding(const std::string& buildingClassName);

private:
    GameClassesManager() { }
    GameClassesManager(const GameClassesManager&);
    GameClassesManager& operator=(const GameClassesManager&);

    //void loadCards(nlohmann:json& json);

    nlohmann::json _json;
};

#endif // GAMECLASSESMANAGER_H_INCLUDED
