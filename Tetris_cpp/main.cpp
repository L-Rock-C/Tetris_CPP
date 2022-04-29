#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"

#define COLLS 11
#define ROWS 21
#define FPS 1

void timer_callback(int);
void display_callback();
void reshape_callback(int, int);

void init(){

    glClearColor(0.0, 0.0, 0.0, 1.0);
    initGrid(COLLS, ROWS);
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500,500);
    glutCreateWindow("Tetris");
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutTimerFunc(0, timer_callback, 0);
    init();
    glutMainLoop();

    return 0;
}

int xP = 0, yP = 0;

void shapes(int form_id){
    //L1
    if(form_id == 1){
        glRectd(xP + 5, yP + 20, xP + 6, yP + 17);
        glRectd(xP + 6, yP + 18, xP + 7, yP + 17);

    }
    //L2
    if(form_id == 2){
        glRectd(xP + 5, yP + 20, xP + 6, yP + 17);
        glRectd(xP + 5, yP + 18, xP + 4, yP + 17);

    }
    //S1
    if(form_id == 3){
        glRectd(xP + 4, yP + 20, xP + 6, yP + 19);
        glRectd(xP + 5, yP + 19, xP + 7, yP + 18);

    }

    //S2
    if(form_id == 4){
        glRectd(xP + 5, yP + 20, xP + 7, yP + 19);
        glRectd(xP + 4, yP + 19, xP + 6, yP + 18);

    }

    //T
    if(form_id == 5){
        glRectd(xP + 5, yP + 20, xP + 6, yP + 19);
        glRectd(xP + 4, yP + 19, xP + 7, yP + 18);

    }
    //I
    if(form_id == 6){
        glRectd(xP + 5, yP + 20, xP + 6, yP + 16);
    }
    //O
    if(form_id == 7){
        glRectd(xP + 5, yP + 20, xP + 7, yP + 18);
    }

}

void display_callback(){

    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();

    shapes(3);
    yP--;

    glutSwapBuffers();

}

void reshape_callback(int w, int h){

    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, COLLS, 0.0, ROWS, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer_callback(int){

    glutPostRedisplay();
    glutTimerFunc(1000/FPS, timer_callback, 0);

}
