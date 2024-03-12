#include<iostream>
#include<GL/glut.h>
#include<math.h>
#define ROUND(x) int(x)+0.5
using namespace std;

int bh_circle(float,float,float);
int plotpoints(float,float,float,float);

void init(void)
{
    glClearColor(0,0,0,0);
    glColor3f(0,0,1);
    glPointSize(2.0);
    // gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);
     gluOrtho2D(-320 , 320 , -240 , 240);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    // glVertex2d(-w / 2, 0);
	// glVertex2d(w / 2, 0);
	// glVertex2d(0, -h / 2);
	// glVertex2d(0, h / 2);
    glVertex2f(-800,0);
    glVertex2f(800,0);
    glVertex2f(0,-600);
    glVertex2f(0,600);
    glEnd();
    bh_circle(100, 100, 50);
    bh_circle(-100, 100, 50);
    bh_circle(100, -100, 50);
    bh_circle(-100, -100, 50);
    glFlush();
}

int bh_circle(float xc, float yc, float r)
{
    float p = 3- 2*r;
    float x =0;
    float y = r;
    while(x <= y){
        if(p < 0){
            p = p + 4*x + 6;
        }else{
            p = p + 4*(x - y) + 10;
            y--;
        }
        x++;
        plotpoints(xc, yc , x, y);
    }
    return 0;
}

int plotpoints(float xc, float yc, float x, float y)
{
    glBegin(GL_POINTS);
    glVertex2i(xc+x, yc+y);
    glVertex2i(xc+x, yc-y);
    glVertex2i(xc-x, yc+y);
    glVertex2i(xc-x, yc-y);
    glVertex2i(xc+y, yc+x);
    glVertex2i(xc+y, yc-x);
    glVertex2i(xc-y, yc+x);
    glVertex2i(xc-y, yc-x);
    glEnd();
    glFlush();
    return 0;
}

int main(int argc , char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(800,600);
    glutCreateWindow("Training Bresenham Circle !!");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}