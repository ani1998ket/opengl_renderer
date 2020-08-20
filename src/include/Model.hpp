#ifndef MODEL_HPP
#define MODEL_HPP

#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

using std::vector;

class Model{

private:
    GLuint VAO;

protected:
    GLuint buffer_positions;
    GLuint buffer_textures;
    GLuint buffer_normals;
    GLuint buffer_indices;

public:
    Model();

    unsigned int vertex_count;
    void fill_vertex_data( vector<float>* positions, vector<float>* normals, vector<float>* textures );
    void fill_indices( vector<unsigned int>* indices );
    void bind();
    void unbind();
};
#endif