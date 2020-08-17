#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class Window{
    private:
    unsigned width, height;
    GLFWwindow* window;
    std::string title;

    void init();

    public:
    Window( unsigned width = 640, unsigned height = 480, std::string title = "MyGame");
    ~Window();
    inline bool running() { return !glfwWindowShouldClose(window); }
    void update();
};

#endif