#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include "Map.h"
#include <random>

Map::Map(){

	// Some cross-platform compatimility stuff

	//const char* rockFileName;
	generate();

	// In Windows (Visual Studio only) the image files are found in the enclosing folder in relation to the project
	// In other environments the image files are in the same folder as the project

	#if defined WIN32
	//rockFileName = "../rock.png";
	//fireballFileName = "../fireball.bmp";
	#else
	//rockFileName = "rock.png";
	//fireballFileName = "fireball.bmp";
	#endif

    //rock = new Rect(-0.25, 0.5, 0.5, 0.5);
    //path = new Rect(-0.05, -0.8, 0.1, 0.1);
    //explosion = new AnimatedRect(fireballFileName, 6, 6, 64, false, false, -0.25, 0.8, 0.5, 0.5);
    
    //projectileVisible = true;
    //rockVisible = true;
    theta = 0;
    deg = 0;
    
}

Rect* getDoor(){
    return map[level][2][0];
}

void  Map::draw() const {
    
    //for (int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            for(int k = 0; k < 6; k++){
                map[level][j][k]->draw();
            }
        }
    //}
    level++;
}

void Map::generate() {
    int rockCount = 0;
    for (int i = 0; i < 5; i++){
        //std:: cout << "creating map " << i + 1 << std::endl;
        for(int j = 0; j < 6; j++){
            //std:: cout << "   in x " << j + 1 << std::endl;
            for(int k = 0; k < 6; k++){
                if(j == 2 && k == 0){
                    map[i][j][k] = new Rect (-1 + (2 * j * 0.166), 1 - (2 * k* 0.166),  0.166,  0.166, 1, 1, 0);
                }
                else{
                //std:: cout << "      in y " << k + 1 << std::endl;
                int r = (rand() % (10)) + 1;
                //std:: cout << "rand r = " << r << std::endl;
                if (r <= 3 && rockCount < 18){
                    map[i][j][k] = new Rect (-1 + (2 * j * 0.166), 1 - (2 * k* 0.166),  0.166,  0.166, 0, 1, 0);
                    rockCount++;
                }
                else 
                    map[i][j][k] = new Rect (-1 + (2 * j * 0.166), 1 - (2 * k* 0.166),  0.166,  0.166, 0, 0, 1);
                //std:: cout << "         x =  " << (j * 0.166) << std::endl;
                //std:: cout << "         y =  " << (k * 0.166) << std::endl;
                }
            }
        }
    }
    //std:: cout << "finished with the map" << std::endl;

}


 Map::~ Map(){
    delete map;
}
