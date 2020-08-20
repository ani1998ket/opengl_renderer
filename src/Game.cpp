#include <iostream>
#include "Game.hpp"
#include "utils.hpp"

Game::Game() 
    : window( 1280, 720, "Snake"), 
    box_program( shader_path + "shader.vs", shader_path + "shader.fs" ),
    light_program( shader_path + "basic.vs", shader_path + "basic.fs" ),
    camera( 45.0f, 1280.0f/720, 0.1, 100),
    light( &cube ), box( &cube ), ground( &square )
{
    ground.rotation = glm::vec3(degree_to_radians(90), 0, 0);
    ground.scale_vector.y = 5.0f;
    ground.rotate( ground.rotation );
    ground.scale( ground.scale_vector );

    camera.eye = glm::vec3( -1.0f, 2.0f, -3.0f);
    glClearColor( 0.3f, 0.3f, 0.3f, 1.0f);
    glEnable( GL_DEPTH_TEST );
    glEnable( GL_MULTISAMPLE );
}
Game::~Game()
{
}

void Game::start()
{
    gameLoop();
}

void Game::gameLoop()
{
    double delta_time = 0;

    while( window.running() ){
        current_time = glfwGetTime();
        delta_time =  current_time - previous_time;
        previous_time = current_time;
        time_elapsed += delta_time;

        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        update( delta_time );
        render();
        window.update();
    }
}

void Game::update( double delta_time )
{
    // print_FPS( delta_time );
    // camera.eye.x = 3 * glm::cos( time_elapsed );
    // camera.eye.y = 3 * glm::cos( time_elapsed );
    // camera.eye.z = 3 * glm::sin( time_elapsed );

    ground.position.z = 0.01;
    ground.translate( ground.position );
    
    light.position = glm::vec3(  0, glm::sin( time_elapsed / 2),  glm::cos( time_elapsed / 2));
    light.reset_matrix();
    light.scale( glm::vec3(0.2) );
    light.translate( light.position );

    box.rotation.y = 0.5 * time_elapsed;
    box.reset_matrix();
    box.translate( glm::vec3( 1.0, 0.0, 0.0) );
    box.rotate( box.rotation );
}

void Game::render(){

    box_program.use();
    box_program.set( "model", box.world_matrix());
    box_program.set( "view", camera.view_matrix());
    box_program.set( "projection", camera.projection_matrix());
    box_program.set( "lightPos", light.position);
    box_program.set( "cameraPos", camera.eye );
    box.render();

    light_program.use();
    light_program.set( "model", light.world_matrix());
    light_program.set( "view", camera.view_matrix() );
    light_program.set( "projection", camera.projection_matrix() );
    light_program.set( "u_color", glm::vec4(1.0) );
    light.render();

    light_program.set( "model", ground.world_matrix());
    light_program.set( "u_color", glm::vec4(0.5, 1.0, 0.4, 1.0) );
    ground.render();

}