#include <iostream>
#include "WorldObject.hpp"

WorldObject::WorldObject( Model* model_ptr ) 
    : model_ptr( model_ptr ), IDENTITY(1.0)
{
    position = glm::vec3(0.0);
    rotation = glm::vec3(0.0);
    scale_vector = glm::vec3(1.0);
    model_matrix = glm::mat4(1.0);
}

void WorldObject::translate( glm::vec3 translation )
{ 
    model_matrix = glm::translate( IDENTITY, translation ) * model_matrix;
}

void WorldObject::rotate( glm::vec3 rotation )
{ 
    model_matrix = glm::rotate( IDENTITY, rotation.x, glm::vec3(1.0, 0.0, 0.0) ) * model_matrix;
    model_matrix = glm::rotate( IDENTITY, rotation.y, glm::vec3(0.0, 1.0, 0.0) ) * model_matrix;
    model_matrix = glm::rotate( IDENTITY, rotation.z, glm::vec3(0.0, 0.0, 1.0) ) * model_matrix;
}

void WorldObject::scale( glm::vec3 scale)
{ 
    model_matrix = glm::scale( IDENTITY, scale ) *  model_matrix;
}

void WorldObject::reset_matrix()
{
    model_matrix = glm::mat4(1.0);
}

glm::mat4 WorldObject::world_matrix(){
    return model_matrix;
}

void WorldObject::render(){
    if( !model_ptr ) return;
    model_ptr->bind();
    glDrawArrays(GL_TRIANGLES, 0, model_ptr->vertex_count );
    model_ptr->unbind();
}

void WorldObject::render_elements(){
    std::cerr << "NOT IMPLEMENTED" << std::endl;
    exit(-1);   
}