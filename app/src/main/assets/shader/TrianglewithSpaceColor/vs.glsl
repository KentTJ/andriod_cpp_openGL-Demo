#version 300 es  

layout(location = 0) in vec3 position;  // 挖值
layout(location = 1) in vec3 acolor;  // 挖值

out vec3 vertexcolor;

void main()  
{
    gl_Position = vec4(position.x, position.y, position.z, 1.0);
    vertexcolor = acolor;
}  