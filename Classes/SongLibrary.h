
#ifndef __SONG_LIBRARY_H__
#define __SONG_LIBRARY_H__

#include "cocos2d.h"
#include "SongLevel.h"

class SongLibrary {
private:
    Vector<char*> songs;
public:
    virtual bool init();

    Vector<SongLevel> getSongNames();

    SongLevel loadSong();
}

#endif