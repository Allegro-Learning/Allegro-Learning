
#ifndef __MIDISTREAM_H__
#define __MIDISTREAM_H__

#include "cocos2d.h"
#include <vector>

class MidiStream {
private:
    
public:
    virtual bool init();
    virtual void update(int tick);
    virtual std::vector<char*> messages() = 0;
};

#endif