#include <iostream>

#include "brick-breaker.hpp"

BrickBreaker::BrickBreaker()
:Game("Brick Breaker")
{}

void BrickBreaker::on_left_mouse_down()
{
    std::cout << "left mouse down" << std::endl;
}

int main(int argc, char ** argv)
{
    Game * game = new BrickBreaker();
    int ret = game->mainloop(argc, argv);
    delete game;
    return ret;
}
