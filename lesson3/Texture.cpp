//
// Created by hds on 17-11-7.
//

#define GL_GLEXT_PROTOTYPES


#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glext.h>


#include "Texture.h"

using namespace Texture;


void Texture::Texture::createTexture() {

    init();
}

void Texture::init() {
    int argc = 1;
    char *argv[1] = {(char *) "Something"};
    glutInit(&argc, argv);
    //初始化 glut
    //清空颜色缓冲和深度缓冲
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glut显示模式:指定 RGB 颜色模式的窗口|指定单缓存窗口
    //https://baike.baidu.com/item/glutInitDisplayMode
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    //窗口位置，相对于屏幕 (200,200)
    glutInitWindowPosition(200, 200);
    //窗口大小
    glutInitWindowSize(300, 300);
    //窗口title
    glutCreateWindow("OpenGL 3D View");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //https://baike.baidu.com/item/glMatrixMode
    glMatrixMode(GL_PROJECTION);
    //可以将当前的可视空间设置为正投影空间
    glOrtho(-5, 5, -5, 5, 5, 15);
    glMatrixMode(GL_MODELVIEW);
    //视点转换
    //https://baike.baidu.com/item/gluLookAt
    gluLookAt(0, 1, 10, 0, 0, 0, 0, 1, 0);
    //画图
    glutDisplayFunc(display);
    //鼠标事件
//    glutMouseFunc(mouse);
    glutMainLoop();
}

void Texture::display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.5, 0);
//    glutWireTeapot(2);


    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    int bytePerline1 = 256 * 24 / 8;
    unsigned char *mipmapImage = new unsigned char[256 * bytePerline1];
    for (int i = 0; i < 256; i++)
        for (int j = 0; j < 256; j++) {
            mipmapImage[i * bytePerline1 + j * 3 + 0] = 255;
            mipmapImage[i * bytePerline1 + j * 3 + 1] = 255;
            mipmapImage[i * bytePerline1 + j * 3 + 2] = 0;
        }
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 200, 200, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, mipmapImage);
    glGenerateMipmap(GL_TEXTURE_2D);
//    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
}

