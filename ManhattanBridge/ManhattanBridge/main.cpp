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

bool isNight = false;

GLfloat snowPos = 0.0f;
GLfloat snowSpd = 0.05f;
void CircleSnow(GLfloat a, GLfloat b, GLdouble r,int R,int G,int B);
void snowFall();
void snowAnimation(int value);
void Bridge();

GLfloat position_car1 = 0.0f, speed_car1 = 0.1f, rotation_car1 = 0.0f;
void animation_car1(int value);
void display_car1();

GLfloat position_car2 = 0.0f, speed_car2 = 0.1f, rotation_car2 = 0.0f;
void animation_car2(int value);
void display_car2();

GLfloat position_car3 = 0.0f, speed_car3 = 0.1f, rotation_car3 = 0.0f;
void animation_car3(int value);
void display_car3();

GLfloat position_car4 = 0.0f, speed_car4 = 0.1f, rotation_car4 = 0.0f;
void animation_car4(int value);
void display_car4();

GLfloat position_car5 = 0.0f, speed_car5 = 0.1f, rotation_car5 = 0.0f;
void animation_car5(int value);
void display_car5();


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Manhattan Bridge");
    glutInitWindowSize(320, 320);

    glutDisplayFunc(WinterView);
    glutPostRedisplay();
    glutTimerFunc(10, animation_car1,0);

    glutTimerFunc(10, animation_car2,0);

    glutTimerFunc(10, animation_car3,0);

    glutTimerFunc(10, animation_car4,0);

    glutTimerFunc(10, animation_car5,0);
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

    glTranslatef(0.0,-0.122,0);
    display_car1();
    display_car4();
    glLoadIdentity();

    glTranslatef(0.0,-0.134,0);
    display_car2();
    display_car3();
    display_car5();
    glLoadIdentity();

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



    //RIGHT PILLAR

    glBegin(GL_LINES);
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



void animation_car1(int value)
{

    if(position_car1 > 1.0)
    {
        position_car1 = -1.0f;
    }

    position_car1 += speed_car1;

    glutPostRedisplay();


    glutTimerFunc(200, animation_car1, 0);
}



