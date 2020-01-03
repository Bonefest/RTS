#ifndef BUILDING_H_INCLUDED
#define BUILDING_H_INCLUDED

#include "NetworkObject.h"

class Building: public NetworkObject {
public:

    //std::shared_ptr<Building> clone();

    void onSerialize(RakNet::VariableDeltaSerializer* serializer) { }
    void onDeserialize(RakNet::VariableDeltaSerializer* serializer) { }

};


#endif // BUILDING_H_INCLUDED
