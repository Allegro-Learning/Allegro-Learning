#include "GameSettings.h"

USING_NS_CC;

GameSettings* GameSettings::instance = nullptr;

GameSettings::GameSettings() {
    
}

GameSettings::~GameSettings() {
    
}

static GameSettings* GameSettings::getInstance() {
    if (!instance) {
        instance = new GameSettings();
    }
    return instance;
}

static void GameSettings::destroyInstance() {
    CC_SAFE_DELETE(instance);
}

float GameSettings::getDelay() {
    
}

void GameSettings::setDelay(float delay) {
    
}

float GameSettings::getNoteTime() {
    
}

void GameSettings::setNoteTime(float delay) {
    
}

int GameSettings::getOctaveRange() {
    
}

void GameSettings::setOctaveRange(int octaves) {
    
}
