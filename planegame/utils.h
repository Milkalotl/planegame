#ifndef UTILS_H
#define UTILS_H

//shoptemp

void shopfunc(int x, int y);

//printscreen
void pts(void);

// io
void takeinput(int *ptr, char type, int colon);

// inventory management

void printinv(int nwl);
int putinv(int item);
int checkinv(int item);
int rminv(int item);


// hud
void printhud(void);
#endif
