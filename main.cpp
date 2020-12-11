#include <cstdio>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <bits/stdc++.h>

# define PI 3.14159265358979323846

GLfloat position_sun = 0.0f;
GLfloat position_sun_down = 0.0f;
GLfloat speed_sun = 0.0175f;

GLfloat position_moon = 0.0f;
GLfloat position_moon_down = 0.0f;
GLfloat speed_moon = 0.0175f;

GLfloat position_cloud = 0.0f;
GLfloat speed_cloud = 0.0175f;

GLfloat rain_position1 = 0.0f;
GLfloat rain_speed1 = 0.02f;
GLfloat rain_position2 = 0.0f;
GLfloat rain_speed2 = 0.01f;

GLfloat position_ship = 0.0f;
GLfloat speed_ship = 0.01f;



void load_Start();
void load_DayBack();



void Idle()
{
    glutPostRedisplay();
}


void update_sun(int value)
{

    if(position_sun <-1.0)
    {
        position_sun = 1.0f;
        position_sun_down = 1.0f;
    }
    position_sun -= speed_sun;
    position_sun_down -= speed_sun/3;
	//glutPostRedisplay();
	glutTimerFunc(135, update_sun, 0);
}

void update_ship(int value)
{

   if(position_ship <-1.0)
    {
        position_ship = 1.0f;
    }
    position_ship -= speed_ship;
	//glutPostRedisplay();
	glutTimerFunc(100, update_ship, 0);


}

void update_moon(int value)
{
    if(position_moon <-1.0)
    {
        position_moon = 1.0f;
        position_moon_down = 1.0f;
    }
    position_moon -= speed_moon;
    position_moon_down -= speed_moon/3;
	//glutPostRedisplay();
	glutTimerFunc(49, update_moon, 0);
}

void update_cloud(int value)
{

    if(position_cloud <-1.0)
    {
        position_cloud = 1.0f;
    }
    position_cloud -= speed_sun;
	//glutPostRedisplay();
	glutTimerFunc(100, update_cloud, 0);
}

void update_rain(int value)
{

     if(rain_position1 <-1.0)
        rain_position1 = 0.2f;

    rain_position1 -= rain_speed1;

    //glutPostRedisplay();

    if(rain_position2 >1.0)
        rain_position2 = -1.0f;

    rain_position2 += rain_speed2;

    //glutPostRedisplay();

    glutTimerFunc(30, update_rain, 0);
}

void load_Restart(int x)
{
    glutDisplayFunc(load_Start);
}

void ship()
{
    glPushMatrix();
    glTranslatef(-position_ship, 0.0f, 0.0f);

    glColor3ub(153, 51, 51);
    glBegin(GL_POLYGON);
    glVertex2f(-0.65,0.17);
    glVertex2f(-0.55,0.08);
    glVertex2f(-0.4,0.08);
    glVertex2f(-0.3,0.17);
    glEnd();

    glColor3ub(57, 20, 20);
    glBegin(GL_QUADS);
    glVertex2f(-0.55,0.17);
    glVertex2f(-0.55,0.25);
    glVertex2f(-0.4,0.25);
    glVertex2f(-0.4,0.17);
    glEnd();


	glLoadIdentity();
	glPopMatrix();


}

void rain()
{
    glPushMatrix();
    glTranslatef(rain_position2,rain_position1, 0.0f);

    // Rain line1
    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();


    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glLoadIdentity();

    glPopMatrix();
    glTranslatef(0,0.4,0);


    glPushMatrix();
    glTranslatef(rain_position2,rain_position1, 0.0f);
    // Rain line2
    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();


    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glLoadIdentity();



    glPopMatrix();




    glTranslatef(0,-0.4,0);



    glPushMatrix();
    glTranslatef(rain_position2,rain_position1, 0.0f);
    // Rain line3
    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();


    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glLoadIdentity();


    glPopMatrix();



    glTranslatef(0,-0.8,0);



    glPushMatrix();
    glTranslatef(rain_position2,rain_position1, 0.0f);
    // Rain line4
    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();


    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();


    glPopMatrix();

    glLoadIdentity();


}

