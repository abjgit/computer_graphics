#include <iostream>
#include <stdlib.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<cstring>
using namespace std;

float _angle1 = 30.0f;
float _angle2 = 45.0f;
float _angle3 = 37.0f;
float speed = 0.0f;
float speed1 = 0.0f;
float speed2= 0.0f;
float savedSpeed = 0.0f;
float savedSpeed1 = 0.0f;
float savedSpeed2 = 0.0f;
bool paused = false;
bool paused1 = false;
bool paused2 = false;
bool clockwise=false;

void update(int value)
{
    if(speed>1 || speed<0)
    {
        //cout<<speed<<endl;
        speed = 0.0f;
    }
    if(clockwise==false)
        _angle1 += speed;
    else
        _angle1-=speed;
	if (_angle1 > 360)
    {
		_angle1 -= 360;
	}
	//first speed done

    if(speed1>1 || speed1<0)
    {
        //cout<<speed<<endl;
        speed1 = 0.0f;
    }
    if(clockwise==false)
        _angle2 += speed1;
    else
        _angle2-=speed1;
	if (_angle2 > 360)
    {
		_angle2 -= 360;
	}

	//second speed done
	if(speed2>1 || speed2<0)
    {
        //cout<<speed<<endl;
        speed2 = 0.0f;
    }
    if(clockwise==false)
        _angle3 += speed2;
    else
        _angle3-=speed2;
	if (_angle1 > 360)
    {
		_angle3 -= 360;
	}


	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}
void specialKeys(int key, int x, int y) {
    switch (key)
    {
      case GLUT_KEY_LEFT:
          speed+=0.05f;
          update(0);
          break;
      case GLUT_KEY_RIGHT:
          speed-=0.05f;
          update(0);
          break;

    }
    switch (key)
    {
      case GLUT_KEY_LEFT:
          speed1+=0.1f;
          update(0);
          break;
      case GLUT_KEY_RIGHT:
          speed1-=0.1f;
          update(0);
          break;

    }
    switch (key)
    {
      case GLUT_KEY_LEFT:
          speed2+=0.07f;
          update(0);
          break;
      case GLUT_KEY_RIGHT:
          speed2-=0.07f;
          update(0);
          break;

    }
}
void keyboard(unsigned char key, int x, int y) {
//find key codes: https://www.cambiaresearch.com/articles/15/javascript-char-codes-key-codes
   switch (key)
   {
      case 'e':     // ESC key
         exit(0);
         break;
   }
   switch(key)
   {
        case 'l':
            clockwise=true;
            break;
        case 'r':
            clockwise=false;
            break;

   }
}
void mouse(int button, int state, int x, int y)
{
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    { // Pause/resume
      paused = !paused;         // Toggle state
      if (paused)
      {
         savedSpeed = speed;  // Save parameters for restore later
         speed = 0;            // Stop movement

      } else
      {
         speed = savedSpeed;  // Restore parameters

      }
   }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    { // Pause/resume
      paused1 = !paused1;         // Toggle state
      if (paused)
      {
         savedSpeed1 = speed1;  // Save parameters for restore later
         speed1 = 0;            // Stop movement

      } else
      {
         speed1 = savedSpeed1;  // Restore parameters

      }
   }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    { // Pause/resume
      paused2 = !paused2;         // Toggle state
      if (paused)
      {
         savedSpeed2 = speed2;  // Save parameters for restore later
         speed2 = 0;            // Stop movement

      } else
      {
         speed2 = savedSpeed2;  // Restore parameters

      }
   }
}
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity(); //Reset the drawing perspective

     glPushMatrix(); //Save the current state of transformations
	 //Move to the center of the triangle
	glRotatef(_angle1, 0.0, 0.0, 1.0);
	glTranslatef(0.4, 0, 0);//Rotate about the the vector (1, 2, 3)
	glColor3f(1.0,1.0,0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.06;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	 glPopMatrix();
	 //planet 2
	 glPushMatrix(); //Save the current state of transformations
	 //Move to the center of the triangle
	glRotatef(_angle2, 0.0, 0.0, 1.0);//chng
	glTranslatef(0.6, 0, 0);//Rotate about the the vector (1, 2, 3)//chng
	glColor3f(0.0,1.0,0);//chng
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.07;//chmg
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	 glPopMatrix();

	 //planet 2 end
	 //planet 3 start
	 glPushMatrix(); //Save the current state of transformations
	 //Move to the center of the triangle
	glRotatef(_angle3, 0.0, 0.0, 1.0);//chng
	glTranslatef(0.8, 0, 0);//Rotate about the the vector (1, 2, 3)//chng
	glColor3f(0.0,0.0,1.0f);//chng
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.1;//chmg
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	 glPopMatrix();
	 //planet 3 end
// Orbit done ------------


    glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.4;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
    glEnd();
    //orbital 2 start
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.6;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
    glEnd();
    //orbital 2 end

    //orbital 3 start
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
    glEnd();

    //orbital 3 start

///////////////////// SUN ///////////////////////////

    glPushMatrix();
        glColor3f(0.81,0.0,0.0);
        glutSolidSphere(.16,50,50);
    glPopMatrix();



	glutSwapBuffers();
}


int main(int argc, char** argv)
{
     cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"\t\tDefault is anti-clockwise rotation.."<<endl;
     cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"Press (r) for anti-clockwise rotation of planets.."<<endl;
    cout<<"Press (l) for clockwise rotation planets.."<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"Press left arrow to speed up and right arrow to speed down.."<<endl;
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);

	//Create the window
	glutCreateWindow("Transformation");

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutSpecialFunc(specialKeys); //Special Key Handler
	glutKeyboardFunc(keyboard);   //Basic keyboard key handler
	glutMouseFunc(mouse);         //Mouse Handler

	glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}
