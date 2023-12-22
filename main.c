#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mainMenu.h"
#include "fun1.h"
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

    int r, c,s,l,turn = 1;
    main_menu.player1.score = 0;
    main_menu.player2.score = 0;
    int point = 0;
   
    

    if(main_menu.diff ==1) {r=5; c=5;s=2;l=12;}
    else if(main_menu.diff ==2) {r=11; c=11;s=5;l=60;}
    int arr[s][s] = {};
    int moves[l];//an array represents the moves in order in the syntax of r*100+c*10+p if p = 1 means player on and player 2 means player 2
    
    char grid[r][c];

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j+=2){
            if (i%2 == 0) {grid[i][j] ='.';}
            else {grid[i][j] = ' ';}
            grid[i][j+1]= ' ';
            
        }
    }

    char r1c, r2c, c1c, c2c;
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
        printGrid(r, c, grid,l,moves,point+1);
        printf(MAGENTA"the score of player two: %i"RESET"\n",main_menu.player2.score);
        printf(CYAN"the score of player one: %i"RESET"\n",main_menu.player1.score);
        
        printf("Make a move!\n");
        
        
        //ch =getchar();
        fflush(stdin);
        while(scanf("%1c %1c %1c %1c",  &r1c,&r2c,&c1c, &c2c) != 4){
                printf("Invalid input! Make another move!\n");
            }   
               
        
        r1 = (r1c)-48;
        c2 = (c2c)-48;
        c1 = (c1c)-48;
        r2 = (r2c)-48;
       
        r1 = r1*2-2; r2 = r2*2-2; c1 = c1*2-2; c2 = c2*2-2;
        
        while (validate(r1, r2, c1, c2) != 1){
            printf("Invalid input! Make another move!\n");
            fflush(stdin);
            
            while(scanf("%1c %1c %1c %1c",  &r1c,&r2c,&c1c, &c2c) !=4){
                
                printf("Invalid input! Make another move!\n");
            }
            fflush(stdin);
            
            
            r1 = (r1c)-48;
            c2 = (c2c)-48;
            c1 = (c1c)-48;
            r2 = (r2c)-48;
            r1 = r1*2-2; r2 = r2*2-2; c1 = c1*2-2; c2 = c2*2-2;
        }

        if (c1 > c2)
        {
            c1 = c1 ^ c2;
            c2 = c1 ^ c2;
            c1 = c1 ^ c2;
        }

        if (r1 > r2)
        {
            r1 = r1 ^ r2;
            r2 = r1 ^ r2;
            r1 = r1 ^ r2;
        }
         
        if (turn%2 == 1){
            if (r1 == r2 && grid[r1][c1 +1] != '_'){
                grid[r1][c1 +1] = '_';
                printf("move made!\n");
                moves[point] = r1*100+(c1+1)*10+1;
                point+=1;
                main_menu.player1.score+= line_contribution(s,arr,r1,r2,c1,c2);
                
            }
            else if (c1 == c2 && grid[r1+1][c1] != '|'){
                grid[r1+1][c1] = '|';
                printf("move made!\n");
                moves[point] = (r1+1)*100+(c1)*10+1;
                point+=1;
                main_menu.player1.score+= line_contribution(s,arr,r1,r2,c1,c2);
                
            }
            else{
                printf("Move has already been made!\n");
            }
                          
            
        }
        if (turn%2 == 0){
            if (r1 == r2 && grid[r1][c1 +1] != '_'){
                grid[r1][c1 +1] = '_';
                printf("move made!\n");
                moves[point] = r1*100+(c1+1)*10+2;
                point+=1;
                main_menu.player2.score+= line_contribution(s,arr,r1,r2,c1,c2);
                
            }
            else if (c1 == c2 && grid[r1+1][c1] != '|'){
                grid[r1+1][c1] = '|';
                printf("move made!\n");
                moves[point] = (r1+1)*100+(c1)*10+2;
                point+=1;
                main_menu.player2.score+= line_contribution(s,arr,r1,r2,c1,c2);
                
            }
            else{
                printf("Move has already been made!\n");
            }
            
                
            
        }
        turn+=1;
        fflush(stdin);

    }
    printGrid(r, c, grid,l,moves,point+1);
}