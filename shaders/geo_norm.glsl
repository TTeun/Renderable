#version 410
layout(triangles) in;

layout (location = 1) in vec4 in_colour[];
layout (location = 2) in vec3 in_normal[];


// Three lines will be generated: 6 vertices
layout(line_strip, max_vertices=6) out;

uniform highp mat4 projectionMatrix;
uniform highp mat4 modelViewMatrix;

out vec4 vertex_color;

void main()
{
  int i;
  for(i=0; i<gl_in.length(); i++)
  {
    vec3 P = gl_in[i].gl_Position.xyz;
    vec3 N = in_normal[i];

    gl_Position = projectionMatrix * modelViewMatrix * vec4(P, 1.0);
    vertex_color = in_colour[i];
    EmitVertex();

    gl_Position = projectionMatrix * modelViewMatrix * vec4(P + N * 0.2, 1.0);
    vertex_color = in_colour[i];
    EmitVertex();

    EndPrimitive();
  }
}
