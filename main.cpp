#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define pi 3.142
static GLfloat angle = 0;

static int submenu;
static int mainmenu;
static int value = -1;


//sets up a two-dimensional orthographic viewing region
void init()
{
    gluOrtho2D(-1000, 1000, -1000, 1000);
}

//function to draw nucleus(circular shape)
void nucleus(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5, 0);
    for (float i = 0; i < (2 * pi); i = i + 0.00001)
    {
        glVertex2f(rad * cos(i), rad * sin(i));
    }
    glEnd();
}


//to give the assigned font family and size
void write_char(float x, float y, float z, char *string)
{
    glColor3f(1,1,1);

    //used to position pixel and bitmap write operations
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);
    }

}

//to give the assigned font family and size
void boldhead(float x, float y, float z, char *string)
{
    glColor3f(1, 1, 1);

    //used to position pixel and bitmap write operations
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

// to give the assigned font family and size
void lighthead(float x, float y, float z, char *string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}

//function to draw shells(circular)
void circle(float rad)
{
    glBegin(GL_POINTS);
    glColor3f(1, 0.5, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(rad * cos(i), rad * sin(i));
    }
    glEnd();
}

//electron positioned to the right
void eleright(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(rad + 20 * cos(i), 20 * sin(i));
    }
    glEnd();
}

//electron positioned to the left
void eleleft(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-(rad + 20 * cos(i)), 20 * sin(i));
    }
    glEnd();
}

//electron positioned at the top
void eletop(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(20 * cos(i), rad + 20 * sin(i));
    }
    glEnd();
}

//electron positioned down
void eledown(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(20 * cos(i), -(rad + 20 * sin(i)));
    }
    glEnd();
}