void Sun()
{
    glPushMatrix();
    glTranslatef(-position_sun, 0.0/*position_sun_down*/, 0.0f);
    int is;
	GLfloat xs=-0.8f;
	GLfloat ys=0.8f;
	GLfloat radiuss =.17f;
	int triangleAmounts = 100;
	GLfloat twicePis = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 209, 26);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
	glEnd();
	glPopMatrix();
}

void Moon()
{
    glPushMatrix();
    glTranslatef(-position_moon, 0.0/*position_moon_down*/, 0.0f);
    int is;
    GLfloat xs=-0.8f;
	GLfloat ys=0.8f;
	GLfloat radiuss =.1f;
    int triangleAmounts = 100;
    GLfloat twicePis = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 204);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
    glEnd();

    glTranslatef(0.04,0.05,0.0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(44,62,80);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
    glEnd();
    glLoadIdentity();
    glPopMatrix();
}

void Cloud()
{
    glPushMatrix();
    glTranslatef(-position_cloud, 0.0f, 0.0f);
    float xC,yC,radiusC,triangleAmountC,twicePiC;
    xC= -0.4f, yC= 0.7f, radiusC =.09f;
    triangleAmountC = 20;
    twicePiC = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(230, 255, 255);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC;iC++)
    {
        glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
    }
	glEnd();
	xC= -0.3f, yC= 0.7f, radiusC =.09f;
    triangleAmountC = 20;
    twicePiC = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC;iC++)
    {
        glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
    }
	glEnd();
	xC= -0.37f, yC= 0.67f, radiusC =.09f;
    triangleAmountC = 20;
    twicePiC = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC;iC++)
    {
        glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
    }
	glEnd();


	glTranslatef(0.5f,0.1,0);
	xC= -0.4f, yC= 0.7f, radiusC =.09f;
    triangleAmountC = 20;
    twicePiC = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(230, 255, 255);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC;iC++)
    {
        glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
    }
	glEnd();
	xC= -0.3f, yC= 0.7f, radiusC =.09f;
    triangleAmountC = 20;
    twicePiC = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC;iC++)
    {
        glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
    }
	glEnd();
	xC= -0.37f, yC= 0.67f, radiusC =.09f;
    triangleAmountC = 20;
    twicePiC = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC;iC++)
    {
        glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
    }
	glEnd();

	glTranslatef(0.5f,-0.19,0);
	xC= -0.4f, yC= 0.7f, radiusC =.09f;
    triangleAmountC = 20;
    twicePiC = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(230, 255, 255);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC;iC++)
    {
        glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
    }
	glEnd();
	xC= -0.3f, yC= 0.7f, radiusC =.09f;
    triangleAmountC = 20;
    twicePiC = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC;iC++)
    {
        glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
    }
	glEnd();
	xC= -0.37f, yC= 0.67f, radiusC =.09f;
    triangleAmountC = 20;
    twicePiC = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(204, 255, 255);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC;iC++)
    {
        glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
    }
	glEnd();
	glLoadIdentity();
	glPopMatrix();
}

void cottage()
{
    glBegin(GL_POLYGON);
    glColor3ub(156, 139, 102);

    glVertex2f(-0.7,-0.5);
    glVertex2f(-0.6,-0.35);
    glVertex2f(-0.4,-0.35);
    glVertex2f(-0.3,-0.5);
    glEnd();

}

