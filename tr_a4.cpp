#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;


struct Point
{
    int x; 
    int y;
};

struct Color
{
    float r;
    float g;
    float b;
};

Color getPixelColor();
int setPixelColor();
void FloodFill();

Color getPixelColor(int x, int y){
    Color color;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
    return color;
}

int setPixelColor(int x, int y, Color color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
    return 0;
}

void FloodFill(int x , int y, Color oldC, Color newC)
{
    Color color;
    color = getPixelColor(x, y);
    if( color.r == oldC.r && color.g == oldC.g && color.b == oldC.b){
        setPixelColor(x, y, newC);
        FloodFill(x+1, y, oldC, newC);
        FloodFill(x-1, y, oldC, newC);
        FloodFill(x, y+1, oldC, newC);
        FloodFill(x, y-1, oldC, newC);
    }
}

void MyMouse(int button, int state, int x ,int y)
{
    Color oldC = {1,0,0};
    Color newC = {0,1,0};
    FloodFill(x, 600-y, oldC, newC);
}

void init()
{
    glClearColor(0,0,0,0);
    glColor3f(1,0,0);
    glPointSize(2.0);
    gluOrtho2D(-800, 800, -600, 600);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
        glVertex2f(800, 0);
        glVertex2f(-800, 0);
        glVertex2f(0, -600);
        glVertex2f(0, 600);
    glEnd();
    glFlush();
}

int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Training floodfill & boundaryfill !!");
    init();
    glutDisplayFunc(display);
    glutMotionFunc(MyMouse);
    glutMainLoop();
}