void display_car1()
{

    glPushMatrix();
    glTranslatef(position_car1,0,0);


    glScalef(0.2,0.2,0);
    glBegin(GL_QUADS); // bus body
    glColor3ub(249,216,216);
    glVertex2f(-0.2f,0.1f);
    glVertex2f(-0.2f,-0.1f);
    glVertex2f(0.25f,-0.1f);
    glVertex2f(0.2f,0.1f);

    glEnd();

    glBegin(GL_QUADS); // design
    glColor3ub(253,174,174);
    glVertex2f(-0.06f,0.1f);
    glVertex2f(0.0f,-0.1f);
    glVertex2f(0.08f,-0.1f);
    glVertex2f(0.02f,0.1f);

    glEnd();


    glColor3ub(0,0,0) ;
    int i_car;

    GLfloat x_car=.15f;
    GLfloat y_car=-0.1f;
    GLfloat radius_car =.05f;
    int triangleAmount_car = 20;

    GLfloat twicePi_car = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN); //wheel 1
    glVertex2f(x_car, y_car);
    for(i_car = 0; i_car <= triangleAmount_car; i_car++)
    {
        glVertex2f(
            x_car + (radius_car * cos(i_car *  twicePi_car / triangleAmount_car)),
            y_car + (radius_car * sin(i_car * twicePi_car / triangleAmount_car))
        );
    }
    glEnd();


    glTranslatef(-0.25,0.0,0.0);
    glColor3ub(0,0,0) ;
    int j_car;

    GLfloat x_car1=.15f;
    GLfloat y_car1=-0.1f;
    GLfloat radius_car1 =.05f;
    int triangleAmount_car1 = 20;

    GLfloat twicePi_car1 = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN); //wheel 2
    glVertex2f(x_car, y_car);
    for(j_car = 0; j_car <= triangleAmount_car1; j_car++)
    {
        glVertex2f(
            x_car1 + (radius_car1 * cos(j_car *  twicePi_car1 / triangleAmount_car1)),
            y_car1 + (radius_car1 * sin(j_car * twicePi_car1 / triangleAmount_car1))
        );
    }
    glEnd();

    glLoadIdentity();


    glPopMatrix();



    glPushMatrix();
    glTranslatef(position_car1,0,0);


    glScalef(0.2,0.2,0);
    glBegin(GL_QUADS); // mirror
    if(!isNight)
    {
           glColor3ub(64,224,208);
    }
    if(isNight)
    {
        glColor3ub(241, 201, 8);
    }
    glVertex2f(-0.195f,0.08f);
    glVertex2f(-0.195f,0.0f);
    glVertex2f(0.219f,0.0f);
    glVertex2f(0.2f,0.08f);

    glEnd();

    glBegin(GL_QUADS); // back light
    glColor3ub(255,69,0);
    glVertex2f(-0.2f,-0.03f);
    glVertex2f(-0.2f,-0.06f);
    glVertex2f(-0.18f,-0.06f);
    glVertex2f(-0.18f,-0.03f);

    glEnd();

    glBegin(GL_QUADS); // head light
    glColor3ub(255,69,0);
    glVertex2f(0.21f,-0.03f);
    glVertex2f(0.21f,-0.06f);
    glVertex2f(0.24f,-0.06f);
    glVertex2f(0.234f,-0.03f);

    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);// mirror outline 1
    glColor3ub(0,0,0);
    glVertex2f(-0.195f,0.08f);
    glVertex2f(-0.195f,0.0f);

    glEnd();

    glBegin(GL_LINES);// mirror outline 2
    glColor3ub(0,0,0);
    glVertex2f(-0.195f,0.0f);
    glVertex2f(0.219f,0.0f);

    glEnd();

    glBegin(GL_LINES);// mirror outline 3
    glColor3ub(0,0,0);
    glVertex2f(0.219f,0.0f);
    glVertex2f(0.2f,0.08f);

    glEnd();

    glBegin(GL_LINES);// mirror outline 4
    glColor3ub(0,0,0);
    glVertex2f(-0.195f,0.08f);
    glVertex2f(0.2f,0.08f);

    glEnd();

    glBegin(GL_LINES);// mirror border 1
    glColor3ub(0,0,0);
    glVertex2f(-0.04f,0.08f);
    glVertex2f(-0.04f,0.00f);

    glEnd();

    glBegin(GL_LINES);// mirror border 2
    glColor3ub(0,0,0);
    glVertex2f(0.1f,0.08f);
    glVertex2f(0.1f,0.00f);

    glEnd();



    glPushMatrix();
    glTranslatef(-0.1,-0.1,0.0);
    glRotatef(rotation_car1,0.0,0.0,-0.1); // wheel 1 rotation

    glScalef(0.2,0.2,0);
    glLineWidth(5);
    glBegin(GL_LINES);//wheel line
    glColor3ub(249,216,216);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(249,216,216);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(249,216,216);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(249,216,216);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(249,216,216);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(249,216,216);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(249,216,216);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(249,216,216);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.03f);

    glEnd();

    glPopMatrix();
    rotation_car1 += 0.1f;


    glPushMatrix();
    glTranslatef(0.15,-0.1,0.0);
    glRotatef(rotation_car1,0.0,0.0,-0.1); // wheel 2 rotation

    glScalef(0.2,0.2,0);
    glBegin(GL_LINES);//wheel line
    glColor3ub(249,216,216);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(249,216,216);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(249,216,216);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(249,216,216);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(249,216,216);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(249,216,216);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(249,216,216);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(249,216,216);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.03f);

    glEnd();

    glPopMatrix();
    rotation_car1 += 0.1f;




    glPopMatrix();

}



void animation_car2(int value)
{

    if(position_car2 < -1.0)
    {
        position_car2 = 1.0f;
    }

    position_car2 -= speed_car2;

    glutPostRedisplay();


    glutTimerFunc(200, animation_car2, 0);
}



