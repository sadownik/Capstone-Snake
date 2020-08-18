#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include <vector>
//#include "menu.h"
class Menu; 
class Square;

class Controller {
 public:
  void HandleInput(bool &running, Snake &snake) const;
  bool HandleMenuInput(std::vector <SDL_Point> &obstacles);
  void HandleMouseInput(std::vector <SDL_Point> &obstacles);

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif