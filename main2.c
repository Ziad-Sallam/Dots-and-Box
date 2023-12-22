#include <stdio.h>
#include <stdlib.h>
#include "mainmenu.h"
#include "functions.h"
#include "score.h"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

int main(){

    settings main_menu;

    main_menu = mainmenu();

    int r, c,s,turn = 1;
    main_menu.player1.score = 0;
    main_menu.player2.score = 0;

    if(main_menu.diff ==1) {r=5; c=5;s=2;}
    else if(main_menu.diff ==2) {r=11; c=11;s=5;}
    int arr[s][s] = {};

    char grid[r][c];

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j+=2){
            if (i%2 == 0) {grid[i][j] ='.';}
            else {grid[i][j] = ' ';}
            grid[i][j+1]= ' ';
            
        }
    }

    /*char r1c, r2c, c1c, c2c, ch;*/
    int r1 =0,r2=0,c1=0,c2=0;

    while(endgame(s,arr))
    {
        system("cls");
        for(int i =0;i<s;i++)
            {
                for(int j = 0;j<s;j++)
                {
                    printf("%i  ",arr[i][j]);
                }
                printf("\n");
            }
        printlogo();
        printGrid(r, c, grid, turn);
        
        printf("Make a move!\n");} 
        
        r1 = r1*2-2; r2 = r2*2-2; c1 = c1*2-2; c2 = c2*2-2;

        turn = 1;
        if (validate(r1, r2, c1, c2) == 1){

        if (turn % 2 == 1 ){
            if (r1 == r2 && grid[r1][c1 +1] != '_'){
                grid[r1][c1 +1] = '_';
                printf("Move made!\n");
                main_menu.player1.score+= line_contribution(s,arr,r1,r2,c1,c2);
                
            }
            else if (c1 == c2 && grid[r1+1][c1] != '|'){
                grid[r1+1][c1] = '|';
                printf("Move made!\n");
                main_menu.player1.score+= line_contribution(s,arr,r1,r2,c1,c2);
            }
            else{
                printf("Move has already been made!\n");
            }
            printf(CYAN"the score of player one: %i"RESET"\n",main_menu.player1.score); 
            printGrid(r, c, grid, turn);
            turn +=1;
        }

        if (turn % 2 == 0 ){
            if (r1 == r2 && grid[r1][c1 +1] != '_'){
                grid[r1][c1 +1] = '_';
                printf("Move made!\n");
                main_menu.player2.score+= line_contribution(s,arr,r1,r2,c1,c2);
                
            }
            else if (c1 == c2 && grid[r1+1][c1] != '|'){
                grid[r1+1][c1] = '|';
                printf("Move made!\n");
                main_menu.player2.score+= line_contribution(s,arr,r1,r2,c1,c2);
            }
            else{
                printf("Move has already been made!\n");
            }
            printf(MAGENTA"the score of player one: %i"RESET"\n",main_menu.player2.score); 
            printGrid(r, c, grid, turn);
            turn +=1;
    }
}
else if (validate(r1, r2, c1, c2) == 0){
    printf("Invalid input! Make another move!\n");
}
            
}
