#include "GameLayer.h"
#include "GameClassesManager.h"
#include "MediaManager.h"
#include "ConfigLoader.h"
#include "MessageBox.h"
#include "Globals.h"

GameLayer* GameLayer::createGameLayer() {
    return GameLayer::create();
}

bool GameLayer::init() {
    if(!cocos2d::ui::ScrollView::init()) return false;

    setDirection(Direction::BOTH);
    setScrollBarEnabled(false);

    if(!gridDrawer.init(this, cocos2d::Color4F::WHITE,
                        cocos2d::Vec2(64, 64),
                        ConfigLoader::getInstance()->getSize("Grid_size"),
                        ConfigLoader::getInstance()->getInteger("Grid_hnumber"),
                        ConfigLoader::getInstance()->getInteger("Grid_vnumber"))) {
        return false;
    }

    MessageBox* messageBox = MessageBox::createBox("Castle");
    cocos2d::Label* desc = cocos2d::Label::createWithTTF("glsdlgsdlgl gsldgls glglsdlglsdg l.",
                                                         "fonts/arial.ttf", 26);
    messageBox->addElement(desc);
    messageBox->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);
    messageBox->setPosition(cocos2d::Director::getInstance()->getVisibleSize() * 0.5);

    addChild(messageBox);

    auto test = GameClassesManager::getInstance()->getBuilding("Castle");
    test->setPosition(cocos2d::Vec2(500, 500));
    test->addToScene(this);

    //cocos2d::Director::getInstance()->getRunningScene()->getChildByTag(TAGS::UI_LAYER_TAG)->addChild(messageBox);
    return true;
}

void GameLayer::draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& mat4, uint32_t flag) {
    cocos2d::ui::ScrollView::draw(renderer, mat4, flag);
    gridDrawer.draw();
}
