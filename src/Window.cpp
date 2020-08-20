#include <iostream>
#include "Window.hpp"

Window::Window( unsigned width, unsigned height, std::string title) 
    : width( width ), height( height ), title( title )
{
    init();
}

Window::~Window()
{
    glfwDestroyWindow( window );
    glfwTerminate();
}

void Window::update()
{ 
    glfwPollEvents();
    glfwSwapBuffers( window );
}

void Window::init()
{
    if( !glfwInit() ){
        std::cerr << "GLFW INIT ERROR \n";
        exit(-1);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_SAMPLES, 4);

    window = glfwCreateWindow( width, height, title.c_str() , NULL, NULL );
    if( !window ){
        std::cerr << "GLFW WINDOW ERROR \n";
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent( window );
    
    GLenum error = glewInit();
    if( error != GLEW_OK ){
        std::cerr << "GLEW ERROR : " << glewGetErrorString(error) << "\n";
        glfwTerminate();
        exit(-1);
    }

    glfwSwapInterval(1);
}