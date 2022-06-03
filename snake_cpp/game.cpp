#include <ctime>
#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"

extern int pontuacao;
extern bool GameOver;
int gridX, gridY;
short Tdirection= RIGHT;
int TamCobra = 3;
int xP[50]={20,20,20,20,20},yP[50]={20,19,18,17,16};
bool Comida=true;
int comidaX,comidaY;

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

void unit(int x, int y){

    if(x == 0 || y == 0 || x == gridX-1 || y == gridY-1){  //COR BORDA E GRID
        glLineWidth(3.0);
        glColor3f(1.0, 0.5, 0.5);
    } else{
        glLineWidth(1.0);
        glColor3f(0.9, 0.9, 0.9);
    }


    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x+1, y);
        glVertex2f(x+1, y+1);
        glVertex2f(x, y+1);

    glEnd();

}
void drawComida(){  //COMIDA EM LUGAR ALEATORIO
    if(Comida)
    random(comidaX,comidaY);
    Comida=false;
    glColor3f(0.0,1.0,0.0);
    glRectf(comidaX,comidaY,comidaX+1,comidaY+1);
}

void drawCobra(){
    for(int i= TamCobra-1; i >0; i--){
        xP[i] = xP[i-1];
        yP[i] = yP[i-1];
     }
    if(Tdirection==UP)  // NÃO MOVER DIREÇÃO OPOSTA
        yP[0]++;
    else if(Tdirection==DOWN)
        yP[0]--;
    else if(Tdirection==RIGHT)
        xP[0]++;
    else if(Tdirection==LEFT)
        xP[0]--;
    for (int i=0 ; i < TamCobra; i++){
        if (i==0)
            glColor3f(1.0,1.0,1.0);
        else
            glColor3f(1.0,0.0,0.0);
        glRectd(xP[i],yP[i],xP[i]+1,yP[i]+1);
    }
    if(xP[0]==0 || xP[0]== gridX-1 || yP[0]==0 || yP[0]== gridY-1) //GAME OVER QUANDO BATER NA BORDA
        GameOver=true;
    if(xP[0]==comidaX && yP[0]==comidaY){ // TAMANHO
        TamCobra++;
        pontuacao++;
        if(TamCobra>TamMax)
            TamCobra=TamMax;
        Comida=true;
    }
    for (int j=1; j<TamCobra;j++){  // GAME OVER RABO
        if(xP[j]==xP[0] && yP[j]==yP[0])
        GameOver=true;
    }
}

void random(int &x, int &y){    //POSIÇÃO ALEATORIA PRA COMIDA
    int _maxX= gridX-2;
    int _maxY= gridY-2;
    int _min= 1;
    srand(time(NULL));
    x= _min + rand() % (_maxX-_min);
    y= _min + rand() % (_maxY-_min);
}
