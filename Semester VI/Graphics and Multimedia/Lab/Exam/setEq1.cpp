// House

#include <iostream>
#include <GL/glut.h>

using namespace std;

float Tx1 = 200, Ty1 = 200;
float Tx2 = 400, Ty2 = 200;
float Tx3 = 300, Ty3 = 250;
float Sx1 = 250, Sy1 = 200;
float Sx2 = 350, Sy2 = 200;
float Sx3 = 350, Sy3 = 100;
float Sx4 = 250, Sy4 = 100;

void myinit () {
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glClear (GL_COLOR_BUFFER_BIT);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho (-500.0, 500.0, -500.0, 500.0, -500.0, 500.0);
}

void drawQuadrants () {
	glPointSize (3.0);   
	glColor3f (0.0f, 0.5f, 0.5f);
	
	glBegin (GL_LINE_LOOP);
    	glVertex3f (-500.0, 0.0, 0.0);
    	glVertex3f (500.0, 0.0, 0.0);
    glEnd ();
    
    glBegin (GL_LINE_LOOP);
    	glVertex3f (0.0, -500.0, 0.0);
    	glVertex3f (0.0, 500.0, 0.0);
    glEnd ();
}

void display () {
    drawQuadrants ();

    glColor3f (1.0, 0.0, 0.0);
    glBegin (GL_POLYGON);
        glVertex2f (Sx1, Sy1);
        glVertex2f (Sx2, Sy2);
        glVertex2f (Sx3, Sy3);
        glVertex2f (Sx4, Sy4);
    glEnd ();
    
    glColor3f (0.0, 1.0, 0.0);
    glBegin (GL_POLYGON);
        glVertex2f (Tx1, Ty1);
        glVertex2f (Tx2, Ty2);
        glVertex2f (Tx3, Ty3);
    glEnd ();

    glFlush ();
}

int main (int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitWindowSize (1000, 1000);
    glutInitWindowPosition (500, 0);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow ("House");
	myinit ();
    glutDisplayFunc (display);
    glutMainLoop ();
    return 0;
}
