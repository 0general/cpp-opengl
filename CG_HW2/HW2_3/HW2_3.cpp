#include <GL/glut.h>
#include <math.h>

double rt3 = sqrt(3);
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);      // set the bg color to a bright white
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
	glLoadIdentity();// to be explained
	gluOrtho2D(-100.0, 100.0, -100.0, 100.0);// to be explained
}
void polygon(void)
{
	glBegin(GL_POLYGON);
	glVertex2i(20, 0);
	glVertex2i(10,10*rt3);
	glVertex2i(-10, 10*rt3);
	glVertex2i(-20,0);
	glVertex2i(-10, -10*rt3);
	glVertex2i(10, -10*rt3);
	glEnd();
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	glMatrixMode(GL_MODELVIEW);
	polygon();
	for (int i = 1; i <= 6; i++) {
		glColor3f(0.08f * i, 0.08f*i, 0.08*i);
		glLoadIdentity(); // CTM = I
		glRotatef(60 * i, 0, 0, 1);
		glTranslatef(30, 10*rt3, 0);
		polygon();
	}
	for (int i = 1; i <= 6; i++) {
		glColor3f(0.1f * i, 0.1f * i, 0.1 * i);
		glLoadIdentity(); // CTM = I
		glRotatef(60 * i, 0, 0, 1);
		glTranslatef(60, 20 * rt3, 0);
		polygon();
	}
	for (int i = 1; i <= 6; i++) {
		glColor3f(0.15f * i, 0.15f * i, 0.15f * i);
		glLoadIdentity(); // CTM = I
		glRotatef(60 * i, 0, 0, 1);
		glTranslatef(30, 30 * rt3, 0);
		polygon();
	}
	
	
	glFlush();                 // send all output to display 
}
void main(int argc, char** argv)
{
	glutInitWindowSize(400, 400);     // set the window size
	glutInitWindowPosition(100, 150); // set the window position on the screen
	glutCreateWindow("my first attempt"); // open the screen window(with its exciting title)
	glutDisplayFunc(myDisplay);     // register the redraw function
	myInit();
	glutMainLoop();      // go into a perpetual loop
}

