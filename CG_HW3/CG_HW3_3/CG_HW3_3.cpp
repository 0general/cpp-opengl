// CG_HW3_3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <fstream>
#include <string>
#include <GL/glut.h>

using namespace std;

class MyVertex
{
public:
    float x;
    float y;
    float z;
    MyVertex(float x=0.0f , float y=0.0f , float z=0.0f) :x(x), y(y), z(z) {};
    ~MyVertex() {};
};


class Myface 
{
public:
    int n;  int v1; int v2; int v3;
    Myface(int n=3, int v1=0, int v2=0, int v3=0) : n(n), v1(v1), v2(v2), v3(v3) {};
    ~Myface() {};
};
void drawScene(void) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //gluLookAt(-15.0, 15.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    gluLookAt(-15.0, 15.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    

    int v_num;
    int f_num;
    int edge;
    int sn;
    int su;
    /*string sf;
    string sx;
    string sy;
    string sz;*/
    ///*
    int sf;
    float sx;
    float sy;
    float sz;
    int sxx;
    int syy;
    int szz;
    //*/

    int i1;
    int i2;
    int i3;

    ifstream fin("block.off");
    if (!fin) {
        cout << "파일을 읽어오지 못했습니다." << endl;
    }
    else {
        string line;
        //off
        getline(fin, line);
        // vertex수
        fin >> line;
        v_num = (int)stoi(line);
        MyVertex* vertex = new MyVertex[v_num];
        // face수
        fin >> line;
        f_num = (int)stoi(line);
        Myface* face = new Myface[f_num];
        // edge
        fin >> line;
        edge = (int)stoi(line);
        fin.ignore();

        //vertext배열 저장
        for (int i = 0; i < v_num; i++) {
            /*getline(fin, line);
            sn = line.find(" ");
            sx = line.substr(0, sn);
            su = line.find(" ", sn + 1);
            sy = line.substr(sn+1, su-sn-1);
            sz = line.substr(su+1);

            MyVertex vi((float)stof(sx), (float)stof(sy), (float)stof(sz));*/
            ///*
            fin >> sx >> sy >> sz;
            MyVertex vi(sx, sy, sz);
            //*/
            vertex[i] = vi;
        }

        for (int j = 0; j < f_num; j++) {
            /*getline(fin, line);
            sf = line.substr(0, 1);
            sn = line.find(" ",2);
            sx = line.substr(2, sn-2);
            su = line.find(" ", sn + 1);
            sy = line.substr(sn + 1, su - sn - 1);
            sz = line.substr(su + 1);
            Myface fi((int)stoi(sf), (int)stoi(sx), (int)stoi(sy), (int)stoi(sz));*/
            ///*
            fin >> sf >> sxx >> syy >> szz;
            Myface fi(sf, sxx, syy, szz);
            //*/            
            face[j] = fi;
        }
        for (int j = 0; j < f_num; j++)
        {
            int c = j % 10;
            glColor3f(0.1+0.1 * c, 0.1 + 0.1*c, 0.1 + 0.1 * c);
            glBegin(GL_POLYGON);
            for (int i = 0; i < face[j].n; i++)
            {
                i1 = face[j].v1;
                i2 = face[j].v2;
                i3 = face[j].v3;
                glVertex3f(vertex[i1].x, vertex[i1].y, vertex[i1].z);
                glVertex3f(vertex[i2].x, vertex[i2].y, vertex[i2].z);
                glVertex3f(vertex[i3].x, vertex[i3].y, vertex[i3].z);
            }
            glEnd();
        }
    }
    glFlush();
}

int main(int argc, char** argv)
{
 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("HW3_3");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutDisplayFunc(drawScene);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-30.0, 30.0, -30.0, 30.0, -30.0, 30.0);
    glutMainLoop();

    return 0;
    
}


