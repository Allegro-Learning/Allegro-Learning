#include "SongLevel.h"
#include "MidiFile.h" // https://midifile.sapp.org/
#include "GameSettings.h"

USING_NS_CC;

ui::Scale9Sprite* makeSprite(float start, int pitch, float duration) {
    ui::Scale9Sprite* sprite = ui::Scale9Sprite::create("note.png");
    sprite->setAnchorPoint(Vec2(0, 0));
    float width = 1.0f / (GAME_SETTINGS.OCTAVE_RANGE * 8);
    float height = duration * GAME_SETTINGS.NOTE_SPEED // TODO
    sprite->setContentSize(Size(width, height));
    return sprite;
}

bool SongLevel::init(MidiReader& instrument_midi, MidiSequencer& song_midi, char* song_name, int difficulty) {
    this->inst_midi = &instrument_midi;
    this->song_midi = &song_midi;
    this->song_name = song_name;
    auto midi_data = FileUtils::getInstance()->getStringFromFile("songs/" + std::string(song_name) + ".mid");
    smf::MidiFile midi_parser;
    midi_parser.read(midi_data);
    midi_parser.absoluteTicks();
    midi_parser.doTimeAnalysis();
    midi_parser.linkNotePairs();

    smf::MidiEventList track = midi_parser[difficulty];
    int size = track.getSize();
    for (int j=1; j<size; j++) {
        smf::MidiEvent event = track[j];
        if (event.isNoteOn()) {
            double duration = event.getDurationInSeconds();
            double start = event.seconds;
            int pitch = event.getKeyNumber();
            
            this->notes.pushBack(makeSprite(start, pitch, duration));
        }
    }
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

void SongLevel::update(float render_time) {
    int id = this->song_audio_ID;
    float time = AudioEngine::getCurrentTime(id);
}

void SongLevel::draw(float time) {
    
}
