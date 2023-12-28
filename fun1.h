
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
    int valid=0;
    if(r1==r2&&(abs(c1-c2)==2))
            valid = 1;
    else if (c1==c2&&(abs(r1-r2)==2))
                valid = 1;
        
    return valid;
 }

//function to get index of the line
//function call if valid=1
void printGrid(int r, int c, char grid[r][c],int moves[],int p){
    
    int turn = 0;
    
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (i%2 == 0) {
                if (grid[i][j] == '.'){
                    printf(YELLOW"%c"RESET,grid[i][j]);
                }
                else{
                    
                    for(int x = 0; x <9;x++)
                    {
                        for(int l = 0;l<p;l++)
                        {
                            if (moves[l]%10 == 1 && ((moves[l])/10)%100 == j && (moves[l]/1000) ==i){turn = 1;break;}
                            else if(moves[l]%10 == 2&& ((moves[l])/10)%100 == j && (moves[l]/1000) ==i){turn = 2;break;}
                        }
                        
                        if(turn==1){printf(CYAN"%c"RESET,grid[i][j]);}
                        else{printf(MAGENTA"%C"RESET,grid[i][j]);}
                        turn = 0;
                        
                    }
                }
                
            }
        }
            if (i%2 == 1)
            {
                
                for(int nr = 0; nr<5;nr++){
                    
                    for(int x = 0; x < c;x++)
                    {
                        for(int l = 0;l<p;l++)
                    {
                        if (moves[l] %10 == 1 && ((moves[l])/10)%100 == x && (moves[l]/1000) ==i){turn =1;break;}
                        else if(moves[l]%10 == 2 && ((moves[l])/10)%100 == x && (moves[l]/1000) ==i){turn = 2;break;}
                    }
                        if(turn==1){printf(CYAN"%c"RESET,grid[i][x]);}
                        else if(turn==2){printf(MAGENTA"%C"RESET,grid[i][x]);}
                        else if(nr == 1){printf("%C",grid[i][x]);}
                        else{printf(" ");}
                        printf("    ");
                        turn = 0;
                    }
                    if(nr < 4)
                    {
                    printf("\n");
                    }
                }          
                
            } 
        
        printf("\n");
        
    }
<<<<<<< HEAD
}
=======
}

>>>>>>> 4ce26ac7b7fe0610243002a7f548436b0b16a38a
