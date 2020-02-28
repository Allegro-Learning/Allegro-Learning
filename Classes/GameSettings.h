#ifndef __GAME_SETTINGS_SCENE_H__
#define __GAME_SETTINGS_SCENE_H__

typedef struct GameSettings {
public:
    float DELAY = 0.0f;
    float NOTE_SPEED = 1.0f;
    int OCTAVE_RANGE = 1;
} GameSettings;

extern GameSettings GAME_SETTINGS;

#endif