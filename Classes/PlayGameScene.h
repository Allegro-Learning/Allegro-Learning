#ifndef __PLAY_GAME_SCENE_H__
#define __PLAY_GAME_SCENE_H__

#include "cocos2d.h"

class PlayGame : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    //void songSelectCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(PlayGame);
};

#endif // __PLAY_GAME_SCENE_H__
