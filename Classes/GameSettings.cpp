#include "GameSettings.h"

USING_NS_CC;

const float DEFAULT_DELAY = 0.0f;
const float DEFAULT_NOTE_TIME = 1.0f;
const int DEFAULT_OCTAVES = 2;

GameSettings* GameSettings::instance = nullptr;

GameSettings::GameSettings() {
    
}

GameSettings::~GameSettings() {
    
}

GameSettings* GameSettings::getInstance() {
    if (!instance) {
        instance = new GameSettings();
    }
    return instance;
}

void GameSettings::destroyInstance() {
    CC_SAFE_DELETE(instance);
}

float GameSettings::getDelay() {
    return DEFAULT_DELAY;
}

void GameSettings::setDelay(float delay) {
    
}

float GameSettings::getNoteTime() {
    return DEFAULT_NOTE_TIME;
}

void GameSettings::setNoteTime(float delay) {
    
}

int GameSettings::getOctaveRange() {
    return DEFAULT_OCTAVES;
}

void GameSettings::setOctaveRange(int octaves) {
    
}
