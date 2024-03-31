//
// Created by Administrator on 3/31/2024.
//

#include "TrianglewithSpaceColor.h"

#include <android/log.h>

#define LOG_TAG "ndk-build"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)


TrianglewithSpaceColor::TrianglewithSpaceColor() : Shape() {
    // 可选的构造函数实现
}

//  获取三角形配置文件接口
char* TrianglewithSpaceColor::getGLSLVertexShader() const {
    // 将三角形顶点坐标转换为字符串格式返回
    return "shader/TrianglewithSpaceColor/vs.glsl";
}

//  获取三角形配置文件接口
char* TrianglewithSpaceColor::getGLSLFragmentShader() const {
    // 将三角形顶点坐标转换为字符串格式返回
    return "shader/TrianglewithSpaceColor/fs.glsl";
}

//  获取三角形配置文件接口
std::vector<GLfloat> TrianglewithSpaceColor::getVertices() const {
    // 将三角形顶点坐标转换为字符串格式返回
    std::vector<GLfloat> vVertices = {
            // 位置                   // 颜色`
            0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f, // 右下`
            -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // 左下`
            0.0f, 0.5f, 0.0f,    0.0f, 0.0f, 1.0f // 顶部`
    };
    return vVertices;
}

// 将 std::vector<GLfloat> 转换为 GLfloat 数组
GLfloat* vectorToFloatArray(const std::vector<GLfloat>& vertices) {
    size_t size = vertices.size();
    // 分配足够的空间来存储 vector 中的元素
    GLfloat* vVerticesArray = new GLfloat[size];
    // 将 vector 中的元素复制到数组中
    std::copy(vertices.begin(), vertices.end(), vVerticesArray);
    return vVerticesArray;
}


void TrianglewithSpaceColor::onRender(GLint    g_programObject) const {
    // Load the vertex data
//    glVertexAttribPointer ( 0, 3, GL_FLOAT, GL_FALSE, 0, getVertices() .data());
//    glEnableVertexAttribArray ( 0 );
//    glDrawArrays ( GL_TRIANGLES, 0, 3 );


    // Load the vertex data ------> to glsl
    // location data------define location index = 0
    GLfloat* vVerticesarray  = vectorToFloatArray(getVertices());
     glVertexAttribPointer ( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), vVerticesarray);
    // ---------> para解释：    index 是定义出来的协议，glsl中会用`
                            // size 是location数据的数据大小`
                            // type .............`
                            // stride 步长：下一个location的跨度：6*float数据大小`
                            // pointer 偏移量：颜色属性是有偏移量的 6*float数据大小`
    glEnableVertexAttribArray ( 0 );
    glDrawArrays ( GL_TRIANGLES, 0, 3 );

    // Load color data------define index = 1
     float* pVertices = &vVerticesarray[0]; // 获取数组的起始地址
     pVertices += 3; // 移动到第四个元素的位置
     glVertexAttribPointer ( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), pVertices );
     glEnableVertexAttribArray ( 1 );
     glDrawArrays ( GL_TRIANGLES, 0, 3 );
}

