#version 300 es  
  
precision mediump float;  
out vec4 fragColor;

// cg add
uniform vec4 ourColor; // 在OpenGL程序代码中设定这个变量
  
void main()  
{
    // changed by cg
    fragColor = ourColor;
    //fragColor = vec4(1.0, 0.0, 0.0, 1.0);
}  