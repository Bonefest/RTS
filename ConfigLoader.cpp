#include "ConfigLoader.h"

#include <fstream>

ConfigLoader* ConfigLoader::getInstance() {
    static ConfigLoader loader;
    return &loader;
}

void ConfigLoader::loadConfig(const std::string& configName) {
    std::ifstream configFile(configName);
    configFile >> _jsonConfig;
    configFile.close();
}

std::string ConfigLoader::getString(const std::string& key) {
    return _jsonConfig[key];
}

int ConfigLoader::getInteger(const std::string& key) {
    return _jsonConfig[key];
}

double ConfigLoader::getDouble(const std::string& key) {
    return _jsonConfig[key];
}

bool ConfigLoader::getBool(const std::string& key) {
    return _jsonConfig[key];
}

cocos2d::Color4B ConfigLoader::getColor(const std::string& key) {
    std::vector<short> colors = _jsonConfig[key];
    for(size_t i = colors.size(); i < 3; ++i) {
        colors.push_back(0);
    }

    if(colors.size() != 4) colors.push_back(255);


    return cocos2d::Color4B(colors[0], colors[1], colors[2], colors[3]);
}

cocos2d::Size ConfigLoader::getSize(const std::string& key) {
    return cocos2d::Size(_jsonConfig[key][0], _jsonConfig[key][1]);
}
