#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<iostream>
using namespace std;
int m=0;

void draw_line(int x,int y,int size,int num)
{
    for(int a=x,b=y,c=0;c<num;c++,a+=size  )
    {
        glBegin(GL_POLYGON);
        glVertex2i(a,b);
        glVertex2i(a+size,b);
        glVertex2i(a+size,b+size);
        glVertex2i(a,b+size);
        glEnd();
        cout<<"x="<<x<<"y="<<y<<endl;
    }
}

void vertical_line(int x,int y,int size,int num)
{
    for(int a=x,b=y,c=0;c<num;c++,b+=size  )
    {
        glBegin(GL_POLYGON);
        glVertex2i(a,b);
        glVertex2i(a+size,b);
        glVertex2i(a+size,b+size);
        glVertex2i(a,b+size);
        glEnd();
    }

}
void temp(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);
    int size=25,block=10;
    int x=9*size,y=3*size;

    glColor3ub(0,0,0);
    draw_line(x,y,size,block);

    x=9*size,y=4*size;


    for(int i=0;i<=5;i++)
    {
        glColor3ub(250,250,0);
        draw_line(x,y,size,block);

        glColor3ub(0,0,0);
        draw_line(x-size,y,size,1);
        draw_line(x+(block*size),y,size,1);

        x=x-size;
        y=y+size;
        block+=2;
    }
    x=3*size,y=10*size;
    for(int i=0;i<7;i++)
    {
        glColor3ub(250,250,0);
        draw_line(x,y,size,22);

        glColor3b(0,0,0);
        draw_line(x-size,y,size,1);
        draw_line((x+(22*size)),y,size,1);
        y+=size;
    }
    x=4*size,block=20,y=17*size;

    for(int i=0;i<=5;i++)
    {
        glColor3ub(250,250,0);
        draw_line(x,y,size,block);

        glColor3ub(0,0,0);
        draw_line(x-size,y,size,1);
        draw_line(x+(block*size),y,size,1);

        x=x+size;
        y=y+size;
        block-=2;
    }
    x=9*size,y=22*size,block=10;
    glColor3ub(0,0,0);
    draw_line(x,y,size,block);

    glFlush();
}
void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glPointSize(5.0);

    glFlush ();
}
void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 900, 0.0, 600.0);
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900,600);
    glutInitWindowPosition(40, 40);
    glutCreateWindow("");
    glutDisplayFunc(temp);
    myInit();
    glutMainLoop();
}
