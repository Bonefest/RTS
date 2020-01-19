#ifndef BUILDING_H_INCLUDED
#define BUILDING_H_INCLUDED

#include "NetworkObject.h"

class Building: public NetworkObject {
public:
    ~Building() { };

    void onSerialize(RakNet::VariableDeltaSerializer* serializer) { }
    void onDeserialize(RakNet::VariableDeltaSerializer* serializer) { }

    void onTouchBegan(cocos2d::Ref* ref) { }
    void onTouchEnded(cocos2d::Ref* ref);
};


#endif // BUILDING_H_INCLUDED
