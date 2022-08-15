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
void Bridge();

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

    Bridge();
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


void Bridge()
{
    //UP TO DOWN
    //x-axis Rod-1
    glBegin(GL_QUADS);
    glColor3ub(81, 78, 82);
    glVertex2f(-1.0f,-0.15f);
    glVertex2f(-1.0f,-0.16f);
    glVertex2f(1.0f,-0.16f);
    glVertex2f(1.0f,-0.15f);
    glEnd();

    //Road
    glBegin(GL_QUADS);
    glColor3ub(81, 78, 82);
    glVertex2f(-1.0f,-0.16f);
    glVertex2f(-1.0f,-0.18f);
    glVertex2f(1.0f,-0.18f);
    glVertex2f(1.0f,-0.16f);
    glEnd();

    //x-axis Rod-2
    glBegin(GL_QUADS);
    glColor3ub(53, 35, 30);
    glVertex2f(-1.0f,-0.18f);
    glVertex2f(-1.0f,-0.2f);
    glVertex2f(1.0f,-0.2f);
    glVertex2f(1.0f,-0.18f);
    glEnd();

    //x-axis Rod-3
    glBegin(GL_QUADS);
    glColor3ub(193, 191, 194);
    glVertex2f(-1.0f,-0.2f);
    glVertex2f(-1.0f,-0.21f);
    glVertex2f(1.0f,-0.21f);
    glVertex2f(1.0f,-0.2f);
    glEnd();

    //x-axis Rod-4
    glBegin(GL_QUADS);
    glColor3ub(112, 111, 109);
    glVertex2f(-1.0f,-0.21f);
    glVertex2f(-1.0f,-0.22f);
    glVertex2f(1.0f,-0.22f);
    glVertex2f(1.0f,-0.21f);
    glEnd();

    //x-axis Rod-5
    glBegin(GL_QUADS);
    glColor3ub(21, 19, 24);
    glVertex2f(-1.0f,-0.22f);
    glVertex2f(-1.0f,-0.24f);
    glVertex2f(1.0f,-0.24f);
    glVertex2f(1.0f,-0.22f);
    glEnd();

    //x-axis Rod-6
    glBegin(GL_QUADS);
    glColor3ub(62, 43, 41);
    glVertex2f(-1.0f,-0.24f);
    glVertex2f(-1.0f,-0.26f);
    glVertex2f(1.0f,-0.26f);
    glVertex2f(1.0f,-0.24f);
    glEnd();

    //x-axis Rod-7
    glBegin(GL_QUADS);
    glColor3ub(179, 170, 161);
    glVertex2f(-1.0f,-0.26f);
    glVertex2f(-1.0f,-0.27f);
    glVertex2f(1.0f,-0.27f);
    glVertex2f(1.0f,-0.26f);
    glEnd();



    //LEFT TO RIGHT
    //y-axis rod-1
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();

    //y-axis rod-2
    glTranslatef(0.1,0,0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-3
    glTranslatef(0.2,0,0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-4
    glTranslatef(0.3,0,0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-5
    glTranslatef(0.4,0,0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-6
    glTranslatef(0.5,0,0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-7
    glTranslatef(0.6,0,0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-8
    glTranslatef(0.7,0,0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-9
    glTranslatef(0.8,0,0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-10
    glTranslatef(0.9,0,0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-11
    glTranslatef(1.0,0,0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-12
    glTranslatef(1.1,0,0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-13
    glTranslatef(1.2,0,0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-14
    glTranslatef(1.3,0,0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-15
    glTranslatef(1.4,0,0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-16
    glTranslatef(1.5,0,0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-17
    glTranslatef(1.6,0,0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-18
    glTranslatef(1.7,0,0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-19
    glTranslatef(1.8,0,0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();
    glLoadIdentity();

    //y-axis rod-20
    glTranslatef(1.9,0,0);
    glBegin(GL_LINES);
    glColor3ub(115, 108, 102);
    glVertex2f(-0.95f,-0.21f);
    glVertex2f(-0.95f,-0.27f);
    glEnd();
    glLoadIdentity();



    //LEFT TO RIGHT
    //Diagonal rod-1
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f,-0.265f);
    glVertex2f(-0.85f,-0.215f);
    glEnd();

    //Diagonal rod-2
    glTranslatef(0.2,0,0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f,-0.265f);
    glVertex2f(-0.85f,-0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-3
    glTranslatef(0.4,0,0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f,-0.265f);
    glVertex2f(-0.85f,-0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-4
    glTranslatef(0.6,0,0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f,-0.265f);
    glVertex2f(-0.85f,-0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-5
    glTranslatef(0.8,0,0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f,-0.265f);
    glVertex2f(-0.85f,-0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-6
    glTranslatef(1.0,0,0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f,-0.265f);
    glVertex2f(-0.85f,-0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-7
    glTranslatef(1.2,0,0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f,-0.265f);
    glVertex2f(-0.85f,-0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-8
    glTranslatef(1.4,0,0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f,-0.265f);
    glVertex2f(-0.85f,-0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-9
    glTranslatef(1.6,0,0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f,-0.265f);
    glVertex2f(-0.85f,-0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-10
    glTranslatef(1.8,0,0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(-0.95f,-0.265f);
    glVertex2f(-0.85f,-0.215f);
    glEnd();
    glLoadIdentity();



    //RIGHT TO LEFT
    //Diagonal rod-1
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f,-0.265f);
    glVertex2f(0.95f,-0.215f);
    glEnd();

    //Diagonal rod-2
    glTranslatef(-0.2,0,0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f,-0.265f);
    glVertex2f(0.95f,-0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-3
    glTranslatef(-0.4,0,0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f,-0.265f);
    glVertex2f(0.95f,-0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-4
    glTranslatef(-0.6,0,0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f,-0.265f);
    glVertex2f(0.95f,-0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-5
    glTranslatef(-0.8,0,0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f,-0.265f);
    glVertex2f(0.95f,-0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-6
    glTranslatef(-1.0,0,0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f,-0.265f);
    glVertex2f(0.95f,-0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-7
    glTranslatef(-1.2,0,0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f,-0.265f);
    glVertex2f(0.95f,-0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-8
    glTranslatef(-1.4,0,0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f,-0.265f);
    glVertex2f(0.95f,-0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-9
    glTranslatef(-1.6,0,0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f,-0.265f);
    glVertex2f(0.95f,-0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-10
    glTranslatef(-1.8,0,0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f,-0.265f);
    glVertex2f(0.95f,-0.215f);
    glEnd();
    glLoadIdentity();

    //Diagonal rod-11
    glTranslatef(-2.0,0,0);
    glBegin(GL_LINES);
    glColor3ub(129, 131, 136);
    glVertex2f(1.05f,-0.265f);
    glVertex2f(0.95f,-0.215f);
    glEnd();
    glLoadIdentity();



    //LEFT PILLAR
    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.83f,-0.5f);
    glVertex2f(-0.8f,0.4f);
    glEnd();

    glTranslatef(0.03,0,0);
    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.83f,-0.5f);
    glVertex2f(-0.8f,0.4f);
    glEnd();
    glLoadIdentity();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.7f,-0.5f);
    glVertex2f(-0.73f,0.4f);
    glEnd();

    glTranslatef(-0.03,0,0);
    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.7f,-0.5f);
    glVertex2f(-0.73f,0.4f);
    glEnd();
    glLoadIdentity();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.8f,0.4f);
    glVertex2f(-0.73f,0.4f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.83f,-0.5f);
    glVertex2f(-0.7f,-0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.83f,-0.5f);
    glVertex2f(-0.7f,-0.35f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.7f,-0.5f);
    glVertex2f(-0.83f,-0.35f);
    glEnd();

    glTranslatef(0,0.15,0);
    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.83f,-0.5f);
    glVertex2f(-0.7f,-0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.83f,-0.5f);
    glVertex2f(-0.71f,-0.35f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.7f,-0.5f);
    glVertex2f(-0.82f,-0.35f);
    glEnd();
    glLoadIdentity();

    glTranslatef(0,0.3,0);
    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.82f,-0.5f);
    glVertex2f(-0.71f,-0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.82f,-0.5f);
    glVertex2f(-0.715f,-0.35f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.71f,-0.5f);
    glVertex2f(-0.815f,-0.35f);
    glEnd();
    glLoadIdentity();

    glTranslatef(0,0.45,0);
    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.81f,-0.5f);
    glVertex2f(-0.72f,-0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.82f,-0.5f);
    glVertex2f(-0.715f,-0.35f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.71f,-0.5f);
    glVertex2f(-0.815f,-0.35f);
    glEnd();
    glLoadIdentity();

    glTranslatef(0,0.6,0);
    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.81f,-0.5f);
    glVertex2f(-0.72f,-0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.81f,-0.5f);
    glVertex2f(-0.72f,-0.35f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.72f,-0.5f);
    glVertex2f(-0.8f,-0.35f);
    glEnd();
    glLoadIdentity();

    glTranslatef(0,0.75,0);
    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.8f,-0.5f);
    glVertex2f(-0.73f,-0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.81f,-0.5f);
    glVertex2f(-0.73f,-0.35f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(-0.72f,-0.5f);
    glVertex2f(-0.8f,-0.35f);
    glEnd();
    glLoadIdentity();

    glBegin(GL_QUADS);
    glColor3ub(123, 98, 92);
    glVertex2f(-0.85f,-0.5f);
    glVertex2f(-0.85f,-0.55f);
    glVertex2f(-0.68f,-0.55f);
    glVertex2f(-0.68f,-0.5f);glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.83f,-0.5f);
    glVertex2f(0.8f,0.4f);
    glEnd();

    glTranslatef(-0.03,0,0);
    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.83f,-0.5f);
    glVertex2f(0.8f,0.4f);
    glEnd();
    glLoadIdentity();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.7f,-0.5f);
    glVertex2f(0.73f,0.4f);
    glEnd();

    glTranslatef(0.03,0,0);
    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.7f,-0.5f);
    glVertex2f(0.73f,0.4f);
    glEnd();
    glLoadIdentity();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.8f,0.4f);
    glVertex2f(0.73f,0.4f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.83f,-0.5f);
    glVertex2f(0.7f,-0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.83f,-0.5f);
    glVertex2f(0.7f,-0.35f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.7f,-0.5f);
    glVertex2f(0.83f,-0.35f);
    glEnd();

    glTranslatef(0,0.15,0);
    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.83f,-0.5f);
    glVertex2f(0.7f,-0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.83f,-0.5f);
    glVertex2f(0.71f,-0.35f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.7f,-0.5f);
    glVertex2f(0.82f,-0.35f);
    glEnd();
    glLoadIdentity();

    glTranslatef(0,0.3,0);
    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.82f,-0.5f);
    glVertex2f(0.71f,-0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.82f,-0.5f);
    glVertex2f(0.715f,-0.35f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.71f,-0.5f);
    glVertex2f(0.815f,-0.35f);
    glEnd();
    glLoadIdentity();

    glTranslatef(0,0.45,0);
    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.81f,-0.5f);
    glVertex2f(0.72f,-0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.82f,-0.5f);
    glVertex2f(0.715f,-0.35f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.71f,-0.5f);
    glVertex2f(0.815f,-0.35f);
    glEnd();
    glLoadIdentity();

    glTranslatef(0,0.6,0);
    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.81f,-0.5f);
    glVertex2f(0.72f,-0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.81f,-0.5f);
    glVertex2f(0.72f,-0.35f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.72f,-0.5f);
    glVertex2f(0.8f,-0.35f);
    glEnd();
    glLoadIdentity();

    glTranslatef(0,0.75,0);
    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.8f,-0.5f);
    glVertex2f(0.73f,-0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.81f,-0.5f);
    glVertex2f(0.73f,-0.35f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(182, 182, 183);
    glVertex2f(0.72f,-0.5f);
    glVertex2f(0.8f,-0.35f);
    glEnd();
    glLoadIdentity();

    glBegin(GL_QUADS);
    glColor3ub(123, 98, 92);
    glVertex2f(0.85f,-0.5f);
    glVertex2f(0.85f,-0.55f);
    glVertex2f(0.68f,-0.55f);
    glVertex2f(0.68f,-0.5f);
    glEnd();
    glEnd();



    //RIGHT PILLAR




    //CURVED ROD
    glBegin(GL_LINES);
    glColor3ub(177, 177, 184);
    glVertex2f(-0.73f,0.4f);
    glVertex2f(-0.6f,0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(177, 177, 184);
    glVertex2f(-0.6f,0.2f);
    glVertex2f(-0.4f,0.05f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(177, 177, 184);
    glVertex2f(-0.4f,0.05f);
    glVertex2f(-0.15f,-0.05f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(177, 177, 184);
    glVertex2f(-0.15f,-0.05f);
    glVertex2f(-0.05f,-0.07f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(177, 177, 184);
    glVertex2f(-0.05f,-0.07f);
    glVertex2f(0.0f,-0.07f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(177, 177, 184);
    glVertex2f(-0.8f,0.4f);
    glVertex2f(-0.9f,0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(177, 177, 184);
    glVertex2f(-0.9f,0.2f);
    glVertex2f(-1.0f,0.05f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(177, 177, 184);
    glVertex2f(0.73f,0.4f);
    glVertex2f(0.6f,0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(177, 177, 184);
    glVertex2f(0.6f,0.2f);
    glVertex2f(0.4f,0.05f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(177, 177, 184);
    glVertex2f(0.4f,0.05f);
    glVertex2f(0.15f,-0.05f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(177, 177, 184);
    glVertex2f(0.15f,-0.05f);
    glVertex2f(0.05f,-0.07f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(177, 177, 184);
    glVertex2f(0.05f,-0.07f);
    glVertex2f(0.0f,-0.07f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(177, 177, 184);
    glVertex2f(0.8f,0.4f);
    glVertex2f(0.9f,0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(177, 177, 184);
    glVertex2f(0.9f,0.2f);
    glVertex2f(1.0f,0.05f);
    glEnd();



    //RODS CONNECTED TO CURVED ROD
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(121, 121, 125);
    glVertex2f(-0.95f,-0.18f);
    glVertex2f(-0.95f,0.13f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(121, 121, 125);
    glVertex2f(-0.85f,-0.18f);
    glVertex2f(-0.85f,0.3f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(121, 121, 125);
    glVertex2f(-0.65f,-0.18f);
    glVertex2f(-0.65f,0.27f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(121, 121, 125);
    glVertex2f(-0.55f,-0.18f);
    glVertex2f(-0.55f,0.17f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(121, 121, 125);
    glVertex2f(-0.45f,-0.18f);
    glVertex2f(-0.45f,0.09f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(121, 121, 125);
    glVertex2f(-0.35f,-0.18f);
    glVertex2f(-0.35f,0.04f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(121, 121, 125);
    glVertex2f(-0.25f,-0.18f);
    glVertex2f(-0.25f,0.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(121, 121, 125);
    glVertex2f(-0.15f,-0.18f);
    glVertex2f(-0.15f,-0.05f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(121, 121, 125);
    glVertex2f(-0.05f,-0.18f);
    glVertex2f(-0.05f,-0.07f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(121, 121, 125);
    glVertex2f(0.95f,-0.18f);
    glVertex2f(0.95f,0.13f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(121, 121, 125);
    glVertex2f(0.85f,-0.18f);
    glVertex2f(0.85f,0.3f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(121, 121, 125);
    glVertex2f(0.65f,-0.18f);
    glVertex2f(0.65f,0.27f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(121, 121, 125);
    glVertex2f(0.55f,-0.18f);
    glVertex2f(0.55f,0.17f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(121, 121, 125);
    glVertex2f(0.45f,-0.18f);
    glVertex2f(0.45f,0.09f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(121, 121, 125);
    glVertex2f(0.35f,-0.18f);
    glVertex2f(0.35f,0.04f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(121, 121, 125);
    glVertex2f(0.25f,-0.18f);
    glVertex2f(0.25f,0.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(121, 121, 125);
    glVertex2f(0.15f,-0.18f);
    glVertex2f(0.15f,-0.05f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(121, 121, 125);
    glVertex2f(0.05f,-0.18f);
    glVertex2f(0.05f,-0.07f);
    glEnd();
}



