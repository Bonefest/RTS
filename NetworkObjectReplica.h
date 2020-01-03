#ifndef NETWORKOBJECTREPLICA_H_INCLUDED
#define NETWORKOBJECTREPLICA_H_INCLUDED

#include <string>
#include "../RakNet/Source/ReplicaManager3.h"

#include "NetworkObject.h"

class NetworkObject;

class NetworkObjectReplica: public RakNet::Replica3 {
public:
    virtual RakNet::RakString getName() const;
    virtual void WriteAllocationID(RakNet::Connection_RM3* destConnection,RakNet::BitStream* allocationBitStream) const;

    virtual void DeallocReplica(RakNet::Connection_RM3* sourceConnection);

    virtual void SerializeConstruction(RakNet::BitStream* stream,RakNet::Connection_RM3* connection);
    virtual bool DeserializeConstruction(RakNet::BitStream* stream,RakNet::Connection_RM3* connection);

    virtual void SerializeDestruction(RakNet::BitStream* stream,RakNet::Connection_RM3* connection);
    virtual bool DeserializeDestruction(RakNet::BitStream* stream,RakNet::Connection_RM3* connection);

    virtual void OnUserReplicaPreSerializeTick();
    virtual RakNet::RM3SerializationResult Serialize(RakNet::SerializeParameters* parameters);
    virtual void Deserialize(RakNet::DeserializeParameters* parameters);

    virtual void OnPoppedConnection(RakNet::Connection_RM3* connection);

    virtual RakNet::RM3ConstructionState QueryConstruction(RakNet::Connection_RM3* connection,RakNet::ReplicaManager3* manager) { return QueryConstruction_ClientConstruction(connection,false); }
    virtual bool QueryRemoteConstruction(RakNet::Connection_RM3* connection) { return QueryRemoteConstruction_ClientConstruction(connection,false); }
    virtual RakNet::RM3QuerySerializationResult QuerySerialization(RakNet::Connection_RM3* connection) { return QuerySerialization_ClientSerializable(connection,false); }
    virtual RakNet::RM3ActionOnPopConnection QueryActionOnPopConnection(RakNet::Connection_RM3* connection) const { return QueryActionOnPopConnection_Client(connection); }
protected:
    RakNet::VariableDeltaSerializer _serializer;

private:
    NetworkObject* _replicaOwner;
};

#endif // NETWORKOBJECTREPLICA_H_INCLUDED
