#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{16};
  constexpr std::size_t kGridHeight{16};

    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    // Screen properties are given for controller as well for mouse input calculation.
    Controller controller(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    // Creation of a Menu object for obstacle selection.
    Menu menu(renderer, controller);
    Game game(kGridWidth, kGridHeight);
    game.Run(controller, renderer, menu, kMsPerFrame);
    std::cout << "Game has terminated successfully!\n";
    std::cout << "Score: " << game.GetScore() << "\n";
    std::cout << "Size: " << game.GetSize() << "\n";


  return 0;
}