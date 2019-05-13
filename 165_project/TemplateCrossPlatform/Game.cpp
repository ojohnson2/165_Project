#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include "Game.h"
#include "App.h"
#include "Map.h"
#include "AppComponent.h"

Game::Game(){

	// Some cross-platform compatimility stuff

	const char* shroomFileName;
	const char* fireballFileName;

	// In Windows (Visual Studio only) the image files are found in the enclosing folder in relation to the project
	// In other environments the image files are in the same folder as the project

	#if defined WIN32
	shroomFileName = "../mushroom.png";
	fireballFileName = "../fireball.bmp";
	#else
	shroomFileName = "mushroom.png";
	fireballFileName = "fireball.bmp";
	#endif

    enemy = new Rect (-0.25, 0.5, 0.1, 0.1, 1.0, 1.0, 0.0);
    player = new Rect(-0.05, -0.8, 0.1, 0.1);
    explosion = new AnimatedRect(fireballFileName, 6, 6, 64, false, false, -0.25, 0.8, 0.5, 0.5);
    
    up = false;
    left = false;
    projectileVisible = true;
    mushroomVisible = true;
    theta = 0;
    deg = 0;
    hit = false;
    
    setRate(1);
    start();
    std:: cout << player->getX() << std::endl;
    std:: cout << player->getY() << std::endl;
}

void Game::action(){
    float mx = player->getX();
    float my = player->getY();
    
    if (up){
        while(player->getY() < my + (0.1667 * 2)){
            player->setY(player->getY() + 0.0001);
            std:: cout << player->getY() << std::endl;
        }
        up = false;
    } 
    else if(down) {
        while(player->getY() > my - (0.1667 * 2)){
            player->setY(player->getY() - 0.0001);
            std:: cout << player->getY() << std::endl;
        }
        down = false;
    } 
    else if(left){
        while(player->getX() > mx - (0.1667 * 2)){
            player->setX(player->getX() - 0.0001);
            std:: cout << player->getX() << std::endl;
        }
        left = false;
    }
    else if (right){
        while(player->getX() < mx + (0.1667 * 2)){
            player->setX(player->getX() + 0.0001);
            std:: cout << player->getX() << std::endl;
        }
        right = false;
    }

    if(mapPointer->getDoor()->contains(player->getX(), player->getY() )){
        player->setX(-0.05);
        player->setY(-0.8);
        mapPointer->draw();
    }

    if (enemy->contains(player->getX(), player->getY())){
        hit = true;
        projectileVisible = false;
        mushroomVisible = false;
        explosion->setX(enemy->getX());
        explosion->setY(enemy->getY());
        explosion->playOnce();
    }
    
    if (hit){
        explosion->setY(explosion->getY()-0.0001);
        if (explosion->getY() < 0){
            stop();
        }
    }
}

void Game::draw() const {
    
    if (projectileVisible){
        player->draw();
    }
    if (mushroomVisible){
        enemy->draw();
    }
    explosion->draw(0.1);
}

void Game::handleKeyDown(unsigned char key, float x, float y){
    if (key == 'p'){
        stop();
    }
    else if (key == 'r'){
        start();
    }
    else if (key == 'w'){
        up = true;
    }
    else if (key == 'a'){
        left = true;
    }
    else if (key == 's'){
        down = true;
    }   
    else if (key == 'd'){
        right = true;
    }
}

Game::~Game(){
    stop();
    delete enemy;
    delete explosion;
    delete player;
}
