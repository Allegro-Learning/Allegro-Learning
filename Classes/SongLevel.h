
#ifndef __SONG_H__
#define __SONG_H__

#include "cocos2d.h"
#include "MidiReader.h"
#include "MidiSequencer.h"
#include "MidiStream.h"

cocos2d::ui::Scale9Sprite* makeSprite(float start, int pitch, float duration);

class SongLevel {
public:
    struct Stats {
        int total_notes;
        int perfect;
        int good;
        int bad;
        int missed;
    };
    struct Note {
        int pitch;
        float start;
        float duration;
    };
private:
    MidiStream* inst_midi;
    MidiStream* song_midi;
    char* song_name;
    int song_audio_ID;
    cocos2d::Vector<cocos2d::Sprite> notes;
    // bool ended = false;
public:
    Stats stats;
    virtual bool init(MidiReader& instrument_midi, MidiSequencer& song_midi, char* song_name, int difficulty);
    void start();
    void pause();
    bool completed();
    void update(float render_time);
    void draw(float time);
};

#endif