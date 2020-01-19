#ifndef BACKGROUNDTERRAINGENERATOR_H_INCLUDED
#define BACKGROUNDTERRAINGENERATOR_H_INCLUDED

#include "cocos2d.h"
#include "ui/UIScrollView.h"
#include <vector>
#include <string>

class BackgroundTerrainGenerator {
public:
    BackgroundTerrainGenerator();

    bool init();

    void setGameLayer(cocos2d::ui::ScrollView* layer);
    void setObjectLimit(int limit);
    int getObjectLimit() const { return _maximalObjectCount; }

    void setSpawnChance(double chance);

    void generate();

private:
    cocos2d::Sprite* generateNewObject();

    cocos2d::SpriteBatchNode* _spriteBatch;
    cocos2d::ui::ScrollView* _layer;

    std::vector<std::string> _objectFrameNames;

    int _maximalObjectCount;
    double _spawnChance;
};

#endif // BACKGROUNDTERRAINGENERATOR_H_INCLUDED
