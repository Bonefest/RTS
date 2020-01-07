#ifndef GRIDDRAWER_H_INCLUDED
#define GRIDDRAWER_H_INCLUDED

#include "cocos2d.h"

class GridDrawer {
public:
    GridDrawer();

    bool init(cocos2d::Node* scene);
    bool init(cocos2d::Node* scene,
              const cocos2d::Color4F& color,
              const cocos2d::Vec2& origin,
              const cocos2d::Size& cellSize,
              int horizontalCellNumber,
              int verticalCellNumber);

    void draw();

    void setGridColor(const cocos2d::Color4F& color);
    inline const cocos2d::Color4F& getGridColor() const { return _gridColor; }

    void setGridOrigin(const cocos2d::Vec2& origin);
    inline const cocos2d::Vec2& getGridOrigin() const { return _origin; }

    void setCellSize(const cocos2d::Size& size);
    inline const cocos2d::Size& getCellSize() const { return _cellSize; }

    void setCellNumber(int horizontal, int vertical);

    void setHorizontalCellNumber(int number);
    inline int getHorizontalCellNumber() const { return _horizontalNumber; }

    void setVerticalCellNumber(int number);
    inline int getVerticalCellNumber() const { return _verticalNumber; }

    void setVisible(bool visible);
    inline bool isVisible() const { return _visible; }

private:

    cocos2d::DrawNode*  _drawer;
    cocos2d::Color4F _gridColor;

    cocos2d::Vec2 _origin;
    cocos2d::Size _cellSize;
    int _horizontalNumber;
    int _verticalNumber;
    bool _visible;

};

#endif // GRIDDRAWER_H_INCLUDED
