#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boardmkr.h"
#include "planegame.h"
#include "utils.h"

/// SETTING ALL VARIABLES UP ///

int x = 35;
int y = 35;
int board[35][35];
int inventory[5] = {4,4,0,0,0};
int invlength = 5;
int shop[5] = {1,2,3,4,5};
int shoplength = 5;
int posx, posy;

/// MAIN ---

int main(int argc, char* argv[]){
    boardmkr(x, y, board, argv[1], &posx, &posy, 'r');
    //boardmkr returns the position of player, so there can only be one, even
    //if the board is all 2
    board[posx][posy] = 1;
    //board[9][9] = 2;

    // set shops
    shopset();
    //pts(x, y, board);
	
	int i = 1;
    int flag = 0;	
    while(i>0){
		printf("\ngt: %d\n", i);
        //printf("posx: %d posy: %d", posx, posy);
		if (flag == 0){pts();}
		flag = chooseplayer();
        if (flag==1){i-=flag;}
        i++;
	}
}

/// BIG UNWIELDLY FUNCS THAT I SHOULD FIX ---


int chooseplayer(){
	int row, col, dir, id;
	row = col = dir = 0;
    
    takeinput(&dir, 'c', 1);

	
	//printf("%d", dir);	

	switch (dir){
		//movement functionality
        case ('w' - 'a'): row -=1; break;
		case ('s' - 'a'): row +=1; break;
		case ('d' - 'a'): col +=1; break;
		case ('a' - 'a'): col -=1; break;
        // quit functionality
        case ('q' - 'a'): exit(0); break;
        // inventory functionality
        case ('i' - 'a'): printinv(1); return 1;
        case ('e' - 'a'): return boq();
        // ignore if input isnt correct
        default: printf("\nW.I"); return 1;
	}
	
	//printf("\nrow: %d col: %d  ||  ", row, col);
	id = identifysq(row, col); 
    if(id == 1){ 
	  board[posx][posy] = 0;
	  posx += row;
	  posy += col;
	  if ((posx>=x)||(posx<=-1)){posx = 0;}	
	  if ((posy>=y)||(posy<=-1)){posy = 0;}
	  board[posx][posy] = 1;
    }
    return 0;
}


int identifysq(int row, int col){
	int a = board[posx + row][posy + col];
    //printf("%d", a);
    switch(a){
      //ground
      case 0: return 1; 
      //boq
      case 10: return 1;
      //talker
      case 2: talktalk(); break;
      //shop
      case 3: shopfunc(posx +row, posy + col); break;
      //sea
      case 9: break;

    }
    // all non-empty spaces return 0, change if needed
    return 0;
}

/// NPC FUNCTIONS ---


void talktalk(){
  printf("\n\"Hellow! I am a robot!!\"\n");
}


/// SHOP FUNCTIONS ---


void shopset(){
  //int shopsetter[5] = {0,0,2,3,4};
  // int a = 1;
  //for(int i = 0; i<5; i++){ 
  //  a = shopsetter[i];
  //}
}

void shopprint(){
  for(int i = 0; i<5; i++){ 
    printf("%d: %d\n", i, shop[i]);
  }
}


/// UTILS ---
/// ITEM FUNCTIONALITY ---
int useitem(void){
  int itemtouse;
  printinv(1);
  printf("which item do you want to use?");
  
  takeinput(&itemtouse, 'd', 1);
  return 1;
}




//boq
int boq(void){
    if (checkinv(4) == -1){printf("\nNo boq :/\n"); return 1;}
    
    int row, col, dir, boqposx, boqposy;
	row = col = dir  =  0;
    boqposx = posx; boqposy = posy;
    
    printf("\nwhat direction do you want to boq in?");
    takeinput(&dir, 'c', 1);
	//printf("%d", dir);	

	switch (dir){
		//movement functionality
        case ('w' - 'a'): row -=1; break;
		case ('s' - 'a'): row +=1; break;
		case ('d' - 'a'): col +=1; break;
		case ('a' - 'a'): col -=1; break;
        // quit functionality
        case ('q' - 'a'): return 1;
        default: printf("\nW.I"); return 1;
	}
	boqposx += row;
	boqposy += col;

    if(board[boqposx][boqposy] == 9){
	  board[boqposx][boqposy] = 10;
      rminv(4);
    }else{
    printf("\nnot boqable\n"); return 1;
    }
  return 0;
}
