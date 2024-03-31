#version 300 es  
  
precision mediump float;

in vec3 vertexcolor;
out vec4 outColor;

void main()  
{
    outColor = vec4(vertexcolor, 1.0);
}  