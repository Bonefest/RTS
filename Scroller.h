#ifndef SCROLLER_H_INCLUDED
#define SCROLLER_H_INCLUDED

#include "cocos2d.h"

class Scroller : public cocos2d::Node {
public:
    CREATE_FUNC(Scroller);
    static Scroller* createScroller();

    void addChild(cocos2d::Node* child);
    cocos2d::Node.draw
private:

};

#endif // SCROLLER_H_INCLUDED