//electron positioned to the top right
void eletopr(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + 20 * cos(i)), ((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}

//electron positioned to the top left
void eletopl(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 175) + 20 * cos(i)), ((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}

//electron positioned to the down left
void eledownl(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 175) + 20 * cos(i)), -((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}

//electron positioned to the down right
void eledownr(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + 20 * cos(i)), -((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}

void display()
{
    glClearColor(0, 0, 0.1, 0.9);

    //initial intro title window
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
    if(value!=-1)
    {
        nucleus(250);
        char nuc[]="NUCLEUS";
        write_char(-80,20,0,nuc);
        char nucleon[]="(NEUTRON + PROTON)";
        write_char(-155,-30,0,nucleon);

        if(value==0)
        {
            char sel[]="SELECT ELEMENT USING MENU";
            boldhead(-430, 900, 0, sel);
        }
    }
        if (value == 1)
    {
        char n[] = "HYDROGEN";
        boldhead(-100, 900, 0, n);
        circle(400);
        char orb[] = "ORBIT";
        write_char(410, 0, 0, orb);
        glPushMatrix(); //saves the current coordinate state
        glRotatef(angle, 0, 0, 1);  //rotation about z axis
        eleright(400);
        char e[] = "ELECTRON";
        write_char(420, 0, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 2)
    {
        char n[] = "HELIUM";
        boldhead(-100, 900, 0, n);
        circle(400);
        char orb[] = "ORBIT";
        write_char(410, 0, 0, orb);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        char e[] = "ELECTRON";
        write_char(420, 0, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 3)
    {
        char n[] = "LITHIUM";
        boldhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char orb[] = "ORBIT";
        write_char(610, 0, 0, orb);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        char e[] = "ELECTRON";
        write_char(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 4)
    {
        char n[] = "BERYLLIUM";
        boldhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char orb[] = "ORBIT";
        write_char(610, 0, 0, orb);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        char e[] = "ELECTRON";
        write_char(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 5)
    {
        char n[] = "BORON";
        boldhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char orb[] = "ORBIT";
        write_char(610, 0, 0, orb);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletopr(600);
        char e[] = "ELECTRON";
        write_char(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 6)
    {
        char n[] = "CARBON";
        boldhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char orb[] = "ORBIT";
        write_char(610, 0, 0, orb);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletopr(600);
        eledownl(600);
        char e[] = "ELECTRON";
        write_char(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 7)
    {
        char n[] = "NITROGEN";
        boldhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char orb[] = "ORBIT";
        write_char(610, 0, 0, orb);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletopr(600);
        eledownl(600);
        eletopl(600);
        char e[] = "ELECTRON";
        write_char(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 8)
    {
        char n[] = "OXYGEN";
        boldhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char orb[] = "ORBIT";
        write_char(610, 0, 0, orb);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletopr(600);
        eledownl(600);
        eletopl(600);
        eledownr(600);
        char e[] = "ELECTRON";
        write_char(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 9)
    {
        char n[] = "FLUORINE";
        boldhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char orb[] = "ORBIT";
        write_char(610, 0, 0, orb);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletopr(600);
        eledownl(600);
        eletopl(600);
        eledownr(600);
        eleleft(600);
        char e[] = "ELECTRON";
        write_char(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 10)
    {
        char n[] = "NEON";
        boldhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char orb[] = "ORBIT";
        write_char(610, 0, 0, orb);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletopr(600);
        eledownl(600);
        eletopl(600);
        eledownr(600);
        eleleft(600);
        eleright(600);
        char e[] = "ELECTRON";
        write_char(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }

        if (value == 11)
    {
        char n[] = "SODIUM";
        boldhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        circle(800);
        char orb[] = "ORBIT";
        write_char(610, 0, 0, orb);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletopr(600);
        eledownl(600);
        eletopl(600);
        eledownr(600);
        eleleft(600);
        eleright(600);
        eletop(800);
        char e[] = "ELECTRON";
        write_char(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }

        if (value == 12)
    {
        char n[] = "MAGNESIUM";
        boldhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        circle(800);
        char orb[] = "ORBIT";
        write_char(610, 0, 0, orb);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletopr(600);
        eledownl(600);
        eletopl(600);
        eledownr(600);
        eleleft(600);
        eleright(600);
        eletop(800);
        eledown(800);
        char e[] = "ELECTRON";
        write_char(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }

        if (value == 13)
    {
        char n[] = "ALUMINIUM";
        boldhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        circle(800);
        char orb[] = "ORBIT";
        write_char(610, 0, 0, orb);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletopr(600);
        eledownl(600);
        eletopl(600);
        eledownr(600);
        eleleft(600);
        eleright(600);
        eletop(800);
        eledown(800);
        eleleft(800);
        char e[] = "ELECTRON";
        write_char(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();

    }

        if (value == 14)
    {
        char n[] = "SILICON";
        boldhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        circle(800);
        char orb[] = "ORBIT";
        write_char(610, 0, 0, orb);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletopr(600);
        eledownl(600);
        eletopl(600);
        eledownr(600);
        eleleft(600);
        eleright(600);
        eletop(800);
        eledown(800);
        eleright(800);
        eleleft(800);
        char e[] = "ELECTRON";
        write_char(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();

    }


    glutSwapBuffers();
}


void rotate()
{
    angle = angle + 5.0; //controls rotation speed
    if (angle > 360)
    {
        angle = angle - 360;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
}


//executes keyboard actions/commands
void keyboard(unsigned char key, int x, int y)
{
    //13 is the ascii code for enter key
    if (key == 13)
    {
        value = 0;
        glClear(GL_COLOR_BUFFER_BIT);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        glutPostRedisplay();
    }
    // 's' key to stop the simulation
    else if (key == 's')
    {
        glutIdleFunc(NULL);
    }

    //32 is the ascii code for spacebar key which will resume simulation
    else if (key == 32)
    {
        glutIdleFunc(rotate);
    }
    // 't' or 'T' key to terminate the program execution completely
    else if (key == 't' || key == 'T')
    {
        exit(0);
    }
    //27 is the ascii code for escape key
    else if (key == 27)
    {
        glutReshapeWindow(700, 700);
    }
}

//mouse press to start simulation
void mousePress(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN) // GLUT_DOWN means mouse button press
            glutIdleFunc(rotate);  //simulation can be started by pressing the left mouse button as well
        break;
    default:
        break;
    }
}

void func_key(int key, int x, int y)
{

    if (key == GLUT_KEY_F10)  //GLUT_KEY_F10 denotes F10 function key
    {
        glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));   //maximizes the window size when F10 key pressed
    }
}

//callback function assigns functionality for every option selected in the menu
void menu(int ser_no)
{
    if (ser_no == 18)
    {
        exit(0);
    }
    else if (ser_no == 15)
    {
        glutIdleFunc(rotate); //calls the callback function, simulation starts
    }
    else if (ser_no == 16)
    {
        glutIdleFunc(NULL);  //stops the simulation
    }
    else if(ser_no==17)
    {
        value=-1;           //goes back to the intro screen
    }
    else
    {
        value = ser_no;
    }
    glClear(GL_COLOR_BUFFER_BIT);

    glutPostRedisplay();
}

//to create the main menu and the submenu and add entries
void createMenu(void)
{
    submenu = glutCreateMenu(menu); //glutCreateMenu creates a popup menu
    //adding the entries of the submenu
    glutAddMenuEntry("HYDROGEN", 1);
    glutAddMenuEntry("HELIUM", 2);
    glutAddMenuEntry("LITHIUM", 3);
    glutAddMenuEntry("BERYLLIUM", 4);
    glutAddMenuEntry("BORON", 5);
    glutAddMenuEntry("CARBON", 6);
    glutAddMenuEntry("NITROGEN", 7);
    glutAddMenuEntry("OXYGEN", 8);
    glutAddMenuEntry("FLUORINE", 9);
    glutAddMenuEntry("NEON", 10);
    glutAddMenuEntry("SODIUM", 11);
    glutAddMenuEntry("MAGNESIUM", 12);
    glutAddMenuEntry("ALUMINIUM", 13);
    glutAddMenuEntry("SILICON", 14);
    //creating the main menu
    mainmenu = glutCreateMenu(menu);
    //on clicking this option, it displayS the submenu
    glutAddSubMenu("SELECT THE ELEMENT", submenu);
    glutAddMenuEntry("START SIMULATION", 15);
    glutAddMenuEntry("STOP SIMULATION", 16);
    glutAddMenuEntry("BACK TO INTRO SCREEN",17);
    glutAddMenuEntry("EXIT", 18);
    //attaching a mouse button for the current window, menu appears when user presses the right mouse button
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);
    glutCreateWindow("ATOM SIMULATION");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mousePress);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(func_key);
    createMenu();
    glutMainLoop();
    return 0;
}
