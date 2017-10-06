#version 410
// Fragment shader
layout (location = 1) in vec4 in_colour;
layout (location = 2) in vec3 in_normal;

uniform bool readNormals;

out vec4 fColor;

void main() {
  if (readNormals){
    vec3 light = vec3(-10, 50.0, 0.0) - gl_FragCoord.xyz;
    float theta = dot( normalize(in_normal), normalize(light));
    fColor = vec4((theta) * in_colour.rgb, in_colour.a);
  }
  else {
    fColor = in_colour;
  }
}
