//
// Created by Administrator on 3/31/2024.
//

#ifndef ANDRIOD_CPP_OPENGL_DEMO_TRIANGLE_H
#define ANDRIOD_CPP_OPENGL_DEMO_TRIANGLE_H


#include <GLES3/gl3.h>
#include <vector>
#include "Shape.h"

class Triangle : public  Shape {
public:
    Triangle();

    char *getGLSLVertexShader() const;

    char *getGLSLFragmentShader() const;

    std::vector<GLfloat> getVertices() const;

    void onRender(GLint g_programObject) const;
};


#endif //ANDRIOD_CPP_OPENGL_DEMO_TRIANGLE_H
