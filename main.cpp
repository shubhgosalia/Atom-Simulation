#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define pi 3.142


static int value = -1;

void init()
{
    gluOrtho2D(-1000, 1000, -1000, 1000);
}

void boldhead(float x, float y, float z, char *string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}
void lighthead(float x, float y, float z, char *string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}
void display()
{
    glClearColor(0, 0, 0.1, 0.9);

    //title window
    if (value == -1)
    {
        char clg[] = "K.J. Somaiya College of Engineering,Mumbai";
        boldhead(-500, 850, 0, clg);

        char cgv[] = "Computer Graphics & Visualization";
        boldhead(-380, 650, 0, cgv);

        char mp[] = "A Mini Project On";
        lighthead(-150, 450, 0, mp);
        char as[] = "ATOM SIMULATION";
        boldhead(-250, 350, 0, as);

        char mb[] = "Made BY: ";
        boldhead(-650, 0, 0, mb);

        char sg[] = "Shubh Gosalia";
        boldhead(-650, -100, 0, sg);
        char rno1[] = "1911015";
        lighthead(-650, -150, 0, rno1);

        char rs[] = "Rajeshwar Singh";
        boldhead(-650, -250, 0, rs);
        char rno2[] = "1911108";
        lighthead(-650, -300, 0, rno2);

        char gb[] = "GUIDED BY: ";
        boldhead(250, 0, 0, gb);

        char vv[] = "Vaibhav Vasani";
        boldhead(250, -100, 0, vv);
        char ap[] = "Assistant Professor, Dept. Of CSE, KJSCE";
        lighthead(250, -150, 0, ap);

        char en[] = "Press enter to Continue";
        boldhead(-250, -550, 0, en);

        glutSwapBuffers();
        glutDetachMenu(GLUT_RIGHT_BUTTON);
    }
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);
    glutCreateWindow("ATOM SIMULATION");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
