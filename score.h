#include <stdio.h>
#include <stdlib.h>
#include "computer.h"

int auto_complete(int r,int c,char grid[r][c],int s,int arr[s][s],int *point,int moves[],int turn);

int line_contribution(int r,int c,char grid[r][c],int s,int arr[s][s],int r1,int r2,int c1,int c2,int *point,int moves[],int turn)
{
    int x = 0;
    r1 = (r1+2)/2;r2 = (r2+2)/2;c1 = (c1+2)/2;c2 = (c2+2)/2;

    if(r1==r2)
    {
        if (r1-2>-1)
        {
            arr[r1-2][c1-1] += 1;
            if (arr[r1-2][c1-1] == 4){
                x+=1;
                
                
                }
        }
        if (r1-1 < s)
        {
            arr[r1-1][c1-1] += 1;
            if(arr[r1-1][c1-1] == 4){
                x+=1;
               
                }
            
        }
    }
    else{
        if (c1-2>-1)
        {
            arr[r1-1][c1-2] += 1;
            if(arr[r1-1][c1-2] == 4){
                x+=1;
                
                
                }
        }
        if(c1-1 < s){
            arr[r1-1][c1-1] += 1;
            if(arr[r1-1][c1-1]== 4){
                x+=1;
                
                
                }
        }
    }
    // int z = 1;
    // while(x && z){
    //     z = x;
    //     x+=auto_complete(r,c,grid,s,arr,point,moves,turn);
    //     z-=x;
        
    // }
    return x;
}


int endgame(int s,int arr[s][s])
{
    for (int i = 0;i<s;i++)
    {
        for(int j = 0;j<s;j++)
        {
            if (arr[i][j] != 4){return 1;}
        }
    }
    return 0;
}

int auto_complete(int r,int c,char grid[r][c],int s,int arr[s][s],int *point,int moves[],int turn)
{
    int count = 0;
    for(int y = 0;y<s;y++)
    {
        for(int x = 0;x<s;x++)
        {
            if(arr[y][x] == 3)
            {
                printf("found a box\n");
                    if(grid[2*y+1][2*x+2] != '|'){  //check right
                    grid[2*y+1][2*x+2] = '|';
                    count+=comp_line_cont(2*y+1,2*x+2,s,arr);
                    
                    moves[(*point)] = (2*y+1)*100+(2*x+2)*10+turn;
                    *point+=1;
                    
                    
                    
                    
                    
                    }  
                    else if(grid[2*y+1][2*x] != '|'){  // check left
                        grid[2*y+1][2*x] = '|';
                        count+=comp_line_cont(2*y+1,2*x,s,arr);
                        
                        moves[(*point)] = (2*y+1)*100+(2*x)*10+turn;
                        *point+=1;
                        
    
                    }    
                    else if(grid[2*y][2*x+1] != '_'){  //check up
                        grid[2*y][2*x+1] = '_';
                        count+=comp_line_cont(2*y,2*x+1,s,arr);
                        
                        moves[(*point)] = (2*y)*100+(2*x+1)*10+turn;
                        *point+=1;
                        
   
                    }    
                    else if(grid[2*y+2][2*x+1] != '_'){  //check down
                        grid[2*y+2][2*x+1] = '_';
                        count+=comp_line_cont(2*y+2,2*x+1,s,arr);
                        
                        moves[(*point)] = (2*y+2)*100+(2*x+1)*10+turn;
                        *point+=1;
                        

                    }
                                                          
            }
        }
    }
    printf("%i\n",count);
    return count;   
}