#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<iostream>
#include<math.h>
#include <limits>
#include<ctime>
#include<cstdlib>
using namespace std;
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
void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glPointSize(1.0);
    //black background
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2i(0,180);
    glVertex2i(900,180);
    glVertex2i(900,900);
    glVertex2i(0,900);
    glEnd();
    //star code
    for(int j=900;j>180;j=j-20)
    {
        for(int i=0;i<901;i=i+8)
        {
            glBegin(GL_POINTS);
            glColor3ub(229,158,114);
            glVertex2i(i,(rand()%900)+1);
            glEnd();
        }
    }
    //wall code start
    int x=0;
    int y=0;
    for(int a=0;a<3;a++)
    {
        glColor3ub(225,255,197);
        vertical(x,y,40,8);
        x=x+40;
    }
    x=40;
    y=0;
    for(int a=0;a<3;a++)
    {
        glColor3ub(0, 0, 0);
        verticalLong(x,y,5,64,2);
        x=x+40;
    }

    //last wall
    glColor3ub(225,255,197);
    vertical(860,y,40,8);



    //stairs
    x=0;
    y=0;

    for(int a=0;a<2;a++)
    {
        glColor3ub(193,187,182);
        horizontal(x,y,25,5);
        y=y+30;
        x=x+25;
    }

    x=50;
    y=60;


    for(int a=0;a<2;a++)
    {
        glColor3ub(154,112,71);
        horizontal(x,y,25,5);
        y=y+30;
        x=x+25;
    }
    x=25;
    y=25;
    for(int a=0;a<4;a++)
    {
        glColor3ub(0,0,0);
        horizontalLong(x,y,25,5,5);
        x=x+25;
        y=y+30;
    }
    //
    x=125;
    y=0;
    glColor3ub(193,187,182);
    horizontal(x,y,30,25);
    x=150;
    y=30;
    glColor3ub(193,187,182);
    horizontal(x,y,30,24);

    x=125;
    y=0;
    glColor3ub(0,0,0);
    verticalLong(x,y,5,6,4);

    x=175;
    y=60;
    glColor3ub(154,116,71);
    horizontal(x,y,30,23);
    x=200;
    y=90;
    glColor3ub(154,116,71);
    horizontal(x,y,30,22);

    x=125;
    y=120;
    glColor3ub(0,0,0);
    horizontalLong(x,y,5,148,4);

    x=350;
    y=120;
    glColor3ub(0,0,0);
    verticalLong(x,y,5,75,4);

    x=855;
    y=120;
    glColor3ub(0,0,0);
    verticalLong(x,y,5,75,4);

    x=355;
    y=125;
    for(int a=0;a<=11;a++)
    {
        glColor3ub(154,116,71);
        horizontal(x,y,25,20);
        y=y+25;
        glColor3ub(0,0,0);
        horizontalLong(x,y,5,100,5);
        y=y+5;
    }
    glColor3ub(154,116,71);
    horizontal(x,y,10,50);
    x=350;
    y=y+10;
    glColor3ub(0,0,0);
    horizontalLong(x,y,5,105,5);

    //x=350;

    x=125;
    y=120;
    glColor3ub(0,0,0);
    verticalLong(x,y,5,75,4);

    x=130;
    y=125;
    for(int a=0;a<=7;a++)
    {
        glColor3ub(154,116,71);
        horizontal(x,y,44,5);
        y=y+45;
        glColor3ub(0,0,0);
        horizontalLong(x,y,5,44,5);
        y=y+5;
    }
    x=100;
    y=490;
    glBegin(GL_TRIANGLES);
    glColor3ub(145,116,71);
    glVertex2i(x,y);
    glVertex2i(380,y);
    glVertex2i(240,630);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(380,490);
    glVertex2i(890,490);
    glVertex2i(800,630);
    glVertex2i(240,630);
    glEnd();

    x=150;
    y=120;
    glColor3ub(0,0,0);
    vertical(x,y,20,16);
    x=x+20;
    for(int a=0;a<5;a++)
    {
        glColor3ub(110,86,66);
        vertical(x,y,20,16);
        x=x+20;
    }
    glColor3ub(0,0,0);
    horizontalLong(150,440,5,24,5);
    //
    x=240;
    y=630;
    int b=113;
    for(int a=0;a<5;a++)
    {
        glColor3ub(0,0,0);
        horizontalLong(x,y,5,b,5);
        x=x+20;
        y=y-30;
    }
    //windows 1
    x=400;
    y=220;
    for(int a=0;a<5;a++)
    {
        glColor3ub(0,0,0);
        vertical(x,y,20,4);
        x=x+20;
    }
    x=400;
    y=y+(4*20);
    for(int a=0;a<5;a++)
    {
        glColor3ub(255,247,107);
        vertical(x,y,20,4);
        x=x+20;
    }
    //windows2
    x=600;
    y=220;
    for(int a=0;a<5;a++)
    {
        glColor3ub(0,0,0);
        vertical(x,y,20,4);
        x=x+20;
    }
    x=600;
    y=y+(4*20);
    for(int a=0;a<5;a++)
    {
        glColor3ub(255,247,107);
        vertical(x,y,20,4);
        x=x+20;
    }

    x=395;
    y=220;
    glColor3ub(215,198,190);
    verticalLong(x,y,5,33,5);

    x=500;
    y=220;
    glColor3ub(215,198,190);
    verticalLong(x,y,5,33,5);

    x=595;
    y=220;
    glColor3ub(215,198,190);
    verticalLong(x,y,5,33,5);

    x=700;
    y=220;
    glColor3ub(215,198,190);
    verticalLong(x,y,5,33,5);

    x=395;
    y=380;
    glColor3ub(215,198,190);
    horizontalLong(x,y,5,22,5);

    x=595;
    y=380;
    glColor3ub(215,198,190);
    horizontalLong(x,y,5,22,5);

    x=595;
    y=220;
    glColor3ub(215,198,190);
    horizontalLong(x,y,5,22,5);

    x=395;
    y=220;
    glColor3ub(215,198,190);
    horizontalLong(x,y,5,22,5);


    glFlush();

}
void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 900,0,900);
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900,900);
    glutInitWindowPosition(40, 40);
    glutCreateWindow("");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}
