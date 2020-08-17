#include <iostream>
#include "Game.hpp"

Game::Game() 
    : window( 1280, 720, "Snake"), 
    program( vertex, fragment ),
    lightProgram( shaderpath + "basic.vs", shaderpath + "basic.fs" ),
    camera( 45.0f, 1280.0f/720, 0.1, 100)
{
    program.use();
    camera.eye.z = -3.0f;
    camera.eye.y =  2.0f;
    camera.eye.x =  -1.0f;
    program.set("lightPos", glm::vec3( 0 , 0, 1));
    light.scale_vector = glm::vec3(0.2);
    glClearColor( 0.3f, 0.3f, 0.3f, 1.0f);
    glEnable( GL_DEPTH_TEST );
}
Game::~Game(){
}

void Game::start(){
    gameLoop();
}

void Game::gameLoop(){
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
void Game::update( double delta_time ){
    program.use();

    // camera.eye.x = 3 * glm::cos( time_elapsed );
    // camera.eye.y = 3 * glm::cos( time_elapsed );
    // camera.eye.z = 3 * glm::sin( time_elapsed );

    
    light.position = glm::vec3(  0, glm::sin( time_elapsed / 2),  glm::cos( time_elapsed / 2));
    program.set("lightPos", light.position);
    shape.rotation.y = 0.5 * time_elapsed;
    // shape.scale_vector.y = 0.2 * time_elapsed;
    // shape.position.z = 2 * glm::sin(time_elapsed);
    
    program.set( "model", shape.world_matrix());
    program.set( "view", camera.view_matrix() );
    program.set( "projection", camera.projection_matrix() );
    program.set( "cameraPos", camera.eye );

    shape.bind();
    glDrawArrays(GL_TRIANGLES, 0, 300);

    lightProgram.use();
    lightProgram.set( "model", light.world_matrix());
    lightProgram.set( "view", camera.view_matrix() );
    lightProgram.set( "projection", camera.projection_matrix() );
    lightProgram.set( "u_color", glm::vec4(1.0) );
    light.bind();
    glDrawArrays(GL_TRIANGLES, 0, 300);
    // print_FPS( delta_time );
}
void Game::render(){

}