#include <cmath>
#include <GL/glut.h>
static float t = 0.0;  //Time parameter.
static float g = 0.2;   //Gravitational accelaration.
void DoTimer(int value)
{
    t += 0.4;
    glutPostRedisplay();
    glutTimerFunc(30, DoTimer, 1);

}


void init(void)
{
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

void drawScene()

{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(-1.0, 10, -50.0, 5, 5, -25.0, 0.0, 1.0, 0.0);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-15.0- sqrt(2) * 3, 15.0, -20.0);
    glVertex3f(25, -25 - sqrt(2) * 3, -20.0);
    glVertex3f(25, -25 - sqrt(2) * 3, -30.0);
    glVertex3f(-15.0 - sqrt(2) * 3, 15.0, -30.0);
    glEnd();

    glTranslatef(-15.0, 15.0, -25.0);
    glTranslatef((g / 2.0) * t * t, - (g / 2.0) * t * t, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glutSolidSphere(3.0, 30, 30);

    glutSwapBuffers();
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-10.0, 10.0, -5.0, 5.0, 5.0, 100.0);
}
int main()

{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("aaa");
    init();
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutTimerFunc(30, DoTimer, 1);
    glutMainLoop();
    return 0;

}






