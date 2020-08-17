#include "Model.hpp"
#include <iostream>

void Model::init(){

    position = glm::vec3(0.0);
    rotation = glm::vec3(0.0);
    scale_vector = glm::vec3(1.0);

    glGenVertexArrays(1, &VAO);

    glBindVertexArray( VAO );

    glGenBuffers( 1, &buffer_positions );
    glBindBuffer( GL_ARRAY_BUFFER, buffer_positions );
    glBufferData( GL_ARRAY_BUFFER, positions.size() * sizeof( float ), &positions[0], GL_STATIC_DRAW );
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    if( textures.size() != 0 ){
        glGenBuffers( 1, &buffer_textures );
        glBindBuffer( GL_ARRAY_BUFFER, buffer_textures );
        glBufferData( GL_ARRAY_BUFFER, textures.size() * sizeof( float ), &textures[0], GL_STATIC_DRAW );
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(1);
    }
    
    if( normals.size() != 0 ){
        glGenBuffers( 1, &buffer_normals );
        glBindBuffer( GL_ARRAY_BUFFER, buffer_normals );
        glBufferData( GL_ARRAY_BUFFER, normals.size() * sizeof( float ), &normals[0], GL_STATIC_DRAW );
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(2);
    }

    glBindVertexArray(0);
}

void Model::translate( glm::vec3 v ){ 
    position += v; 
}
void Model::rotate( glm::vec3 v ){ 
    rotation += v;
}
void Model::scale( glm::vec3 v){ 
    scale_vector += v;
}

glm::mat4 Model::world_matrix(){
    glm::mat4 mat(1.0f);
    mat = glm::translate( mat, position );
    mat = glm::rotate( mat, rotation.x, glm::vec3(1.0, 0.0, 0.0) );
    mat = glm::rotate( mat, rotation.y, glm::vec3(0.0, 1.0, 0.0) );
    mat = glm::rotate( mat, rotation.z, glm::vec3(0.0, 0.0, 1.0) );
    mat = glm::scale( mat, scale_vector );
    return mat;
}

void Model::bind(){
    glBindVertexArray( VAO );
}