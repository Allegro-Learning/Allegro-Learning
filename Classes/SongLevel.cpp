#include "SongLevel.h"
#include "MidiFile.h" // https://midifile.sapp.org/
#include "GameSettings.h"
#include "MidiReader.h"
#include "MidiSequencer.h"
#include "MidiStream.h"

USING_NS_CC;

cocos2d::Sprite* makeSprite(float start, int pitch, float duration) {
    Sprite* sprite = Sprite::create("note.png");
    sprite->setCenterRectNormalized(Rect(0.25f, 0.25f, 0.75f, 0.75f));
    sprite->setAnchorPoint(Vec2(0, 0));
    float width = 1.0f / (GameSettings::getInstance()->getOctaveRange() * 8);
    float height = duration * GameSettings::getInstance()->getNoteTime(); // TODO
    sprite->setContentSize(Size(width, height));
    return sprite;
}

struct membuf : std::streambuf
{
    membuf(unsigned char* begin, unsigned char* end) {
        this->setg(reinterpret_cast<char *>(begin), reinterpret_cast<char *>(begin), reinterpret_cast<char *>(end));
    }
    membuf(char* begin, char* end) {
        this->setg(begin, begin, end);
    }
};

SongLevel::SongLevel(const char* song_name, int difficulty) {
    this->inst_midi = new MidiReader();
    this->song_midi = new MidiSequencer();
    this->song_name = song_name;
    this->layer = Layer::create();
    FileUtils* fm = FileUtils::getInstance();
    std::string midi_path;
    for (std::string& fname : fm->listFiles("songs/" + std::string(song_name))) {
        if (fm->getFileExtension(fname) == ".mid") {
            midi_path = fm->fullPathForFilename("songs/" + std::string(song_name) + "/" + fname);
        }
    }
    Data midi_data = fm->getDataFromFile(midi_path);
    char* midi_bytes = reinterpret_cast<char *>(midi_data.getBytes());
    ssize_t midi_size = midi_data.getSize();
    // log("MIDI DATA %s", fm->getDataFromFile(midi_path).getBytes());
    membuf sbuf(midi_bytes, midi_bytes + sizeof(char) * midi_size);
    std::istream in(&sbuf);
    // smf::Binasc().outputStyleAscii(std::cout, in);
    smf::MidiFile midi_parser(in);
    if (!midi_parser.status()) {
        log("Bad midi file");
        return;
    }
    midi_parser.linkNotePairs();
    midi_parser.doTimeAnalysis();
    // DEBUG
    std::ostringstream os;
    os << midi_parser;
    std::string s=os.str();
    log("%s", s.c_str());
    // END DEBUG

    int i = difficulty;
    for (int j=0; j<midi_parser[i].getEventCount(); j++) {
        if (midi_parser[i][j].isNoteOn()) {
            double duration = midi_parser[i][j].getDurationInSeconds();
            double start = midi_parser[i][j].seconds;
            int pitch = midi_parser[i][j].getKeyNumber();
            Sprite* sprite = makeSprite(start, pitch, duration);
            layer->addChild(sprite);
            log("NOTE ON %i, %f, %f", pitch, start, duration);
            // this->notes.pushBack(sprite);
        } else if (midi_parser[i][j].isNoteOff()) {
            log("NOTE OFF %i, %f", midi_parser[i][j].getKeyNumber(), midi_parser[i][j].seconds);
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

cocos2d::Layer* SongLevel::getLayer() {
    return this->layer;
}