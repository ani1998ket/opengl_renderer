#include "Camera.hpp"
#include <glm/glm.hpp>
#include <glm/ext.hpp>

Camera::Camera( double fov, double aspect_ratio, double near_plane, double far_plane )
    : fov( fov ),
    aspect_ratio( aspect_ratio ), 
    near_plane( near_plane ),
    far_plane( far_plane )
{
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    origin = glm::vec3(0.0f);
    eye = glm::vec3(0.0f, 0.0f, -1.0f);
}

glm::mat4 Camera::view_matrix(){
    return glm::lookAt( eye, origin, up );
}

glm::mat4 Camera::projection_matrix(){
    return glm::perspective( fov, aspect_ratio, near_plane, far_plane );
}