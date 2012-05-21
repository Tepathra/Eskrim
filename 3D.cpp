/*Nama File       : 3D.cpp
  Team Programmer : Amin Abdull Rachman (10108470)
                    Jafrin J.J.S (10108481)
                    Trifonio M.F.S. Da Costa (10108512)
       		        Atep Nurdin (10108489)

       		        Tekan W untuk memunculkan gambar / Menjauhkan Gambar
       		        Tekan S untuk mendekatkan gambar
       		        Tekan X untuk memutar searah sumbu x
       		        Tekan Y untuk memutar searah sumbu Y
       		        Tekan Z untuk memutar searah sumbu Z
  Deskripsi       : Tugas Openg GL 3D*/

#include "stdlib.h"
#include "gl/glut.h"

int w=1024, h=720, z=0;
int x1=0, y1=0, sudut=0, z1=0, skalaX=0, skalaY=0;

void renderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.4,0,0,0);
    glLoadIdentity();
    glTranslatef(0,0,z);
    glRotatef(sudut,x1,y1,z1);

    //ESKRIM

    glPushMatrix();
    glTranslatef(0,4,0);
    glColor3f(0.7,1,1);
    glutWireSphere(2.5,200,50);
    glPopMatrix();

    //CONE

    glPushMatrix();
    glTranslatef(0,2.5,0);
    glRotatef(90,1,0,0);
    glColor3f(0.8,0.5,0.1);
    glutWireCone(2,4,200,50);
    glPopMatrix();
    glutSwapBuffers();
}

void resize(int w1,int h1)
{
    glViewport(0,0,w1,h1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(float) w1/(float) h1, 1.0,300.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void myKeyboard(unsigned char key, int x, int y)
{
    if (key =='s') z+=5;
    else if (key == 'w') z-=5;
    else if (key == 'x')
    {
        x1=1;
        y1=0;
        z1=0;
        sudut+=10;
    }
    else if (key == 'y')
    {
        y1=1;
        x1=0;
        z1=0;
        sudut+=-10;
    }
    else if (key == 'z')
    {
        y1=0;
        x1=0;
        z1=1;
        sudut+=-10;
    }
}

void mySpecialKeyboard(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        z+=5;
        break;
    case GLUT_KEY_DOWN:
        z-=5;
        break;
    }
}

void init(void)
{
    glClearColor(0,0,0,0);
    GLfloat modelambient[] = { 0, 0.2, 0.5, 0.5 };
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glColorMaterial ( GL_FRONT_AND_BACK, GL_EMISSION ) ;
    glEnable ( GL_COLOR_MATERIAL ) ;
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, modelambient);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(GLdouble) w/(GLdouble) h, 1.0,300.0);
    glMatrixMode(GL_MODELVIEW);

}

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(50,timer,0);
}




int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(w,h);
    glutCreateWindow("3D Eskrim, Tekan W untuk memunculkan gambar");
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
    glutDisplayFunc(renderScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(myKeyboard);
    glutSpecialFunc(mySpecialKeyboard);
    glutTimerFunc(1,timer,0);
    init();
    glutMainLoop();
}
