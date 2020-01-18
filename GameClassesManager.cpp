#include "GameClassesManager.h"
#include <fstream>

GameClassesManager* GameClassesManager::getInstance() {
    static GameClassesManager instance;
    return &instance;
}

bool GameClassesManager::parseJsonFile(const std::string& fileName) {
    std::ifstream jsonFile(fileName);
    if(!jsonFile.is_open()) return false;

    jsonFile >> _json;

    jsonFile.close();

    return true;
}

std::shared_ptr<NetworkObject> GameClassesManager::getUnit(const std::string& unitClassName) {
    std::shared_ptr<NetworkObject> unit = std::make_shared<Unit>();
    unit->initWithJson(_json["units"][unitClassName]);
    unit->setName(unitClassName);

    return unit;
}

std::shared_ptr<NetworkObject> GameClassesManager::getBuilding(const std::string& buildingClassName) {
    std::shared_ptr<Building> building = std::make_shared<Building>();
    building->initWithJson(_json["buildings"][buildingClassName]);
    building->setName(buildingClassName);

    return building;
}
