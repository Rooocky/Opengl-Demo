#include <iostream>
#include<SOIL.h>
// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <freeglut.h>

//a demo about sun and plant
static int year = 0, day = 0;
void init(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glutWireSphere(1.0, 20, 16);
	glRotatef(year, 0.0, 0.0, 1.0);
	glTranslatef(3.0, 0.0, 0.0);
	glRotatef(day, 0.0, 0.0, 1.0);
	glColor3f(0.0, 1.0, 1.0);
	glutWireSphere(0.4, 10, 8);
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(day / 3, 0.0, 0.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	glutWireSphere(0.2, 8, 6);
	glPopMatrix();
	glutSwapBuffers();
}
void reshape(int h, int w){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0, w / h, 1.0, 60.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, -3, 5, 0, 0, 0, 0, 1, 0);
}
//void keyboard(unsigned char key,int x,int y){
//	switch (key){
//	case'd':
//		day = (day + 10)%360;
//		glutPostRedisplay();
//		break;
//	case'y':
//		year = (year + 10)%360;
//		glutPostRedisplay();
//		break;
//	}
//}
void timer(int value){
	day = (day + 10) % 360;
	year = (year + 10) % 360;
	glutPostRedisplay();
	glutTimerFunc(150, timer, 1);
}
int main(int argc, char**argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("demo");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	/*glutKeyboardFunc(keyboard);*/
	glutTimerFunc(100, timer, 1);
	glutMainLoop();
	return 0;
}
