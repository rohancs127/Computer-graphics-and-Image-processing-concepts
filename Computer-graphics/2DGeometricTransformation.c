#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

int translate,rotate, scale;

void init();
void display();
void menu(int);

void main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D Geometric Transformation");
    init();
    glutDisplayFunc(display);

    translate = glutCreateMenu(menu);
    glutAddMenuEntry("Left", 1);
    glutAddMenuEntry("Right", 2);
    glutAddMenuEntry("Up", 3);
    glutAddMenuEntry("Down", 4);

    rotate = glutCreateMenu(menu);
    glutAddMenuEntry("Clockwise", 5);
    glutAddMenuEntry("Anticlockwise", 6);

    scale = glutCreateMenu(menu);
    glutAddMenuEntry("Minimize", 7);
    glutAddMenuEntry("Maximize", 8);
    
    glutCreateMenu(menu);
    glutAddSubMenu("Translate", translate);
    glutAddSubMenu("Rotate", rotate);
    glutAddSubMenu("Scale", scale);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
}

void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(){
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-100,-100);
    glVertex2f(0,200);
    glVertex2f(100,-100);
    glVertex2f(-100,100);
    glVertex2f(0,-200);
    glVertex2f(100,100);

    glEnd();
    glFlush();
}

void menu(int id){
    if(id==1)
    glTranslatef(-10,0,0);
    if(id==2)
    glTranslatef(10,0,0);
    if(id==3)
    glTranslatef(0,10,0);
    if(id==4)
    glTranslatef(0,-10,0);

    if(id==5)
    glRotatef(-10,0,0,1);
    if(id==6)
    glRotatef(10,0,0,1);

    if(id==7)
    glScalef(0.5,0.5,0);
    if(id==8)
    glScalef(1.5,1.5,0);

    glutPostRedisplay();
}