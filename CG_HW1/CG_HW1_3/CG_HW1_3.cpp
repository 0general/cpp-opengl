#include <windows.h> // use proper includes for your system
#include <math.h>
#include <GL/glut.h>
#define PI 3.141592
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);      // set the bg color to a bright white
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
	glLoadIdentity();// to be explained
	gluOrtho2D(0.0, 50.0, 50.0, 100.0);// to be explained
}
void drdisc(double r, int b, int c) {
	double t = 0;
	int N = 5000;
	glVertex2f(b,c);
	for (t = 0; t <= 2 * PI; t += PI / N)
	{
		glVertex2f(r*cos(t)+b, r*sin(t)+c);
	}
}
void drdisc_2(double a, double b, int c, int d) { // 타원 공식
	double t = 0;
	int N = 5000;
	glVertex2f(c, d); //타원의 중심
	for (t = 0; t <= 2 * PI; t += PI / N)
	{
		glVertex2f(a * cos(t) + c, b * sin(t) + d);
	}
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	
	// 빨간 도넛

	/*
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 0.0);
	drdisc(20.0, 25.0, 75.0); // 빨간색 큰 원 먼저 
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 1.0); // white
	drdisc(10.0, 25.0, 75.0); // 흰색 작은 원 나중에
	glEnd();*/
	
	// 타원 이리저리
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	drdisc_2(20.0,15.0, 25.0, 75.0); // 검은 타원 먼저
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 1.0); // white
	drdisc(14.8, 25.0, 75.0); // 흰색 작은 원 나중에
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	drdisc_2(14.8, 10.0, 25.0, 75.0); // 검은 타원 먼저
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 1.0); // white
	drdisc(9.8, 25.0, 75.0); // 흰색 작은 원 나중에
	glEnd();


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
