#include "GameLayer.h"
#include "GameClassesManager.h"
#include "MediaManager.h"
#include "MessageBox.h"

GameLayer* GameLayer::createGameLayer() {
    return GameLayer::create();
}

bool GameLayer::init() {
    if(!cocos2d::ui::ScrollView::init()) return false;

    setDirection(Direction::BOTH);
    setScrollBarEnabled(false);

    if(!gridDrawer.init(this, cocos2d::Color4F::WHITE, cocos2d::Vec2(64, 64), cocos2d::Size(32, 32), 24, 24))
        return false;

    MessageBox* messageBox = MessageBox::createBox("Castle", cocos2d::Size(200, 300));
    cocos2d::Label* desc = cocos2d::Label::createWithTTF("glsdlgsdlgl gsldgls glglsdlglsdg l.",
                                                         "fonts/arial.ttf", 26);
    messageBox->addElement(desc);
    messageBox->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);
    messageBox->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
    messageBox->setBackGroundColorOpacity(192);
    messageBox->setBackGroundColor(cocos2d::Color3B(192, 113, 0.0f));
    messageBox->setPosition(cocos2d::Vec2(300, 200));

    addChild(messageBox);
    return true;
}

void GameLayer::draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& mat4, uint32_t flag) {
    cocos2d::ui::ScrollView::draw(renderer, mat4, flag);
    gridDrawer.draw();
}
