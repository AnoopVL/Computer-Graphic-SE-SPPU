#include <iostream>
#include <GL/glut.h>
using namespace std;
void init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);//set matrix to projection matrix mode;projection matrix responsible for trnsforming 3D objects to 2D space for rendering
    gluOrtho2D(0,640,0,480);
}

void bound_it(int x, int y, float* n, float* b){
    float cl[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,cl);//read the pixel data; stored in location(x,y) and in array cl,1.0 and 1.0 indicate the width and height of the region,gl_rgb = color mode,gl_float = data type is float
    if((cl[0]!=b[0] || cl[1]!=b[1] || cl[2]!=b[2])&&(
     cl[0]!=n[0] || cl[1]!=n[1] || cl[2]!=n[2])){
        glColor3f(n[0],n[1],n[2]);
        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();
        glFlush();
        bound_it(x+1,y,n,b);
        bound_it(x-2,y,n,b);
        bound_it(x,y+2,n,b);
        bound_it(x,y-2,n,b);
    }
}//checks if the color of the pixel is different from the boundary color, if it is different then is sets the color to new color

void mouse(int btn, int state, int x, int y){
    y = 480-y;
    if(btn==GLUT_LEFT_BUTTON)//symbolic constant represent left mouse btn
    {
        if(state==GLUT_DOWN)//specify the state of mouse btn(btn is pressed or released)
        {
            float bcl[] = {0,0,1};
            float cl[] = {1,0,0};
            bound_it(x,y,cl,bcl);
        }
    }
}//sets the boundary color and new color

void display(){
    glLineWidth(3);//set width of the line
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,1);
    glBegin(GL_LINE_LOOP);
        glVertex2i(150,100);
        glVertex2i(300,300);
        glVertex2i(450,100);
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Sample");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}