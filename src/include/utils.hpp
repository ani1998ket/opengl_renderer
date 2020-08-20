#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <glm/glm.hpp>
#include <glm/ext.hpp>


void print_vec4( glm::vec4 v );
void print_vec3( glm::vec3 v );
void print_mat4( glm::mat4 m );

double degree_to_radians( double degree );
#endif