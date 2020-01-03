#ifndef UNIT_H_INCLUDED
#define UNIT_H_INCLUDED

#include "NetworkObject.h"

class Unit: public NetworkObject {
public:
    void onSerialize(RakNet::VariableDeltaSerializer* serializer) { }
    void onDeserialize(RakNet::VariableDeltaSerializer* serializer) { }
};

#endif // UNIT_H_INCLUDED
