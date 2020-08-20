#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>

class Camera{
private:

public:
    double fov;
    double aspect_ratio;
    double near_plane, far_plane;
    glm::vec3 up, eye, origin;

    Camera( double fov = 45, double aspect_ratio = 16.0f/9.0, double near_plane = 0.1, double far_plane = 100);
    
    glm::mat4 view_matrix();
    glm::mat4 projection_matrix();
};

#endif