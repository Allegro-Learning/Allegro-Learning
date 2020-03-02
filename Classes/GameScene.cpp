#include "GameScene.h"

USING_NS_CC;

Scene* Game::createScene() {
    return Game::create();
}

bool Game::init() {
    if ( !Scene::init() || !Layer::init())
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Sprite test;

    auto background = DrawNode::create();
    background->drawSolidRect(origin, visibleSize, Color4F(0.6,0.6,0.6,1.0));
    this->addChild(background);
    
    return true;
}

bool Game::onTouchBegan(Touch *touch, Event *event) {

}

bool Game::onTouchEnd(Touch *touch, Event *event) {

}


Game::CREATE_FUNC(Game) {
    
}
