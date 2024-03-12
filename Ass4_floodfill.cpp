#include <iostream>
#include <GL/glut.h>

using namespace std;

float p1[3][3],p2[3][3],t[3][3],s[3][3],r[3][3],m[3][3],m1[3][3],Sh[3][3];

struct Point {
int x;
int y;
};//represents 2D space

struct Color {
float r;
float g;
float b;
};//represents color with r = red, g = green , b = blue

void init() {
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0, 0.0, 0.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();//sets the current matrix to identity matrix
gluOrtho2D(0, 640, 0, 480);
}//sets the clear color(white), drawing color(black), point size, projection matrix

Color getPixelColor(int x, int y) {
Color c;
glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &c);
return c;
}//takes the coordinates x & y and retrives its color

void setPixelColor(int x, int y, Color c) {
glColor3f(c.r, c.g, c.b);
glBegin(GL_POINTS);
glVertex2i(x, y);
glEnd();
glFlush();
}//sets the color of the pixel using c

void floodFill(int x, int y, Color oc, Color nc) {
Color c;
c= getPixelColor(x, y);

if(c.r == oc.r && c.g == oc.g && c.b == oc.b)
{
setPixelColor(x, y, nc);
floodFill(x+1, y, oc, nc);
floodFill(x, y+1, oc, nc);
floodFill(x-1, y, oc, nc);
floodFill(x, y-1, oc, nc);
}
return;
}//checks if the current pixel color matches the old color, if it does then it sets the current pixel color to new color

void mouse(int button, int state, int x, int y)
{
Color nc = {1.0f, 0.0f, 0.0f};
Color oc = {1.0f, 1.0f, 1.0f};

floodFill(320, 240, oc, nc);
}//callback function, new color and old color is defined

void drawpoly(float p1[3][3])

{

glBegin(GL_LINE_LOOP);

for(int i=0;i<3;i++)

{

glVertex2d(p1[i][0],p1[i][1]);

}

glEnd();

}//drawing the polygon



void display(void) {


glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS);
drawpoly(p1);
glEnd();
glFlush();
}//display the drawing

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640, 480);
glutInitWindowPosition(200, 200);
glutCreateWindow("sample");
init();
glutDisplayFunc(display);
glutMouseFunc(mouse);
glutMainLoop();
return 0;
}