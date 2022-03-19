#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

#include "Image.h"
#include <GLFW/glfw3.h>

struct Point {
    int x;
    int y;
};

enum class MovementDir {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Player {
    explicit Player(Point pos = {.x = 10, .y = 10}) : coords(pos), old_coords(coords) { };

    bool Moved() const;
    void ProcessInput(MovementDir dir, GLfloat deltaTime);
    void Draw(Image& screen);
    Point getPos() { return coords; }
    bool isInside(Point top_left, Point size) const;
    void Reset() { coords = old_coords; }

private:
    Point coords{.x = 10, .y = 10};
    Point old_coords{.x = 10, .y = 10};
    Pixel color{.r = 255, .g = 255, .b = 0, .a = 255};
    int move_speed = 200;
};



#endif //MAIN_PLAYER_H