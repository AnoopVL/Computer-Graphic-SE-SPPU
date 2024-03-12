#include<iostream>
#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int menu_id, submenu_id;
float x1,yy1,x2,y2,x3,y3,tx,ty,ABC[3][2];
void init();
void display();
void draw_original();
void menu();
void translation();
void scaling();
void rotation();
void shearing();
void reflection();

int main(int argc, char *argv[]){
    x1=0;
    yy1= 0;
    x2=400;
    y2=0;
    x3=200;
    y3=346.41;

    glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(100,100);
	glutCreateWindow("2D-TRANSFORMATIONS");
	init();
	glutDisplayFunc(display);
	submenu_id=glutCreateMenu(menu);
	glutAddMenuEntry("------MENU------",0);
	glutAddMenuEntry("1)TRANSLATION",1);
	glutAddMenuEntry("2)SCALING",2);
	glutAddMenuEntry("3)ROTATION",3);
	glutAddMenuEntry("4)SHEARING",4);
	glutAddMenuEntry("5)REFLECTION",5);
	menu_id=glutCreateMenu(menu);
	glutAddSubMenu("DRAW",submenu_id);
	glutAddMenuEntry("EXIT",6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return(0);
}

void init()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1000.0,1000.0,-1000.0,1000.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex2i(-1000,0);
	glVertex2i(1000,0);
	glVertex2i(0,-1000);
	glVertex2i(0,1000);
	glEnd();
	glFlush();
	draw_original();
}

void draw_original()
{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1,yy1);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glEnd();
	glFlush();
}

void menu(int key)
{
	switch(key)
	{
		case 1:
			translation();
			break;
		case 2:
			scaling();
			break;
		case 3:
			rotation();
			break;
		case 4:
			shearing();
			break;			
		case 5:
			reflection();
			break;			
		case 6:
			exit(0);
	}
}

void translation()
{	
	cout<<"\n";
	cout<<"Enter the translation factor tx:";
	cin>>%f>>tx;
	cout<<"\n";
	cout<<"Enter the translation factor ty:";
	cin>>%f>>&ty;
	ABC[0][0]=x1;
	ABC[0][1]=yy1;
	ABC[1][0]=x2;
	ABC[1][1]=y2;
	ABC[2][0]=x3;
	ABC[2][1]=y3;
	ABC[0][0]=ABC[0][0]+tx;
	ABC[0][1]=ABC[0][1]+ty;
	ABC[1][0]=ABC[1][0]+tx;
	ABC[1][1]=ABC[1][1]+ty;
	ABC[2][0]=ABC[2][0]+tx;
	ABC[2][1]=ABC[2][1]+ty;
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(ABC[0][0],ABC[0][1]);
	glVertex2f(ABC[1][0],ABC[1][1]);
	glVertex2f(ABC[2][0],ABC[2][1]);
	glEnd();
	glFlush();
}

void scaling()
{
	float sx,sy;	
	cout<<"\n";
	cout<<"Enter the scaling factor sx:";
	cin>>%f>>&sx;
	
	cout<<"\n";
	cout<<"Enter the scaling factor sy:";
	cin>>%f>>&sy;
	
	ABC[0][0]=x1;
	ABC[0][1]=yy1;
	
	ABC[1][0]=x2;
	ABC[1][1]=y2;
	
	ABC[2][0]=x3;
	ABC[2][1]=y3;
	
	ABC[0][0]=x1*sx;
	ABC[0][1]=yy1*sy;
	
	ABC[1][0]=x2*sx;
	ABC[1][1]=y2*sy;
	
	ABC[2][0]=x3*sx;
	ABC[2][1]=y3*sy;
	
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(ABC[0][0],ABC[0][1]);
	glVertex2f(ABC[1][0],ABC[1][1]);
	glVertex2f(ABC[2][0],ABC[2][1]);
	glEnd();
	glFlush();
	
}
