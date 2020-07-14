#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Game
{
public:
    Game(std::string title, int w=800, int h=600, double r=0.2, double g=0.3, double b=0.3, double a=1.0);
    int mainloop(int argc, char ** argv);
    virtual void on_right_mouse_down();
    virtual void on_right_mouse_up();
    virtual void on_left_mouse_down();
    virtual void on_left_mouse_up();
    virtual void on_key_down(int key);
    virtual void on_key_up(int key);
    virtual void on_cursor_pos(double x, double y);
    virtual void update(double delta_time);
    virtual void draw();
private:
    std::string title;
    int screen_width, screen_height;
    double r, g, b, a;
};

#endif // STATE_HPP