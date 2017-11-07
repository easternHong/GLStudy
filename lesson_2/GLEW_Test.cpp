//
// Created by hds on 17-11-1.
//

#include "GLEW_Test.h"

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);

void drawTriangle();

/**
 * 需要链接 -lglfw
 */
void GLEW_Test::run() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
    bool glewExperimental = GL_TRUE;
    if (glfwInit() != 1) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return;
    }
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSetKeyCallback(window, key_callback);

    // 程序循环
    while (!glfwWindowShouldClose(window)) {
        // 检查事件
        glfwPollEvents();
        // 渲染指令
        drawTriangle();
//        ...
        // 交换缓冲
        glfwSwapBuffers(window);
    }
    glfwTerminate();
}

GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
};

void drawTriangle() {
//    GLuint VBO;
    std::cout << "gl_version" << GL_VERSION << std::endl;
//    glGenBuffers(1, &VBO);
    glGenerateMipmap(GL_TEXTURE_2D);
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode) {
    // 当用户按下ESC键,我们设置window窗口的WindowShouldClose属性为true
    // 关闭应用程序
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
