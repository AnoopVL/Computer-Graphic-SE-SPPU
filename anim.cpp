#include <GL/glut.h>

GLfloat ballRadius = 0.5f; // Radius of the bouncing ball
GLfloat ballX = 0.0f;      // Ball's initial X position
GLfloat ballY = 0.0f;      // Ball's initial Y position
GLfloat ballXSpeed = 0.02f; // Ball's initial horizontal speed
GLfloat ballYSpeed = 0.0f;  // Ball's initial vertical speed
GLfloat gravity = -0.001f;  // Acceleration due to gravity

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Update ball's position
    ballX += ballXSpeed;
    ballY += ballYSpeed;
    ballYSpeed += gravity;
    
    // Bounce the ball when it reaches the screen edges
    if (ballX > 1.0f - ballRadius || ballX < -1.0f + ballRadius)
        ballXSpeed = -ballXSpeed;
    if (ballY > 1.0f - ballRadius || ballY < -1.0f + ballRadius)
    {
        ballYSpeed = -ballYSpeed;
        ballYSpeed *= 0.9f; // Damping factor to gradually reduce vertical speed
    }
    
    glTranslatef(ballX, ballY, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glutSolidSphere(ballRadius, 20, 20);
    
    glutSwapBuffers();
}

void reshape(int width, int height)
{
    if (height == 0)
        height = 1;
    
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // Refresh rate: approximately 60 FPS
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Bouncing Ball");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background color
    
    glutMainLoop();
    
    return 0;
}