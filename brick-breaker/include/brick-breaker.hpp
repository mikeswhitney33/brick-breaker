#ifndef BRICK_BREAKER_HPP
#define BRICK_BREAKER_HPP

#include "game.hpp"

class BrickBreaker:public Game
{
public:
    BrickBreaker();
    virtual void on_left_mouse_down();
};

#endif // BRICK_BREAKER_HPP