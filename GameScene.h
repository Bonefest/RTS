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

    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
private:
    GridDrawer gridDrawer;
    //BackgroundTerrainGenerator - генерирует тайлы для заднего фона игры(не нужно реплицировать)
};

#endif // GAMESCENE_H_INCLUDED
