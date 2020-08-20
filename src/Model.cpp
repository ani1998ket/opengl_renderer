#include "Model.hpp"
#include <iostream>

Model::Model()
{
    glGenVertexArrays(1, &VAO);
    glBindVertexArray( VAO );

    glCreateBuffers(1, &buffer_positions );
    glCreateBuffers(1, &buffer_normals );
    glCreateBuffers(1, &buffer_textures );
    glCreateBuffers(1, &buffer_indices );

    glBindVertexArray(0);
}

void Model::fill_vertex_data(vector<float>* positions, vector<float>* normals, vector<float>* textures ){
    bind();
    if( positions ){
        vertex_count = positions->size() / 3;
        glBindBuffer( GL_ARRAY_BUFFER,  buffer_positions );
        glBufferData( GL_ARRAY_BUFFER, positions->size() * sizeof( float ), &(*positions)[0], GL_STATIC_DRAW );
        glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(0);
    }
    if( normals ){
        glBindBuffer( GL_ARRAY_BUFFER,  buffer_normals );
        glBufferData( GL_ARRAY_BUFFER, normals->size() * sizeof( float ), &(*normals)[0], GL_STATIC_DRAW );
        glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(1);
    }
    if( textures ){
        glBindBuffer( GL_ARRAY_BUFFER,  buffer_textures );
        glBufferData( GL_ARRAY_BUFFER, textures->size() * sizeof( float ), &(*textures)[0], GL_STATIC_DRAW );
        glVertexAttribPointer( 2, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(2);
    }
    glBindBuffer( GL_ARRAY_BUFFER, 0 );
    unbind();
}
void Model::fill_indices( vector<unsigned int>* indices ){
    bind();
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER,  buffer_indices );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, indices->size() * sizeof( unsigned int ), &(*indices)[0], GL_STATIC_DRAW );
    unbind();
}

void Model::bind()
{
    glBindVertexArray( VAO );
}
void Model::unbind()
{
    glBindVertexArray( 0 );
}