void display_car2()
{

    glPushMatrix();
    glTranslatef(position_car2,0,0);


    glScalef(0.1,0.1,0);
    glBegin(GL_QUADS); // car upper body
    glColor3ub(101,92,92);
    glVertex2f(-0.1f,0.2f);
    glVertex2f(-0.2f,0.1f);
    glVertex2f(0.2f,0.1f);
    glVertex2f(0.1f,0.2f);

    glEnd();

    glBegin(GL_QUADS); // car lower body
    glColor3ub(101,92,92);
    glVertex2f(-0.4f,0.1f);
    glVertex2f(-0.45f,-0.1f);
    glVertex2f(0.3f,-0.1f);
    glVertex2f(0.3f,0.1f);

    glEnd();


    glBegin(GL_QUADS); // car design
    glColor3ub(54,51,51);
    glVertex2f(-0.414f,0.05f);
    glVertex2f(-0.438f,-0.05f);
    glVertex2f(0.3f,-0.05f);
    glVertex2f(0.3f,0.05f);

    glEnd();



    glColor3ub(0,0,0) ;
    int i_car3;

    GLfloat x_car3=.15f;
    GLfloat y_car3=-0.1f;
    GLfloat radius_car3 =.06f;
    int triangleAmount_car3 = 20;

    GLfloat twicePi_car3 = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN); //wheel 1
    glVertex2f(x_car3, y_car3);
    for(i_car3 = 0; i_car3 <= triangleAmount_car3; i_car3++)
    {
        glVertex2f(
            x_car3 + (radius_car3 * cos(i_car3 *  twicePi_car3 / triangleAmount_car3)),
            y_car3 + (radius_car3 * sin(i_car3 * twicePi_car3 / triangleAmount_car3))
        );
    }
    glEnd();


    glTranslatef(-0.4,0.0,0.0);
    glColor3ub(0,0,0) ;
    int j_car4;

    GLfloat x_car4=.15f;
    GLfloat y_car4=-0.1f;
    GLfloat radius_car4 =.06f;
    int triangleAmount_car4 = 20;

    GLfloat twicePi_car4 = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN); //wheel 2
    glVertex2f(x_car4, y_car4);
    for(j_car4 = 0; j_car4 <= triangleAmount_car4; j_car4++)
    {
        glVertex2f(
            x_car4 + (radius_car4 * cos(j_car4 *  twicePi_car4 / triangleAmount_car4)),
            y_car4 + (radius_car4 * sin(j_car4 * twicePi_car4 / triangleAmount_car4))
        );
    }
    glEnd();

    glLoadIdentity();


    glPopMatrix();

    glPushMatrix();
    glTranslatef(position_car2,0,0);


    glScalef(0.1,0.1,0);
    glBegin(GL_QUADS); // car mirror
    if(!isNight)
    {
        glColor3ub(64,224,208);
        glVertex2f(-0.095f,0.19f);
        glVertex2f(-0.185f,0.1f);
        glVertex2f(0.185f,0.1f);
        glVertex2f(0.095f,0.19f);
    }
    if(isNight)
    {
        glColor3ub(250, 237, 172);
        glVertex2f(-0.095f,0.19f);
        glVertex2f(-0.185f,0.1f);
        glVertex2f(0.185f,0.1f);
        glVertex2f(0.095f,0.19f);
    }

    glEnd();

    glBegin(GL_LINES); // mirror line
    glColor3ub(0,0,0);
    glVertex2f(0.01f,0.19f);
    glVertex2f(0.0f,0.1f);

    glEnd();


    glBegin(GL_QUADS); // car headlight
    glColor3ub(255,99,71);
    glVertex2f(-0.423f,0.015f);
    glVertex2f(-0.431f,-0.015f);
    glVertex2f(-0.39f,-0.015f);
    glVertex2f(-0.39f,0.015f);

    glEnd();

    glBegin(GL_QUADS); // car back light
    glColor3ub(255,99,71);
    glVertex2f(0.285f,0.015f);
    glVertex2f(0.285f,-0.015f);
    glVertex2f(0.3f,-0.015f);
    glVertex2f(0.3f,0.015f);

    glEnd();


    glPushMatrix();
    glTranslatef(-0.25,-0.1,0.0);
    glRotatef(rotation_car1,0.0,0.0,0.1); // wheel 1 rotation

    glScalef(0.1,0.1,0);
    glLineWidth(5);
    glBegin(GL_LINES);//wheel line vertical
    glColor3ub(101,92,92);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line vertical
    glColor3ub(101,92,92);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line horizontal
    glColor3ub(101,92,92);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line horizontal
    glColor3ub(101,92,92);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(101,92,92);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(101,92,92);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(101,92,92);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(101,92,92);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.03f);

    glEnd();

    glPopMatrix();
    rotation_car1 += 0.1f;


    glPushMatrix();
    glTranslatef(0.15,-0.1,0.0);
    glRotatef(rotation_car1,0.0,0.0,0.1); // wheel 2 rotation

    glScalef(0.1,0.1,0);
    glBegin(GL_LINES);//wheel line
    glColor3ub(101,92,92);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(101,92,92);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(101,92,92);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(101,92,92);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(101,92,92);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(101,92,92);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(101,92,92);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(101,92,92);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.03f);

    glEnd();

    glPopMatrix();
    rotation_car1 += 0.1f;


    glPopMatrix();
}



