#include <iostream>
#include "ShaderProgram.hpp"
#include "FileReader.hpp"

ShaderProgram::ShaderProgram()
{  
    id = glCreateProgram();
    use();
    std::cout << "Program created with id : " << id << std::endl;
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram( id );
}

ShaderProgram::ShaderProgram( std::string vertex_shader_path, std::string fragment_shader_path )
    : ShaderProgram()
{
    attach( GL_VERTEX_SHADER, vertex_shader_path);
    attach( GL_FRAGMENT_SHADER, fragment_shader_path);
    link();
}

void ShaderProgram::use()
{
    glUseProgram( id );
    // std::cout << "Using Program with id : " << id << std::endl;
}

void ShaderProgram::attach(GLenum type, std::string path)
{
    GLuint shader = glCreateShader( type );

    std::string data;
    FileReader::read_text_file( path, data );
    const GLchar* source = (GLchar *)data.c_str();

    glShaderSource( shader, 1, &source, NULL); 
    compile_shader( shader );
    shaders.push_back( shader );
    glAttachShader( id, shader );
}

void ShaderProgram::compile_shader( GLuint shader )
{
    glCompileShader( shader );

    GLint isCompiled = 0;
    glGetShaderiv( shader, GL_COMPILE_STATUS, &isCompiled);

    if(isCompiled == GL_FALSE){
        GLint maxLength = 0;
        glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &maxLength);
        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);
        glDeleteShader(shader);

        std::cerr << "Shader Compilation Error : \n";
        std::cerr << &infoLog[0] << "\n";
        exit(-1);
    }
}

void ShaderProgram::link()
{
    glLinkProgram( id );

    GLint isLinked = 0;
    glGetProgramiv( id, GL_LINK_STATUS, &isLinked );

    if( isLinked == GL_FALSE ){
        GLint maxLength = 0;
        glGetProgramiv( id, GL_INFO_LOG_LENGTH, &maxLength );
        std::vector<char> infoLog( maxLength );
        glGetProgramInfoLog( id, maxLength, &maxLength, &infoLog[0] );
        glDeleteProgram( id );
        for( auto shader : shaders ){
            glDeleteShader( shader );
        }
        shaders.clear();
        std::cerr << "Linking Error : \n";
        std::cerr << &infoLog[0] << "\n";

        exit(-1);
    }
}

void ShaderProgram::set( std::string name, glm::mat4 matrix ){
    glUniformMatrix4fv( glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &matrix[0][0] );
}
void ShaderProgram::set( std::string name, glm::vec3 vec ){
    glUniform3f( glGetUniformLocation(id, name.c_str()), vec.x, vec.y, vec.z );
}
void ShaderProgram::set( std::string name, glm::vec4 vec ){
    glUniform4f( glGetUniformLocation(id, name.c_str()), vec.x, vec.y, vec.z, vec.w );
}