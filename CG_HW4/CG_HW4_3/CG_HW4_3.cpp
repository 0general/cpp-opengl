#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <GL/glut.h>

using namespace std;
static GLuint texName;
struct BitMapFile
{
    int sizeX;
    int sizeY;
    unsigned char* data;
};

BitMapFile* getBMPData(string filename)
{
    BitMapFile* bmp = new BitMapFile;
    unsigned int size, offset, headerSize;

    // Read input file name.
    ifstream infile(filename.c_str(), ios::binary);

    // Get the starting point of the image data.
    infile.seekg(10);
    infile.read((char*)&offset, 4);

    // Get the header size of the bitmap.
    infile.read((char*)&headerSize, 4);

    // Get width and height values in the bitmap header.
    infile.seekg(18);
    infile.read((char*)&bmp->sizeX, 4);
    infile.read((char*)&bmp->sizeY, 4);

    // Allocate buffer for the image.
    size = bmp->sizeX * bmp->sizeY * 24;
    bmp->data = new unsigned char[size];

    // Read bitmap data.
    infile.seekg(offset);
    infile.read((char*)bmp->data, size);

    // Reverse color from bgr to rgb.
    int temp;
    for (int i = 0; i < size; i += 3)
    {
        temp = bmp->data[i];
        bmp->data[i] = bmp->data[i + 2];
        bmp->data[i + 2] = temp;
    }

    return bmp;
}
void InitLight() {
    GLfloat MyLightPosition[] = { 1.0, 2.0, 3.0, 1.0 }; // 광원 위치
    glEnable(GL_LIGHTING);   //  조명 활성화­
    glEnable(GL_LIGHT0);    // 0번 광원 활성화­ 
    glEnable(GL_DEPTH_TEST);  // 음영 효과 위해 (shading)
    glLightfv(GL_LIGHT0, GL_POSITION, MyLightPosition);

    GLfloat MyLightAmbient[] = { 0.0, 0.0, 0.0, 1.0 }; //ambient = red
    GLfloat MyLightDiffuse[] = { 1.0, 1.0, 1.0, 1.0 }; // diffuse = yellow
    GLfloat MyLightSpecular[] = { 1.0, 1.0, 1.0, 1.0 }; // specular = white

    glLightfv(GL_LIGHT0, GL_AMBIENT, MyLightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, MyLightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, MyLightSpecular);

    GLfloat material_ambient[] = { 0.1, 0.1, 0.1, 1.0 };  // ambient (almost black)
    GLfloat material_diffuse[] = { 1, 0, 0, 1.0 };    // diffuse: red
    GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // specular: white
    GLfloat material_shininess[] = { 25.0 };   // shininess:25

    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);


}
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    BitMapFile* image[1];

    // Load the texture.
    image[0] = getBMPData("canTop.bmp");
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[0]->sizeX,
        image[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE,
        image[0]->data);
}

void Display() {

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    //gluLookAt(5.0, 5.0, -5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    //gluLookAt(2.0, -5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    //face 0
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glNormal3f(-1.0, 0.0, 0.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.0, 0.0, 1.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.0, 1.0, 1.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.0, 1.0, 0.0);
    glEnd();

    //face 1
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glNormal3f(-0.707, 0.707, 0.0);
    glTexCoord2f(1, 1 - sqrt(2) / 2);
    glVertex3f(0.5, 1.5, 0.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.0, 1.0, 0.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.0, 1.0, 1.0);
    glTexCoord2f(0, 1 - sqrt(2) / 2);
    glVertex3f(0.5, 1.5, 1.0);
    glEnd();

    //face 2
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glNormal3f(0.707, 0.707, 0.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glTexCoord2f(1.0, sqrt(2) / 2);
    glVertex3f(0.5, 1.5, 0.0);
    glTexCoord2f(0.0, sqrt(2) / 2);
    glVertex3f(0.5, 1.5, 1.0);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(1.0, 1.0, 1.0);
    glEnd();

    //face 3
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glNormal3f(1.0, 0.0, 0.0);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(1.0, 0.0, 1.0);
    glEnd();

    //face 4
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glNormal3f(0.0, -1.0, 0.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(1.0, 0.0, 1.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.0, 0.0, 1.0);
    glEnd();

    float X = 0.66666666666666666666666666666666666667f; // 2/3
    float Y = 0.16666666666666666666666666666666666667f; // 1/6

    //face 5 front
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, 1.0);
    glTexCoord2f(0.0, 1 - Y);
    glVertex3f(0.0, 0.0, 1.0);
    glTexCoord2f(0.0, Y);
    glVertex3f(1.0, 0.0, 1.0);
    glTexCoord2f(X, Y);
    glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(1.0, 0.5);
    glVertex3f(0.5, 1.5, 1.0);
    glTexCoord2f(X, 1 - Y);
    glVertex3f(0.0, 1.0, 1.0);
    glEnd();

    //face 6
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, -1.0);
    glTexCoord2f(0.0, 1 - Y);
    glVertex3f(0.0, 0.0, 0.0);
    glTexCoord2f(X, 1 - Y);
    glVertex3f(0.0, 1.0, 0.0);
    glTexCoord2f(1.0, 0.5);
    glVertex3f(0.5, 1.5, 0.0);
    glTexCoord2f(X, Y);
    glVertex3f(1.0, 1.0, 0.0);
    glTexCoord2f(0.0, Y);
    glVertex3f(1.0, 0.0, 0.0);
    glEnd();


    glFlush();
    glDisable(GL_TEXTURE_2D);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    //init();
    InitLight();
    init();
    glutDisplayFunc(Display);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-1.0, 1.0, -1.0, 1.0, 3.0, 15.0);

    glutMainLoop();
    return 0;
}

