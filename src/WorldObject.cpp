#include "WorldObject.h"

WorldObject::WorldObject( Model model ) : model( model ){
    position = glm::vec3(0.0);
    rotation = glm::vec3(0.0);
    scale_vector = glm::vec3(1.0);
}

void WorldObject::translate( glm::vec3 v ){ 
    position += v; 
}
void WorldObject::rotate( glm::vec3 v ){ 
    rotation += v;
}
void WorldObject::scale( glm::vec3 v){ 
    scale_vector += v;
}

glm::mat4 WorldObject::world_matrix(){
    glm::mat4 mat(1.0f);
    mat = glm::translate( mat, position );
    mat = glm::rotate( mat, rotation.x, glm::vec3(1.0, 0.0, 0.0) );
    mat = glm::rotate( mat, rotation.y, glm::vec3(0.0, 1.0, 0.0) );
    mat = glm::rotate( mat, rotation.z, glm::vec3(0.0, 0.0, 1.0) );
    mat = glm::scale( mat, scale_vector );
    return mat;
}

void WorldObject::draw(){
    model.bind();
    glDrawArrays(GL_TRIANGLES, 0, model.positions.size());
}