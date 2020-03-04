#ifndef __GAME_SETTINGS_SCENE_H__
#define __GAME_SETTINGS_SCENE_H__

#include "cocos2d.h"

class GameSettings : public cocos2d::Scene
{
public:
<<<<<<< Updated upstream
    float DELAY = 0.0f;
    float NOTE_SPEED = 1.0f;
    int OCTAVE_RANGE = 1;
} GameSettings;
=======
    static cocos2d::Scene* createScene();

    virtual bool init();
>>>>>>> Stashed changes

    CREATE_FUNC(GameSettings);
};

#endif