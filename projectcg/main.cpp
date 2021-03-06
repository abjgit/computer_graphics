#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>
#include<mmsystem.h>

using namespace std;

float _run = 0.0;
float _run1 = 0.0;
float _run2 = 0.0;
float _run3 = 0.0;
float _rain = 0.0;
float _nt = 0.0;
float _ang_tri = 0.0;
char text[] = "Jack Weeds Rose";


bool onOff;
bool frd = false;
bool bck = false;
bool starOn=false;

bool rainday = false;
bool night = false;


//float _angle = 0.0;
//float _cameraAngle = 0.0;
//float _run = 0.0;
///function for looping start
void horizontal(int x,int y,int size,int block)
{
    for(int a=x,b=y,c=0;c<block;c++,a+=size)
    {
        glBegin(GL_POLYGON);
        glVertex2i(a,b);
        glVertex2i(a+size,b);
        glVertex2i(a+size,b+size);
        glVertex2i(a,b+size);
        glEnd();

    }

}

void vertical(int x,int y,int size,int block)
{
    for(int a=x,b=y,c=0;c<block;c++,b+=size)
    {
        glBegin(GL_POLYGON);
        glVertex2i(a,b);
        glVertex2i(a+size,b);
        glVertex2i(a+size,b+size);
        glVertex2i(a,b+size);
        glEnd();
    }
}

void horizontalLong(int x,int y,int size,int block,int l)
{
    for(int a=x,b=y,c=0;c<block;c++,a+=size)
    {
        glBegin(GL_POLYGON);
        glVertex2i(a,b);
        glVertex2i(a+size,b);
        glVertex2i(a+size,b+l);
        glVertex2i(a,b+l);
        glEnd();

    }

}

void verticalLong(int x,int y,int size,int block,int l)
{
    for(int a=x,b=y,c=0;c<block;c++,b+=size)
    {
        glBegin(GL_POLYGON);
        glVertex2i(a,b);
        glVertex2i(a+l,b);
        glVertex2i(a+l,b+size);
        glVertex2i(a,b+size);
        glEnd();
    }
}
///function for looping start


void Sprint( float x, float y, char *st)
{
    int l,i;


    l=strlen( st ); // see how many characters are in text string.
    glColor3f(1.0,0.0,0.0);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, st[i]);

    }
}


void init()
{
	glClearColor(0.0,0.5,0.8,1.0);
	glColor3f(0.0,0.0,0.0);
	sndPlaySound("day.wav",SND_ASYNC|SND_LOOP);
	glPointSize(4.0);
	gluOrtho2D(0.0,1000.0,0.0,1000.0);
}



