#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include<iostream>
using namespace std;

GLfloat position = 1.0f;
GLfloat speed = 0.1f;

GLfloat xposition = 0.0f;
GLfloat xposition1 = 0.0f;
GLfloat xposition2 = 0.0f;
GLfloat xposition3 = 0.0f;
//missiles
GLfloat mposition1 = 0.0f;
GLfloat mposition2 = 0.0f;
GLfloat mposition3 = 0.0f;
GLfloat body=0.0f;

int fire=0;
GLfloat nullspeed1=0.0f;
GLfloat nullspeed2=0.0f;
GLfloat nullspeed3=0.0f;

void update(int value)
{

    if(position < -2.2)
    {
        position = 1.0f;
    }

    position -= speed;
    //yposition+=nullspeed;
    mposition1+=nullspeed1;
    mposition2+=nullspeed2;
    mposition3+=nullspeed3;

	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}
void init()
{
   glClearColor(255.0f, 255.0f, 255.0f, 1.0f);
}

void handleMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
		    if(fire==0)
            {
                nullspeed1 = 0.1f;
                fire=fire+1;
                printf("clicked at (%d, %d)\n", x, y);
            }
            else if(fire==1)
            {
                nullspeed2 = 0.1f;
                fire=fire+1;
                printf("clicked at (%d, %d)\n", x, y);
            }
            else if(fire==2)
            {
                nullspeed3 = 0.1f;
                fire=fire+1;
                printf("clicked at (%d, %d)\n", x, y);
            }
		}
	}

	glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y)
{

	switch (key)
	{

case 'l':
    if(fire==0)
    {
        xposition -= 0.1f;
        xposition1 -= 0.1f;
        xposition2 -= 0.1f;
        xposition3 -= 0.1f;


//        mposition1-= 0.1f;
//        mposition2-= 0.1f;
//        mposition3-= 0.1f;
        break;
    }
    else if(fire==1)
    {
        xposition -= 0.1f;
        xposition2 -= 0.1f;
        xposition3 -= 0.1f;

        //mposition1-= 0.1f;
//        mposition2-= 0.1f;
//        mposition3-= 0.1f;
        break;
    }
    else if(fire==2)
    {
        xposition -= 0.1f;
        xposition3 -= 0.1f;
        //mposition1-= 0.1f;
        //mposition2-= 0.1f;
        //mposition3-= 0.1f;
        break;
    }
    else if(fire==3)
    {
        xposition -= 0.1f;
        //mposition1-= 0.1f;
        //mposition2-= 0.1f;
        //mposition3-= 0.1f;
        break;
    }
case 'r':
    if(fire==0)
    {
        xposition += 0.1f;
        xposition1 += 0.1f;
        xposition2 += 0.1f;
        xposition3 += 0.1f;

//        mposition1+= 0.1f;
//        mposition2+= 0.1f;
//        mposition3+= 0.1f;
        break;
    }
    else if(fire==1)
    {
        xposition += 0.1f;
        xposition2 += 0.1f;
        xposition3 += 0.1f;
        //mposition1-= 0.1f;

//        mposition2+= 0.1f;
//        mposition3+= 0.1f;
        break;
    }
    else if(fire==2)
    {
        xposition += 0.1f;
        xposition3 += 0.1f;
        //mposition1-= 0.1f;
        //mposition2-= 0.1f;
        //mposition3+= 0.1f;
        break;
    }
    else if(fire==3)
    {
        xposition += 0.1f;
        //mposition1-= 0.1f;
        //mposition2-= 0.1f;
        //mposition3-= 0.1f;
        break;
    }


glutPostRedisplay();


	}
}


void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();



    glPushMatrix();
    glTranslatef(0.0f,position, 0.0f);
       glBegin(GL_TRIANGLES);
       glColor3f(255.0f, 0.0f, 1.0f);
       glVertex2f(-1.0f,1.0f);
       glVertex2f(-0.8f, 0.8f);
       glVertex2f(-0.6f, 1.0f);
       glEnd();

        glBegin(GL_TRIANGLES);
       glColor3f(255.0f, 0.0f, 1.0f);
       glVertex2f(-0.2f,1.0f);
       glVertex2f(0.0f, 0.8f);
       glVertex2f(0.2f, 1.0f);
       glEnd();


        glBegin(GL_TRIANGLES);
       glColor3f(255.0f, 0.0f, 1.0f);
       glVertex2f(0.5f,1.0f);
       glVertex2f(0.7f, 0.8f);
       glVertex2f(0.9f, 1.0f);
       glEnd();

       glPopMatrix();


       glPushMatrix();
       glTranslatef(xposition,0.0f,0.0f);
        glBegin(GL_QUADS);
       glColor3f(0.0f, 255.0f, 1.0f);
       glVertex2f(-0.1f,-1.0f);
       glVertex2f(0.1f, -1.0f);
       glVertex2f(0.1f, -0.7f);
       glVertex2f(-0.1f, -0.7f);
       glEnd();

       glBegin(GL_TRIANGLES);
       glColor3f(0.0f, 0.0f, 255.0f);
       glVertex2f(0.1f,-0.9f);
       glVertex2f(0.2f, -0.9f);
       glVertex2f(0.1f, -0.8f);
       glEnd();

       glBegin(GL_TRIANGLES);
       glColor3f(0.0f, 0.0f, 255.0f);
       glVertex2f(-0.1f,-0.9f);
       glVertex2f(-0.2f, -0.9f);
       glVertex2f(-0.1f, -0.8f);
       glEnd();
       glPopMatrix();

       //first missile
       glPushMatrix();
       glTranslatef(xposition1,mposition1,0.0f);
       glBegin(GL_TRIANGLES);
       glColor3f(255.0f, 0.0f, 0.0f);
       glVertex2f(-0.1f,-0.7f);
       glVertex2f(0.1f, -0.7f);
       glVertex2f(0.0f, -0.5f);
       glEnd();
       glPopMatrix();

       //second missile
       glPushMatrix();
       glTranslatef(xposition2,mposition2,0.0f);
       glBegin(GL_TRIANGLES);
       glColor3f(255.0f, 0.0f, 0.0f);
       glVertex2f(-0.1f,-0.7f);
       glVertex2f(0.1f, -0.7f);
       glVertex2f(0.0f, -0.5f);
       glEnd();
       glPopMatrix();

       //third missile
       glPushMatrix();
       glTranslatef(xposition3,mposition3,0.0f);
       glBegin(GL_TRIANGLES);
       glColor3f(255.0f, 0.0f, 0.0f);
       glVertex2f(-0.1f,-0.7f);
       glVertex2f(0.1f, -0.7f);
       glVertex2f(0.0f, -0.5f);
       glEnd();
       glPopMatrix();


   glFlush();
}



int main(int argc, char** argv)
{
    cout<<"Press (l=>L) for left move of missile and (r=>R) for right move of missile and click (left mouse) button to shot fire ==>"<<endl;
   glutInit(&argc, argv);
   glutInitWindowSize(600, 600);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Missile Attack");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutTimerFunc(1000, update, 0);
   glutMainLoop();
   return 0;
}