void tree()
{

    glBegin(GL_QUADS);
    glColor3ub(156, 139, 102);

    glVertex2f(0.8, -0.6f);
    glVertex2f(0.75, -0.6f);
    glVertex2f(0.75, -0.9f);
    glVertex2f(0.8, -0.9f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(36, 211, 47);
    glVertex2f(0.65,-0.6);
    glVertex2f(0.9,-0.6);
    glVertex2f(0.775,-0.4);
    glEnd();

    glTranslatef(0,0.04,0);

    glBegin(GL_TRIANGLES);
    glColor3ub(36, 211, 47);
    glVertex2f(0.65,-0.6);
    glVertex2f(0.9,-0.6);
    glVertex2f(0.775,-0.4);
    glEnd();




/*
    glTranslatef(-1.6,0,0);

    glBegin(GL_QUADS);
    glColor3ub(156, 139, 102);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(35, 174, 43);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(36, 211, 47);

    glEnd();*/

    glLoadIdentity();
}

void Day_Sky()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 153, 255);
    glVertex2f(-1.0, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, .95f);
    glVertex2f(-1.0f, .95f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(26, 163, 255);
    glVertex2f(-1.0, .95f);
    glVertex2f(1.0f, .95f);
    glVertex2f(1.0f, .90f);
    glVertex2f(-1.0f, .90f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(51, 173, 255);
    glVertex2f(-1.0, .90f);
    glVertex2f(1.0f, .90f);
    glVertex2f(1.0f, .85f);
    glVertex2f(-1.0f, .85f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(77, 184, 255);
    glVertex2f(-1.0, .85f);
    glVertex2f(1.0f, .85f);
    glVertex2f(1.0f, .80f);
    glVertex2f(-1.0f, .80f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 194, 255);
    glVertex2f(-1.0, .80f);
    glVertex2f(1.0f, .80f);
    glVertex2f(1.0f, .70f);
    glVertex2f(-1.0f, .70f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 204, 255);
    glVertex2f(-1.0, .70f);
    glVertex2f(1.0f, .70f);
    glVertex2f(1.0f, .60f);
    glVertex2f(-1.0f, .60f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(153, 214, 255);
    glVertex2f(-1.0, .60f);
    glVertex2f(1.0f, .60f);
    glVertex2f(1.0f, .40f);
    glVertex2f(-1.0f, .40f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 224, 255);
    glVertex2f(-1.0, .40f);
    glVertex2f(1.0f, .40f);
    glVertex2f(1.0f, .15f);
    glVertex2f(-1.0f, .15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(204, 235, 255);
    glVertex2f(-1.0, .15f);
    glVertex2f(1.0f, .15f);
    glVertex2f(1.0f, -.15f);
    glVertex2f(-1.0f, -.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 245, 255);
    glVertex2f(-1.0, .15f);
    glVertex2f(1.0f, .15f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();


    Sun();

    Cloud();


}
void Evening_Sky()
{
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 153);
    glVertex2f(-1.0, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, .95f);
    glVertex2f(-1.0f, .95f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);
    glVertex2f(-1.0, .95f);
    glVertex2f(1.0f, .95f);
    glVertex2f(1.0f, .90f);
    glVertex2f(-1.0f, .90f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 77);
    glVertex2f(-1.0, .90f);
    glVertex2f(1.0f, .90f);
    glVertex2f(1.0f, .85f);
    glVertex2f(-1.0f, .85f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-1.0, .85f);
    glVertex2f(1.0f, .85f);
    glVertex2f(1.0f, .80f);
    glVertex2f(-1.0f, .80f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 128);
    glVertex2f(-1.0, .80f);
    glVertex2f(1.0f, .80f);
    glVertex2f(1.0f, .70f);
    glVertex2f(-1.0f, .70f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 153);
    glVertex2f(-1.0, .70f);
    glVertex2f(1.0f, .70f);
    glVertex2f(1.0f, .60f);
    glVertex2f(-1.0f, .60f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 179);
    glVertex2f(-1.0, .60f);
    glVertex2f(1.0f, .60f);
    glVertex2f(1.0f, .40f);
    glVertex2f(-1.0f, .40f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 204);
    glVertex2f(-1.0, .40f);
    glVertex2f(1.0f, .40f);
    glVertex2f(1.0f, .15f);
    glVertex2f(-1.0f, .15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 204);
    glVertex2f(-1.0, .15f);
    glVertex2f(1.0f, .15f);
    glVertex2f(1.0f, -.15f);
    glVertex2f(-1.0f, -.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 204);
    glVertex2f(-1.0, .15f);
    glVertex2f(1.0f, .15f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();


    Sun();

    Cloud();


}

void drawCircle(float x1, float y1,double radius)
{
    float x2, y2;
    float angle;
    glBegin(GL_POLYGON);
    for (angle = .1f; angle<361.0f; angle += 1.0f)
    {
        x2 = x1 + sin(angle)*radius;
        y2 = y1 + cos(angle)*radius;
        glVertex2f(x2, y2);
    }
    glEnd();
}

void Stars()
{
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(255,255,240);
    drawCircle(0.2,0.9,0.006);
    drawCircle(0.4,0.9,0.006);
    drawCircle(0.6,0.9,0.006);
    drawCircle(0.8,0.9,0.006);
    drawCircle(-0.2,0.9,0.006);
    drawCircle(-0.4,0.9,0.006);
    drawCircle(-0.6,0.9,0.006);
    drawCircle(-0.8,0.9,0.006);
    drawCircle(-0.9,0.8,0.006);
    drawCircle(-0.7,0.8,0.006);
    drawCircle(-0.5,0.8,0.006);
    drawCircle(-0.3,0.8,0.006);
    drawCircle(-0.0,0.9,0.006);
    drawCircle(-0.1,0.8,0.006);
    drawCircle(0.1,0.8,0.006);
    drawCircle(0.3,0.8,0.006);
    drawCircle(0.5,0.8,0.006);
    drawCircle(0.7,0.8,0.006);
    drawCircle(0.9,0.8,0.006);

    drawCircle(0.2,0.7,0.006);
    drawCircle(0.4,0.7,0.006);
    drawCircle(0.6,0.7,0.006);
    drawCircle(0.8,0.7,0.006);
    drawCircle(-0.2,0.7,0.006);
    drawCircle(-0.4,0.7,0.006);
    drawCircle(-0.6,0.7,0.006);
    drawCircle(-0.8,0.7,0.006);
    drawCircle(-0.9,0.6,0.006);
    drawCircle(-0.7,0.6,0.006);
    drawCircle(-0.5,0.6,0.006);
    drawCircle(-0.3,0.6,0.006);
    drawCircle(-0.0,0.7,0.006);
    drawCircle(-0.1,0.6,0.006);
    drawCircle(0.1,0.6,0.006);
    drawCircle(0.3,0.6,0.006);
    drawCircle(0.5,0.6,0.006);
    drawCircle(0.7,0.6,0.006);
    drawCircle(0.9,0.6,0.006);

    drawCircle(0.2,0.5,0.006);
    drawCircle(0.4,0.5,0.006);
    drawCircle(0.6,0.5,0.006);
    drawCircle(0.8,0.5,0.006);
    drawCircle(-0.2,0.5,0.006);
    drawCircle(-0.4,0.5,0.006);
    drawCircle(-0.6,0.5,0.006);
    drawCircle(-0.8,0.5,0.006);
    drawCircle(-0.9,0.4,0.006);
    drawCircle(-0.7,0.4,0.006);
    drawCircle(-0.5,0.4,0.006);
    drawCircle(-0.3,0.4,0.006);
    drawCircle(-0.0,0.5,0.006);
    drawCircle(-0.1,0.4,0.006);
    drawCircle(0.1,0.4,0.006);
    drawCircle(0.3,0.4,0.006);
    drawCircle(0.5,0.4,0.006);
    drawCircle(0.7,0.4,0.006);
    drawCircle(0.9,0.4,0.006);
    glPopMatrix();
    glEnd();
}

void Night_Sky()
{
    glBegin(GL_QUADS);
    glColor3ub(44,62,80);
    glVertex2f(-1.0, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    Stars();

    Moon();
}

void Day_Sea()
{
    glBegin(GL_QUADS);
    glColor3ub(102, 153, 255);
    glVertex2f(-1.0, .15f); // top left
    glVertex2f(1.0f, .15f); // top right
    glVertex2f(1.0, -0.30f); // top left
    glVertex2f(-1.0f, -0.30f); // top right
    glEnd();

    ///ADD POLIGON IN SAND

}

void Night_Sea()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 34, 102);
    glVertex2f(-1.0, .15f); // top left
    glVertex2f(1.0f, .15f); // top right
    glVertex2f(1.0, -0.30f); // top left
    glVertex2f(-1.0f, -0.30f); // top right
    glEnd();

    ///ADD POLIGON IN SAND

}

void Evening_Sea()
{
    glBegin(GL_QUADS);
    glColor3ub(77, 136, 255);
    glVertex2f(-1.0, .15f); // top left
    glVertex2f(1.0f, .15f); // top right
    glVertex2f(1.0, -0.30f); // top left
    glVertex2f(-1.0f, -0.30f); // top right
    glEnd();

    ///ADD POLIGON IN SAND

}


void Day_Mountain()
{
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(0.0f, 0.45f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glEnd();

    glScalef(0.8,0.8,0.0);
    glTranslatef(0.18,0.0335,0.0);
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(0.0f, 0.35f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glEnd();
    glLoadIdentity();

    glScalef(0.8,0.8,0.0);
    glTranslatef(-0.18,0.0335,0.0);
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(0.0f, 0.35f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glEnd();
    glLoadIdentity();
}

void Night_Mountain()
{
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 26, 0);
    glVertex2f(0.0f, 0.45f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glEnd();

    glScalef(0.8,0.8,0.0);
    glTranslatef(0.18,0.0335,0.0);
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 26, 0);
    glVertex2f(0.0f, 0.35f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glEnd();
    glLoadIdentity();

    glScalef(0.8,0.8,0.0);
    glTranslatef(-0.18,0.0335,0.0);
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 26, 0);
    glVertex2f(0.0f, 0.35f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glEnd();
    glLoadIdentity();
}

void Evening_Mountain()
{
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 77, 0);
    glVertex2f(0.0f, 0.45f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glEnd();

    glScalef(0.8,0.8,0.0);
    glTranslatef(0.18,0.0335,0.0);
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 77, 0);
    glVertex2f(0.0f, 0.35f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glEnd();
    glLoadIdentity();

    glScalef(0.8,0.8,0.0);
    glTranslatef(-0.18,0.0335,0.0);
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 77, 0);
    glVertex2f(0.0f, 0.35f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glEnd();
    glLoadIdentity();
}

void Sand_Texure()
{
    ///SAND TEXURE
    glBegin(GL_LINES);
    glColor3ub(153, 153, 0);
    glVertex2f(-0.95,-0.35);
    glVertex2f(-0.91,-0.32);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(153, 153, 0);
    glVertex2f(-0.91,-0.32);
    glVertex2f(-0.91,-0.35);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(153, 153, 0);
    glVertex2f(-0.91,-0.35);
    glVertex2f(-0.87,-0.33);
    glEnd();
}

void Day_Sand()
{
    glBegin(GL_QUADS);
    glColor3ub(243, 213, 120);
    glVertex2f(-1.0, -0.30f);
    glVertex2f(1.0f, -0.30f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    Sand_Texure();

    glTranslatef(0.2, -0.2, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.15, -0.3, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.35, -0.4, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.55, -0.5, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.65, -0.45, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.2, -0.2, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.15, -0.3, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.35, -0.4, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.55, -0.5, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.65, -0.45, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.75, -0.25, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.75, -0.45, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.75, -0.45, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.85, -0.35, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.55, -0.55, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.35, -0.60, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.95, -0.60, 0.0);
    Sand_Texure();
    glLoadIdentity();

    ///ADD MORE TEXURE

    tree();
}

void Night_Sand()
{
    glBegin(GL_QUADS);
    glColor3ub(170, 149, 8);
    glVertex2f(-1.0, -0.30f);
    glVertex2f(1.0f, -0.30f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    Sand_Texure();

    glTranslatef(0.2, -0.2, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.15, -0.3, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.35, -0.4, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.55, -0.5, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.65, -0.45, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.2, -0.2, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.15, -0.3, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.35, -0.4, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.55, -0.5, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.65, -0.45, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.75, -0.25, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.75, -0.45, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.75, -0.45, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.85, -0.35, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.55, -0.55, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.35, -0.60, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.95, -0.60, 0.0);
    Sand_Texure();
    glLoadIdentity();

    ///ADD MORE TEXURE
}

void Evening_Sand()
{
    glBegin(GL_QUADS);
    glColor3ub(249, 233, 185);
    glVertex2f(-1.0, -0.30f);
    glVertex2f(1.0f, -0.30f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    Sand_Texure();

    glTranslatef(0.2, -0.2, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.15, -0.3, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.35, -0.4, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.55, -0.5, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.65, -0.45, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.2, -0.2, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.15, -0.3, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.35, -0.4, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.55, -0.5, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.65, -0.45, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.75, -0.25, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.75, -0.45, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.75, -0.45, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.85, -0.35, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.55, -0.55, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.35, -0.60, 0.0);
    Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.95, -0.60, 0.0);
    Sand_Texure();
    glLoadIdentity();

    ///ADD MORE TEXURE
}

///VIEWS
void View_Night() ///NIGHT TIME
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Night_Sky();
    Night_Sand();
    Night_Sea();
    Night_Mountain();
    tree();
    rain();

    glutTimerFunc(5500,load_Restart,0);

    glFlush();
}

void load_Night(int x)
{
    glutDisplayFunc(View_Night);
}

void View_Evening() ///EVENING TIME
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    Evening_Sky();
    Evening_Sand();
    Evening_Sea();
    Evening_Mountain();
    ship();

    glutTimerFunc(5500,load_Night,0);

    glFlush();
}

void load_Evening(int x)
{
    glutDisplayFunc(View_Evening);
}

void View_Day() ///DAY TIME
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Day_Sky();
    Day_Sand();
    Day_Sea();
    Day_Mountain();
    cottage();
    //ship();
    rain();


    glutTimerFunc(5500,load_Evening,1);

    glFlush();
}

void load_Day(int x)
{
    glutDisplayFunc(View_Day);
}

void load_Start()
{
    glutDisplayFunc(View_Day);
}

void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'p':
            rain();
        break;

        case 'm':
            ///
        break;

        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(800, 640);
    glutInitWindowPosition(400, 80);
	glutCreateWindow("Dynamic Sea Beach View (Including Audio Effects)");

	glutDisplayFunc(load_Start);

	glutTimerFunc(100, update_sun, 0);
	glutTimerFunc(100, update_cloud, 0);
	glutTimerFunc(100, update_moon, 0);
	glutTimerFunc(100, update_rain, 0);
	glutTimerFunc(100, update_ship, 0);

	glutKeyboardFunc(handleKeypress);

<<<<<<< HEAD
    ///"W:\\CODES\\Computer Graphics\\Final\\Sea_Beach_Dynamic_View\\"
    //sndPlaySound( "W:\\CODES\\Computer Graphics\\Final\\Sea_Beach_Dynamic_View\\sound_effect_wav.wav", SND_ASYNC|SND_LOOP );
=======
    ///"W:\\CODES\\Computer Graphics\\Final\\Sea_Beach_Dynamic_View\\Dynamic-Sea-Beach-View\\sound_effect_wav.wav"
    sndPlaySound( "W:\\CODES\\Computer Graphics\\Final\\Sea_Beach_Dynamic_View\\Dynamic-Sea-Beach-View\\sound_effect_wav.wav", SND_ASYNC|SND_LOOP );
>>>>>>> 57bfdccb93b108b3f8c3df91bf46d1c5c3f835bd

    sndPlaySound( "C:\\Users\\aacfahim\\Desktop\\Dynamic-Sea-Beach-View\\sound_effect_wav.wav", SND_ASYNC|SND_LOOP );
    glutIdleFunc(Idle);

	glutMainLoop();

	return 0;
}