void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	///sun start
	if(night==false)
    {
        glPushMatrix();
        glTranslatef(600, 900, 0.0);
        glBegin(GL_POLYGON);
        glColor3f(255.0f, 0.0f, 0.0f);
        for(int i=0;i<50;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/50;
            float r=40;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
    }
	///sun end

	///moon start
	if(night)
    {
        glPushMatrix();
        glTranslatef(100, 940, 0.0);
        glBegin(GL_POLYGON);
        glColor3f(255.0f, 255.0f, 0.0f);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=40;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
    }
	///moon end

	///Cloud
    glPushMatrix();
    glTranslatef(_run3, 0.0, 0.0);

    glPushMatrix();
    glTranslatef(200, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(180, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(250, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(230, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

///cloud 2
    glPushMatrix();
    glTranslatef(350, 100, 0);
    glPushMatrix();
    glTranslatef(200, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(180, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(250, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(230, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(300, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(290, 760, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();
    ///end of cloud

    ///circle tree 3 start
     glPushMatrix();
    glTranslatef(160, 600, 0);



    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(150, 580, 0);



    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(160, 580, 0);



    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();




    glColor3f(0.4, 0, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(150, 450);
    glVertex2i(150, 555);
	glVertex2i(155, 555);
	glVertex2i(155, 450);
	glEnd();
	///circle tree 3 end
	///main road start
	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2i(0,0);
	glVertex2i(1000,0);
	glVertex2i(1000,100);
	glVertex2i(0,100);
	glEnd();
	///road End

	///white divider on road start
	int x=0;
	int y=50;
	for(int i=0;i<100;i++)
    {
        glColor3ub(255,255,255);
        horizontalLong(x,y,10,10,5);
        x=x+10;
    }
	///white divider on road end

	///garden start
	glBegin(GL_POLYGON);
	glColor3ub(0,178,0);
	glVertex2i(0,100);
	glVertex2i(1000,100);
	glVertex2i(1000,500);
	glVertex2i(0,500);
	glEnd();
	///road inside garden start
    glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
	glVertex2i(470,250);
	glVertex2i(530,250);
	glVertex2i(530,400);
	glVertex2i(470,400);
	glEnd();
	///road inside garden end
	///1stTable start
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(120,250);
    glVertex2i(140,250);   //Right chair stand
    glVertex2i(140,280);
    glVertex2i(120,280);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(140,280);
    glVertex2i(140,300);   //right chair top
    glVertex2i(135,300);
    glVertex2i(135,280);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(60,250);
    glVertex2i(80,250);   //left chair stand
    glVertex2i(80,280);
    glVertex2i(60,280);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(60,280);
    glVertex2i(60,300);   //left chair top
    glVertex2i(65,300);
    glVertex2i(65,280);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(90,250);
    glVertex2i(110,250);   //Table stand
    glVertex2i(100,300);
    glEnd();


    glPushMatrix();
    glTranslatef(100, 300, 0);

    glBegin(GL_POLYGON);
    glColor3f(0.68, 0.49, 0.33);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;     //Table circle
		float A=(i*2*pi)/200;
		float r=20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    ///1stTable end

	///2ndTable start
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(220,250);
    glVertex2i(240,250);   //Right chair stand
    glVertex2i(240,280);
    glVertex2i(220,280);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(240,280);
    glVertex2i(240,300);   //right chair top
    glVertex2i(235,300);
    glVertex2i(235,280);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(160,250);
    glVertex2i(180,250);   //left chair stand
    glVertex2i(180,280);
    glVertex2i(160,280);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(160,280);
    glVertex2i(160,300);   //left chair top
    glVertex2i(165,300);
    glVertex2i(165,280);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(190,250);
    glVertex2i(210,250);   //Table stand
    glVertex2i(200,300);
    glEnd();


glPushMatrix();
    glTranslatef(200, 300, 0);

    glBegin(GL_POLYGON);
    glColor3f(0.68, 0.49, 0.33);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;     //Table circle
		float A=(i*2*pi)/200;
		float r=20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    ///2ndTable end

    ///3rdTable start
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(320,250);
    glVertex2i(340,250);   //Right chair stand
    glVertex2i(340,280);
    glVertex2i(320,280);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(340,280);
    glVertex2i(340,300);   //right chair top
    glVertex2i(335,300);
    glVertex2i(335,280);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(260,250);
    glVertex2i(280,250);   //left chair stand
    glVertex2i(280,280);
    glVertex2i(260,280);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(260,280);
    glVertex2i(260,300);   //left chair top
    glVertex2i(265,300);
    glVertex2i(265,280);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(290,250);
    glVertex2i(310,250);   //Table stand
    glVertex2i(300,300);
    glEnd();


glPushMatrix();
    glTranslatef(300, 300, 0);

    glBegin(GL_POLYGON);
    glColor3f(0.68, 0.49, 0.33);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;     //Table circle
		float A=(i*2*pi)/200;
		float r=20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    ///3rdTable end

     ///4thTable start
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(420,250);
    glVertex2i(440,250);   //Right chair stand
    glVertex2i(440,280);
    glVertex2i(420,280);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(440,280);
    glVertex2i(440,300);   //right chair top
    glVertex2i(435,300);
    glVertex2i(435,280);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(360,250);
    glVertex2i(380,250);   //left chair stand
    glVertex2i(380,280);
    glVertex2i(360,280);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(360,280);
    glVertex2i(360,300);   //left chair top
    glVertex2i(365,300);
    glVertex2i(365,280);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(390,250);
    glVertex2i(410,250);   //Table stand
    glVertex2i(400,300);
    glEnd();


glPushMatrix();
    glTranslatef(400, 300, 0);

    glBegin(GL_POLYGON);
    glColor3f(0.68, 0.49, 0.33);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;     //Table circle
		float A=(i*2*pi)/200;
		float r=20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    ///4thTable end

    ///swimming pool start
    glPushMatrix();
    glTranslatef(800, 250, 0);

    glBegin(GL_POLYGON);
    glColor3f(0.52, 0.59, 0.65);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=100;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(800, 250, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=90;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(800, 250, 0);

    glBegin(GL_POLYGON);
    glColor3f(0.35, 0.75, 0.84);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=88;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    ///swimming pool end
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(100,400);
    glVertex2i(200,400);   //stage outer quad
    glVertex2i(200,500);
    glVertex2i(100,500);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(105,405);
    glVertex2i(195,405);   //stage inner quad
    glVertex2i(195,495);
    glVertex2i(105,495);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(95,400);
    glVertex2i(205,400);   //stage bottom quad
    glVertex2i(205,390);
    glVertex2i(95,390);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(130,400);
    glVertex2i(170,400);   //stage chair
    glVertex2i(170,430);
    glVertex2i(130,430);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.81, 0.73, 0.58);
    glVertex2i(130,400);
    glVertex2i(170,400);   //stage chair white
    glVertex2i(170,410);
    glVertex2i(130,410);
    glEnd();

	///garden end


    ///fence start
    glBegin(GL_QUADS);      //fence     fence

    glColor3ub(255,255,153);
    glVertex2i(0,105);
    glVertex2i(0,175);
    glVertex2i(1000,175);
    glVertex2i(1000,105);

    glColor3ub(0,0,0);


    glVertex2i(0,100);
    glVertex2i(0,105);
    glVertex2i(1000,105);
    glVertex2i(1000,100);

    glVertex2i(15,105);
    glVertex2i(15,175);
    glVertex2i(20,175);
    glVertex2i(20,105);

    glVertex2i(35,105);
    glVertex2i(35,175);
    glVertex2i(40,175);
    glVertex2i(40,105);

    glVertex2i(55,105);
    glVertex2i(55,175);
    glVertex2i(60,175);
    glVertex2i(60,105);

    glVertex2i(75,105);
    glVertex2i(75,175);
    glVertex2i(80,175);
    glVertex2i(80,105);

    glVertex2i(95,105);
    glVertex2i(95,175);
    glVertex2i(100,175);
    glVertex2i(100,105);

    glVertex2i(115,105);
    glVertex2i(115,175);
    glVertex2i(120,175);
    glVertex2i(120,105);

    glVertex2i(135,105);
    glVertex2i(135,175);
    glVertex2i(140,175);
    glVertex2i(140,105);

    glVertex2i(155,105);
    glVertex2i(155,175);
    glVertex2i(160,175);
    glVertex2i(160,105);

    glVertex2i(175,105);
    glVertex2i(175,175);
    glVertex2i(180,175);
    glVertex2i(180,105);

    glVertex2i(195,105);
    glVertex2i(195,175);
    glVertex2i(200,175);
    glVertex2i(200,105);

    glVertex2i(215,105);
    glVertex2i(215,175);
    glVertex2i(220,175);
    glVertex2i(220,105);

    glVertex2i(235,105);
    glVertex2i(235,175);
    glVertex2i(240,175);
    glVertex2i(240,105);

    glVertex2i(255,105);
    glVertex2i(255,175);
    glVertex2i(260,175);
    glVertex2i(260,105);

    glVertex2i(275,105);
    glVertex2i(275,175);
    glVertex2i(280,175);
    glVertex2i(280,105);

    glVertex2i(295,105);
    glVertex2i(295,175);
    glVertex2i(300,175);
    glVertex2i(300,105);

    glVertex2i(315,105);
    glVertex2i(315,175);
    glVertex2i(320,175);
    glVertex2i(320,105);

    glVertex2i(335,105);
    glVertex2i(335,175);
    glVertex2i(340,175);
    glVertex2i(340,105);

    glVertex2i(355,105);
    glVertex2i(355,175);
    glVertex2i(360,175);
    glVertex2i(360,105);

    glVertex2i(375,105);
    glVertex2i(375,175);
    glVertex2i(380,175);
    glVertex2i(380,105);

    glVertex2i(395,105);
    glVertex2i(395,175);
    glVertex2i(400,175);
    glVertex2i(400,105);

    glVertex2i(415,105);
    glVertex2i(415,175);
    glVertex2i(420,175);
    glVertex2i(420,105);

    glVertex2i(435,105);
    glVertex2i(435,175);
    glVertex2i(440,175);
    glVertex2i(440,105);

    glVertex2i(455,105);
    glVertex2i(455,175);
    glVertex2i(460,175);
    glVertex2i(460,105);

    glVertex2i(475,105);
    glVertex2i(475,175);
    glVertex2i(480,175);
    glVertex2i(480,105);

    glVertex2i(495,105);
    glVertex2i(495,175);
    glVertex2i(500,175);
    glVertex2i(500,105);

    glVertex2i(515,105);
    glVertex2i(515,175);
    glVertex2i(520,175);
    glVertex2i(520,105);

    glVertex2i(535,105);
    glVertex2i(535,175);
    glVertex2i(540,175);
    glVertex2i(540,105);

    glVertex2i(555,105);
    glVertex2i(555,175);
    glVertex2i(560,175);
    glVertex2i(560,105);

    glVertex2i(575,105);
    glVertex2i(575,175);
    glVertex2i(580,175);
    glVertex2i(580,105);

    glVertex2i(595,105);
    glVertex2i(595,175);
    glVertex2i(600,175);
    glVertex2i(600,105);

    glVertex2i(615,105);
    glVertex2i(615,175);
    glVertex2i(620,175);
    glVertex2i(620,105);

    glVertex2i(635,105);
    glVertex2i(635,175);
    glVertex2i(640,175);
    glVertex2i(640,105);

    glVertex2i(655,105);
    glVertex2i(655,175);
    glVertex2i(660,175);
    glVertex2i(660,105);

    glVertex2i(675,105);
    glVertex2i(675,175);
    glVertex2i(680,175);
    glVertex2i(680,105);

    glVertex2i(695,105);
    glVertex2i(695,175);
    glVertex2i(700,175);
    glVertex2i(700,105);

    glVertex2i(715,105);
    glVertex2i(715,175);
    glVertex2i(720,175);
    glVertex2i(720,105);

    glVertex2i(735,105);
    glVertex2i(735,175);
    glVertex2i(740,175);
    glVertex2i(740,105);

    glVertex2i(755,105);
    glVertex2i(755,175);
    glVertex2i(760,175);
    glVertex2i(760,105);

    glVertex2i(775,105);
    glVertex2i(775,175);
    glVertex2i(780,175);
    glVertex2i(780,105);

    glVertex2i(795,105);
    glVertex2i(795,175);
    glVertex2i(800,175);
    glVertex2i(800,105);

    glVertex2i(815,105);
    glVertex2i(815,175);
    glVertex2i(820,175);
    glVertex2i(820,105);

    glVertex2i(835,105);
    glVertex2i(835,175);
    glVertex2i(840,175);
    glVertex2i(840,105);

    glVertex2i(855,105);
    glVertex2i(855,175);
    glVertex2i(860,175);
    glVertex2i(860,105);

    glVertex2i(875,105);
    glVertex2i(875,175);
    glVertex2i(880,175);
    glVertex2i(880,105);

    glVertex2i(895,105);
    glVertex2i(895,175);
    glVertex2i(900,175);
    glVertex2i(900,105);

    glVertex2i(915,105);
    glVertex2i(915,175);
    glVertex2i(920,175);
    glVertex2i(920,105);

    glVertex2i(935,105);
    glVertex2i(935,175);
    glVertex2i(940,175);
    glVertex2i(940,105);

    glVertex2i(955,105);
    glVertex2i(955,175);
    glVertex2i(960,175);
    glVertex2i(960,105);

    glVertex2i(975,105);
    glVertex2i(975,175);
    glVertex2i(980,175);
    glVertex2i(980,105);
    glEnd();

    ///gate start

    glBegin(GL_QUADS);      //fence     fence

    glColor3ub(153,76,0);
    glVertex2i(445,105);
    glVertex2i(445,250);
    glVertex2i(455,250);
    glVertex2i(455,105);

    glVertex2i(545,105);
    glVertex2i(545,250);
    glVertex2i(555,250);
    glVertex2i(555,105);

    /*glColor3ub(0,0,0);    ///rope
    glVertex2i(445,175);
    glVertex2i(345,105);
    glVertex2i(455,250);
    glVertex2i(455,105);*/

    glColor3ub(0,178,0);
    glVertex2i(455,105);
    glVertex2i(455,250);
    glVertex2i(545,250);
    glVertex2i(545,105);

    glEnd();

    glBegin(GL_TRIANGLES);          //Tree 2 Part
    glColor3ub(153,76,0);
    glVertex2i(445,250);
    glVertex2i(555,250);
    glVertex2i(500,330);

    glColor3ub(238,17,39);
    glVertex2i(455,260);
    glVertex2i(545,260);
    glVertex2i(500,320);


    glEnd();
    ///fence end

    ///road inside garden start
    glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
	glVertex2i(470,105);
	glVertex2i(530,105);
	glVertex2i(530,250);
	glVertex2i(470,250);
	glEnd();
	///road inside garden end

	///circle tree 4 start
     glPushMatrix();
    glTranslatef(950, 600, 0);



    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(940, 580, 0);



    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(950, 580, 0);



    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();




    glColor3f(0.4, 0, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(950, 450);
    glVertex2i(950, 555);
	glVertex2i(955, 555);
	glVertex2i(955, 450);
	glEnd();
	///circle tree 4 end

	///circle tree 4 start
     glPushMatrix();
    glTranslatef(850, 600, 0);



    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(840, 580, 0);



    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(850, 580, 0);



    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();




    glColor3f(0.4, 0, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(850, 450);
    glVertex2i(850, 555);
	glVertex2i(855, 555);
	glVertex2i(855, 450);
	glEnd();
	///circle tree 5 end

	///Swing start
    glLoadIdentity();
    glTranslatef(0,-.2,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 246, 77);
    glVertex2d(0.6, 0.3);
    glVertex2d(0.84, 0.3);
    glVertex2d(0.72, 0.36);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 246, 77);
    glVertex2d(0.59, 0);
    glVertex2d(0.61, 0);
    glVertex2d(0.6, 0.29);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 246, 77);
    glVertex2d(0.83, 0);
    glVertex2d(0.85, 0);
    glVertex2d(0.84, 0.29);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(0, 20, 130);

    glVertex2f(0.6, 0.29);
    glVertex2f(0.6, 0.3);

    glVertex2f(0.84, 0.29);
    glVertex2f(0.84, 0.3);

    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(89, 89, 89);

    glVertex2f(0.64, 0.06);
    glVertex2f(0.64, 0.1);

    glVertex2f(0.8, 0.06);
    glVertex2f(0.8, 0.1);

    glEnd();


    glBegin(GL_QUAD_STRIP);
    glColor3ub(214, 214, 214);

    glVertex2f(0.64, 0.1);
    glVertex2f(0.64, 0.16);

    glVertex2f(0.8, 0.1);
    glVertex2f(0.8, 0.16);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.64, 0.1);
    glVertex2f(0.8, 0.1);
    glEnd();


    glBegin(GL_QUAD_STRIP);
    glColor3ub(156, 26, 26);

    glVertex2f(0.64, 0.16);
    glVertex2f(0.64, 0.29);

    glVertex2f(0.65, 0.16);
    glVertex2f(0.65, 0.29);

    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(156, 26, 26);

    glVertex2f(0.79, 0.16);
    glVertex2f(0.79, 0.29);

    glVertex2f(0.8, 0.16);
    glVertex2f(0.8, 0.29);

    glEnd();

    glLoadIdentity();
    glPointSize(4.0);
    gluOrtho2D(0.0,1000.0,0.0,1000.0);
    ///Swing end
	///house start
	glBegin(GL_POLYGON);///start
	glColor3ub(176,171,166);
	glVertex2i(220,400);
	glVertex2i(780,400);
	glVertex2i(780,410);
	glVertex2i(220,410);
	glEnd();

	glBegin(GL_POLYGON);///first floor
	glColor3ub(171,141,87);
	glVertex2i(220,410);
	glVertex2i(780,410);
	glVertex2i(780,500);
	glVertex2i(220,500);
	glEnd();

	glBegin(GL_POLYGON);///door backside
	glColor3ub(0,0,0);
	glVertex2i(485,410);
	glVertex2i(530,410);
	glVertex2i(530,485);
	glVertex2i(485,485);
	glEnd();

	glBegin(GL_POLYGON);///door
	glColor3ub(110,85,66);
	glVertex2i(490,410);
	glVertex2i(530,410);
	glVertex2i(530,480);
	glVertex2i(490,480);
	glEnd();

	glBegin(GL_POLYGON);///window right back
	glColor3ub(0,0,0);
	glVertex2i(615,435);
	glVertex2i(645,435);
	glVertex2i(645,485);
	glVertex2i(615,485);
	glEnd();

	glBegin(GL_POLYGON);///window right
	glColor3ub(110,85,66);
	glVertex2i(620,440);
	glVertex2i(640,440);
	glVertex2i(640,480);
	glVertex2i(620,480);
	glEnd();

	glBegin(GL_POLYGON);///window last right back top+++++++++++++
	glColor3ub(0,0,0);
	glVertex2i(680,435);
	glVertex2i(710,435);
	glVertex2i(710,485);
	glVertex2i(680,485);
	glEnd();

	glBegin(GL_POLYGON);///window last right top
	glColor3ub(110,85,66);
	glVertex2i(685,440);
	glVertex2i(705,440);
	glVertex2i(705,480);
	glVertex2i(685,480);
	glEnd();

	glBegin(GL_POLYGON);///window left back
	glColor3ub(0,0,0);
	glVertex2i(345,435);
	glVertex2i(385,435);
	glVertex2i(385,485);
	glVertex2i(345,485);
	glEnd();

	glBegin(GL_POLYGON);///window left
	glColor3ub(110,85,66);
	glVertex2i(350,440);
	glVertex2i(380,440);
	glVertex2i(380,480);
	glVertex2i(350,480);
	glEnd();

	glBegin(GL_POLYGON);///window last left back
	glColor3ub(0,0,0);
	glVertex2i(255,435);
	glVertex2i(295,435);
	glVertex2i(295,485);
	glVertex2i(255,485);
	glEnd();

	glBegin(GL_POLYGON);///window last left
	glColor3ub(110,85,66);
	glVertex2i(260,440);
	glVertex2i(290,440);
	glVertex2i(290,475);
	glVertex2i(260,475);
	glEnd();



	glBegin(GL_POLYGON);///first floor break
	glColor3ub(0,0,0);
	glVertex2i(220,500);
	glVertex2i(780,500);
	glVertex2i(780,505);
	glVertex2i(220,505);
	glEnd();

    glBegin(GL_POLYGON);///second floor
	glColor3ub(171,141,87);
	glVertex2i(220,505);
	glVertex2i(780,505);
	glVertex2i(780,595);
	glVertex2i(220,595);
	glEnd();

	glBegin(GL_POLYGON);///window right back top
	glColor3ub(0,0,0);
	glVertex2i(615,535);
	glVertex2i(645,535);
	glVertex2i(645,585);
	glVertex2i(615,585);
	glEnd();

	glBegin(GL_POLYGON);///window right top
	glColor3ub(110,85,66);
	glVertex2i(620,540);
	glVertex2i(640,540);
	glVertex2i(640,580);
	glVertex2i(620,580);
	glEnd();

	glBegin(GL_POLYGON);///window last right back top+++++++++++++
	glColor3ub(0,0,0);
	glVertex2i(680,535);
	glVertex2i(710,535);
	glVertex2i(710,585);
	glVertex2i(680,585);
	glEnd();

	glBegin(GL_POLYGON);///window last right top
	glColor3ub(110,85,66);
	glVertex2i(685,540);
	glVertex2i(705,540);
	glVertex2i(705,580);
	glVertex2i(685,580);
	glEnd();


	glBegin(GL_POLYGON);///window left back
	glColor3ub(0,0,0);
	glVertex2i(345,535);
	glVertex2i(385,535);
	glVertex2i(385,585);
	glVertex2i(345,585);
	glEnd();

	glBegin(GL_POLYGON);///window left
	glColor3ub(110,85,66);
	glVertex2i(350,540);
	glVertex2i(380,540);
	glVertex2i(380,580);
	glVertex2i(350,580);
	glEnd();

	glBegin(GL_POLYGON);///window last left back
	glColor3ub(0,0,0);
	glVertex2i(255,535);
	glVertex2i(295,535);
	glVertex2i(295,585);
	glVertex2i(255,585);
	glEnd();

	glBegin(GL_POLYGON);///window last left
	glColor3ub(110,85,66);
	glVertex2i(260,540);
	glVertex2i(290,540);
	glVertex2i(290,580);
	glVertex2i(260,580);
	glEnd();

	glBegin(GL_POLYGON);///window center back
	glColor3ub(0,0,0);
	glVertex2i(465,535);
	glVertex2i(505,535);
	glVertex2i(505,585);
	glVertex2i(465,585);
	glEnd();

	glBegin(GL_POLYGON);///window center
	glColor3ub(110,85,66);
	glVertex2i(470,540);
	glVertex2i(500,540);
	glVertex2i(500,580);
	glVertex2i(475,580);
	glEnd();

	glBegin(GL_POLYGON);///second floor belconi
	glColor3ub(110,85,66);
	glVertex2i(650,545);
	glVertex2i(780,545);
	glVertex2i(780,550);
	glVertex2i(650,550);
	glEnd();

	glBegin(GL_POLYGON);///second floor break
	glColor3ub(0,0,0);
	glVertex2i(220,595);
	glVertex2i(780,595);
	glVertex2i(780,600);
	glVertex2i(220,600);
	glEnd();

	glBegin(GL_TRIANGLES);///left triangle
	glColor3ub(114,69,34);
    glVertex2i(220,600);
    glVertex2i(320,600);
    glVertex2i(270,660);
    glEnd();

    glBegin(GL_POLYGON);///left pillar
    glColor3ub(0,0,0);
    glVertex2i(320,410);
    glVertex2i(325,410);
    glVertex2i(325,600);
    glVertex2i(320,600);
    glEnd();

    glBegin(GL_POLYGON);///long part
    glColor3ub(114,69,34);
    glVertex2i(320,600);
    glVertex2i(610,600);
    glVertex2i(610,660);
    glVertex2i(270,660);
    glEnd();

    glBegin(GL_TRIANGLES);///left part triangle inside
	glColor3ub(171,141,87);
    glVertex2i(235,610);
    glVertex2i(305,610);
    glVertex2i(270,650);
    glEnd();

    glBegin(GL_TRIANGLES);///left triangle's inside
	glColor3ub(114,69,34);
    glVertex2i(610,600);
    glVertex2i(650,600);
    glVertex2i(610,660);
    glEnd();

    glBegin(GL_TRIANGLES);///right triangle
	glColor3ub(114,69,34);
    glVertex2i(650,600);
    glVertex2i(780,600);
    glVertex2i(715,690);
    glEnd();

    glBegin(GL_POLYGON);///left pillar
    glColor3ub(0,0,0);
    glVertex2i(650,410);
    glVertex2i(655,410);
    glVertex2i(655,600);
    glVertex2i(650,600);
    glEnd();

    glBegin(GL_TRIANGLES);///right triangle's inside
	glColor3ub(171,141,87);
    glVertex2i(665,610);
    glVertex2i(765,610);
    glVertex2i(715,680);
    glEnd();


	///house end


	///circle tree 1
	 glPushMatrix();
    glTranslatef(50, 600, 0);



    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(60, 580, 0);



    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(40, 580, 0);



    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();




    glColor3f(0.4, 0, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(50, 450);
    glVertex2i(50, 555);
	glVertex2i(55, 555);
	glVertex2i(55, 450);
	glEnd();

	///circle tree 1 end


	///circle tree 2 start
	glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(250, 50, 0);


    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(200, 450, 0);



    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
    glPopMatrix();



    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(210, 438, 0);



    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();



    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(190, 438, 0);



    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();




    glColor3f(0.4, 0, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(198, 350);
    glVertex2i(198, 425);
	glVertex2i(203, 425);
	glVertex2i(203, 350);
	glEnd();


    glPopMatrix();

    ///circle tree 2 end
    ///tree start
    glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
    glTranslatef(200, 440, 0);

    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();


	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();
    ///tree end

     //TREE 2

    glPushMatrix();
    glScalef(0.50, 0.50, 0.25);
    glTranslatef(1400, 500, 0);

    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();


	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();
    ///tree 2 end

     //tree 3

    glPushMatrix();
    glScalef(0.6, 0.50, 0.25);
    glTranslatef(-400, 500, 0);

    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();


	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();

    ///tree 3 end


    glFlush();
	glutSwapBuffers();
}


void update(int value)
{
	_run += 1.0f;
	if (_run > 1000)
    {
        _run -= 1700;
    }

    _run1 += 1.0f;
	if (_run1 > 1000)
    {
        _run1 -= 1300;
    }

    _run2 += 3.5f;
	if (_run2 > 1000)
    {
        _run2 -= 1300;
    }

     _run3 += 0.8f;
	if (_run3 > 1000)
    {
        _run3 -= 1700;
    }

    if(onOff){
	_ang_tri += 2.5f;
	if (_ang_tri > 1000){
		_ang_tri = 1300;
	}
	 }

	glutPostRedisplay(); //Tell GLUT that the display has changed
	glutTimerFunc(25, update, 0);
}


void railForward(int value)
{

    if(frd){

    _ang_tri += 2.2f;

    if (_ang_tri > 1000)
    {
		_ang_tri -= 1400;
	}

	glutPostRedisplay();
	glutTimerFunc(25, railForward, 0);
}
}

void railBackward(int value)
{
    if(bck){

    _ang_tri -= 2.2f;

     if (_ang_tri < -350) {
		_ang_tri = 1100;
	}
	glutPostRedisplay();
	glutTimerFunc(25, railBackward, 0);
}
}

void start()
{

}
void Rain(int value)
{

    if(rainday)
    {

        _rain += 0.01f;

        glBegin(GL_POINTS);
        for(int i=1;i<=1000;i++)
        {
            int x=rand(),y=rand();
            x%=1000; y%=1000;
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2d(x,y);
            glVertex2d(x+5,y+5);
            glEnd();
        }
        glutPostRedisplay();
        glutTimerFunc(5, Rain, 0);

        glFlush();

    }
}

void Night(int value)
{

    if(night)
    {
        glClearColor(0.0,0.0,0.0,0.0);
        glutPostRedisplay();
        glutTimerFunc(5, Night, 0);
        glFlush();

    }
}

void myKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
        frd = false;
	    bck = true;
	    railBackward(_ang_tri);
	break;

	case 'd':
	     frd = true;
	     bck = false;
         railForward(_ang_tri);
	    break;

    case 's':
        frd = false;
        bck = false;
        break;

    case 'r':
        rainday = true;
        Rain(_rain);
        sndPlaySound("rain6.wav",SND_ASYNC|SND_LOOP);
        //sndPlaySound("rain.wav",SND_MEMORY|SND_ASYNC);
        break;

    case 'e':
        rainday = false;
		sndPlaySound("day.wav",SND_ASYNC|SND_LOOP);
        break;

    case 'n':
        night = true;
        Night(_nt);
        sndPlaySound("night.wav",SND_ASYNC|SND_LOOP);
        break;

    case 'b':
        night = false;
        glClearColor(0.0,0.5,0.8,1.0);
        sndPlaySound("day.wav",SND_ASYNC|SND_LOOP);
        break;

    case 27:     // ESC key
        exit(0);
        break;

	default:
	break;
	}
}


int main(int argc,char **argv)
{
    cout << endl << "*********** Matrimonial House ********************" << endl << endl;

    cout << "Press N : For Night " << endl << endl;
    cout << "Press B : For Day" << endl << endl;

     cout << "Press R : For Rain " << endl << endl;
    cout << "Press E : For Stop Raining" << endl << endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1300, 750);
	glutCreateWindow("Matrimonial House");

	glutDisplayFunc(display);
	glutKeyboardFunc(myKeyboard);
	glutTimerFunc(25, update, 0);
	init();
	glutMainLoop();
	return 0;
}

