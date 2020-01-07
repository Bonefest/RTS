#ifndef GAMELAYER_H_INCLUDED
#define GAMELAYER_H_INCLUDED

#include "ui/UIScrollView.h"
#include "GridDrawer.h"
/*
    Прим. Я использую ScrollView т.к, он наследует Layer, который позволяет
    создать что-то в духе вьюпорта.
*/

class GameLayer: public cocos2d::ui::ScrollView {
public:
    CREATE_FUNC(GameLayer);
    static GameLayer* createGameLayer();
    bool init();

    void draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& mat4, uint32_t flag);
private:
    GridDrawer gridDrawer;
};


#endif // GAMELAYER_H_INCLUDED
