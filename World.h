#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "NetworkObject.h"

#include <vector>
#include <memory>

class World {
public:
    bool initWorld();

private:
    std::vector<std::vector<std::shared_ptr<NetworkObject> > > _buildings;
    std::vector<std::vector<std::shared_ptr<NetworkObject> > > _units;

};

#endif // WORLD_H_INCLUDED
