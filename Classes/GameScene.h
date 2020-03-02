#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class Game : public cocos2d::Scene 
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);

    bool onTouchEnd(cocos2d::Touch *touch, cocos2d::Event *event);
    
    CREATE_FUNC(Game);
};

#endif // __GAME_SCENE_H__
