#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 texture;
layout (location = 2) in vec4 normal;

out vec4 v_position;
out vec4 v_texture;
out vec3 v_normal;
out vec4 v_color;
out vec3 v_lightPos;
out vec4 raw_normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 lightPos;

vec4 worldCoords;
vec3 toLight;
float col;

void main(){

    worldCoords = model * position;
    v_position = worldCoords;
    v_normal = normalize( mat3(transpose(inverse(model))) * normal.xyz );
    v_lightPos = lightPos;

    toLight = normalize(lightPos - worldCoords.xyz);
    col = max(0.2, dot( toLight, v_normal.xyz ) );
    v_color = vec4( col, col, col, 1.0);

    raw_normal = normal;
    gl_Position = projection * view * worldCoords;
}