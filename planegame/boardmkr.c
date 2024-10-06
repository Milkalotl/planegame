#include "boardmkr.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

FILE *fp;
void boardmkr(int x, int y, int board[x][y], char* filename, int *posx, int *posy, char type){
  if (type == 'f'){
    loadboard(x, y, board, filename, posx, posy);
  }  
  if (type == 'r'){
    randboard(x, y, board, filename, posx, posy);
  }

}



void loadboard(int x, int y, int board[x][y], char* filename, int *posx, int *posy){
  fp = fopen(filename, "r"); 
  int current;
  for(int e=0; e<x; e++){
   for(int f=0; f<y; f++){
      if (fscanf(fp, "%d", &current) != EOF){
      if (current == 1){*posx = e; *posy = f; current = 0;}
      board[e][f] = current;

      }
      }
    }
}
void randboard(int x, int y,int board[x][y], char* seed, int *posx, int *posy){ 
  
  // how common are clusters (0 and 1 are no 9s at all)
  int prevel = 3;
  // this one
  int rboard[x][y];
  int vboard[x][y];
  int current;
  if (strcmp("NULL", seed) == 0){srandom(time(NULL));}else{
  srandom(atoi(seed));
  }
  // first pass, adds random 0-9 to board
  
  for(int e=0; e<x; e++){
   for(int f=0; f<y; f++){
      
      current = random()%10;
      rboard[e][f] = current;

      }
    }
  // second, makes 9s form in clusters
  for(int e=0; e<x; e++){
   for(int f=0; f<y; f++){
      current = rboard[e][f];
      if(current < prevel && current != 0){
        if (e > 0 && f > 0 && e < x-1 && f < y - 1){
        
        vboard[e+current][f] = 9;
        vboard[e-current][f] = 9;
        vboard[e][f+current] = 9;
        vboard[e][f-current] = 9;
        vboard[e][f] =  9;


      }else{
      vboard[e][f]= 0;
      }}else{
      vboard[e][f] = 0;
      }
      
      }
  }
  // clears lone islands, all have to be connected, and places players and
  // shops 
int shop = 3;
int randcount = (x * y)/50;
int shopcount = rand()%randcount;
for(int e=0; e<x; e++){
  for(int f=0; f<y; f++){
    
    current = vboard[e][f];
    
    if(current == 0){
      
      if(e > 0 && f > 0 && e < x-1 && f < y-1){
        
        if(
          vboard[e+1][f] == 9 &&
          vboard[e-1][f] == 9 &&
          vboard[e][f+1] == 9 &&
          vboard[e][f-1] == 9
        ) {
          board[e][f] = 9;
          }
        }else{
          board[e][f] = 0; 
          if(shopcount== 0){board[e][f] = shop; if(shop==3){shop--;} shopcount = rand()%randcount;}else{shopcount--;}
          if(random() % 34 == 0){*posx = e; *posy = f;}}
     
      }else{
        board[e][f] = 9; 
      }
    }
  }
}
