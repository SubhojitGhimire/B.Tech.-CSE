// Pentagon Rotation About Pivot point (20, -40)

#include <iostream>
#include <GL/glut.h>

using namespace std;

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

void drawPentagon () {
    glBegin (GL_POLYGON);
        glVertex2f (100, 100);
        glVertex2f (120, 50);
        glVertex2f (180, 50);
        glVertex2f (200, 100);
        glVertex2f (150, 150);
    glEnd ();
}

void display () {
    drawQuadrants ();

    glColor3f (1.0, 0.0, 0.0);
    drawPentagon ();

    glTranslatef (-20, 40, 0);
    glRotatef (-90, 0 ,0, 1);
    glTranslatef (20, -40, 0);

    glColor3f (0.0, 1.0, 0.0);
    drawPentagon ();

    glFlush ();
}

int main (int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitWindowSize (1000, 1000);
    glutInitWindowPosition (500, 0);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow ("Pentagon Rotation About Pivot point (20, -40)");
	myinit ();
    glutDisplayFunc (display);
    glutMainLoop ();
    return 0;
}
