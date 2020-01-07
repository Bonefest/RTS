#ifndef MEDIAMANAGER_H_INCLUDED
#define MEDIAMANAGER_H_INCLUDED

/*
"animation1" {
    "frames":["move_left","move_right",...]
    "speed":1.0,
    "repeat":false
};

*/

#include <string>
#include <map>
#include "json.hpp"
#include "cocos2d.h"

class MediaManager {
public:
    static MediaManager* getInstance();

    void loadSpritesheet(const std::string& fileName);
    bool loadAnimations(const std::string& fileName);

    cocos2d::SpriteFrame* getSpriteFrame(const std::string& spriteFrameName);
    cocos2d::Animation* getAnimation(const std::string& animationName);

private:
    MediaManager();
    MediaManager(const MediaManager&);
    const MediaManager& operator=(const MediaManager&);
    cocos2d::Animation* createAnimationFromJson(nlohmann::json& jsonParser);

    cocos2d::SpriteFrameCache* _frameCache;
    std::map<std::string, cocos2d::Animation*> _animations;
};

#endif // MEDIAMANAGER_H_INCLUDED
