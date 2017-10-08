#version 410
// Vertex shader

layout (location = 0) in vec3 in_coords;
layout (location = 1) in vec4 in_colour;
layout (location = 2) in vec3 in_normal;

layout (location = 0) out vec3 out_coords;
layout (location = 1) out vec4 out_colour;
layout (location = 2) out vec3 out_normal;

uniform highp mat4 projectionMatrix;
uniform highp mat4 modelViewMatrix;

void main() {
  gl_Position = projectionMatrix * modelViewMatrix * vec4(in_coords, 1.0);
  out_coords = gl_Position.xyz;
  out_colour = in_colour;
  vec4 t_normal = vec4(in_normal, 0.0);
  out_normal = t_normal.xyz;
}
