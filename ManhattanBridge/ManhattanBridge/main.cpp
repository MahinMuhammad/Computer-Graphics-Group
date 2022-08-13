#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

void display()
{

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Manhattan Bridge");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
