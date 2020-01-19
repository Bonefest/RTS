#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "NetworkObject.h"

#include <vector>
#include <memory>

class World {
public:

    void setGameLayer(cocos2d::Node* layer);
    bool initWorld();

private:
    std::vector<std::vector<std::shared_ptr<NetworkObject> > > _buildings;
    std::vector<std::vector<std::shared_ptr<NetworkObject> > > _units;
    cocos2d::Node* _layer;
    //std::vector<Card> _availableCards;
};

#endif // WORLD_H_INCLUDED
