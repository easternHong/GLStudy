//
// Created by hds on 17-11-1.
//

#include "LessonOne.h"

bool mouseisdown = false;

bool loopr = false;

int mx, my;

int ry = 30;

int rx = 30;

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            mouseisdown = true;
            loopr = false;
        } else
            mouseisdown = false;
    }
    if (button == GLUT_RIGHT_BUTTON)
        if (state == GLUT_DOWN) {
            loopr = true;
            glutTimerFunc(200, timer, 0);
        }
}


void timer(int time) {
    ry -= 5;
    glutPostRedisplay();                 //marks the current window as needing to be redisplayed.
    if (loopr)
        glutTimerFunc(static_cast<unsigned int>(time), timer, 0);
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //https://baike.baidu.com/item/glMatrixMode
    glMatrixMode(GL_PROJECTION);
    //可以将当前的可视空间设置为正投影空间
    glOrtho(-5, 5, -5, 5, 5, 15);
    glMatrixMode(GL_MODELVIEW);
    //视点转换
    //https://baike.baidu.com/item/gluLookAt
    gluLookAt(0, 1, 10, 0, 0, 0, 0, 1, 0);
}

void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 0.5, 0);
//    glutWireTeapot(2);
////    glutFullScreen();//全屏
//    glFlush();
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex3d(-0.5, -0.5, 0.5); //点P1,左下角
    glVertex3d(-0.5, 0.5, 0.5);  //点P2,左上角
    glVertex3d(0.5, 0.5, 0.5);   //点P3,右上角
    glVertex3d(0.5, -0.5, 0.5); //点P4,右下角
    glEnd();
    glFlush();
}

void LessonOne::run(int argc, char *argv[]) {
    //初始化 glut
    glutInit(&argc, argv);
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
    init();
    //画图
    glutDisplayFunc(display);
    //鼠标事件
    glutMouseFunc(mouse);
    glutMainLoop();
}

