#ifndef __GAME_SETTINGS_SCENE_H__
#define __GAME_SETTINGS_SCENE_H__

#include "cocos2d.h"

class GameSettings : public cocos2d::Scene
{
public:
    float DELAY = 0.0f;
    float NOTE_SPEED = 1.0f;
    int OCTAVE_RANGE = 1;

    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(GameSettings);
};
#endif