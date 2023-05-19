#ifndef Game_h
#define Game_h

#include "ofMain.h"
#include "StateMachine.h"
#include "GameObjectContainer.h"
#include "GameObjectGenerator.h"
#include <vector>
class Player;

enum Sounds {BUTTON_SFX, SCREAM_SFX, COIN_SFX, EXPLOSION_SFX, TURBO_SFX, OIL_SFX, PIT_SFX, BOING_SFX, GOAL_SFX, MAX_SOUND};

const string SoundsPaths[MAX_SOUND] = {
    {"../../src/resources/sounds/buttonSound.wav"},
    {"../../src/resources/sounds/aaa.wav"},
    {"../../src/resources/sounds/coinSound.wav"},
    {"../../src/resources/sounds/bombSound.wav"},
    {"../../src/resources/sounds/drsSound.wav"},
    {"../../src/resources/sounds/oilSound.wav"},
    {"../../src/resources/sounds/pitSound.wav"},
    {"../../src/resources/sounds/boingSound.wav"},
    {"../../src/resources/sounds/goalSound.wav"}
};

enum Songs {MENU_THEME, RESULT_THEME, MAX_MUSIC};

const string SongsPath[MAX_MUSIC] = {
    {"../../src/resources/music/menuTheme.wav"},
    {"../../src/resources/music/resultTheme.mp3"}
};

class Game : public StateMachine{
    ofEasyCam cam;
    Player *player;
    GameObjectContainer *gameObjects = nullptr;
    GameObjectGenerator *generator  = nullptr;
    bool bDebug;
    bool bPlayerFinish;
    float initTime;
    ofSoundPlayer* sounds[MAX_SOUND];
    ofSoundPlayer* music[MAX_MUSIC];

    void loadSounds();
    void loadMusic();

public:
    int ROAD_LENGTH;
    int ROAD_WIDTH;
    
    Game();
    virtual ~Game();
    void init();
    void update();
    void draw();
    void finishGame();
    void toggleDebug();
    bool isDebug();
    bool isFinished();
    void setFinished(bool v);
    
    Player *getPlayer();
    vector<GameObject *> getCollisions(GameObject *gameObject);
    void addGameObject(GameObject *gameobject);
    
    float getEllapsedTime();
    void playSound(Sounds s);
    void playMusic(Songs s);
    void stopMusic(Songs s);
};
#endif
