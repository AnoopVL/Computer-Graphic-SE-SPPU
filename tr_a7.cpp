#include<iostream>
#include<GL/glut.h>
#include<math.h>
#define sin 0.866
using namespace std;

int x1,yy1,x2,y2,n;

void koch();
void koch(int x1, int yy1, int x2, int y2, int n)
{
    int lx, ly, xx, yy, x[5], y[5];
    lx = (x2 - x1) / 3;
    ly = (y2 - yy1) / 3;

    x[0] = x1;
    y[0] = yy1;

    x[4] = x2;
    y[4] = y2;

    x[1] = x1 + lx;
    y[1] = yy1 + ly;

    x[3] = x1 + 2*lx;
    y[3] = yy1 + 2*ly;

    xx = x[3] - x[1];
    yy = y[3] - y[1];

    x[2] = xx*(0.5) + yy*(sin);
    y[2] = -xx*(sin) + yy*(0.5);

    x[2] = x[2] + x[1];
    y[2] = y[2] + y[1];

    if (n > 0){
        koch(x[0], y[0], x[1], y[1], n-1);
        koch(x[1], y[1], x[2], y[2], n-1);
        koch(x[2], y[2], x[3], y[3], n-1);
        koch(x[3], y[3], x[4], y[4], n-1);
    }else{
        glColor3f(0,1,0);
        glBegin(GL_LINES);
            glVertex2f(x[0],y[0]);
            glVertex2f(x[1],y[1]);
        glEnd();
        glBegin(GL_LINES);
            glVertex2f(x[1],y[1]);
            glVertex2f(x[2],y[2]);
        glEnd();
        glBegin(GL_LINES);
            glVertex2f(x[2],y[2]);
            glVertex2f(x[3],y[3]);
        glEnd();
        glBegin(GL_LINES);
            glVertex2f(x[3],y[3]);
            glVertex2f(x[4],y[4]);
        glEnd();
        glFlush();
    }
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 640, 480, 0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    cout<<"\n Enter starting and ending points of line : \n";
    cout<<" x1 \n";
    cin>>x1;
    cout<<" y1 \n";
    cin>>yy1;
    cout<<" x2 \n";
    cin>>x2;
    cout<<" y2 \n";
    cin>>y2;
    cout<<"\n Enter how many time would you like to execute koch curve algo : ";
    cin>>n;
    koch(x1,yy1, x2, y2, n);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Training koch curve !!");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}
