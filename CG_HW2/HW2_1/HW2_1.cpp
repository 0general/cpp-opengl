#include <GL/glut.h>
#include <math.h>

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);      // set the bg color to a bright white
	glColor3f(0.0f, 0.0f, 0.0f);           // set the drawing color to black 
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
	glLoadIdentity();// to be explained
	gluOrtho2D(-100.0, 100.0, -100.0, 100.0);// to be explained
}
void  spoke(void)
{
	double rt3 = sqrt(3);
	glLineWidth(1.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(1, 1);
	glVertex2i(10, 1);         
	glVertex2i(15, 1);
	glVertex2i(19, 4 * rt3 + 1);
	glVertex2i(20.5, 1 + (7 / 2) * rt3);
	glVertex2i(17, 1);
	glVertex2i(22, 1);
	glVertex2i(25, 1 + 3 * rt3);
	glVertex2i(26.5, 1 + (5/2) * rt3);
	glVertex2i(24, 1);
	glVertex2i(29, 1);
	glVertex2i(30, 0);
	glEnd();
}

void  rotate(void)
{
	spoke();
	for (int i = 1; i <= 6; i++)
	{
		glRotatef(60, 0, 0, 1);
		spoke();
	}

	glEnd();
}
void  myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);// clear the screen
	rotate();
	glScalef(-1, 1, 1);
	rotate();
	glFlush();		                 // send all output to display 
}
void main(int argc, char** argv)
{
	glutInitWindowSize(500, 500);     // set the window size
	glutInitWindowPosition(200, 150); // set the window position on the screen
	
	glutCreateWindow("my first attempt"); // open the screen window(with its exciting title)
	glutDisplayFunc(myDisplay);     // register the redraw function
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}
