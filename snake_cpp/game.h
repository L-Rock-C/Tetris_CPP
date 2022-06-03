#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2
#define TamMax 50

void initGrid(int, int);
void drawGrid();
void drawCobra();
void drawComida();
void random(int&,int&);

#endif // GAME_H_INCLUDED
