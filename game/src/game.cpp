#include "game.hpp"

void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);
void mouse_button_callback(GLFWwindow * window, int button, int action, int mods);
void cursor_pos_callback(GLFWwindow * window, double x, double y);

Game::Game(std::string title, int w, int h, double r, double g, double b, double a)
:title(title), screen_width(w), screen_height(h), r(r), g(g), b(b), a(a)
{

}

void Game::on_cursor_pos(double x, double y)
{

}

void Game::on_key_down(int key)
{

}

void Game::on_key_up(int key)
{

}

void Game::on_right_mouse_down()
{

}

void Game::on_right_mouse_up()
{

}

void Game::on_left_mouse_down()
{

}

void Game::on_left_mouse_up()
{

}

void Game::update(double delta_time)
{

}

void Game::draw()
{

}

int Game::mainloop(int argc, char ** argv)
{
    if(glfwInit() == GLFW_FALSE)
    {
        std::cerr << "Failed to init glfw" << std::endl;
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GL_FALSE);
#endif
    GLFWwindow * window = glfwCreateWindow(screen_width, screen_height, title.c_str(), NULL, NULL);
    if(window == NULL)
    {
        std::cerr << "Failed to make window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    if(gladLoadGL() == GL_FALSE)
    {
        std::cerr << "Failed to load glad" << std::endl;
        glfwTerminate();
        glfwDestroyWindow(window);
        return -1;
    }
    glViewport(0, 0, screen_width, screen_height);

    double last = glfwGetTime();
    while(glfwWindowShouldClose(window) != GLFW_TRUE)
    {
        glClearColor(0.2, 0.3, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        double current = glfwGetTime();
        double delta_time = current - last;
        update(delta_time);
        draw();

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
    Game * self = (Game*)glfwGetWindowUserPointer(window);
    if(action == GLFW_PRESS)
    {
        self->on_key_down(key);
    }
    if(action == GLFW_RELEASE)
    {
        self->on_key_up(key);
    }
    if(key == GLFW_KEY_ESCAPE)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void mouse_button_callback(GLFWwindow * window, int button, int action, int mods)
{
    Game * self = (Game *)glfwGetWindowUserPointer(window);
    if(action == GLFW_PRESS && button == GLFW_MOUSE_BUTTON_LEFT)
    {
        self->on_left_mouse_down();
    }
    if(action == GLFW_RELEASE && button == GLFW_MOUSE_BUTTON_LEFT)
    {
        self->on_left_mouse_up();
    }
    if(action == GLFW_PRESS && button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        self->on_right_mouse_down();
    }
    if(action == GLFW_RELEASE && button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        self->on_right_mouse_up();
    }
}

void cursor_pos_callback(GLFWwindow * window, double x, double y)
{
    Game * self = (Game *)glfwGetWindowUserPointer(window);
    self->on_cursor_pos(x, y);
}