void animation_car3(int value)
{

    if(position_car3 > 1.0)
    {
        position_car3 = -1.0f;
    }

    position_car3 += speed_car3;

    glutPostRedisplay();


    glutTimerFunc(300, animation_car3, 0);
}



void display_car3()
{

    glPushMatrix();
    glTranslatef(position_car3,0,0);


    glScalef(-0.1,0.1,0);
    glBegin(GL_QUADS); // car upper body
    glColor3ub(166,1,1);
    glVertex2f(-0.1f,0.2f);
    glVertex2f(-0.2f,0.1f);
    glVertex2f(0.2f,0.1f);
    glVertex2f(0.1f,0.2f);

    glEnd();

    glBegin(GL_QUADS); // car lower body
    glColor3ub(166,1,1);
    glVertex2f(-0.4f,0.1f);
    glVertex2f(-0.45f,-0.1f);
    glVertex2f(0.3f,-0.1f);
    glVertex2f(0.3f,0.1f);

    glEnd();



    glColor3ub(0,0,0) ;
    int i_car5;

    GLfloat x_car5=.15f;
    GLfloat y_car5=-0.1f;
    GLfloat radius_car5 =.06f;
    int triangleAmount_car5 = 20;

    GLfloat twicePi_car5 = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN); //wheel 1
    glVertex2f(x_car5, y_car5);
    for(i_car5 = 0; i_car5 <= triangleAmount_car5; i_car5++)
    {
        glVertex2f(
            x_car5 + (radius_car5 * cos(i_car5 *  twicePi_car5 / triangleAmount_car5)),
            y_car5 + (radius_car5 * sin(i_car5 * twicePi_car5 / triangleAmount_car5))
        );
    }
    glEnd();


    glTranslatef(-0.4,0.0,0.0);
    glColor3ub(0,0,0) ;
    int j_car6;

    GLfloat x_car6=.15f;
    GLfloat y_car6=-0.1f;
    GLfloat radius_car6 =.06f;
    int triangleAmount_car6 = 20;

    GLfloat twicePi_car6 = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN); //wheel 2
    glVertex2f(x_car6, y_car6);
    for(j_car6 = 0; j_car6 <= triangleAmount_car6; j_car6++)
    {
        glVertex2f(
            x_car6 + (radius_car6 * cos(j_car6 *  twicePi_car6 / triangleAmount_car6)),
            y_car6 + (radius_car6 * sin(j_car6 * twicePi_car6 / triangleAmount_car6))
        );
    }
    glEnd();

    glLoadIdentity();


    glPopMatrix();

    glPushMatrix();
    glTranslatef(position_car3,0,0);


    glScalef(-0.1,0.1,0);
    glBegin(GL_QUADS); // car mirror
    glColor3ub(64,224,208);
    glVertex2f(-0.095f,0.19f);
    glVertex2f(-0.185f,0.1f);
    glVertex2f(0.185f,0.1f);
    glVertex2f(0.095f,0.19f);

    glEnd();

    glBegin(GL_LINES); // mirror line
    glColor3ub(0,0,0);
    glVertex2f(0.01f,0.19f);
    glVertex2f(0.0f,0.1f);

    glEnd();


    glBegin(GL_QUADS); // car headlight
    glColor3ub(255,99,71);
    glVertex2f(-0.423f,0.015f);
    glVertex2f(-0.431f,-0.015f);
    glVertex2f(-0.39f,-0.015f);
    glVertex2f(-0.39f,0.015f);

    glEnd();

    glBegin(GL_QUADS); // car back light
    glColor3ub(255,99,71);
    glVertex2f(0.285f,0.015f);
    glVertex2f(0.285f,-0.015f);
    glVertex2f(0.3f,-0.015f);
    glVertex2f(0.3f,0.015f);

    glEnd();


    glPushMatrix();
    glTranslatef(-0.25,-0.1,0.0);
    glRotatef(rotation_car3,0.0,0.0,0.1); // wheel 1 rotation

    glScalef(-0.1,0.1,0);
    glLineWidth(5);
    glBegin(GL_LINES);//wheel line vertical
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line vertical
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line horizontal
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line horizontal
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.03f);

    glEnd();

    glPopMatrix();
    rotation_car3 += 0.1f;


    glPushMatrix();
    glTranslatef(0.15,-0.1,0.0);
    glRotatef(rotation_car3,0.0,0.0,0.1); // wheel 2 rotation

    glScalef(-0.1,0.1,0);
    glBegin(GL_LINES);//wheel line
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.03f);

    glEnd();

    glPopMatrix();
    rotation_car3 += 0.1f;


    glPopMatrix();

}



