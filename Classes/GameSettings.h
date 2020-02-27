#ifndef __GAME_SETTINGS_SCENE_H__
#define __GAME_SETTINGS_SCENE_H__

typedef struct GameSettings {
public:
    float DELAY;
    float NOTE_SPEED;
} GameSettings;

extern GameSettings GAME_SETTINGS;

#endif