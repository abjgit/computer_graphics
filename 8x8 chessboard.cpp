#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<iostream>

using namespace std;

void myDisplay(void)
{
    int xn1=0;
    int xn2=100;

    //y values
    int yn1=0;
    int yn2=100;

    glClear (GL_COLOR_BUFFER_BIT);
    glColor3ub (128, 128, 128);
    glPointSize(5.0);
    glBegin(GL_QUADS);
    for(int i=1;i<=8;i++)
    {
        if(i%2!=0)
        {
            for(int j=1;j<=8;j++)
            {
                if(j%2!=0)
                {
                    glColor3f(0, 0, 0);
                    glVertex2i(xn1,yn1);
                    glVertex2i(xn2,yn1);
                    glVertex2i(xn2,yn2);
                    glVertex2i(xn1,yn2);

                    yn1=yn1+100;
                    yn2=yn2+100;

                }
                else
                {
                    glColor3f(255, 255, 255);
                    glVertex2i(xn1,yn1);
                    glVertex2i(xn2,yn1);
                    glVertex2i(xn2,yn2);
                    glVertex2i(xn1,yn2);

                    yn1=yn1+100;
                    yn2=yn2+100;
                }
            }
        }
        else
        {
            for(int j=1;j<=8;j++)
            {
                if(j%2!=0)
                {
                    glColor3f(255, 255, 255);
                    glVertex2i(xn1,yn1);
                    glVertex2i(xn2,yn1);
                    glVertex2i(xn2,yn2);
                    glVertex2i(xn1,yn2);

                    yn1=yn1+100;
                    yn2=yn2+100;

                }
                else
                {
                    glColor3f(0, 0, 0);
                    glVertex2i(xn1,yn1);
                    glVertex2i(xn2,yn1);
                    glVertex2i(xn2,yn2);
                    glVertex2i(xn1,yn2);

                    yn1=yn1+100;
                    yn2=yn2+100;
                }
            }

        }
        //setting y values again
        yn1=0;
        yn2=100;

        //increasing x+100;
        xn1=xn1+100;
        xn2=xn2+100;
    }
    glEnd();
    glFlush ();
}

void myInit (void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 800.0);
}





int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}
