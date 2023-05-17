
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

GameObjectGenerator::GameObjectGenerator(Game *game): game(game){}

void GameObjectGenerator::generateWorld(){
    int W = game->ROAD_WIDTH;
    int L = game->ROAD_LENGTH;
    
    glm::vec3 roadPos(0, -50.1, L/2 - 1000);
    auto road = new Road(game, roadPos, glm::vec3(W, 0, L));
    
    game->addGameObject(road);
//
    int wallSize = 100;

    ofImage circuito;
    circuito.load("gp.png");

    int w = circuito.getWidth()/20;
    int h = circuito.getHeight()/20;
    circuito.resize(w, h);


    //// Pared derecha
    //auto wall_r = new Wall(game,
    //                glm::vec3(-W/2, roadPos.y, roadPos.z),
    //                       glm::vec3(wallSize, wallSize, L));
    //game->addGameObject(wall_r);

    //wall_r = new Wall(game,
    //                glm::vec3(-W/2, roadPos.y, roadPos.z - L * 0.8),
    //                       glm::vec3(wallSize, wallSize, L));
    //game->addGameObject(wall_r);

    //// Pared izquierda
    //auto wall_l = new Wall(game,
    //                glm::vec3(W/2, roadPos.y, roadPos.z),
    //                       glm::vec3(wallSize, wallSize, L));
    //game->addGameObject(wall_l);

    //wall_l = new Wall(game,
    //                glm::vec3(W/2, roadPos.y, roadPos.z - L * 0.8),
    //                       glm::vec3(wallSize, wallSize, L));
    //game->addGameObject(wall_l);

    for(int x = 0; x < w; x++){
        for(int y = 0; y < h; y++){
            if(circuito.getColor(x, y).r < 100){

                auto wall = new Wall(game,
                                glm::vec3(x*wallSize - 2000, roadPos.y, y*wallSize - 150),
                                glm::vec3(wallSize*0.99));
                game->addGameObject(wall);
            }
        }
    }

    // Orden: MONEDAS - OBSTACULOS - TIERRA - BOMBARDERO - DRS - ARCO - PEATON - BARRERA - GRUA - ACEITE - POZO - PILOTES - AGUA

    //// Moneda
    //for (int i = 0; i < 3; i++) {
    //    int posx = ofRandom(wall_l->transform.getX(), wall_r->transform.getX());
    //    auto coin = new Coin(game,
    //        glm::vec3(posx, -25, i * 500), glm::vec3(50));

    //    game->addGameObject(coin);
    //}

    //// Obstaculos
    //for (int i = 0; i < 3; i++) {
    //    int posx = ofRandom(wall_l->transform.getX(), wall_r->transform.getX());
    //    auto obs = new Obstacle(game,
    //        glm::vec3(posx, 75, 700 + i * 500), glm::vec3(250,250,250));
    //    game->addGameObject(obs);
    //}

    //// Tierra
    //auto dirt = new Dirt(game, glm::vec3(posx, roadPos.y + 5, 6000), glm::vec3(W, 1000, 1000));
    //game->addGameObject(dirt);

    //// Bombardero
    //auto bomber = new Bomber(game, glm::vec3(posx - 750, 1000, 4000), glm::vec3(250, 1200, 250), 1500);
    //game->addGameObject(bomber);
    
    //// DRS
    //auto drs = new DRS(game, glm::vec3(posx - 750, 1000, 4000), glm::vec3(50), 1500);
    //game->addGameObject(drs);

    // ARCO
    GameObject* arc = new Arco(game,
        glm::vec3(W / 2 - 300, 75, 500), glm::vec3(250, 250, 1));
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

    // Mancha de aceite
    auto op = new OilPuddle(game, glm::vec3(-750, roadPos.y + 5, 5600), glm::vec3(400, 600, 400));
    game->addGameObject(op);

    // Pozo
    auto pit = new Pit(game, glm::vec3(200, -100, 5600), glm::vec3(500, 250, 250));
    game->addGameObject(pit);

    // Meta
    auto goal = new Goal(game,
                    glm::vec3(0, roadPos.y, roadPos.z + L/2 - 1000),
                           glm::vec3(W, 100, 100));
    goal->isFixed = true;
    game->addGameObject(goal);
}
