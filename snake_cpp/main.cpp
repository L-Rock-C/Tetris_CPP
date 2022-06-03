#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"
#include <stdlib.h>

#define COLLS 40
#define ROWS 40
#define FPS 10

extern short Tdirection;
bool GameOver=false;
void timer_callback(int);
void display_callback();
void reshape_callback(int, int);
void keyboard_callback(int,int,int);
int pontuacao=0;

void init(){

    glClearColor(0.0, 0.0, 0.0, 1.0);
    initGrid(COLLS, ROWS);
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(600,600);
    glutCreateWindow("Snake Game");
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutTimerFunc(0, timer_callback, 0);
    glutSpecialFunc(keyboard_callback);
    init();
    glutMainLoop();

    return 0;
}





void display_callback(){

    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    drawCobra();
    drawComida();
    glutSwapBuffers();
    if(GameOver){
        char pontuacao1[10];
        itoa(pontuacao,pontuacao1,10);  //converter int para string
        char texto[50]= "Sua pontuação: ";
        strcat(texto,pontuacao1);
        MessageBox(NULL,texto,"GAME OVER",0);
        exit(0);
    }
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
void keyboard_callback(int key,int,int){    //COMANDOS
    switch(key){
        case GLUT_KEY_UP:
        if(Tdirection!=DOWN)
            Tdirection=UP;
            break;
    case GLUT_KEY_DOWN:
        if(Tdirection!=UP)
            Tdirection=DOWN;
            break;
    case GLUT_KEY_LEFT:
        if(Tdirection!=RIGHT)
            Tdirection=LEFT;
            break;
    case GLUT_KEY_RIGHT:
        if(Tdirection!=LEFT)
            Tdirection=RIGHT;
            break;
    }
}

