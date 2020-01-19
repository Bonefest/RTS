#include "GridDrawer.h"

GridDrawer::GridDrawer(): _drawer(nullptr),
                          _horizontalNumber(0),
                          _verticalNumber(0),
                          _visible(true) { }

bool GridDrawer::init(cocos2d::Node* scene) {
    _drawer = cocos2d::DrawNode::create();
    if(_drawer == nullptr) {
        return false;
    }
    scene->addChild(_drawer, 1);
    return true;
}

bool GridDrawer::init(cocos2d::Node* scene,
                      const cocos2d::Color4F& color,
                      const cocos2d::Vec2& origin,
                      const cocos2d::Size& cellSize,
                      int hnumber,
                      int vnumber) {
    if(!init(scene)) return false;

    setGridColor(color);
    setGridOrigin(origin);
    setCellSize(cellSize);
    setHorizontalCellNumber(hnumber);
    setVerticalCellNumber(vnumber);

    return true;
}

void GridDrawer::draw() {
    _drawer->clear();
    if(isVisible() && _drawer != nullptr &&
       getHorizontalCellNumber() > 0 && getVerticalCellNumber() > 0) {
            cocos2d::Vec2 origin = getGridOrigin();
            cocos2d::Size cellSize = getCellSize();

            for(int y = 0;y < getVerticalCellNumber() + 1; ++y) {
                _drawer->drawLine(origin + cocos2d::Vec2(0, y * cellSize.height),
                                  origin + cocos2d::Vec2(getHorizontalCellNumber() * cellSize.width,
                                                         y * cellSize.height),
                                  getGridColor());
            }

            for(int x = 0;x < getHorizontalCellNumber() + 1; ++x) {
                _drawer->drawLine(origin + cocos2d::Vec2(x * cellSize.width, 0),
                                  origin + cocos2d::Vec2(x * cellSize.width,
                                                         getVerticalCellNumber() * cellSize.height),
                                  getGridColor());
            }
    }
}

void GridDrawer::setGridColor(const cocos2d::Color4F& color) {
    _gridColor = color;
}

void GridDrawer::setGridOrigin(const cocos2d::Vec2& origin) {
    _origin = origin;
}

void GridDrawer::setCellSize(const cocos2d::Size& size) {
    _cellSize = size;
}

void GridDrawer::setCellNumber(int horizontal, int vertical) {
    setHorizontalCellNumber(horizontal);
    setVerticalCellNumber(vertical);
}

void GridDrawer::setHorizontalCellNumber(int number) {
    _horizontalNumber = number;
}

void GridDrawer::setVerticalCellNumber(int number) {
    _verticalNumber = number;
}

void GridDrawer::setVisible(bool visible) {
    _visible = visible;
}
