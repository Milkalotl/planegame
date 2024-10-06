#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "lookuptables.h"
#include "planegame.h"
//shoptemp

void shopfunc(int x, int y){
  int choice;
  printf("\nthis is a shop!!\n");
  printf("choose your item:\n");
  // print out all the shop items
  for(int i=0; i<shoplength; i++){
    printf("%d: %s, ", i+1, items[shop[i]]);
  }
  takeinput(&choice, 'd', 1); 
  choice --;
  // if input is 0, quit;
  if (choice ==  -1){return;}
  
  // uses putinv to put in inventory, prints if inv full
  if (putinv(shop[choice])==1){
    printf("\nInv full, sry\n");
  }

}



// printscreen
void pts(void){

  int a;
    printhud();
	printf("\n");
	
    for(int e=0; e < x; e++){
		for(int f=0; f < y; f++){
			a = board[e][f];
            printf("%s ", icons[a]);
        } 
		printf("\n");
	}

}

// io
void takeinput(int *ptr, char type, int colon){
  int temp;
  char chtemp;
  if(colon == 1){printf("\n: ");}
  do {
      chtemp = fgetc(stdin);
  } while(chtemp == 0 || chtemp == '\n'); 
  
  if(type == 'c'){((chtemp - 'a')>=0)? (temp = chtemp - 'a') : (temp = chtemp - 'A');}
  if(type == 'd'){temp = chtemp - '0';}
  *ptr = temp;
}



// inventory management

void printinv(int nwl){

  printf("inv: ");
  for(int i=0; i<invlength; i++){
    if (nwl == 1){printf("\n");}
    printf("%d: %s, ", i+1, items[inventory[i]]);
  }

}


int putinv(int item){
  for(int i=0; i<invlength; i++){
    if ((inventory[i])==0){
      inventory[i]=item;
      return 0;
    }
  }
  return 1;
}


int checkinv(int item){
  int loc;
  for(int i=0; i<invlength; i++){
    if ((inventory[i])==item){
      return loc;
    }
  }
  return -1;
}


int rminv(int item){
  for(int i=0; i<invlength; i++){
    if ((inventory[i])==item){
      inventory[i]=0;
      return 0;
    }
  }
  return 1;
}

//hud
void printhud(void){
  printf("Player: %s", icons[1]);
  printf("  %s  ", faces[4]);
  printinv(0);

}

