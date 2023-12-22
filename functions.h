#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

//function to check if the input is valid
int validate(int r1,int r2,int c1,int c2){
    int valid;
    if(r1==r2&&(abs(c1-c2)==2))
            valid = 1;
    else if (c1==c2&&(abs(r1-r2)==2))
            valid = 1;
    else if(r1==0||r2==0||c1==0||c2==0)
            valid = 0; 
return valid;
}

    /*ch =getchar();
        while(scanf("%1c %1c %1c %1c",  &r1c,&r2c,&c1c, &c2c) != 4){
                valid = 0;
            }         
        
        r1 = (r1c)-48;
        c2 = (c2c)-48;
        c1 = (c1c)-48;
        r2 = (r2c)-48; 

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
        }*/

//function to get index of the line
//function call if valid=1
void printGrid(int r, int c, char grid[r][c],int turn){
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (i%2 == 0) {
                if (grid[i][j] == '.'){
                    printf(YELLOW"%c"RESET,grid[i][j]);
                }
                else{
                    for(int x = 0; x <9;x++)
                    {
                        if(turn == 1 ){printf(CYAN"%c"RESET,grid[i][j]);}
                    }
                }
                
            }
        }
            if (i%2 == 1)
            {
                for(int nr = 0; nr<4;nr++){
                    for(int x = 0; x < c;x++)
                    {
                        if(turn==1){printf(CYAN"%c"RESET,grid[i][x]);}
                        printf("    ");
                    }
                    if(nr < 3)
                    {
                    printf("\n");
                    }
                }          
                
            } 
        
        printf("\n");
        
    }
}
