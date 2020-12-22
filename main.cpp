                            ///------------------****------------------///
                                ///TANVIR TANJUM SHOURAV (17-35860-3)
                                ///ASHFAQ AFZAL CHOWDHURY (17-35800-3)
                                ///ZISHAD HOSSAIN LIMON (18-36101-1)
                                ///ANIKA TAHSIN TINA (17-35852-3)
                            ///------------------****------------------///
#include <cstdio>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265358979323846

GLfloat position_sun = 0.0f;
GLfloat position_sun_down = 0.0f;
GLfloat speed_sun = 0.0175f;

GLfloat position_moon = 0.0f;
GLfloat position_moon_down = 0.0f;
GLfloat speed_moon = 0.0175f;

GLfloat position_cloud = 0.0f;
GLfloat speed_cloud = 0.02f;

GLfloat position_bird = 0.0f;
GLfloat speed_bird = 0.03f;

GLfloat rain_position1 = 0.0f;
GLfloat rain_speed1 = 0.02f;
GLfloat rain_position2 = 0.0f;
GLfloat rain_speed2 = 0.01f;

GLfloat position_ship = 0.0f;
GLfloat speed_ship = 0.01f;

GLfloat position_sea_wave = 0.0f;
GLfloat speed_sea_wave = 0.05f;

boolean RainController = false;

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

