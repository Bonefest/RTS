#include "MediaManager.h"
#include "cocos2d.h"

#include <fstream>

MediaManager::MediaManager() {
    _frameCache = cocos2d::SpriteFrameCache::getInstance();
}

MediaManager* MediaManager::getInstance() {
    static MediaManager instance;
    return &instance;
}

void MediaManager::loadSpritesheet(const std::string& fileName) {
    _frameCache->addSpriteFramesWithFile(fileName);
}

bool MediaManager::loadAnimations(const std::string& fileName) {
    std::ifstream jsonFile(fileName);
    if(!jsonFile.is_open()) return false;

    nlohmann::json jsonParser;
    jsonFile >> jsonParser;

    for(auto animationItem : jsonParser.items()) {
        _animations[animationItem.key()] = createAnimationFromJson(animationItem.value());
    }

    return true;
}

cocos2d::Animation* MediaManager::createAnimationFromJson(nlohmann::json& jsonParser) {
    cocos2d::Animation* animation = cocos2d::Animation::create();
    if(animation == nullptr) return nullptr;

    cocos2d::SpriteFrame* frame = nullptr;
    for(const std::string& frameName : jsonParser["frames"]) {
        frame = _frameCache->getSpriteFrameByName(frameName);
        if(frame == nullptr) {
            std::string spritesheetName = jsonParser.value("spritesheet", "");
            if(spritesheetName != "") {
                loadSpritesheet(spritesheetName);
            }
            frame = _frameCache->getSpriteFrameByName(frameName);
        }

        if(frame != nullptr)
            animation->addSpriteFrame(frame);
        else {
            animation->release();
            return nullptr;
        }
    }
    animation->setDelayPerUnit(jsonParser.value("delay", 0.16));
    animation->setLoops(jsonParser.value("loops", -1));
    animation->setRestoreOriginalFrame(jsonParser.value("restore", true));

    return animation;
}
