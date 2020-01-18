#ifndef GAMESCENE_H_INCLUDED
#define GAMESCENE_H_INCLUDED

#include "cocos2d.h"
#include "GridDrawer.h"
#include "GameLayer.h"

class GameScene: public cocos2d::Scene {
public:
    CREATE_FUNC(GameScene);
    static GameScene* createScene();
    bool init();
    //void setRakNetPeer(RakNet::RakPeerInterface* peer);
    void update(float delta);

    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
private:
    bool initGameLayer();

    GameLayer* _gameLayer;
    Node* _uiLayer;
    cocos2d::DrawNode* _debugDrawer;

    cocos2d::Size visibleSize;
    //BackgroundTerrainGenerator - генерирует тайлы для заднего фона игры(не нужно реплицировать)
};

#endif // GAMESCENE_H_INCLUDED
