#version 410
// Vertex shader

layout (location = 0) in vec3 in_coords;
layout (location = 1) in vec4 in_colour;
layout (location = 2) in vec3 in_normal;

layout (location = 1) out vec4 out_colour;

uniform highp mat4 projectionMatrix;
uniform highp mat4 modelViewMatrix;
uniform bool readNormals;

void main() {
  gl_Position = projectionMatrix * modelViewMatrix * vec4(in_coords, 1.0);

  vec3 light = -gl_Position.xyz;
  if (readNormals){
    vec4 norm = projectionMatrix * vec4(in_normal, 0.0);
    float theta = dot( normalize(norm.xyz), normalize(light));
    out_colour = vec4(theta * in_colour.rgb, in_colour.a);
  }
  else {
    out_colour = in_colour;
  }
}
