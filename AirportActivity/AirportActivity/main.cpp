#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

void display(){
    glClearColor(0.5f, 0.7f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3ub(94, 94, 94);
    glRectf(-1.0, -0.55, 1.0, -1.0);
    
    glColor3ub(173, 173, 173);
    glRectf(-1.0, 0.0, 1.0, -0.55);
    
    glColor3ub(255, 255, 255);
    glRectf(-0.05, 0.4, 0.7, 0.0);
    glRectf(0.0, 0.5, 0.6, 0.4);
    glRectf(0.0, 0.55, 0.3, 0.5);
    
    glColor3ub(63, 104, 255);
    glRectf(0.3, 0.3, 0.5, 0.0);
    glRectf(-0.02, 0.3, 0.27, 0.05);
    glRectf(0.52, 0.3, 0.67, 0.05);
    glRectf(0.02, 0.53, 0.28, 0.5);
    
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutCreateWindow("Airport");
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
