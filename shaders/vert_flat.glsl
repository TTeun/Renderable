#version 410
// Vertex shader

layout (location = 0) in vec3 in_coords;
layout (location = 1) in vec4 in_colour;

layout (location = 1) out vec4 out_colour;

uniform highp mat4 projectionMatrix;
uniform highp mat4 modelViewMatrix;

void main() {
  gl_Position = projectionMatrix * modelViewMatrix * vec4(in_coords, 1.0);
  out_colour = in_colour;
}
