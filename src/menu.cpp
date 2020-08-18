 #include "menu.h"
#include <iostream>
#include <vector>


void Menu::Update() {
    running = true;
    running = controller.HandleMenuInput(ObstacleList);
    renderer.RenderCheckeredBoard(ObstacleList);
}
