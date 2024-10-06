#ifndef BOARDMKR_H
#define BOARDMKR_H

void boardmkr(int x, int y, int board[x][y], char* filename, int *posx, int *posy, char type);
void loadboard(int x, int y, int board[x][y], char* filename, int *posx, int *posy);
void randboard(int x, int y, int board[x][y], char* seed, int *posx, int *posy);


#endif
