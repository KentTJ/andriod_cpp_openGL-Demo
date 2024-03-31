//
// Created by Administrator on 3/31/2024.
//

#ifndef ANDRIOD_CPP_OPENGL_DEMO_TRIANGLEWITHSPACECOLOR_H
#define ANDRIOD_CPP_OPENGL_DEMO_TRIANGLEWITHSPACECOLOR_H


#include <GLES3/gl3.h>
#include <vector>
#include "Shape.h"

class TrianglewithSpaceColor : public Shape{
public:
    virtual char *getGLSLVertexShader() const override;

    virtual char *getGLSLFragmentShader() const override;

    virtual std::vector<GLfloat> getVertices() const override;

    virtual void onRender(GLint g_programObject) const override;

    TrianglewithSpaceColor();
};


#endif //ANDRIOD_CPP_OPENGL_DEMO_TRIANGLEWITHSPACECOLOR_H
