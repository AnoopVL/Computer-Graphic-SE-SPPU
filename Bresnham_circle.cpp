#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
// #include<conio.h>
using namespace std;
float x1,Y1,x2,y2;
void displayMe(void)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glBegin(GL_LINES);
glVertex2d(0,-240);
glVertex2d(0,240);
glBegin(GL_LINES);
glVertex2d(-320,0);
glVertex2d(320,0);
glEnd();
//DDA Algo
/*float xinc,yinc,dx,dy,len,x,y,i;
dx = x2-x1;
dy = y2-Y1;

if (abs(dx)>abs(dy)){
len = abs(dx);
}
else{
len = abs(dy);
}
xinc = dx/len;
yinc = dy/len;
x = x1;
y = Y1;
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
for(i=0;i<=len;i++){
x = x+xinc;
y = y+yinc;
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
}
glFlush();*/


//Bresenham's algo
float x,y,e,dx,dy;
dx = x2-x1;
dy = y2-Y1;
x = x1;
y = Y1;
e = (2*dy) - dx;
glBegin(GL_POINTS);
glVertex2f(x,y);
for(int i;i<dx;i++){

if (e>=0){
y = y+1;
e = e-(2*dx);
}
x = x+1;
e = e+(2*dy);
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
}
glFlush();
}
//circle algo

void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc+x, yc+y);
    putpixel(xc-x, yc+y);
    putpixel(xc+x, yc-y);
    putpixel(xc-x, yc-y);
    putpixel(xc+y, yc+x);
    putpixel(xc-y, yc+x);
    putpixel(xc+y, yc-x);
    putpixel(xc-y, yc-x);
}
void circleBres(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    while (y >= x)
    {
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + (4 * x) + 6;
        drawCircle(xc, yc, x, y);
        delay(50);
    }
}

void myInit()
{
glClearColor(1.0,1.0,1.0,0);
glColor3f(0.0,0.0,0.0);
glPointSize(4.0);
gluOrtho2D(-320 , 320 , -240 , 240);
}
int main(int argc, char** argv)
{

cout<<"enter first point co-ordinates"<<endl;
cin>>x1>>Y1;
cout<<"enter second point co-ordinates"<<endl;
cin>>x2>>y2;
cout<<"Enter the coordinates of center of the circle";
cin>>x2>>y2;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(400, 300);
glutInitWindowPosition(100, 100);
glutCreateWindow("Hello world!");
myInit();
glutDisplayFunc(displayMe);
glutMainLoop();
return 0;
}
