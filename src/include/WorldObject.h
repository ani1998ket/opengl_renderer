#ifndef WORLD_OBJECT_HPP
#define WORLD_OBJECT_HPP

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "Model.hpp"

class WorldObject{
private:
    Model model;
    WorldObject();
public:
    WorldObject( Model model );

    glm::vec3 position, rotation, scale_vector;
    void translate( glm::vec3 v );
    void rotate( glm::vec3 v );
    void scale( glm::vec3 v);

    glm::mat4 world_matrix();

    void draw();
};

#endif