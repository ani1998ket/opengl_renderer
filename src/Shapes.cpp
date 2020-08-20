#include "Model.hpp"
#include "Shapes.hpp"

Triangle::Triangle()
{
    vector<float> positions = {
        -0.5, -0.5, 0.0,
         0.5, -0.5, 0.0,
         0.0,  0.5, 0.0
    };

    fill_vertex_data( &positions, NULL, NULL );
}

Square::Square()
{
    vector<float> positions = {
        -0.5, -0.5, 0.0,
         0.5, -0.5, 0.0,
         0.5,  0.5, 0.0,

        -0.5, -0.5, 0.0,
         0.5,  0.5, 0.0,
        -0.5,  0.5, 0.0};

    fill_vertex_data( &positions, NULL, NULL );
}

Cube::Cube()
{
    vector<float> positions = {
        -0.5, -0.5, -0.5,
         0.5, -0.5, -0.5,
         0.5,  0.5, -0.5,
        -0.5, -0.5, -0.5,
         0.5,  0.5, -0.5,
        -0.5,  0.5, -0.5,

         0.5, -0.5,  0.5, 
        -0.5, -0.5,  0.5, 
        -0.5,  0.5,  0.5, 
         0.5, -0.5,  0.5, 
        -0.5,  0.5,  0.5, 
         0.5,  0.5,  0.5,

        -0.5, -0.5,  0.5, 
        -0.5, -0.5, -0.5,
        -0.5,  0.5, -0.5,
        -0.5, -0.5,  0.5,
        -0.5,  0.5, -0.5,
        -0.5,  0.5,  0.5,
         
         0.5, -0.5, -0.5, 
         0.5, -0.5,  0.5, 
         0.5,  0.5,  0.5, 
         0.5, -0.5, -0.5, 
         0.5,  0.5,  0.5, 
         0.5,  0.5, -0.5, 
        
        -0.5, -0.5,  0.5, 
         0.5, -0.5,  0.5,
         0.5, -0.5, -0.5,
        -0.5, -0.5,  0.5,
         0.5, -0.5, -0.5,
        -0.5, -0.5, -0.5,
        
        -0.5,  0.5, -0.5, 
         0.5,  0.5, -0.5, 
         0.5,  0.5,  0.5, 
        -0.5,  0.5, -0.5, 
         0.5,  0.5,  0.5, 
        -0.5,  0.5,  0.5 
    };

    float temp_normals[] = {
         0,  0, -1,
         0,  0,  1,
        -1,  0,  0,
         1,  0,  0,
         0, -1,  0,
         0,  1,  0
    };

    vector<float> normals;

    for( int i = 0; i < 6; i++ ){
        for( int j = 0; j < 6; j++ ){
            normals.push_back( temp_normals[3*i] );
            normals.push_back( temp_normals[3*i + 1] );
            normals.push_back( temp_normals[3*i + 2] );
        }
    }
    
    fill_vertex_data( &positions, &normals, NULL );
}

Plane::Plane(){
    vector<float> positions = {
        -1, -1, 0,
         1, -1, 0,
         1,  1, 0,
        -1,  1, 0
    };
    vector<unsigned> indices = {
        0, 1, 2,
        0, 2, 3
    };
    fill_vertex_data( &positions, NULL, NULL );
    fill_indices( &indices );
}