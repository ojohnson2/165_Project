#ifndef Game_hpp
#define Game_hpp

#include "AppComponent.h"
#include "AnimatedRect.h"
#include "Timer.h"
#include "App.h"

class Game: public AppComponent, private Timer{
    Rect* enemy;
    Rect* player;
    AppComponent* mapPointer = sendComponent();

    
    bool projectileVisible;
    bool mushroomVisible;
    bool left, right, up, down;
    bool hit;
    float theta;
    float deg;
public:
    AnimatedRect* explosion;
    Game();
    
    void draw() const ;
    void handleKeyDown(unsigned char, float, float);
    
    void action();

    ~Game();

};

#endif 
