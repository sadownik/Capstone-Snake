#ifndef MENU_H
#define MENU_H

// #include "game.h"


#include <vector>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"

class Square {
    public: 
        
        Square(SDL_Point pos): 
        pos(pos) {}
        SDL_Point pos;
        
        
    private: 
        enum squareColor{defaultcolor, red};


    
};

class Menu {
    public:
        Menu(Renderer & renderer, Controller & controller):
        renderer(renderer), controller(controller) {}
        void RenderMenu();
        void Update();
        std::vector <SDL_Point> GetObstacles(){ return ObstacleList;};
        
    private:
        void UpdateObstacles();
        std::vector <SDL_Point> ObstacleList;// {{0,0}};
        Renderer renderer;
        Controller controller;


};


#endif