#version 330 core

in vec4 v_position;
in vec4 v_texture;
in vec3 v_normal;
in vec4 v_color;

in vec4 raw_normal;

out vec4 color;

in vec3 v_lightPos;
uniform vec3 cameraPos;

vec3 toCamera;
vec3 reflected;
float spec;

vec4 intensity;
vec3 cam;

void main(){
   cam = cameraPos;
   if( dot( v_normal, v_lightPos - v_position.xyz ) > 0 ){
   reflected = normalize(reflect( v_position.xyz - v_lightPos, v_normal.xyz));
   toCamera = normalize( cam - v_position.xyz);
   spec = pow( max(0, dot( toCamera, reflected )), 16 );
   }else{
      spec = 0;
   }
   color = v_color * abs(vec4(raw_normal)) + spec * vec4( 1.0, 1.0, 1.0, 1.0);
}