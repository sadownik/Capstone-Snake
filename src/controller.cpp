#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"
#include "menu.h"
#include <algorithm>
#include "sdl_util.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;

          case SDLK_x:
          // exit(0);
          snake.ResetSnake();
          running = false;
          break;
      }
    }
  }
}

// This member function handles user input during the "menu" phase of \
the program. 
bool Controller::HandleMenuInput(std::vector <SDL_Point> &obstacles) {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
  if (e.type == SDL_KEYDOWN) {
    switch (e.key.keysym.sym) {

      case SDLK_y:
        return false;
        break;

      case SDLK_x:
        exit(0);
        break;
    }
  }
  //If the mouse button is pressed the current location of the cursor is \
  searched within the obstacles vector. If it isn't found it is being added \
  else it is erased (unselecting the cell) providing only unique cells. 
  if (e.type == SDL_MOUSEBUTTONDOWN ) {

  SDL_Point val { e.motion.x/((long unsigned int)screen_width/grid_width), e.motion.y/((long unsigned int)screen_height/grid_height)};
  std::vector<SDL_Point>::iterator it;
  it = std::find(obstacles.begin(), obstacles.end(), val);

  if (it == obstacles.end() || obstacles.size() == 0 )
    obstacles.push_back(val);
 
  else
    obstacles.erase(it);
 
    }
  }
  return true;
}
