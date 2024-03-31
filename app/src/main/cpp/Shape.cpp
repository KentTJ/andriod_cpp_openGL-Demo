//
// Created by Administrator on 3/31/2024.
//

#include "Shape.h"

Shape::Shape() {
    // 可选的构造函数实现
}

char *Shape::getGLSLVertexShader() const {
    return nullptr;
}

char *Shape::getGLSLFragmentShader() const {
    return nullptr;
}

void Shape::onRender(GLint g_programObject) const {

}

std::vector<GLfloat> Shape::getVertices() const {
    return std::vector<GLfloat>();
}
