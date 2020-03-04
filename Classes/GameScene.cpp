#include "GameScene.h"
#include "SongLevel.h"

USING_NS_CC;

Scene* Game::createScene() {
    return Game::create();
}

bool Game::init() {
    if ( !Scene::init())// || !Layer::init())
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    SongLevel* level = new SongLevel("Miku", 1);
    this->addChild(level->getLayer());

    auto background = DrawNode::create();
    background->drawSolidRect(origin, visibleSize, Color4F(0.1f,0.6f,1.0f,1.0f));
    this->addChild(background);
    
    return true;
}

bool Game::onTouchBegan(Touch *touch, Event *event) {
    return true;
}

bool Game::onTouchEnd(Touch *touch, Event *event) {
    return true;
}