void animation_car4(int value)
{

    if(position_car4 < -1.0)
    {
        position_car4 = 1.0f;
    }

    position_car4 -= speed_car4;

    glutPostRedisplay();


    glutTimerFunc(400, animation_car4, 0);
}



void display_car4()
{


    glPushMatrix();
    glTranslatef(position_car4,0,0);


    glScalef(-0.2,0.2,0);
    glBegin(GL_QUADS); // bus body
    glColor3ub(175,161,161);
    glVertex2f(-0.2f,0.1f);
    glVertex2f(-0.2f,-0.1f);
    glVertex2f(0.25f,-0.1f);
    glVertex2f(0.2f,0.1f);

    glEnd();


    glColor3ub(0,0,0) ;
    int i_car;

    GLfloat x_car=.15f;
    GLfloat y_car=-0.1f;
    GLfloat radius_car =.05f;
    int triangleAmount_car = 20;

    GLfloat twicePi_car = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN); //wheel 1
    glVertex2f(x_car, y_car);
    for(i_car = 0; i_car <= triangleAmount_car; i_car++)
    {
        glVertex2f(
            x_car + (radius_car * cos(i_car *  twicePi_car / triangleAmount_car)),
            y_car + (radius_car * sin(i_car * twicePi_car / triangleAmount_car))
        );
    }
    glEnd();


    glTranslatef(-0.25,0.0,0.0);
    glColor3ub(0,0,0) ;
    int j_car;

    GLfloat x_car1=.15f;
    GLfloat y_car1=-0.1f;
    GLfloat radius_car1 =.05f;
    int triangleAmount_car1 = 20;

    GLfloat twicePi_car1 = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN); //wheel 2
    glVertex2f(x_car, y_car);
    for(j_car = 0; j_car <= triangleAmount_car1; j_car++)
    {
        glVertex2f(
            x_car1 + (radius_car1 * cos(j_car *  twicePi_car1 / triangleAmount_car1)),
            y_car1 + (radius_car1 * sin(j_car * twicePi_car1 / triangleAmount_car1))
        );
    }
    glEnd();

    glLoadIdentity();


    glPopMatrix();



    glPushMatrix();
    glTranslatef(position_car4,0,0);


    glScalef(-0.2,0.2,0);
    glBegin(GL_QUADS); // mirror
    glColor3ub(64,224,208);
    glVertex2f(-0.195f,0.08f);
    glVertex2f(-0.195f,0.0f);
    glVertex2f(0.219f,0.0f);
    glVertex2f(0.2f,0.08f);

    glEnd();

    glBegin(GL_QUADS); // back light
    glColor3ub(255,69,0);
    glVertex2f(-0.2f,-0.03f);
    glVertex2f(-0.2f,-0.06f);
    glVertex2f(-0.18f,-0.06f);
    glVertex2f(-0.18f,-0.03f);

    glEnd();

    glBegin(GL_QUADS); // head light
    glColor3ub(255,69,0);
    glVertex2f(0.21f,-0.03f);
    glVertex2f(0.21f,-0.06f);
    glVertex2f(0.24f,-0.06f);
    glVertex2f(0.234f,-0.03f);

    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);// mirror outline 1
    glColor3ub(0,0,0);
    glVertex2f(-0.195f,0.08f);
    glVertex2f(-0.195f,0.0f);

    glEnd();

    glBegin(GL_LINES);// mirror outline 2
    glColor3ub(0,0,0);
    glVertex2f(-0.195f,0.0f);
    glVertex2f(0.219f,0.0f);

    glEnd();

    glBegin(GL_LINES);// mirror outline 3
    glColor3ub(0,0,0);
    glVertex2f(0.219f,0.0f);
    glVertex2f(0.2f,0.08f);

    glEnd();

    glBegin(GL_LINES);// mirror outline 4
    glColor3ub(0,0,0);
    glVertex2f(-0.195f,0.08f);
    glVertex2f(0.2f,0.08f);

    glEnd();

    glBegin(GL_LINES);// mirror border 1
    glColor3ub(0,0,0);
    glVertex2f(-0.04f,0.08f);
    glVertex2f(-0.04f,0.00f);

    glEnd();

    glBegin(GL_LINES);// mirror border 2
    glColor3ub(0,0,0);
    glVertex2f(0.1f,0.08f);
    glVertex2f(0.1f,0.00f);

    glEnd();



    glPushMatrix();
    glTranslatef(-0.1,-0.1,0.0);
    glRotatef(rotation_car4,0.0,0.0,-0.1); // wheel 1 rotation

    glScalef(-0.2,0.2,0);
    glLineWidth(5);
    glBegin(GL_LINES);//wheel line
    glColor3ub(222,211,211);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(222,211,211);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(222,211,211);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(222,211,211);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(222,211,211);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(222,211,211);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(222,211,211);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(222,211,211);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.03f);

    glEnd();

    glPopMatrix();
    rotation_car4 += 0.1f;


    glPushMatrix();
    glTranslatef(0.15,-0.1,0.0);
    glRotatef(rotation_car4,0.0,0.0,-0.1); // wheel 2 rotation

    glScalef(-0.2,0.2,0);
    glBegin(GL_LINES);//wheel line
    glColor3ub(222,211,211);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(222,211,211);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(222,211,211);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(222,211,211);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(222,211,211);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(222,211,211);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(222,211,211);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(222,211,211);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.03f);

    glEnd();

    glPopMatrix();
    rotation_car4 += 0.1f;


    glPopMatrix();
}



