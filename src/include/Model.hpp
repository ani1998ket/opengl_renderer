#ifndef MODEL_HPP
#define MODEL_HPP

#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

class Model{

private:
    GLuint VAO;
    GLuint buffer_positions;
    GLuint buffer_textures;
    GLuint buffer_normals;
    
public:
    std::vector<float> positions;
    std::vector<float> textures;
    std::vector<float> normals;

    void init();
    void bind();
    void unbind();
};
#endif