 #include "menu.h"
#include <iostream>
#include <vector>


void Menu::Update() {

    UpdateObstacles();
    renderer.RenderCheckeredBoard(ObstacleList);


    // std::cout << "------" << std::endl;
    // for(auto &i: ObstacleList)
    // std::cout << i.x << std::endl;
    // std::cout << "------" << std::endl;

}

void Menu::UpdateObstacles() {

    controller.HandleMouseInput(ObstacleList);
}