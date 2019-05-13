#ifndef Map_hpp
#define Map_hpp

#include "AppComponent.h"
#include "AnimatedRect.h"
#include "TexRect.h"


class Map: public AppComponent{
    Rect* rock;
    Rect* path;
    Rect* map[5][6][6];
    int level = 0;

    void generate() ;
    
    //bool projectileVisible;
    //bool rockVisible;
    //bool hasBeenGenerated = false;
   
    float theta;
    float deg;
public:
    //AnimatedRect* explosion;
    Map();
    
    void draw() const;
    Rect* getDoor(int);

   
    ~Map();

};

#endif 
