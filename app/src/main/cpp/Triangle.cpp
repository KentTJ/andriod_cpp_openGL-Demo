//
// Created by Administrator on 3/31/2024.
//

#include "Triangle.h"

#include <android/log.h>

#define LOG_TAG "ndk-build"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)


Triangle::Triangle() : Shape() {
    // 可选的构造函数实现
}

//  获取三角形配置文件接口
char* Triangle::getGLSLVertexShader() const {
    // 将三角形顶点坐标转换为字符串格式返回
    return "shader/vs.glsl";
}

//  获取三角形配置文件接口
char* Triangle::getGLSLFragmentShader() const {
    // 将三角形顶点坐标转换为字符串格式返回
    return "shader/fs.glsl";
}

//  获取三角形配置文件接口
std::vector<GLfloat> Triangle::getVertices() const {
    // 将三角形顶点坐标转换为字符串格式返回
    std::vector<GLfloat> vVertices = {  0.0f,  0.5f, 0.0f,
                             -0.5f, -0.5f, 0.0f,
                             0.5f, -0.5f, 0.0f
    };
    return vVertices;
}

void Triangle::onRender(GLint    g_programObject) const {
    // Load the vertex data
    glVertexAttribPointer ( 0, 3, GL_FLOAT, GL_FALSE, 0, getVertices() .data());
    glEnableVertexAttribArray ( 0 );
    glDrawArrays ( GL_TRIANGLES, 0, 3 );


    float greenValue = Triangle::getYValue();
    LOGE("chen, greenValue: %f", greenValue);
    int vertexColorLocation = glGetUniformLocation(g_programObject, "ourColor");
    glUseProgram(g_programObject);
    // CG add: set color value to OPNEGL
    glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
}


#include <jni.h>
#include <chrono>
#include <cmath>
double Triangle::getYValue() {
    // 获取当前时间
    auto currentTime = std::chrono::steady_clock::now();
    // 转换为秒
    double timeInSeconds = std::chrono::duration<double>(currentTime.time_since_epoch()).count();

    // 计算sin函数值，确保y在0~1之间
    double yValue = (1.0 + std::sin(timeInSeconds)) / 2.0;

    return yValue;
}