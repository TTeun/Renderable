#version 410
// Fragment shader
layout (location = 0) in vec3 in_coords;
layout (location = 1) in vec4 in_colour;
layout (location = 2) in vec3 in_normal;

uniform vec3 lightPos;

out vec4 fColor;

float scale (float a){
  return (a + 1.0) / 2.0;
}

void main() {
    float theta = dot( normalize(-in_normal), normalize(lightPos - in_coords));
    fColor = vec4(scale(theta) * in_colour.rgb, in_colour.a);
}
