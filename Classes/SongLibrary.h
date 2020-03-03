
#ifndef __SONG_LIBRARY_H__
#define __SONG_LIBRARY_H__

#include "cocos2d.h"
#include "SongLevel.h"
#include <vector>

class SongLibrary {
private:
    std::vector<char*> songs;
public:
    virtual bool init();

    cocos2d::Vector<SongLevel> getSongNames();

    SongLevel loadSong();
};

#endif