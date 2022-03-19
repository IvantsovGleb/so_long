#include "Player.h"

bool Player::Moved() const
{
    if (coords.x == old_coords.x && coords.y == old_coords.y)
        return false;
    else
        return true;
}

void Player::ProcessInput(MovementDir dir, GLfloat deltaTime)
{
    int move_dist = float(move_speed) * deltaTime;
    switch (dir) {
    case MovementDir::UP:old_coords.y = coords.y;
        coords.y -= move_dist;
        break;
    case MovementDir::DOWN:old_coords.y = coords.y;
        coords.y += move_dist;
        break;
    case MovementDir::LEFT:old_coords.x = coords.x;
        coords.x -= move_dist;
        break;
    case MovementDir::RIGHT:old_coords.x = coords.x;
        coords.x += move_dist;
        break;
    default:break;
    }
}

void Player::Draw(Image& screen)
{
    for (int y = coords.y; y <= coords.y + tileSize; ++y) {
        for (int x = coords.x; x <= coords.x + tileSize; ++x) {
            screen.PutPixel(x, y, color);
        }
    }
}
bool Player::isInside(Point top_left, Point size) const {
  Point points[] = {
      {coords.x + 10, coords.y + 10},
      {coords.x + tileSize - 10, coords.y + tileSize - 10},
      {coords.x + tileSize - 10, coords.y + 10},
      {coords.x + 10, coords.y + tileSize - 10},
  };
  for (int i = 0 ; i < 4 ; i++) {
    if (points[i].x >= top_left.x && top_left.x + size.x > points[i].x) {
      if (points[i].y >= top_left.y && top_left.y + size.y > points[i].y) {
        return true;
      }
    }
  }
  return false;
}
