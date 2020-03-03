#ifndef __GAME_SETTINGS_SCENE_H__
#define __GAME_SETTINGS_SCENE_H__

typedef struct GameSettings {
public:
    // Delay in seconds for syncing hardware input to the display.  
    float DELAY = 0.0f;
    // Time in seconds it takes for a note to enter the view and reach the delimeter. 
    float NOTE_TIME = 1.0f;
    // Octave range of keyboard, 8 full steps and 12 notes per octave.
    int OCTAVE_RANGE = 1; 
} GameSettings;

extern GameSettings GAME_SETTINGS;

#endif