#include <stdio.h>
#include <stdlib.h>
#include "mainMenu.h"
#include "fun1.h"


int main(){

    settings main_menu;

    main_menu = mainmenu(main_menu);

    int r, c;
    if(main_menu.diff ==1) {r=5; c=5;}
    else if(main_menu.diff ==2) {r=11; c=11;}

    char grid[r][c];

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j+=2){
            if (i%2 == 0) {grid[i][j] ='.';}
            else {grid[i][j] = ' ';}
            grid[i][j+1]= ' ';
            
        }

    }

    int r1, r2, c1, c2;

    while(1)
    {
        system("cls");
        printlogo();
        printGrid(r, c, grid);
        
        printf("Make a move!\n");
        scanf("%d %d %d %d", &r1, &r2, &c1, &c2);
        r1 = r1*2-2; r2 = r2*2-2; c1 = c1*2-2; c2 = c2*2-2;

        while (validate(r1, r2, c1, c2) != 1){
            printf("Invalid input! Make another move!\n");
            scanf("%d %d %d %d", &r1, &r2, &c1, &c2);
        }

        if (validate(r1, r2, c1, c2) == 1){
            if (r1 == r2 && grid[r1][c1 +1] != '_'){
                grid[r1][c1 +1] = '_';
                printf("changed\n");
            }
            else if (c1 == c2 && grid[r1+1][c1] != '|'){
                grid[r1+1][c1] = '|';
                printf("changed\n");
            }
            else{
                printf("Invalid move!!\n");
            }
            
        }

    }
}