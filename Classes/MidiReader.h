
#ifndef __MIDIREADER_H__
#define __MIDIREADER_H__

#include "cocos2d.h"
#include "AudioEngine.h"
#include "MidiStream.h"

class MidiReader : public MidiStream {
private:
    
public:
    MidiReader();
    std::vector<char*> messages();
};

#endif