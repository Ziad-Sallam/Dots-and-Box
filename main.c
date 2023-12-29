#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mainMenu.h"
#include "fun1.h"
#include "score.h"
#include <windows.h>
//#include "computer.h"
//#include "load.h"


#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

int main(){

    settings main_menu;
    int moves[60];//an array represents the moves in order in the syntax of r*100+c*10+p if p = 1 means player on and player 2 means player 2
    int point = 0;
    main_menu = mainmenu(&point,moves);
    
    
    

    int r, c,s,turn = 1,ch;
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

    for(int i = 0; i<r;i++)
    {
        for(int j = 0;j<c;j++)
        {
            for(int k = 0;k<point;k++)
            {
                
                if(moves[k]/1000 == i && (moves[k]/10)%100 == j)
                {
                    if((moves[k]/1000)%2 == 0)
                    {
                        grid[i][j] = '_';
                    }
                    else{
                        grid[i][j] = '|';
                    }
                }
            }
        }

    }
    for(int k = 0;k<point;k++)
    {
        comp_line_cont(moves[k]/1000,(moves[k]/10)%100,s,arr);
    }    

    char r1c, r2c, c1c, c2c;
    int r1 =0,r2=0,c1=0,c2=0;

    while(endgame(s,arr))
    {

        //system("cls");
        printlogo();
        for(int i =0;i<s;i++)
            {
                for(int j = 0;j<s;j++)
                {
                    printf("%i  ",arr[i][j]);
                }
                printf("\n");
            }
        
        printGrid(r, c, grid,moves,point+1);
        printf("player %i Turn\n", turn);
        printf(CYAN"the score of player %s: %i"RESET"\t ",main_menu.player1.name,main_menu.player1.score);
        printf(MAGENTA"the score of player %s: %i"RESET"\n",main_menu.player2.name,main_menu.player2.score);
        
        
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
         
        if (turn == 1){
            if (r1 == r2 && grid[r1][c1 +1] != '_'){
                grid[r1][c1 +1] = '_';
                printf("move made!\n");
                moves[point] = r1*1000+(c1+1)*10+1;
                point+=1;
                ch = line_contribution(r,c,grid,s,arr,r1,r2,c1,c2,&point,moves,turn);
                main_menu.player1.score+= ch ;
                for (int i = 0;i<s;i++)
                {
                    for(int j = 0;j<s;j++)
                    {
                        if (arr[i][j] == 4 && grid[2*i+1][2*j+1] == ' '){grid[2*i+1][2*j+1] = turn+48;}
                    }
                }
                if (ch == 0){turn = 2;};
                
            }
            else if (c1 == c2 && grid[r1+1][c1] != '|'){
                grid[r1+1][c1] = '|';
                printf("move made!\n");
                moves[point] = (r1+1)*1000+(c1)*10+1;
                point+=1;
                ch = line_contribution(r,c,grid,s,arr,r1,r2,c1,c2,&point,moves,turn);
                
                main_menu.player1.score+= ch ;
                for (int i = 0;i<s;i++)
                {
                    for(int j = 0;j<s;j++)
                    {
                        if (arr[i][j] == 4 && grid[2*i+1][2*j+1] == ' '){grid[2*i+1][2*j+1] = turn+48;}
                    }
                }
                if (ch == 0){turn = 2;};
                                
                
            }
            
                          
            
        }
        if (turn == 2 && main_menu.mode==2){
            if (r1 == r2 && grid[r1][c1 +1] != '_'){
                grid[r1][c1 +1] = '_';
                printf("move made!\n");
                moves[point] = r1*1000+(c1+1)*10+2;
                point+=1;
                ch = line_contribution(r,c,grid,s,arr,r1,r2,c1,c2,&point,moves,turn);
                
                main_menu.player2.score+= ch ;
                for (int i = 0;i<s;i++)
                {
                    for(int j = 0;j<s;j++)
                    {
                        if (arr[i][j] == 4 && grid[2*i+1][2*j+1] == ' '){grid[2*i+1][2*j+1] = turn+48;}
                    }
                }
                if (ch == 0){turn = 1;};
                
            }
            else if (c1 == c2 && grid[r1+1][c1] != '|'){
                grid[r1+1][c1] = '|';
                printf("move made!\n");
                moves[point] = (r1+1)*1000+(c1)*10+2;
                point+=1;
                ch = line_contribution(r,c,grid,s,arr,r1,r2,c1,c2,&point,moves,turn);
                
                main_menu.player2.score+= ch ;
                for (int i = 0;i<s;i++)
                {
                    for(int j = 0;j<s;j++)
                    {
                        if (arr[i][j] == 4&& grid[2*i+1][2*j+1] == ' '){grid[2*i+1][2*j+1]= turn+48;}
                    }
                }
                if (ch == 0){turn = 1;};
                
            }
            
            char z;
            char stop = '1';
            system("cls");
            printlogo();
            printGrid(r, c, grid,moves,point+1);
            printf("Enter S to save the game/ Entre Uto undo this move: ");
            fflush(stdin);
            scanf("%c",&z);
            if (z=='s' || z=='S')
            {
                FILE *file;
                file = fopen("save.txt","w");
                save(main_menu,moves,point,file);
                printf("Saved\n");
                
            }
            else if (z== 'u'|| z=='U')
            {
                int ru,cu;
                ru = moves[point-1]/1000;
                cu = (moves[point-1]/10)%100;
                grid[ru][cu] = ' ';
                anti_move(ru,cu,s,arr);
                point--;
                while (stop != '\n')
                {
                    printGrid(r, c, grid,moves,point+1);
                    printf("r to redo the last move\n");
                    fflush(stdin);
                    scanf("%c",&stop);
                    if (stop == 'r'|| stop == 'R')
                    {
                        point++;
                        ru = moves[point-1]/1000;
                        cu = (moves[point-1]/10)%100;
                        if (ru%2==0)
                        {
                            grid[ru][cu] = '_';
                        }
                        else{grid[ru][cu] = '|';}
                        comp_line_cont(ru,cu,s,arr);

                    }
                }
            }
            
 
        }
        while(turn==2 && main_menu.mode==1)
        {
            int a= comp_move(r,c,grid,s,arr)*10+2;
            int ch = comp_line_cont(a/1000,(a/10)%100,s,arr);
            main_menu.player2.score+=ch;            
            moves[point] = a; 
            point+=1;
            
            for (int i = 0;i<s;i++)
                {
                    for(int j = 0;j<s;j++)
                    {
                        if (arr[i][j] == 4 && grid[2*i+1][2*j+1] == ' '){grid[2*i+1][2*j+1]= turn+48;}
                    }
                }
                if (ch == 0){turn = 1;};      
        }

        fflush(stdin);

    }
    //system("cls");
    printlogo();       
        for(int i =0;i<s;i++)
            {
                for(int j = 0;j<s;j++)
                {
                    printf("%i  ",arr[i][j]);
                }
                printf("\n");
            }
    printGrid(r, c, grid,moves,point+1);

    for(int i = 0;i<point;i++){printf("%i ",moves[i]);}printf("\n");

    printf(CYAN"the score of player %s: %i"RESET"\t ",main_menu.player1.name,main_menu.player1.score);
    printf(MAGENTA"the score of player %s: %i"RESET"\n",main_menu.player2.name,main_menu.player2.score);

    if (main_menu.player1.score>main_menu.player2.score)
    {
        printf("Player One Won !!");
    }
    else if (main_menu.player1.score<main_menu.player2.score)
    {
        printf("Player Two Won !!");
    }
    else{printf("Draw");}
}