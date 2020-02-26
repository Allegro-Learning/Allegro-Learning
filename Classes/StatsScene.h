#ifndef __STATS_SCENE_H__
#define __STATS_SCENE_H__

#include "cocos2d.h"

class Stats : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(Stats);
};

#endif // __STATS_SCENE_H__
