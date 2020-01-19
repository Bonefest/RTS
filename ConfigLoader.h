#ifndef CONFIGLOADER_H_INCLUDED
#define CONFIGLOADER_H_INCLUDED

#include "cocos2d.h"
#include "json.hpp"

class ConfigLoader {
public:
    static ConfigLoader* getInstance();

    void loadConfig(const std::string& configName);

    //template?

    template <typename T> T get(const std::string& key) {
        return _jsonConfig[key].get<T>();
    }

    std::string getString(const std::string& key);
    int getInteger(const std::string& key);
    double getDouble(const std::string& key);
    bool getBool(const std::string& key);
    cocos2d::Color4B getColor(const std::string& key);
    cocos2d::Size getSize(const std::string& key);
    cocos2d::Vec2 getVec2(const std::string& key);

private:
    ConfigLoader() { }
    ConfigLoader(const ConfigLoader&);
    ConfigLoader& operator=(const ConfigLoader&);

    nlohmann::json _jsonConfig;
};

#endif // CONFIGLOADER_H_INCLUDED
