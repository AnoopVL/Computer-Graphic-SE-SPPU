#include<iostream>
#include<GL/glut.h>
using namespace std;

void display(void);
// void reshape();

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,1);
    glLoadIdentity(); //reset parameters of model view matrix 

    // glPointSize(10.0);
    // glBegin(GL_POINTS);
    // glVertex2f(20,20);
    // glVertex2f(-20,-20);
    // glEnd();
    glPointSize(10.0);
    glBegin(GL_POINTS);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, 0.0);
    glEnd();
    glFlush();
}

// void reshape(int w, int h)
// {
//     glViewport(0,0,100,100);
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity(); //resets parameters of projection matrix
//     gluOrtho2D(-10,10,-10,10);
//     glMatrixMode(GL_MODELVIEW);
// }

// void init(void){
//     glClearColor(1,0,1,0);
// }

int main( int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Training !!");
    glutDisplayFunc(display);
    // glutReshapeFunc(reshape);
    // init();
    glutMainLoop();
    return 0;
}