#version 410
// Fragment shader
layout (location = 1) in vec4 in_color;

out vec4 fColor;

void main() {
  fColor = in_color;
}
