#include "GameClassesManager.h"
#include <fstream>

GameClassesManager* GameClassesManager::getInstance() {
    static GameClassesManager instance;
    return &instance;
}

bool GameClassesManager::parseJsonFile(const std::string& fileName) {
    std::ifstream jsonFile(fileName);
    if(!jsonFile.is_open()) return false;

    nlohmann::json json;
    jsonFile >> json;

    loadUnits(json["units"]);
    loadBuildings(json["buildings"]);

    jsonFile.close();

    return true;
}

void GameClassesManager::loadUnits(nlohmann::json& json) {
    Unit unit;
    for(auto unitData: json.items()) {
        unit.initWithJson(unitData.value());
        unit.setName(unitData.key());
        _units[unitData.key()] = unit;
    }
}

void GameClassesManager::loadBuildings(nlohmann::json& json) {
    Building building;
    for(auto buildingData: json.items()) {
        building.initWithJson(buildingData.value());
        building.setName(buildingData.key());
        _buildings[buildingData.key()] = building;
    }
}

std::shared_ptr<NetworkObject> GameClassesManager::getUnit(const std::string& unitClassName) {
    auto iter = _units.find(unitClassName);
    if(iter == _units.end()) return nullptr;

    return iter->second.clone();
}

std::shared_ptr<NetworkObject> GameClassesManager::getBuilding(const std::string& buildingClassName) {
    auto iter = _buildings.find(buildingClassName);
    if(iter == _buildings.end()) return nullptr;

    return iter->second.clone();
}
