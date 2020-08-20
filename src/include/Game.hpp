#ifndef GAME_HPP
#define GAME_HPP

#include "Window.hpp"
#include "ShaderProgram.hpp"
#include "Shapes.hpp"
#include "WorldObject.hpp"
#include "Camera.hpp"
#include "utils.hpp"

class Game{

private:
    Window window;
    Cube cube;
    Plane plane;
    Square square;
    WorldObject box;
    WorldObject light;
    WorldObject ground;
    Camera camera;

    const std::string shader_path = "res/shaders/";
    ShaderProgram box_program, light_program;

    double current_time = 0, previous_time = 0;
    double time_elapsed = 0; 
    void gameLoop();

public:
    Game();
    ~Game();

    void start();
    void update( double delta_time );
    void render();

    inline void print_FPS( double delta_time ){ std::cout << "\r FPS : " << 1.0 / delta_time << std::flush; }
};

#endif