void update_sea_wave(int value)
{
/*
   if(position_sea_wave <-.30)
    {
        position_sea_wave = .14f;
    }
    position_sea_wave -= speed_sea_wave;
	//glutPostRedisplay();
	glutTimerFunc(100, update_sea_wave, 0);

	*/


	position_sea_wave -= 50;
	if(position_sea_wave <= -80)
		position_sea_wave = 0;

    glutPostRedisplay();

    glutTimerFunc(1500,update_sea_wave,0);


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

void update_bird(int value)
{

    if(position_bird <-1.0)
    {
        position_bird = 1.0f;
    }
    position_bird -= speed_bird;
	//glutPostRedisplay();
	glutTimerFunc(100, update_bird, 0);
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

void Ship()
{
    glScalef(.2,.2,0);

    glTranslatef(.3,.9,0);
    glPushMatrix();
    glTranslatef(-position_ship,0.0, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(52, 73, 94 );
    glVertex2f(-0.3f, -0.2f);
    glVertex2f(-0.3f, -0.4f);
    glVertex2f(0.1f, -0.4f);
    glVertex2f(0.3f, -0.2f);
    glEnd();

    /// 1st floor
    glBegin(GL_POLYGON);
    glColor3ub(51, 0, 128);
    glVertex2f(-0.25f, -0.07f);
    glVertex2f(-0.25f, -0.2f);
    glVertex2f(0.15f, -0.2f);
    glVertex2f(0.1f, -0.07f);
    glEnd();

    glBegin(GL_QUADS); ///window1
    glColor3ub(255, 0, 255);
    glVertex2f(-0.2f, -0.09f);
    glVertex2f(-0.2f, -0.18f);
    glVertex2f(-0.15f, -0.18f);
    glVertex2f(-0.15f, -0.09f);
    glEnd();

    glBegin(GL_QUADS); ///window2
    glColor3ub(241, 196, 15);
    glVertex2f(-0.1f, -0.09f);
    glVertex2f(-0.1f, -0.18f);
    glVertex2f(-0.05f, -0.18f);
    glVertex2f(-0.05f, -0.09f);
    glEnd();

    glBegin(GL_QUADS); ///window3
    glColor3ub(255, 0, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.0f, -0.18f);
    glVertex2f(0.05f, -0.18f);
    glVertex2f(0.05f, -0.09f);
    glEnd();


    ///2nd floor
    glBegin(GL_POLYGON);
    glColor3ub(33, 97, 140);
    glVertex2f(-0.2f, 0.05f);
    glVertex2f(-0.2f, -0.07f);
    glVertex2f(0.06f, -0.07f);
    glVertex2f(0.02f, 0.05f);
    glEnd();

    glBegin(GL_QUADS); ///window1
    glColor3ub(0, 153, 51);
    glVertex2f(-0.18f, 0.03f);
    glVertex2f(-0.18f, -0.061f);
    glVertex2f(-0.13f, -0.061f);
    glVertex2f(-0.13f, 0.03f);
    glEnd();

    /*  glBegin(GL_QUADS); ///window2
    glColor3ub(241, 196, 15);
    glVertex2f(-0.12f, 0.03f);
    glVertex2f(-0.12f, -0.061f);
    glVertex2f(-0.07f, -0.061f);
    glVertex2f(-0.07f, 0.03f);
    glEnd();
    */
    glBegin(GL_QUADS); ///window3
    glColor3ub(0, 153, 51);
    glVertex2f(-0.06f, 0.03f);
    glVertex2f(-0.06f, -0.061f);
    glVertex2f(-0.01f, -0.061f);
    glVertex2f(-0.01f, 0.03f);
    glEnd();
    glPopMatrix();

    glLoadIdentity();
}

void Rain()
{
    ///sndPlaySound( "W:\\CODES\\Computer Graphics\\Final\\Sea_Beach_Dynamic_View\\Dynamic-Sea-Beach-View\\Sounds\\Rain.wav", SND_ASYNC|SND_LOOP );

    glPushMatrix();
    glTranslatef(rain_position2,rain_position1, 0.0f);

    glLineWidth(1.5);


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
    glTranslatef(position_cloud, 0.0f, 0.0f);
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

void Bird()
{
    glPushMatrix();
    glTranslatef(-position_bird, 0.0f, 0.0f);
    int i;

	GLfloat mm=0.182f; GLfloat nn=.801f; GLfloat radiusmm =.01f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mm, nn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();
	/////2nd bird////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.02f,0.8f);
    glVertex2f(-0.01f,0.79f);
    glVertex2f(0.0f,0.78f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.79f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.03f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.024f,0.8f);
    glVertex2f(0.0f,0.83f);
    glEnd();

	GLfloat mmm=0.062f; GLfloat nnn=.801f; GLfloat radiusmmm =.01f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmm, nnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	/////3rd bird/////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

	GLfloat mmmm=-0.638f; GLfloat nnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmm,nnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	////4th bird////
	GLfloat mmmmm=-0.518f; GLfloat nnnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmmm, nnnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmmm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nnnnn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.59f,0.79f);
    glVertex2f(-0.58f,0.78f);
    glVertex2f(-0.54f,0.77f);
    glVertex2f(-0.51f,0.79f);
    glVertex2f(-0.499f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.56f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.556f,0.8f);
    glVertex2f(-0.58f,0.83f);
    glEnd();
    glPopMatrix();

}

void Tree()
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

    glEnable(GL_LIGHTING);
    GLfloat sun_shine[] = {77, 77, 0, 7.5};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, sun_shine);
        Sun();
    glDisable(GL_LIGHTING);

    Cloud();

    if(RainController == false)
    {
        Bird();

        glTranslatef(0.2, -0.1, 0.0);
            Bird();
        glLoadIdentity();
    }
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

    Sun();

    Cloud();

    if(RainController == false)
    {
        Bird();

        glTranslatef(0.2, -0.1, 0.0);
            Bird();
        glLoadIdentity();
    }

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
    glVertex2f(1.0f, .15f);
    glVertex2f(-1.0f, .15f);
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

void Sea_Wave(int r, int g, int b)
{
    glPushMatrix();
    glTranslatef(position_sea_wave, 0.0f, 0.0f);

    glTranslatef(0.0f, -0.14f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);

    glVertex2f(-1.0, -0.14f);
    glVertex2f(-0.9f, -0.2f);
    glVertex2f(-0.8, -0.14f);
    glVertex2f(-0.7f, -0.2f);
    glVertex2f(-0.6f, -0.14f);
    glVertex2f(-0.5f, -0.2f);
    glVertex2f(-0.4f, -0.14f);
    glVertex2f(-0.3f, -0.2f);
    glVertex2f(-0.2f, -0.14f);
    glVertex2f(-0.1f, -0.2f);
    glVertex2f(0.0f, -0.14f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.2f, -0.14f);
    glVertex2f(0.3f, -0.2f);
    glVertex2f(0.4f, -0.14f);
    glVertex2f(0.5f, -0.2f);
    glVertex2f(0.6f, -0.14f);
    glVertex2f(0.7f, -0.2f);
    glVertex2f(0.8f, -0.14f);
    glVertex2f(0.9f, -0.2f);
    glVertex2f(1.0f, -0.14f);
    glEnd();

    glTranslatef(0.1f, -0.01f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);

    glVertex2f(-1.0, -0.14f);
    glVertex2f(-0.9f, -0.2f);
    glVertex2f(-0.8, -0.14f);
    glVertex2f(-0.7f, -0.2f);
    glVertex2f(-0.6f, -0.14f);
    glVertex2f(-0.5f, -0.2f);
    glVertex2f(-0.4f, -0.14f);
    glVertex2f(-0.3f, -0.2f);
    glVertex2f(-0.2f, -0.14f);
    glVertex2f(-0.1f, -0.2f);
    glVertex2f(0.0f, -0.14f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.2f, -0.14f);
    glVertex2f(0.3f, -0.2f);
    glVertex2f(0.4f, -0.14f);
    glVertex2f(0.5f, -0.2f);
    glVertex2f(0.6f, -0.14f);
    glVertex2f(0.7f, -0.2f);
    glVertex2f(0.8f, -0.14f);
    glVertex2f(0.9f, -0.2f);
    glVertex2f(1.0f, -0.14f);
    glEnd();

    glPopMatrix();
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

void Day_Sand_Texure()
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

void Evening_Sand_Texure()
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

void Night_Sand_Texure()
{
    ///SAND TEXURE
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.95,-0.35);
    glVertex2f(-0.91,-0.32);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.91,-0.32);
    glVertex2f(-0.91,-0.35);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
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

    Day_Sand_Texure();

    glTranslatef(0.2, -0.2, 0.0);
    Day_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.15, -0.3, 0.0);
    Day_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.35, -0.4, 0.0);
    Day_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.55, -0.5, 0.0);
    Day_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.65, -0.45, 0.0);
    Day_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.2, -0.2, 0.0);
    Day_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.15, -0.3, 0.0);
    Day_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.35, -0.4, 0.0);
    Day_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.55, -0.5, 0.0);
    Day_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.65, -0.45, 0.0);
    Day_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.75, -0.25, 0.0);
    Day_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.75, -0.45, 0.0);
    Day_Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.75, -0.45, 0.0);
    Day_Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.85, -0.35, 0.0);
    Day_Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.55, -0.55, 0.0);
    Day_Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.35, -0.60, 0.0);
    Day_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.95, -0.60, 0.0);
    Day_Sand_Texure();
    glLoadIdentity();

    ///ADD MORE TEXURE
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

    Night_Sand_Texure();

    glTranslatef(0.2, -0.2, 0.0);
    Night_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.15, -0.3, 0.0);
    Night_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.35, -0.4, 0.0);
    Night_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.55, -0.5, 0.0);
    Night_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.65, -0.45, 0.0);
    Night_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.2, -0.2, 0.0);
    Night_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.15, -0.3, 0.0);
    Night_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.35, -0.4, 0.0);
    Night_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.55, -0.5, 0.0);
    Night_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.65, -0.45, 0.0);
    Night_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.75, -0.25, 0.0);
    Night_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.75, -0.45, 0.0);
    Night_Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.75, -0.45, 0.0);
    Night_Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.85, -0.35, 0.0);
    Night_Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.55, -0.55, 0.0);
    Night_Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.35, -0.60, 0.0);
    Night_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.95, -0.60, 0.0);
    Night_Sand_Texure();
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

    Evening_Sand_Texure();

    glTranslatef(0.2, -0.2, 0.0);
    Evening_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.15, -0.3, 0.0);
    Evening_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.35, -0.4, 0.0);
    Evening_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.55, -0.5, 0.0);
    Evening_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.65, -0.45, 0.0);
    Evening_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.2, -0.2, 0.0);
    Evening_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.15, -0.3, 0.0);
    Evening_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.35, -0.4, 0.0);
    Evening_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.55, -0.5, 0.0);
    Evening_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.65, -0.45, 0.0);
    Evening_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.75, -0.25, 0.0);
    Evening_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.75, -0.45, 0.0);
    Evening_Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.75, -0.45, 0.0);
    Evening_Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.85, -0.35, 0.0);
    Evening_Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.55, -0.55, 0.0);
    Evening_Sand_Texure();
    glLoadIdentity();

    glTranslatef(1.35, -0.60, 0.0);
    Evening_Sand_Texure();
    glLoadIdentity();

    glTranslatef(0.95, -0.60, 0.0);
    Evening_Sand_Texure();
    glLoadIdentity();

    ///ADD MORE TEXURE
}
///UMBRELLA
void umbrella()
{
    ///Umbrella 1.
    glTranslatef(-0.75, 0.00, 0.0);

    glBegin(GL_QUADS);
    glColor3ub(156, 156, 161);

    glVertex2f(-0.01, -0.6f);
    glVertex2f(0.01, -0.6f);
    glVertex2f(0.01, -0.9f);
    glVertex2f(-0.01, -0.9f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(245, 203, 66);
    glVertex2f(-0.05,-0.65);
    glVertex2f(0.05,-0.65);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(245, 105, 66);
    glVertex2f(0.13,-0.64);
    glVertex2f(0.05,-0.65);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(24, 161, 26);
    glVertex2f(-0.13,-0.64);
    glVertex2f(-0.05,-0.65);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(82, 235, 212);
    glVertex2f(-0.18,-0.63);
    glVertex2f(-0.13,-0.64);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(232, 9, 9);
    glVertex2f(0.18,-0.63);
    glVertex2f(0.13,-0.64);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(179, 2, 219);
    glVertex2f(0.21,-0.62);
    glVertex2f(0.18,-0.63);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(18, 51, 219);
    glVertex2f(-0.21,-0.62);
    glVertex2f(-0.18,-0.63);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(142, 136, 148);
    glVertex2f(-0.23,-0.61);
    glVertex2f(-0.21,-0.62);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(117, 118, 128);
    glVertex2f(0.23,-0.61);
    glVertex2f(0.21,-0.62);
    glVertex2f(0.0,-0.45);
    glEnd();

    glLoadIdentity();

    ///Umbrella 2
    glTranslatef(-0.2, -0.10, 0.0);
    glScalef(.7, .7, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(156, 156, 161);

    glVertex2f(-0.01, -0.6f);
    glVertex2f(0.01, -0.6f);
    glVertex2f(0.01, -0.9f);
    glVertex2f(-0.01, -0.9f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(245, 203, 66);
    glVertex2f(-0.05,-0.65);
    glVertex2f(0.05,-0.65);
    glVertex2f(0.0,-0.45);
    glEnd();

    //glRotatef(45.0,0.0,1.0, 0.0);
    glBegin(GL_TRIANGLES);
    glColor3ub(245, 105, 66);
    glVertex2f(0.13,-0.64);
    glVertex2f(0.05,-0.65);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(24, 161, 26);
    glVertex2f(-0.13,-0.64);
    glVertex2f(-0.05,-0.65);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(82, 235, 212);
    glVertex2f(-0.18,-0.63);
    glVertex2f(-0.13,-0.64);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(232, 9, 9);
    glVertex2f(0.18,-0.63);
    glVertex2f(0.13,-0.64);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(179, 2, 219);
    glVertex2f(0.21,-0.62);
    glVertex2f(0.18,-0.63);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(18, 51, 219);
    glVertex2f(-0.21,-0.62);
    glVertex2f(-0.18,-0.63);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(142, 136, 148);
    glVertex2f(-0.23,-0.61);
    glVertex2f(-0.21,-0.62);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(117, 118, 128);
    glVertex2f(0.23,-0.61);
    glVertex2f(0.21,-0.62);
    glVertex2f(0.0,-0.45);
    glEnd();

    glLoadIdentity();
}

void seat()
{
    ///seat 1
    glScalef(1.8,1.8, 0);
    glTranslatef(-0.42, 0.42, 0.0);

    glBegin(GL_QUADS);
    glColor3ub(201, 200, 199);

    glVertex2f(0.09, -0.83f);
    glVertex2f(0.16, -0.83f);
    glVertex2f(0.08, -0.88f);
    glVertex2f(0.02, -0.88f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(201, 200, 199);

    glVertex2f(0.13, -0.83f);
    glVertex2f(0.15, -0.83f);
    glVertex2f(0.15, -0.86f);
    glVertex2f(0.13, -0.866f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(186, 185, 184);

    glVertex2f(0.02, -0.8f);
    glVertex2f(0.08, -0.8f);
    glVertex2f(0.08, -0.9f);
    glVertex2f(0.02, -0.9f);

    glEnd();

    ///seat 2

    glTranslatef(0.31, -0.28, 0.0);

    glScalef(0.6,0.6, 0);

    glBegin(GL_QUADS);
    glColor3ub(201, 200, 199);

    glVertex2f(0.09, -0.83f);
    glVertex2f(0.16, -0.83f);
    glVertex2f(0.08, -0.88f);
    glVertex2f(0.02, -0.88f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(201, 200, 199);

    glVertex2f(0.13, -0.83f);
    glVertex2f(0.15, -0.83f);
    glVertex2f(0.15, -0.86f);
    glVertex2f(0.13, -0.866f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(186, 185, 184);

    glVertex2f(0.02, -0.8f);
    glVertex2f(0.08, -0.8f);
    glVertex2f(0.08, -0.9f);
    glVertex2f(0.02, -0.9f);

    glEnd();

    glLoadIdentity();
}

///EVENT HANDLER
void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
        ///RAIN START
        case 'r':
            RainController = true;

            ///Sound Effect
            sndPlaySound( "Sounds\\Rain.wav", SND_ASYNC|SND_LOOP );
        break;

        case 'R':
            RainController = true;

            ///Sound Effect
            sndPlaySound( "Sounds\\Rain.wav", SND_ASYNC|SND_LOOP );
        break;

        ///RAIN END
        case 'd':
            RainController = false;

            ///Sound Effect
            sndPlaySound( "Sounds\\Sea Beach.wav", SND_ASYNC|SND_LOOP );
        break;

        case 'D':
            RainController = false;

            ///Sound Effect
            sndPlaySound( "Sounds\\Sea Beach.wav", SND_ASYNC|SND_LOOP );
        break;
    }
}

///VIEWS
void View_Night() ///NIGHT TIME
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Night_Sea();
    Night_Sky();
    Night_Sand();
    Sea_Wave(0, 34, 102);
    Night_Mountain();
    Tree();
    umbrella();
    seat();
    if(RainController == true)
    {
        Rain();
    }
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

    Evening_Sea();
    Evening_Sky();
    Evening_Sand();
    Sea_Wave(77, 136, 255);
    Evening_Mountain();
    Tree();
    umbrella();
    Ship();
    seat();
    if(RainController == true)
    {
        Rain();
    }
    glutTimerFunc(5500,load_Night,0);

    glutSwapBuffers();

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
    Day_Sea();
    Day_Sky();
    Day_Sand();
    Sea_Wave(102, 153, 255);
    Day_Mountain();
    Tree();
    umbrella();
    Ship();
    seat();
    if(RainController == true)
    {
        Rain();
    }
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

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(800, 640);
    glutInitWindowPosition(400, 80);
	glutCreateWindow("Dynamic Sea Beach View (Including Audio Effects)");

	glutDisplayFunc(load_Start);

	glutTimerFunc(100, update_sun, 0);
	glutTimerFunc(100, update_cloud, 0);
	glutTimerFunc(100, update_bird, 0);
	glutTimerFunc(100, update_moon, 0);
	glutTimerFunc(100, update_rain, 0);
	glutTimerFunc(100, update_ship, 0);
	glutTimerFunc(100, update_sea_wave, 0);

	glutKeyboardFunc(handleKeypress);

    sndPlaySound( "Sounds\\Sea Beach.wav", SND_ASYNC|SND_LOOP );

    glutIdleFunc(Idle);

	glutMainLoop();

	return 0;
}
