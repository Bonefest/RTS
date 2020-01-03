#ifndef GAMESCENE_H_INCLUDED
#define GAMESCENE_H_INCLUDED

#include "cocos2d.h"
#include "GridDrawer.h"

class GameScene: public cocos2d::Scene {
public:
    CREATE_FUNC(GameScene);
    static GameScene* createScene();
    bool init();
    void render(cocos2d::Renderer* renderer, const cocos2d::Mat4& eyeTransform, const cocos2d::Mat4* eyeProjection);
    //void setRakNetPeer(RakNet::RakPeerInterface* peer);
    void update(float delta);
private:
    GridDrawer gridDrawer;
};

#endif // GAMESCENE_H_INCLUDED
