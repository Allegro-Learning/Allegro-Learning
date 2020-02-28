#include "SongLevel.h"
// #include "SimpleAudioEngine.h"

USING_NS_CC;

bool SongLevel::init(MidiReader& instrument_midi, MidiSequencer& song_midi, char* song_name) {
    this->inst_midi = &instrument_midi;
    this->song_midi = &song_midi;
    this->song_name = song_name;
}

void SongLevel::start() {
    this->song_audio_ID = AudioEngine::play2d(std::string(this->song_name));
}

void SongLevel::pause() {
    AudioEngine::pause(this->song_audio_ID);
}

bool SongLevel::completed() {
    int id = this->song_audio_ID;
    return AudioEngine::getCurrentTime(id) == AudioEngine::getDuration(id);
}

void SongLevel::update(float time) {
    int id = this->song_audio_ID;
    float time = AudioEngine::getCurrentTime(id);
}

void SongLevel::draw(float time) {
    
}
