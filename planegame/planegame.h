#ifndef PLANEGAME_H
#define PLANEGAME_H

extern int x;
extern int y;
extern int board[35][35];
extern int inventory[5];
extern int invlength;
extern int shop[5];
extern int shoplength;
extern int posx, posy;



/// MAIN GAMEPLAY FUNCTIONS
// io handling
int chooseplayer(void); 
int identifysq(int row, int col);

// NPC functions
void talktalk(void);

// shopfunctions
void shopset(void);
void shopprint();


// items
int useitem(void);
int boq(void);

#endif
