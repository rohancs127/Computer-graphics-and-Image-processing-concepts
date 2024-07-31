#include<stdio.h>
#include<GL/glut.h>

GLfloat v[8][3] = {{-200,-200,200}, {200,-200,200}, {200,200,200}, {-200,200,200}, {-200,-200,-200}, {200,-200,-200}, {200,200,-200}, {-200,200,-200}};

void init();
void display();
void drawcube(GLfloat*, GLfloat*, GLfloat*, GLfloat*);
void keys(unsigned char, int, int);
void spincube();

void main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Geometric Transformation");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keys);
    glutIdleFunc(spincube);
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}

void init(){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-500,500,-500,500,-500,500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glRotatef(0.01, 1.0, 0.0, 1.0);
    glColor3f(1.0,0.0,0.0);
    drawcube(v[0], v[1], v[2], v[3]);
    glColor3f(1.0,1.0,0.0);
    drawcube(v[1], v[5], v[6], v[2]);
    glColor3f(1.0,1.0,1.0);
    drawcube(v[3], v[2], v[6], v[7]);
    glColor3f(1.0,0.0,1.0);
    drawcube(v[4], v[5], v[1], v[0]);
    glColor3f(1.0,1.0,0.0);
    drawcube(v[7], v[6], v[5], v[4]);
    glColor3f(0.0,0.0,1.0);
    drawcube(v[3], v[7], v[4], v[0]);
    glFlush();
}

void drawcube(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d){
    glBegin(GL_POLYGON);
    glVertex3fv(a);
    glVertex3fv(b);
    glVertex3fv(c);
    glVertex3fv(d);
    glEnd();
}

void keys(unsigned char key, int x, int y){
    if(key=='s')
    glScalef(0.5,0.5,0.5);
    if(key=='S')
    glScalef(1.5,1.5,1.5);
    if(key=='t')
    glTranslatef(10,10,10);
    if(key=='T')
    glTranslatef(-10,-10,-10);

    glutPostRedisplay();
}

void spincube(){
    glutPostRedisplay();
}