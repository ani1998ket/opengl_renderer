#ifndef SHADER_PROGRAM_HPP
#define SHADER_PROGRAM_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <iostream>

class ShaderProgram{

private:
    GLuint id;
    std::vector< GLuint > shaders;

    void compile_shader( GLuint shader );

public:
    ShaderProgram();
    ShaderProgram( std::string vertex_shader_path, std::string fragment_shader_path );
    ~ShaderProgram();

    void attach( GLenum shader_type, std::string shader_path );
    void link();
    void use();

    void set( std::string name, glm::mat4 matrix );
    void set( std::string name, glm::vec3 vec );
    void set( std::string name, glm::vec4 vec );
};

#endif