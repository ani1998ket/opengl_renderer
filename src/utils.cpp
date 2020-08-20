#include "utils.hpp"

void print_vec4( glm::vec4 v ){
    std::cout << v.x << " " << v.y << " " << v.z << " " << v.w << std::endl;
}
void print_vec3( glm::vec3 v ){
    std::cout << v.x << " " << v.y << " " << v.z << std::endl;
}
void print_mat4( glm::mat4 m ){
    for( int i = 0; i < 4; i++ ){
        for( int j = 0; j < 4; j++ ){
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

double degree_to_radians( double degree ){
    return  ( glm::pi<double>() / 180.0f ) * degree;
}