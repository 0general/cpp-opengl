#include <GL/glut.h>
#include <math.h>
void myInit(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);      // set the bg color to a black
    glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
    glLoadIdentity();// to be explained
}
void Display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    //gluLookAt(-5.0, -5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    //gluLookAt(0.2, 0.5, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glColor3f(1.0, 1.0, 0.0);
    //glColor3f(1.0, 1.0, 0.85);
    //face 0
    glBegin(GL_POLYGON);
    //glNormal3f();
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 1.0, 1.0);
    glVertex3f(0.0, 1.0, 0.0);
    glEnd();
    //face 1
    glColor3f(1.0, 1.0, 0.0);
    //glColor3f(1.0, 1.0, 0.2);
    glBegin(GL_POLYGON);
    glVertex3f(0.5, 1.5, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 1.0, 1.0);
    glVertex3f(0.5, 1.5, 1.0);
    glEnd();
    //face 2
    glColor3f(1.0, 1.0, 0.0);
    //glColor3f(1.0, 1.0, 0.1);
    glBegin(GL_POLYGON);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(0.5, 1.5, 0.0);
    glVertex3f(0.5, 1.5, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glEnd();
    //face 3
    glColor3f(1.0, 1.0, 0.0);
    //glColor3f(1.0, 1.0, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 0.0, 1.0);
    glEnd();
    //face 4
    glColor3f(1.0, 1.0, 0.0);
    //glColor3f(1.0, 1.0, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 1.0);    
    glEnd();
    //face 5
    glColor3f(1.0, 1.0, 0.0);
    //glColor3f(1.0, 1.0, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, 0.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(0.5, 1.5, 1.0);
    glVertex3f(0.0, 1.0, 1.0);
    glEnd();
    //face 6
    glColor3f(1.0, 1.0, 0.0);
    //glColor3f(1.0, 1.0, 0.8);
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(0.5, 1.5, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);
    glEnd();


    glFlush();
}

int main() {
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("basic barn");
    glutDisplayFunc(Display);
    myInit();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 15.0);

    glutMainLoop();
    return 0;
}

