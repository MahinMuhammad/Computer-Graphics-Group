#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif
#include<math.h>
#include<cstdio>
# define PI 3.14159265358979323846
#include <cctype>

void WinterView();
void WinterSky();
void WinterRiver();

GLfloat snowPos = 0.0f;
GLfloat snowSpd = 0.05f;
void CircleSnow(GLfloat a, GLfloat b, GLdouble r,int R,int G,int B);
void snowFall();
void snowAnimation(int value);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Manhattan Bridge");
    glutInitWindowSize(320, 320);
    
    glutDisplayFunc(WinterView);
    glutPostRedisplay();
    glutTimerFunc(100, snowAnimation, 0);
    
    glutMainLoop();

    return 0;
}

void WinterView()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    WinterRiver();
    
    WinterSky();
    
    glPushMatrix();
    glTranslatef(0,snowPos,0);
    snowFall();
    glPopMatrix();
    
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

void CircleSnow(GLfloat a, GLfloat b, GLdouble r, int R, int G, int B)
{
    int i;
    GLfloat x=a;
    GLfloat y=b;
    GLdouble radius =r;
    int triangleAmount = 60;

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(R, G, B);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * sin(i *  twicePi / triangleAmount)),
            y + 2*(radius * cos(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void snowAnimation(int value)
{

    if(snowPos <-5)
        snowPos = -4;

    snowPos -= snowSpd;

    glutPostRedisplay();


    glutTimerFunc(100, snowAnimation, 0);
}



void snowFall()
{
    //CircleSnow(0,-0.5,0.01,190, 217, 244);'

    int cnt = 0;
    float posY = 0.99;

    for(int i=0; i<100; i++)
    {
        float posX = -1.5;

        for(int j=0; j<15; j++)
        {
            if(cnt%4==0)
            {
                posX +=0.33;
            }
            else if(cnt%3==0)
            {
                posX +=0.25;
            }
            else
            {
                posX +=0.15;
            }
            CircleSnow(posX,posY,0.008,240, 240, 240);
            CircleSnow(posX,posY,0.005,198, 222, 245);


            cnt++;

        }
        posY +=0.2;

    }

}


