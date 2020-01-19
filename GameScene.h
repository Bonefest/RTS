#ifndef GAMESCENE_H_INCLUDED
#define GAMESCENE_H_INCLUDED

#include "cocos2d.h"
#include "GridDrawer.h"
#include "GameLayer.h"
#include "BackgroundTerrainGenerator.h"
#include "ui/UIButton.h"

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

    bool onGridButtonTouched(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
private:
    bool initGameLayer();
    bool initTerrainGenerator();
    bool initMenuButtons();

    GameLayer* _gameLayer;
    Node* _uiLayer;
    BackgroundTerrainGenerator _terrainGenerator;
    cocos2d::ui::Button* _enableGridButton;
    cocos2d::ui::Button* _disableGridButton;
    cocos2d::DrawNode* _debugDrawer;

    cocos2d::Size visibleSize;
};

#endif // GAMESCENE_H_INCLUDED
