#include <GL/glut.h>
#include <iostream>
using namespace std;

float X1,Y1,X2,Y2;
void myInit()
{
glClearColor(0,0,0,0);
glColor3f(0,1,0);
//glColor3f(0.1f, 0.1f, 0.1f);
glPointSize(2.0);
gluOrtho2D(-320 , 320 , -240 , 240);
}

void bresenham(float X1,float X2,float Y1,float Y2)
{

float X,Y,e,dx,dy;
dx = X2-X1;
dy = Y2-Y1;
X = X1;
Y = Y1;
e = (2*dy) - dx;
glBegin(GL_POINTS);
glVertex2f(X,Y);
for(int i=0;i<dx;i++){

if (e>=0){
Y = Y+1;
e = e-(2*dx);
}
X = X+1;
e = e+(2*dy);
  glBegin(GL_POINTS);
  glVertex2f(X,Y);
  glEnd();
  }
  }
 

void MyDisplay()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glBegin(GL_POINTS);
//dda(X1,X2,Y1,Y2);
bresenham(X1,X2,Y1,Y2);
glEnd();


glBegin(GL_LINES);
glVertex2d(0,-240);
glVertex2d(0,240);

glBegin(GL_LINES);
glVertex2d(-320,0);
glVertex2d(320,0);
glEnd();
glFlush();
}

int main(int argc, char **argv)
{
cout << "Enter X1:\n";
cin >> X1;
cout << "Enter Y1:\n";

cin >> Y1;
cout << "Enter X2:\n";
cin >> X2;
cout << "Enter Y2:\n";
cin >> Y2;

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(640,480);
glutCreateWindow("Bresnham Line Algo");
myInit();
glutDisplayFunc(MyDisplay);
glutMainLoop();
}
