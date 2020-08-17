#include "Model.hpp"
#include <iostream>

void Model::init()
{
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

void Model::bind(){
    glBindVertexArray( VAO );
}
void Model::unbind(){
    glBindVertexArray( 0 );
}