void animation_car5(int value)
{

    if(position_car5 > 1.0)
    {
        position_car5 = -1.0f;
    }

    position_car5 += speed_car5;

    glutPostRedisplay();


    glutTimerFunc(100, animation_car5, 0);
}



void display_car5()
{

    glPushMatrix();
    glTranslatef(position_car5,0,0);


    glScalef(-0.1,0.1,0);
    glBegin(GL_QUADS); // car upper body
    glColor3ub(71,85,141);
    glVertex2f(-0.1f,0.2f);
    glVertex2f(-0.2f,0.1f);
    glVertex2f(0.2f,0.1f);
    glVertex2f(0.1f,0.2f);

    glEnd();

    glBegin(GL_QUADS); // car lower body
    glColor3ub(71,85,141);
    glVertex2f(-0.4f,0.1f);
    glVertex2f(-0.45f,-0.1f);
    glVertex2f(0.3f,-0.1f);
    glVertex2f(0.3f,0.1f);

    glEnd();


    glBegin(GL_QUADS); // car design
    glColor3ub(17,38,145);
    glVertex2f(-0.414f,0.05f);
    glVertex2f(-0.438f,-0.05f);
    glVertex2f(0.3f,-0.05f);
    glVertex2f(0.3f,0.05f);

    glEnd();



    glColor3ub(0,0,0) ;
    int i_car5;

    GLfloat x_car5=.15f;
    GLfloat y_car5=-0.1f;
    GLfloat radius_car5 =.06f;
    int triangleAmount_car5 = 20;

    GLfloat twicePi_car5 = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN); //wheel 1
    glVertex2f(x_car5, y_car5);
    for(i_car5 = 0; i_car5 <= triangleAmount_car5; i_car5++)
    {
        glVertex2f(
            x_car5 + (radius_car5 * cos(i_car5 *  twicePi_car5 / triangleAmount_car5)),
            y_car5 + (radius_car5 * sin(i_car5 * twicePi_car5 / triangleAmount_car5))
        );
    }
    glEnd();


    glTranslatef(-0.4,0.0,0.0);
    glColor3ub(0,0,0) ;
    int j_car6;

    GLfloat x_car6=.15f;
    GLfloat y_car6=-0.1f;
    GLfloat radius_car6 =.06f;
    int triangleAmount_car6 = 20;

    GLfloat twicePi_car6 = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN); //wheel 2
    glVertex2f(x_car6, y_car6);
    for(j_car6 = 0; j_car6 <= triangleAmount_car6; j_car6++)
    {
        glVertex2f(
            x_car6 + (radius_car6 * cos(j_car6 *  twicePi_car6 / triangleAmount_car6)),
            y_car6 + (radius_car6 * sin(j_car6 * twicePi_car6 / triangleAmount_car6))
        );
    }
    glEnd();

    glLoadIdentity();


    glPopMatrix();

    glPushMatrix();
    glTranslatef(position_car5,0,0);


    glScalef(-0.1,0.1,0);
    glBegin(GL_QUADS); // car mirror
    glColor3ub(64,224,208);
    glVertex2f(-0.095f,0.19f);
    glVertex2f(-0.185f,0.1f);
    glVertex2f(0.185f,0.1f);
    glVertex2f(0.095f,0.19f);

    glEnd();

    glBegin(GL_LINES); // mirror line
    glColor3ub(0,0,0);
    glVertex2f(0.01f,0.19f);
    glVertex2f(0.0f,0.1f);

    glEnd();


    glBegin(GL_QUADS); // car headlight
    glColor3ub(255,99,71);
    glVertex2f(-0.423f,0.015f);
    glVertex2f(-0.431f,-0.015f);
    glVertex2f(-0.39f,-0.015f);
    glVertex2f(-0.39f,0.015f);

    glEnd();

    glBegin(GL_QUADS); // car back light
    glColor3ub(255,99,71);
    glVertex2f(0.285f,0.015f);
    glVertex2f(0.285f,-0.015f);
    glVertex2f(0.3f,-0.015f);
    glVertex2f(0.3f,0.015f);

    glEnd();


    glPushMatrix();
    glTranslatef(-0.25,-0.1,0.0);
    glRotatef(rotation_car5,0.0,0.0,0.1); // wheel 1 rotation

    glScalef(-0.1,0.1,0);
    glLineWidth(5);
    glBegin(GL_LINES);//wheel line vertical
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line vertical
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line horizontal
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line horizontal
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.03f);

    glEnd();

    glPopMatrix();
    rotation_car5 += 0.1f;


    glPushMatrix();
    glTranslatef(0.15,-0.1,0.0);
    glRotatef(rotation_car5,0.0,0.0,0.1); // wheel 2 rotation

    glScalef(-0.1,0.1,0);
    glBegin(GL_LINES);//wheel line
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.0f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.03f,-0.03f);

    glEnd();

    glBegin(GL_LINES);//wheel line slanted
    glColor3ub(166,1,1);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.03f,0.03f);

    glEnd();

    glPopMatrix();
    rotation_car5 += 0.1f;


    glPopMatrix();
}



