//
// Created by hds on 17-11-1.
//

#ifndef GLTEST_LESSONONE_H
#define GLTEST_LESSONONE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init();
void display();
void timer(int time);
void mouse(int button, int state, int x, int y);

class LessonOne {
private:
public:
    void run(int argc, char *argv[]);
};


#endif //GLTEST_LESSONONE_H
