#ifndef SCANNIGSCENE_H_INCLUDED
#define SCANNIGSCENE_H_INCLUDED

#include "cocos2d.h"
#include "ui/UIButton.h"
#include "ui/UITextField.h"
#include "../RakNet/Source/RakPeerInterface.h"

class ScanningScene: public cocos2d::Scene {
public:
    CREATE_FUNC(ScanningScene);
    static ScanningScene* createScene();
    bool init();

private:
    bool initRakNet();
    bool initUI();

    cocos2d::ui::TextField* portField;
    cocos2d::ui::Button* createServerButton;
    cocos2d::ui::Button* showAvailableServersButton;

    RakNet::RakPeerInterface* peer;

    cocos2d::Size visibleSize;
};


#endif // SCANNIGSCENE_H_INCLUDED
