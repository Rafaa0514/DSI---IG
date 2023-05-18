#include "GameObjectGenerator.h"
#include "Game.h"
#include "Road.h"
#include "Wall.h"
#include "Goal.h"
#include "Coin.h"
#include "Pedestrian.h"
#include "PedestrianGenerator.h"
#include "Obstacle.h"
#include "Barrier.h"
#include "OilPuddle.h"
#include "Dirt.h"
#include "Crane.h"
#include "Pit.h"
#include "Bomber.h"
#include "Arc.h"
#include "DRS.h"
#include "Bouncers.h"
#include "Water.h"

GameObjectGenerator::GameObjectGenerator(Game *game): game(game){}

void GameObjectGenerator::generateWorld(){
    int W = game->ROAD_WIDTH;
    int L = game->ROAD_LENGTH;
    int wallSize = 100;
    
    // CARRETERA
    glm::vec3 roadPos(0, -50.1, L/2 - 1000);
    auto road = new Road(game, roadPos, glm::vec3(W, 0, L));
    game->addGameObject(road);

    // CIRCUITO
    ofImage circuito;
    circuito.load("../../src/resources/textures/gp.png");

    int w = circuito.getWidth()/20;
    int h = circuito.getHeight()/20;
    circuito.resize(w, h);

    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            if (circuito.getColor(x, y).r < 100) {

                auto wall = new Wall(game,
                    glm::vec3(x * wallSize - 2000, roadPos.y, y * wallSize - 150),
                    glm::vec3(wallSize * 0.99));
                game->addGameObject(wall);
            }
        }
    }

    // MONEDA
    glm::vec3 playerPos = game->getPlayer()->transform.getPosition();
    for (int i = 0; i < 3; i++) {
        int posx = ofRandom(playerPos.x - 200, playerPos.x + 200);
        auto coin = new Coin(game,
            glm::vec3(posx, -25, playerPos.z + (i + 1) * 500), glm::vec3(50));

        game->addGameObject(coin);
    }

    // OBSTACULOS
    for (int i = 0; i < 3; i++) {
        int posx = ofRandom(playerPos.x - 300, playerPos.x + 300);
        auto obs = new Obstacle(game,
            glm::vec3(posx, 75, playerPos.z + 700 + i * 500), glm::vec3(250,250,250));
        game->addGameObject(obs);
    }

    // TIERRA
    auto dirt = new Dirt(game, glm::vec3(playerPos.x, roadPos.y + 5, 2400), glm::vec3(W, 1000, 1000));
    game->addGameObject(dirt);

    // BOMBARDERO
    auto bomber = new Bomber(game, glm::vec3(playerPos.x - 750, 1000, 2800), glm::vec3(250, 1200, 250), 1500);
    game->addGameObject(bomber);
    
    // DRS
    for (int i = 0; i < 3; i++) {
        auto drs = new DRS(game, glm::vec3(-950 - i * 200, 25, 2900), glm::vec3(50, 50, 50));
        game->addGameObject(drs);
    }

    // ARCO
    GameObject* arc = new Arco(game,
        glm::vec3(-1250, 75, 3500), glm::vec3(250, 250, 1));
    game->addGameObject(arc);

    // PEATON
    auto pedestrian = new PedestrianGenerator(game,
        glm::vec3(-825, -25, 4300), glm::vec3(50, 150, 50));

    game->addGameObject(pedestrian);

    // BARRERA
    int posx = -1200;
    auto bar = new Barrier(game,
        glm::vec3(posx, 500, 4750), glm::vec3(700, 250, 100), 0);
    game->addGameObject(bar);

    // GRUA
    auto crane = new Crane(game,
        glm::vec3(game->getPlayer()->transform.getPosition().x, 150, 4000), glm::vec3(300, 600, 300));
    game->addGameObject(crane);

    // MANCHA DE ACEITE
    auto op = new OilPuddle(game, glm::vec3(-750, roadPos.y + 5, 5600), glm::vec3(400, 100, 600));
    game->addGameObject(op);

    // POZO
    auto pit = new Pit(game, glm::vec3(200, -100, 5600), glm::vec3(500, 250, 250));
    game->addGameObject(pit);

    // REBOTADORES
    for (int i = 0; i < 3; i++) {
        int posx = ofRandom(900, 1200);
        auto bouncer = new Bouncers(game,
            glm::vec3(posx, -25, 6000 + (i + 1) * 500), glm::vec3(50));
        game->addGameObject(bouncer);
    }

    // AGUA
    auto water = new Water(game, 
        glm::vec3 (1100, roadPos.y + 5, 6500), glm::vec3(1000,100,1200));
    game->addGameObject(water);

    // META
    auto goal = new Goal(game,
                    glm::vec3(0, roadPos.y, roadPos.z + L/2 - 1000),
                           glm::vec3(W, 100, 100));
    goal->isFixed = true;
    game->addGameObject(goal);
}
