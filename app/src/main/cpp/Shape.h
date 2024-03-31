//
// Created by Administrator on 3/31/2024.
//

#ifndef ANDRIOD_CPP_OPENGL_DEMO_SHAPE_H
#define ANDRIOD_CPP_OPENGL_DEMO_SHAPE_H


#include <GLES3/gl3.h>
#include <vector>

class Shape {
public:
    Shape();
    ~Shape() {} // 基类析构函数要声明为虚函数，以确保正确释放资源
    // 获取三角形配置文件接口

    // 纯虚函数！！
    virtual char* getGLSLVertexShader() const = 0;
    virtual char* getGLSLFragmentShader() const = 0;
    virtual void onRender(GLint    g_programObject) const = 0;
    virtual std::vector<GLfloat> getVertices() const = 0;
};

#endif //ANDRIOD_CPP_OPENGL_DEMO_SHAPE_H
