#include "World.h"
#include "ConfigLoader.h"
#include "GameClassesManager.h"

void World::setGameLayer(cocos2d::Node* layer) {
    _layer = layer;
}

bool World::initWorld() {
    cocos2d::Size cellSize = ConfigLoader::getInstance()->getSize("Grid_size");
    for(int y = 0; y < ConfigLoader::getInstance()->getInteger("Grid_vnumber"); ++y) {
        _buildings.push_back(std::vector<std::shared_ptr<NetworkObject>>());
        for(int x = 0; x < ConfigLoader::getInstance()->getInteger("Grid_hnumber"); ++x){
            std::shared_ptr<NetworkObject> building = GameClassesManager::getInstance()->getBuilding("Cell");
            building->getButton()->setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);
            building->getButton()->setPosition(cocos2d::Vec2(x * cellSize.width + 64, y * cellSize.height + 64));
            building->getButton()->setSizeType(cocos2d::ui::Button::SizeType::ABSOLUTE);
            building->getButton()->setContentSize(cellSize);
            building->getButton()->setScale9Enabled(true);
            building->getButton()->setTitleText("C");
            building->addToScene(_layer);
            _buildings[y].push_back(building);

        }
    }
}
