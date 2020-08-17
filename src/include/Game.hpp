#ifndef GAME_HPP
#define GAME_HPP

#include "Window.hpp"
#include "ShaderProgram.hpp"
#include "Shapes.hpp"
#include "WorldObject.h"
#include "Camera.hpp"
#include "utils.hpp"

class Game{

private:
    Window window;
    Cube cube;
    WorldObject shape;
    WorldObject light;
    Camera camera;
    void gameLoop();

    std::string shaderpath = "res/shaders/";
    std::string vertex = shaderpath + "shader.vs", fragment = shaderpath + "shader.fs";
    ShaderProgram program, lightProgram;

    double current_time = 0, previous_time = 0;
    double time_elapsed = 0;

public:
    Game();
    ~Game();

    void start();
    void update( double delta_time );
    void render();

    inline void print_FPS( double delta_time ){ std::cout << "\r FPS : " << 1.0 / delta_time << std::flush; }
};

#endif