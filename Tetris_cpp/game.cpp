#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"

int gridX, gridY;

void initGrid(int x, int y){

    gridX = x;
    gridY = y;

}

void unit(int x, int y);
void shapes(int form_id);
void drawGrid(){

    for(int x = 0; x < gridX; x++){
        for(int y = 0; y < gridY; y++){
            unit(x, y);
        }
    }

}

void unit(int x, int y){ // Draw a lines that forms a square

    if(x == 0 || y == 0 || x == gridX-1 || y == gridY-1){
        glLineWidth(3.0);
        glColor3f(1.0, 0.2, 0.2);
    } else{
        glLineWidth(1.0);
        glColor3f(1.0, 1.0, 1.0);
    }


    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x+1, y);
        glVertex2f(x+1, y+1);
        glVertex2f(x, y+1);

    glEnd();

}

void shapes(int form_id){

    int x = 0, y = 0;
    //L
    if(form_id == 1){
        glRectd(x + 2, y + 4, x + 4, y + 8);
    }

}
