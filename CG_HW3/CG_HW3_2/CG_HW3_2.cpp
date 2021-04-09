
#include <cstdlib>
#include <iostream>
using namespace std;
#include <GL/glut.h>

void DrawPixel(int x, int y)
{
    glPointSize(10.0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}


void MidpointLine(int x1, int y1, int x2, int y2) {
    int dx, dy, incN, incrE, incrNE, D, x, y;
    dx = x2 - x1; dy = y2 - y1;
    incrNE = 2 * dy - 2 * dx; //동북쪽 화소 선택시 증가분
    x = x1; y = y1; //첫 화소
    if (abs(dy) > abs(dx)) {
        D = dy - 2 * dx;
        incN = -2 * dx;
        DrawPixel(x, y); //첫 화소 그리기
        while (y < y2) {
            cout << "D  = " << D << endl;
            if (D > 0) { //결정변수가 양수. 북쪽화소 선택
                D += incN; //결정변수 증가
                y++; //다음 화소는 북쪽
            }
            else { //결정변수가 음수. 동북쪽 화소 선택
                D += incrNE; //결정변수 증가
                x++; y++; //다음 화소는 동북쪽
            }
            DrawPixel(x, y); //화소 그리기
        }
    }
    else { // 기울기 절대값이 1 이하일 때 
        D = 2 * dy - dx; //결정변수 값을 초기화
        incrE = 2 * dy; //동쪽 화소 선택시 증가분
        DrawPixel(x, y); //첫 화소 그리기
        while (x < x2) {
            cout << "D  = " << D << endl;
            if (D <= 0) { //결정변수가 음수. 동쪽화소 선택
                D += incrE; //결정변수 증가
                x++; //다음 화소는 동쪽
            }
            else { //결정변수가 양수. 동북쪽 화소 선택
                D += incrNE; //결정변수 증가
                x++; y++; //다음 화소는 동북쪽
            }
            DrawPixel(x, y); //화소 그리기
        }
    }

}

void drawScene(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);

    MidpointLine(0, 0, 5, 9);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("MidpointLine.cpp");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glutDisplayFunc(drawScene);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 6.0, -1.0, 10.0);
    glutMainLoop();

    return 0;
}


