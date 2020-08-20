#ifndef WORLD_OBJECT_HPP
#define WORLD_OBJECT_HPP

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "Model.hpp"

class WorldObject{
private:
    Model* model_ptr;
    glm::mat4 model_matrix;
    const glm::mat4 IDENTITY;
public:
    WorldObject( Model* model_ptr = NULL );

    glm::vec3 position, rotation, scale_vector;
    void translate( glm::vec3 translation );
    void rotate( glm::vec3 rotation );
    void scale( glm::vec3 scale);
    void reset_matrix();

    glm::mat4 world_matrix();

    void render();
    void render_elements();
};

#endif