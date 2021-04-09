#include <windows.h> // use proper includes for your system
#include <math.h>
#include <GL/glut.h>
#define PI 3.141592
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);      // set the bg color to a bright white
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
	glLoadIdentity();// to be explained
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);// to be explained
}
void drdisc(double r, int b, int c) {
	double t = 0;
	int N = 5000;
	for (t = 0; t <= 2 * PI; t += PI / N)
	{
		glVertex2f(r * cos(t) + b, r * sin(t) + c);
	}
}
void render() {
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, 1);
	glVertex2f(-1, 1);
	glVertex2f(-1, -1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	drdisc(2.0, -1.0, -1.0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	drdisc(2.0, 1.0, -1.0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	drdisc(2.0, 1.0, 1.0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	drdisc(2.0, -1.0, 1.0);
	glEnd();
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 

	// 원 만들기
	//render();


	// tiling
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			glViewport(i*100, j*100, 100, 100);
			render();
		}
	}
	

	glFlush();		                 // send all output to display 
}
void main(int argc, char** argv)
{
	glutInitWindowSize(400, 400);     // set the window size
	glutInitWindowPosition(100, 150); // set the window position on the screen
	glutCreateWindow("my first attempt"); // open the screen window(with its exciting title)
	glutDisplayFunc(myDisplay);     // register the redraw function
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}
