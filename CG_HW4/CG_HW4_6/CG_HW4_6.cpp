#include <GL/glut.h>           //   we will use GLUT (GL UTILITY TOOLKIT)

static float ctrlpoints[7][3]{
	{12.0, 3.0, 0.0}, {4.0, 19.0, 0.0}, {16.0, 33.0, 0.0},
	{24.0, 22.0, 0.0},{34.0, 32.0, 0.0}, {38.0, 24.0, 0.0},
	{32.0, 16.0, 0.0}
};

double a(double t, double k) {
	return (t - k) * (t - k) / 2;
}
double b(double t, double k) {
	return -(t - 2 / 3)*(t - 2 / 3) +0.75;
}
double c(double t, double k) {
	return (3 - t + k) * (3 - t + k) / 2;
}
void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	int i;
	float x; float y;
	float sx; float sy;
	int Num = 100;
	double u1;
	double v1;
	double u2;
	double v2;
	double u3;
	double v3;
	glPointSize(10.0);
	glBegin(GL_POINTS);
	for (int j = 0; j < 7; j++) {
		glVertex2f(ctrlpoints[j][0], ctrlpoints[j][1]);
	}
	glEnd();
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINE_STRIP);
	for (int k = 0; k < 7; k++) {
		glVertex2f(ctrlpoints[k][0], ctrlpoints[k][1]);
	}
	glEnd();

	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_LINE_STRIP);
	for (int k = 0; k <= 6; k++) {		
		for (i = 0; i < Num; i++)
		{
			u1 = double(i) / (Num * 1.0); //0~1
			u2 = u1 + 1; // 1~2
			u3 = u1 + 2; // 2~3

			v1 = u1 + 1 / (Num * 1.0);
			v2 = v1 + 1;
			v3 = v2 + 1;

			
			x = ctrlpoints[k][0] * a(u1, k);
			y = ctrlpoints[k][1] * a(u1, k);
			glVertex2f(x, y);
			x = ctrlpoints[k][0] * a(v1, k);
			y = ctrlpoints[k][1] * a(v1, k);
			glVertex2f(x, y);
			
			x = ctrlpoints[k][0] * b(u2, k);
			y = ctrlpoints[k][1] * b(u2, k);
			glVertex2f(x, y);
			x = ctrlpoints[k][0] * b(v2, k);
			y = ctrlpoints[k][1] * b(v2, k);
			glVertex2f(x, y);
			
			x = ctrlpoints[k][0] * c(u3, k);
			y = ctrlpoints[k][1] * c(u3, k);
			glVertex2f(x, y);
			x = ctrlpoints[k][0] * c(v3, k);
			y = ctrlpoints[k][1] * c(v3, k);
			glVertex2f(x, y);
			
		}
	}
	glEnd();

	glFlush();
}
int main() {
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("quadratic-spline");
	glutDisplayFunc(Display);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(0, 45, 0, 40);
	glutMainLoop();
	return 0;
}




