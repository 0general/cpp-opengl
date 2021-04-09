#include <GL/glut.h>           //   we will use GLUT (GL UTILITY TOOLKIT)

static float ctrlpoints[9][3]{
	{0.0, 0.0, 0.0}, {2.0, -5.0, 0.0}, {6.0, -3.0, 0.0},
	{6.0, 2.0, 0.0},{6.0, 5.0, 0.0}, {3.0, 7.0, 0.0}, 
	{2.0, 6.0, 0.0},{3.0, 9.0, 0.0}, {6.0, 9.0, 0.0}
};
void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	int i;
	float x; float y;
	int Num = 100;
	double u;
	double v;
	glPointSize(10.0);
	glBegin(GL_POINTS);
	for (int j = 0; j < 9; j++) {
		glVertex2f(ctrlpoints[j][0], ctrlpoints[j][1]);
	}
	glEnd();
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINE_STRIP);
	for (int k= 0; k < 4; k++) {
		glVertex2f(ctrlpoints[k][0], ctrlpoints[k][1]);
	}
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_STRIP);
	for (int k = 3; k < 7; k++) {
		glVertex2f(ctrlpoints[k][0], ctrlpoints[k][1]);
	}
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i <Num; i++)
	{
		u = double(i) / (Num * 1.0);
		v = u + 1 / (Num * 1.0);
		x = ctrlpoints[0][0] * (1 - u) * (1 - u) * (1 - u) + ctrlpoints[1][0] * 3 * (1 - u) * (1 - u) * u + ctrlpoints[2][0] * 3 * (1 - u) * u * u + ctrlpoints[3][0] * u * u * u;
		y = ctrlpoints[0][1] * (1 - u) * (1 - u) * (1 - u) + ctrlpoints[1][1] * 3 * (1 - u) * (1 - u) * u + ctrlpoints[2][1] * 3 * (1 - u) * u * u + ctrlpoints[3][1] * u * u * u;
		glVertex2f(x,y);
		x = ctrlpoints[0][0] * (1 - v) * (1 - v) * (1 - v) + ctrlpoints[1][0] * 3 * (1 - v) * (1 - v) * v + ctrlpoints[2][0] * 3 * (1 - v) * v * v + ctrlpoints[3][0] * v * v * v;
		y = ctrlpoints[0][1] * (1 - v) * (1 - v) * (1 - v) + ctrlpoints[1][1] * 3 * (1 - v) * (1 - v) * v + ctrlpoints[2][1] * 3 * (1 - v) * v * v + ctrlpoints[3][1] * v * v * v;
		glVertex2f(x, y);
	}
	for (i = 0; i < Num; i++)
	{
		u = double(i) / (Num * 1.0);
		v = u + 1 / (Num * 1.0);
		x = ctrlpoints[3][0] * (1 - u) * (1 - u) * (1 - u) + ctrlpoints[4][0] * 3 * (1 - u) * (1 - u) * u + ctrlpoints[5][0] * 3 * (1 - u) * u * u + ctrlpoints[6][0] * u * u * u;
		y = ctrlpoints[3][1] * (1 - u) * (1 - u) * (1 - u) + ctrlpoints[4][1] * 3 * (1 - u) * (1 - u) * u + ctrlpoints[5][1] * 3 * (1 - u) * u * u + ctrlpoints[6][1] * u * u * u;
		glVertex2f(x, y);
		x = ctrlpoints[3][0] * (1 - v) * (1 - v) * (1 - v) + ctrlpoints[4][0] * 3 * (1 - v) * (1 - v) * v + ctrlpoints[5][0] * 3 * (1 - v) * v * v + ctrlpoints[6][0] * v * v * v;
		y = ctrlpoints[3][1] * (1 - v) * (1 - v) * (1 - v) + ctrlpoints[4][1] * 3 * (1 - v) * (1 - v) * v + ctrlpoints[5][1] * 3 * (1 - v) * v * v + ctrlpoints[6][1] * v * v * v;
		glVertex2f(x, y);
	}
	glVertex2f(ctrlpoints[7][0], ctrlpoints[7][1]);
	glVertex2f(ctrlpoints[8][0], ctrlpoints[8][1]);
	glEnd();

	glFlush();
}
int main() {
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bezier");
	glutDisplayFunc(Display);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(-2, 8, -6, 11);
	glutMainLoop();
	return 0;
}




