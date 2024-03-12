#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;

static int submenu_id,menu;
float x1,yy1,x2,y2,x3,y3,abc[3][2];

void init(void)
{
    glClearColor(1.0f,1.0f,1.0f,0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1000.0f,1000.0f,-1000.0f,1000.0f);
}

void draw_original()
{
    //glColor3f(1.0f,1.0f,1.0f);
    glColor3f(1.0f,0.0f,0.0f);
    // glBegin(GL_LINE_LOOP);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1,yy1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glEnd();
    glFlush();
}

void Translation()
{
    float tx,ty;
    cout<<"Enter value for tx:";
    cin>>tx;

    cout<<"Enter value for ty:";
    cin>>ty;

    abc[0][0]=x1;
    abc[0][1]=yy1;

    abc[1][0]=x2;
    abc[1][1]=y2;

    abc[2][0]=x3;
    abc[2][1]=y3;

    abc[0][0]=x1+tx;
    abc[0][1]=yy1+ty;

    abc[1][0]=x2+tx;
    abc[1][1]=y2+ty;

    abc[2][0]=x3+tx;
    abc[2][1]=y3+ty;

    glPointSize(4.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(abc[0][0],abc[0][1]);
    glVertex2f(abc[1][0],abc[1][1]);
    glVertex2f(abc[2][0],abc[2][1]);
    glEnd();
    glFlush();
}

void Scaling()
{
    float sx,sy;
    cout<<"Enter value for sx:";
    cin>>sx;

    cout<<"Enter value for sy:";
    cin>>sy;

    abc[0][0]=x1;
    abc[0][1]=yy1;

    abc[1][0]=x2;
    abc[1][1]=y2;

    abc[2][0]=x3;
    abc[2][1]=y3;

    abc[0][0]=x1*sx;
    abc[0][1]=yy1*sy;

    abc[1][0]=x2*sx;
    abc[1][1]=y2*sy;

    abc[2][0]=x3*sx;
    abc[2][1]=y3*sy;

    glPointSize(4.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(abc[0][0],abc[0][1]);
    glVertex2f(abc[1][0],abc[1][1]);
    glVertex2f(abc[2][0],abc[2][1]);
    glEnd();
    glFlush();
}

void Shearing()
{
    float shx,shy;
    cout<<"Enter value for shx:";
    cin>>shx;

    cout<<"Enter value for shy:";
    cin>>shy;

    abc[0][0]=x1;
    abc[0][1]=yy1;

    abc[1][0]=x2;
    abc[1][1]=y2;

    abc[2][0]=x3;
    abc[2][1]=y3;

    abc[0][0]=x1+shx*yy1;
    abc[0][1]=yy1+shy*x1;

    abc[1][0]=x2+shx*y2;
    abc[1][1]=y2*shy*x2;

    abc[2][0]=x3+shx*y3;
    abc[2][1]=y3+shy*x3;

    glPointSize(4.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(abc[0][0],abc[0][1]);
    glVertex2f(abc[1][0],abc[1][1]);
    glVertex2f(abc[2][0],abc[2][1]);
    glEnd();
    glFlush();
}

void Rotation()
{
    float x,angle;
    int choice;
    cout<<"Enter angle:";
    cin>>angle;
    x=0.01745*angle;

    cout<<"1.Anticlockwise";
    cout<<"2.Clockwise";

    cout<<"Enter Your Choice:";
    cin>>choice;


    abc[0][0]=x1;
    abc[0][1]=yy1;

    abc[1][0]=x2;
    abc[1][1]=y2;

    abc[2][0]=x3;
    abc[2][1]=y3;

    switch(choice)
    {
        case 1:
            abc[0][0]=x1*cos(x)-yy1*sin(x);
            abc[0][1]=x1*sin(x)+yy1*cos(x);

            abc[1][0]=x2*cos(x)-y2*sin(x);
            abc[1][1]=x2*sin(x)+y2*cos(x);

            abc[2][0]=x3*cos(x)-y3*sin(x);
            abc[2][1]=x3*sin(x)+y3*cos(x);

            glPointSize(4.0);
            glBegin(GL_LINE_LOOP);
            glVertex2f(abc[0][0],abc[0][1]);
            glVertex2f(abc[1][0],abc[1][1]);
            glVertex2f(abc[2][0],abc[2][1]);
            glEnd();
            glFlush();
            break;
        

        case 2:
            abc[0][0]=x1*cos(x)+yy1*sin(x);
            abc[0][1]=yy1*cos(x)-x1*sin(x);

            abc[1][0]=x2*cos(x)+y2*sin(x);
            abc[1][1]=y2*cos(x)-x2*sin(x);

            abc[2][0]=x3*cos(x)+y3*sin(x);
            abc[2][1]=y3*cos(x)-x3*sin(x);

            glPointSize(4.0);
            glBegin(GL_LINE_LOOP);
            glVertex2f(abc[0][0],abc[0][1]);
            glVertex2f(abc[1][0],abc[1][1]);
            glVertex2f(abc[2][0],abc[2][1]);
            glEnd();
            glFlush();
            break;
    }
}

void Reflection()
{
    int choice;
    cout<<"1.Reflection about X-axis:";
    cout<<"2.Reflection about Y-axis:";
    cout<<"3.Reflection about Y=X:";
    cout<<"4.Reflection about origin:";

    cout<<"Enter Your Choice:";
    cin>>choice;

    abc[0][0]=x1;
    abc[0][1]=yy1;

    abc[1][0]=x2;
    abc[1][1]=y2;

    abc[2][0]=x3;
    abc[2][1]=y3;

    switch(choice)
    {
        case 1:
            abc[0][0]=x1;
            abc[0][1]=-yy1;

            abc[1][0]=x2;
            abc[1][1]=-y2;

            abc[2][0]=x3;
            abc[2][1]=-y3;

            glPointSize(4.0);
            glBegin(GL_LINE_LOOP);
            glVertex2f(abc[0][0],abc[0][1]);
            glVertex2f(abc[1][0],abc[1][1]);
            glVertex2f(abc[2][0],abc[2][1]);
            glEnd();
            glFlush();
            break;
    
        case 2:
            abc[0][0]=-x1;
            abc[0][1]=yy1;

            abc[1][0]=-x2;
            abc[1][1]=y2;

            abc[2][0]=-x3;
            abc[2][1]=y3;

            glPointSize(4.0);
            glBegin(GL_LINE_LOOP);
            glVertex2f(abc[0][0],abc[0][1]);
            glVertex2f(abc[1][0],abc[1][1]);
            glVertex2f(abc[2][0],abc[2][1]);
            glEnd();
            glFlush();
            break;

        case 3:
            abc[0][0]=yy1;
            abc[0][1]=x1;

            abc[1][0]=y2;
            abc[1][1]=x2;

            abc[2][0]=y3;
            abc[2][1]=x3;

            glPointSize(4.0);
            glBegin(GL_LINE_LOOP);
            glVertex2f(abc[0][0],abc[0][1]);
            glVertex2f(abc[1][0],abc[1][1]);
            glVertex2f(abc[2][0],abc[2][1]);
            glEnd();
            glFlush();
            break;
    
        case 4:
            abc[0][0]=-x1;
            abc[0][1]=-yy1;

            abc[1][0]=-x2;
            abc[1][1]=-y2;

            abc[2][0]=-x3;
            abc[2][1]=-y3;

            glPointSize(4.0);
            glBegin(GL_LINE_LOOP);
            glVertex2f(abc[0][0],abc[0][1]);
            glVertex2f(abc[1][0],abc[1][1]);
            glVertex2f(abc[2][0],abc[2][1]);
            glEnd();
            glFlush();
            break;
    
    }
}




void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0f,0.f,1.0f);
    glBegin(GL_LINES);
    glVertex2f(-1000.0,0.0);
    glVertex2f(1000.0,0.0);
    glVertex2f(0.0,-1000.0);
    glVertex2f(0.0,1000.0);
    glEnd();
    glFlush();
    draw_original();
}

void Transformation(int a)
{
    switch(a)
    {
        case 1:
            Translation();
            break;
        case 2:
            Scaling();
            break;
        case 3:
            Shearing();
            break;
        case 4:
            Rotation();
            break;
        case 5:
            Reflection();
            break;

    }
}

int main(int argc,char **argv)
{
    x1 = 0;
    yy1 = 0;

    x2 = 400;
    y2 = 0;

    x3 = 200;
    y3 = 346.41;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("2D Transformation");
    init();

    submenu_id=glutCreateMenu(Transformation);
    glutAddMenuEntry("1.Translation",1);
    glutAddMenuEntry("2.Scaling",2);
    glutAddMenuEntry("3.Shearing",3);
    glutAddMenuEntry("4.Rotation",4);
    glutAddMenuEntry("5.Reflection",5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}