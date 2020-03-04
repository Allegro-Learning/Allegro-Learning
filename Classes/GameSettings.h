#ifndef __GAME_SETTINGS_SCENE_H__
#define __GAME_SETTINGS_SCENE_H__

class GameSettings {
private:
    static GameSettings* instance;
protected:
    GameSettings();
    virtual ~GameSettings();
public:
    static GameSettings* getInstance();
    static void destroyInstance();
    // Delay in seconds for syncing hardware input to the display.  
    float getDelay();
    void setDelay(float delay);
    // Time in seconds it takes for a note to enter the view and reach the delimeter. 
    float getNoteTime();
    void setNoteTime(float delay);
    // Octave range of keyboard, 8 full steps and 12 notes per octave.
    int getOctaveRange();
    void setOctaveRange(int octaves);
};

#endif