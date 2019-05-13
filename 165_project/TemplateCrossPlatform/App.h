#ifndef App_h
#define App_h
#include <vector>

#include "GlutApp.h"
#include "Game.h"
#include "Map.h"
#include "Ad.h"

class App: public GlutApp {
    
   
    
    void addComponent(AppComponent* component){
        components.push_back(component);
    }
    
    bool fullscreen;
public:
     std::vector<AppComponent*> components;
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw() const;

    AppComponent* sendComponent(){
        return components[1];
    }
    
    void keyDown(unsigned char key, float x, float y);
    
    void gameOver();
    
    ~App();
};

#endif
