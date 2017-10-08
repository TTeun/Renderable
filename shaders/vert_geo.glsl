#version 410
// Vertex shader

layout (location = 0) in vec3 in_coords;
layout (location = 1) in vec4 in_colour;
layout (location = 2) in vec3 in_normal;

layout (location = 1) out vec4 out_colour;
layout (location = 2) out vec3 out_normal;

void main() {
  gl_Position = vec4(in_coords, 1.0);
  out_colour = vec4(1.0, 0.0, 0.0, 1.0);
  out_normal = in_normal;
}
