#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}

  void Update();
  void GrowBody();
  bool SnakeCell(int x, int y);
  void ResetSnake();

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
};

class Obstacle {
  public:
    Obstacle(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height) {}
    
    // std::vector<std::vector <int>>obstacle_positions;
    //std::vector<SDL_Point> obstacle_positions;
    bool CheckForCollision(int x, int y);
    void UpdatePositions(std::vector <SDL_Point> &obstacle_pos);
    std::vector <SDL_Point> GetObstaclePostions() const;

  private:
    
    std::vector <SDL_Point> obstacle_positions;
    int grid_width;
    int grid_height;

};

#endif