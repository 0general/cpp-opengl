#include <cstdlib>
#include <cmath>
#include <iostream>
#include <GL/glut.h>

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);       // the background color is white
	glColor3f(1.0f, 0.0f, 0.0f);         // the drawing color is black 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 50.0);
}

void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -15.0); // T1,   CTM=T1
	glTranslatef(5, 0, 0);  // T2,            CTM=T1?T2
	glutWireCube(5.0);   // V1,               T1?(T2 ?????)      
	glTranslatef(0, 10, 0);  // T3           CTM=T1?T2?T3
	glutWireSphere(2.0, 10, 8); //V2     T1?T2 ?"(T" ???????) 
	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("box.cpp");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutDisplayFunc(drawScene);
	myInit();

	glutMainLoop();
	return 0;
}






