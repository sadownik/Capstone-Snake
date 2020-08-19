 #include "menu.h"
#include <iostream>
#include <vector>


void Menu::Update() {
    
    running = true;
    //running turns to false by user request (starting a new game)
    running = controller.HandleMenuInput(ObstacleList);
    renderer.RenderCheckeredBoard(ObstacleList);
}
