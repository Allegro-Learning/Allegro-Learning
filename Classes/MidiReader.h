
#ifndef __MIDIREADER_H__
#define __MIDIREADER_H__

#include <AMidi.h>
#include "cocos2d.h"
#include "MidiStream.h"

class MidiReader : public MidiStream {
private:
    
public:
    virtual bool init();
}

#endif