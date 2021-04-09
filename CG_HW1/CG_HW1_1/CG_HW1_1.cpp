#define _USE_MATH_DEFINES //M_PI 사용 위해 
#include <GL/glut.h>
#include <math.h> //cos함수 사용 위해

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);      // set the bg color to a bright white
	glColor3f(0.0f, 0.0f, 0.0f);           // set the drawing color to black 
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
	glLoadIdentity();// to be explained
	gluOrtho2D(0.0, 4.0, -1.0, 1.0);// to be explained
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	glBegin(GL_POINTS);
	for (double x = 0; x <= 4; x += 0.005)
	{
		glVertex2d(x, exp(-x) * cos(2 * M_PI * x));  //f(x) = exp(-x) * cos(2 * M_PI * x)
	}
	glEnd();
	glFlush();		                 // send all output to display 
}
void main(int argc, char** argv)
{
	glutInitWindowSize(400, 200);     // set the window size
	glutInitWindowPosition(100, 150); // set the window position on the screen
	glutCreateWindow("출력"); // open the screen window(with its exciting title)
	glutDisplayFunc(myDisplay);     // register the redraw function
	myInit();
	glutMainLoop();      // go into a perpetual loop
}

