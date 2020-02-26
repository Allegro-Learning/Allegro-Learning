
#ifndef __MIDISTREAM_H__
#define __MIDISTREAM_H__

#include "cocos2d.h"

class MidiStream {
private:
    
public:
    virtual bool init();
    virtual void update(int tick);
    virtual Vector<char*> messages() = 0;
}

#endif