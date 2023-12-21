#include <stdio.h>
#include <stdlib.h>
#include "mainMenu.h"
#include "fun1.h"

void line_contribution(int s,int arr[s][s],int r1,int r2,int c1,int c2)
{
    r1 = (r1+2)/2;r2 = (r2+2)/2;c1 = (c1+2)/2;c2 = (c2+2)/2;

    if(r1==r2)
    {
        if (r1-2>-1)
        {
            arr[c1-1][r1-2] += 1;
        }
        if (r1-1 < s)
        {
            arr[c1-1][r1-1] += 1;
        }
    }
    else{
        if (c1-2>-1)
        {
            arr[c1-1][r1-1] += 1;
        }
        else{
            arr[c1-2][r1-1] += 1;
        }
    }
}



int main(){

    settings main_menu;

    main_menu.diff = 1;
    main_menu.mode = 1;

    int r, c,s;
    if(main_menu.diff ==1) {r=5; c=5; s=2;}
    else if(main_menu.diff ==2) {r=11; c=11;s=3;}

    char grid[r][c];
    int arr[s][s] = {};

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j+=2){
            if (i%2 == 0) {grid[i][j] ='.';}
            else {grid[i][j] = ' ';}
            grid[i][j+1]= ' ';
            
        }

    }

    

    while(1)
    {
        char r1c, r2c, c1c, c2c,ch;
        int r1 =0,r2=0,c1=0,c2=0;
        
        //system("cls");
        printlogo();
        printGrid(r, c, grid);
        
        printf("Make a move!\n");
        
        ch =getchar();
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
            ch =getchar();
            
            while(scanf("%1c %1c %1c %1c",  &r1c,&r2c,&c1c, &c2c) !=4){
                printf("Invalid input! Make another move!\n");
            }
            
            
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
         
        if (validate(r1, r2, c1, c2) == 1){
            if (r1 == r2 && grid[r1][c1 +1] != '_'){
                grid[r1][c1 +1] = '_';
                printf("changed\n");
                line_contribution(2,arr,r1,r2,c1,c2);
            }
            else if (c1 == c2 && grid[r1+1][c1] != '|'){
                grid[r1+1][c1] = '|';
                printf("changed\n");
                line_contribution(2,arr,r1,r2,c1,c2);
            }
            else{
                printf("Invalid move!!\n");
            }
            for(int i =0;i<2;i++)
            {
                for(int j = 0;j<2;j++)
                {
                    printf("%i  ",arr[i][j]);
                }
                printf("\n");
            }
            
        }

    }
}