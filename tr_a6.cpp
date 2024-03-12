#include<iostream>
#include<math.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

float x1,x2,y2,x3,y3,a[3][2];
float yy1; // I have no idea why the f*ck it shows error when we use y1 instead of yy1
void translation();
void scaling();
void reflection();
void rotation();

void translation()
{
    float tx, ty;
    // tx = 50;
    // ty = 50;
    cout<< "\n";
    cout<< "Enter the translation factor tx:";
    cin>> tx;

    cout<< "\n";
    cout<< "Enter the translation factor ty:";
    cin>> ty;

    a[0][0]= x1;
    a[0][1]= yy1;
    
    a[1][0]= x2;
    a[1][1]= y2;
    
    a[2][0]= x3;
    a[2][1]= y3;

    a[0][0] = a[0][0] + tx;
    a[0][1] = a[0][1] + ty;

    a[1][0] = a[1][0] + tx;
    a[1][1] = a[1][1] + ty;

    a[2][0] = a[2][0] + tx;
    a[2][1] = a[2][1] + ty;

    glColor3f(0,0,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(a[0][0] , a[0][1]);
        glVertex2f(a[1][0] , a[1][1]);
        glVertex2f(a[2][0] , a[2][1]);
    glEnd();
    glFlush();
}

void scaling()
{
    float sx, sy;
    // tx = 50;
    // ty = 50;
    cout<< "\n";
    cout<< "Enter the scaling factor sx:";
    cin>> sx;

    cout<< "\n";
    cout<< "Enter the scaling factor sy:";
    cin>> sy;

    a[0][0]= x1;
    a[0][1]= yy1;
    
    a[1][0]= x2;
    a[1][1]= y2;
    
    a[2][0]= x3;
    a[2][1]= y3;

    a[0][0] = a[0][0] * sx;
    a[0][1] = a[0][1] * sy;

    a[1][0] = a[1][0] * sx;
    a[1][1] = a[1][1] * sy;

    a[2][0] = a[2][0] * sx;
    a[2][1] = a[2][1] * sy;

    glColor3f(0,1,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(a[0][0] , a[0][1]);
        glVertex2f(a[1][0] , a[1][1]);
        glVertex2f(a[2][0] , a[2][1]);
    glEnd();
    glFlush();
}

void rotation()
{
    float x, angle;
    int choice;
    cout <<"\n Enter which rotation you want to execute : ";
    cout <<"\n 1. Counter-clockwise";
    cout <<"\n 2. clockwise";
    cout <<"\n ";
    cin>> choice;
    cout<<"\n Enter the angle of rotation : ";
    cin>>angle;
        a[0][0]= x1;
        a[0][1]= yy1;
    
        a[1][0]= x2;
        a[1][1]= y2;
    
        a[2][0]= x3;
        a[2][1]= y3;

    x = 0.01745*angle;
    if(choice ==1 )
    {
        a[0][0]= (x1*cos(x) - yy1*sin(x));
        a[0][1]= (x1*sin(x) + yy1*cos(x));
    
        a[1][0]= (x2*cos(x) - y2*sin(x));
        a[1][1]= (x2*sin(x) + y2*cos(x));
    
        a[2][0]= (x3*cos(x) - y3*sin(x));
        a[2][1]= (x3*sin(x) + y3*cos(x));

        glColor3f(1,1,0);
        glBegin(GL_LINE_LOOP);
            glVertex2f(a[0][0] , a[0][1]);
            glVertex2f(a[1][0] , a[1][1]);
            glVertex2f(a[2][0] , a[2][1]);
        glEnd();
        glFlush();
    }
    if(choice == 2)
    {
        a[0][0]=(x1*cos(x)+yy1*sin(x));
        a[0][1]=(yy1*cos(x)-x1*sin(x));

        a[1][0]=(x2*cos(x)+y2*sin(x));
        a[1][1]=(y2*cos(x)-x2*sin(x));

        a[2][0]=(x3*cos(x)+y3*sin(x));    
        a[2][1]=(y3*cos(x)-x3*sin(x));

        glColor3f(1,1,0);
        glBegin(GL_LINE_LOOP);
            glVertex2f(a[0][0] , a[0][1]);
            glVertex2f(a[1][0] , a[1][1]);
            glVertex2f(a[2][0] , a[2][1]);
        glEnd();
        glFlush();
    }

}

void OrgTri()
{   
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x1,yy1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
    glEnd();
    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0,1,0);
    glBegin(GL_LINES);
    glVertex2f(1000,0);
    glVertex2f(-1000,0);
    glVertex2f(0,-1000);
    glVertex2f(0,1000);
    glEnd();
    glFlush();
    OrgTri();
    //translation();
    //scaling();
    rotation();
}

void init()
{
    glClearColor(0,0,0,0);
    glColor3f(0,1,0);
    // glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-800, 800, -800, 800);
}

int main(int argc, char**argv)
{   
    x1 = 0.0;
    yy1 = 0.0;
    x2 = 100.0;
    y2 = 100.0;
    x3 = 200.0;
    y3 = 0.0;
    
    glutInit(&argc, argv);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Training 2D transformation !!");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}