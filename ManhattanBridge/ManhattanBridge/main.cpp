#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

void WinterView();
void WinterSky();
void WinterRiver();

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Manhattan Bridge");
    glutInitWindowSize(320, 320);
    
    glutDisplayFunc(WinterView);
    
    glutMainLoop();

    return 0;
}

void WinterView()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    WinterRiver();
    
    WinterSky();
    
    glFlush();
}

void WinterSky()
{
    glBegin(GL_QUADS);
    glColor3ub(209, 207, 204);
    glVertex2f(-1.0f,1.0f);
    glColor3ub(109, 123, 147);
    glVertex2f(-1.0f,-0.15f);
    glVertex2f(1.0f,-0.15f);
    glVertex2f(1.0f,1.0f);
    glEnd();
}

void WinterRiver()
{
    glBegin(GL_QUADS);
    glColor3ub(162, 181, 236);
    glVertex2f(-1.0f,-0.27f);
    glVertex2f(-1.0f,-1.0f);
    glVertex2f(1.0f,-1.0f);
    glColor3ub(231,245,254);
    glVertex2f(1.0f,-0.27f);
    glEnd();

    glLineWidth(4);

    glBegin(GL_LINES);
    glColor3ub(205,237,241);
    glVertex2f(-0.9f,-0.9f);
    glVertex2f(0.6f,-0.3f);

    glVertex2f(-0.7f,-0.65f);
    glVertex2f(0.0f,-0.4f);

    glEnd();
    glTranslatef(0.5,0.2,0);
    glBegin(GL_LINES);
    glColor3ub(205,237,241);

    glVertex2f(-0.05f,-0.75f);
    glVertex2f(-0.4f,-0.9f);

    glEnd();

    glLoadIdentity();
}
