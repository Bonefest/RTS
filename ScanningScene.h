#ifndef SCANNIGSCENE_H_INCLUDED
#define SCANNIGSCENE_H_INCLUDED

#include "cocos2d.h"
#include "MessageQueue.h"
#include "ui/UIButton.h"
#include "ui/UIText.h"
#include "ui/UITextField.h"
#include "../RakNet/Source/RakPeerInterface.h"

class ScanningScene: public cocos2d::Scene {
public:
    CREATE_FUNC(ScanningScene);
    static ScanningScene* createScene();
    bool init();

    void onCreateServerTouched(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);
    void onShowAvailableServersTouched(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);

    void update(float delta);
private:
    bool initRakNet();
    bool initUI();

    void processPackets();
    void broadcastLAN();

    void onServerFound(RakNet::Packet* packet);

    cocos2d::ui::TextField* portField;
    cocos2d::ui::Button* createServerButton;
    cocos2d::ui::Button* showAvailableServersButton;
    cocos2d::ui::Text* messagesText;

    MessageQueue messageQueue;
    float messageTimer;

    RakNet::RakPeerInterface* peer;

    cocos2d::Size visibleSize;
};


#endif // SCANNIGSCENE_H_INCLUDED
