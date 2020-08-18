#ifndef MENU_H
#define MENU_H

// #include "game.h"


#include <vector>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"

class Menu {
    public:
        Menu(Renderer & renderer, Controller & controller):
        renderer(renderer), controller(controller) {}
        void RenderMenu();
        void Update();
        std::vector <SDL_Point> GetObstacles() const {return ObstacleList;};
        bool GetRunningState() const {return running;}
        
    private:
        void UpdateObstacles();
        bool running; 
        std::vector <SDL_Point> ObstacleList;
        Renderer renderer;
        Controller controller;

};


#endif