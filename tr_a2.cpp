#include <iostream>
#include <GL/glut.h>
#include<math.h>
#define ROUND(X)((int)X+0.5)

void init(void)
{
    glClearColor(0,0,0,0);
    glColor3f(0,1,0);
    glPointSize(2.0);
    gluOrtho2D(-320 , 320 , -240 , 240);
}

void dda_simple(float x1, float y1, float x2, float y2)
{
    float X,Y,dx,dy,step;
    int i = 0;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(x1)>=abs(y1))
    {
        step = abs(x1);
    }else
    {
        step = abs(y1);
    }
    dx = dx / step;
    dy = dy/ step;
    X=x1;
    Y=y1;
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(ROUND(X), ROUND(Y));
    glEnd();
    glFlush();
    while(i<=step)
    {
        glPointSize(4.0);
        glBegin(GL_POINTS);
        glVertex2f(ROUND(X), ROUND(Y));
        glEnd();
        X = X + dx;
        Y = Y + dy;
        glFlush();
        i++;
    }
}

void dda_dashed(float x1, float y1, float x2, float y2)
{
    float X, Y, dx, dy, step, count;
    int i =0;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx)>=abs(dy))
    {
        step = abs(dx);
    }else{
        step = abs(dy);
    }
    dx = dx / step;
    dy = dy / step;
    X = x1;
    Y = y1;
    glBegin(GL_POINTS);
    glVertex2f(ROUND(X), ROUND(Y));
    glEnd();
    glFlush();
    i  = 1;
    count = 1;
    while (i<= step)
    {
        X = X + dx;
        Y = Y + dy;
        if(count <= 10) {
            glBegin(GL_POINTS);
            glVertex2f(ROUND(X), ROUND(Y));
            glEnd();
            glFlush();
            count++;
        }
        if(count > 10){
            count++;
            if(count == 20){
                count = 1;
            }
        }
        i++;
    }
    
}

void dda_dotted(float x1, float y1, float x2, float y2)

{
    float X,Y,dx,dy,step;
    int i, count;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx)>abs(dy)){
        step = abs(dx);
    }else{
        step = abs(dy);
    }
    dx = dx / step;
    dy = dy / step;
    X = x1;
    Y = y1;
    glBegin(GL_POINTS);
    glVertex2f(ROUND(X), ROUND(Y));
    glEnd();
    glFlush();
    while (i <= step)
    {
        X = X + dx;
        Y = Y + dy;
        if(count % 10 == 0){
            glBegin(GL_POINTS);
            glVertex2f(ROUND(X), ROUND(Y));
            glEnd();
            glFlush();
        }
        count++;
        i++;
    }
    
}

void bh_simple(float x1, float y1, float x2, float y2)
{
    float di, ds, dl, dx, dy;
    int i = 0;
    int step;
    dx = x2 - x1;
    dy = y2 - y1; 
    di = 2*dy - dx;
    ds = 2*dy;
    dl = 2*(dy - dx);
    if(abs(dx)>=abs(dy))
    {
        step = abs(dx);
    }else
    {
        step = abs(dy);
    }
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(x1,y1);
    glEnd();
    glFlush();
    while(i <= step){
        if (dx != 0){
            x1++;
            i++;
        }else{
            i++;
        }
        if(di < 0){
            if(dy == 0){
                di = di + ds; 
            }else{
                di = di + ds; 
                y1--;
            }
            //ignore the below comments as they are not applicable now !!
            //comment the above line if you want horizontal line but not -ve slope 
            //keep the above line if you want -ve slope but not horizontal line
        }else{
            if(y2>y1){
                di = di + dl;
                y1++;
            }else{
                di = di + dl;
                y1--;
            }
        }
        glPointSize(4.0);
        glBegin(GL_POINTS);
        glVertex2f(x1,y1);
        glEnd();
        glFlush();
    }
    //few updates made : as -ve slope, horizontal line , straight line was not applicable for this code 
}

void bh_dashed(float x1, float y1, float x2, float y2)
{
    float di, ds, dl, dx, dy;
    int count;
    dx = x2 - x1;
    dy = y2 - y1; 
    di = 2*dy + dx;
    ds = 2*dy;
    dl = 2*(dy + dx);
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(x1,y1);
    glEnd();
    glFlush();
    count = 1;
    while(x1 < x2){
        x1++;
        if(di < 0){
            di = di + ds;
        }else{
            di = di + dl;
            y1++;
        } 
        if(count <= 10){
            glPointSize(4.0);
            glBegin(GL_POINTS);
            glVertex2f(x1,y1);
            glEnd();
            glFlush();
            count++;
        }if(count > 10){
            count++;
            if(count == 20){
                count = 1;
            }
        }
    }

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    // dda_simple(10, 50, 150, 200);
    // dda_dashed(60, 100, 200, 250);
    // dda_dotted(10, 50, 150, 200);
    // bh_simple(10, 50, 150, 200);
    bh_simple(10, 50, 200, 50);
    // bh_dashed(-150, 50, -10, 200);
    // bh_dashed( -150, -200, -10, -50);
    // bh_dashed(10, -200, 150, -50);
    // glEnd();
    glBegin(GL_LINES);
	glVertex2d(-1280 / 2, 0);
	glVertex2d(1280 / 2, 0);
	glVertex2d(0, -720 / 2);
	glVertex2d(0, 720 / 2);
	glEnd();
    glFlush();
}

int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Training DDA line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
