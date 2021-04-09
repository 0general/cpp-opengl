#include <cstdlib>
#include <cmath>
#include <GL/glut.h>


void display(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//glEnable(GL_DEPTH_TEST);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	
	
	 /*
	glColor4f(0.0, 0.0, 1.0, 0.5);
	glRecti(1, 8, 19, 4); //파란색 먼저 그리면 destination이 파란색
	 */

	glColor4f(1.0, 0.0, 0.0, 0.5);
	glRecti(12,19,16,1);

	// /*
	glColor4f(0.0, 0.0, 1.0, 0.5);
	glRecti(1, 8, 19, 4); //파란색을 나중에 그리면 source가 파란색
	// */


	

	/*
	!!!!!!!!!!!!!!!!!!!!!!!!!!!1!!!!!여기서부터 추가코드!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//파란색(0.5,0.5,1)이 destination일 때 색상 비교
	//빨간색이 source이므로 source의 알파값 sa = 0.5
	// sa * (0.5, 0.5, 1) + (1-sa) * (1, 0, 0)  = (0.25, 0.25, 0.5) + (0.5, 0, 0)
	glColor3f(0.75, 0.25, 0.5);
	glRecti(9, 11, 12, 8);

	//빨간색(1, 0.5, 0.5)이 destination일 때 색상 비교
	//파란색이 source이므로 source의 알파값 sa = 0.5
	// sa * (1, 0.5, 0.5) + (1-sa) * (0, 0, 1)  = (0.5, 0.25, 0.25) + (0, 0, 0.5)
	glColor3f(0.5, 0.25, 0.75);
	glRecti(16, 4, 19, 1);

	*/

	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow(argv[0]);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 20, 0, 20, -1, 1);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

