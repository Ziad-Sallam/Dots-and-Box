#include <stdio.h>

int comp_move(int r,int c,char grid[r][c],int s,int matrix[s][s])//makes the computer choose a move and returns the index of that move (rc)
{
    
    for(int i = 0; i<s; i++)
    {
        for(int j = 0;j<s;j++)
        {
            if(matrix[i][j] == 3 )
            {
                if(grid[2*i+1][2*j+2] != '|'){  //check right
                    grid[2*i+1][2*j+2] = '|';
                    return (2*i+1)*10+2*j+2;
                }  
                else if(grid[2*i+1][2*j] != '|'){  // check left
                    grid[2*i+1][2*j] = '|';
                    return (2*i+1)*10+2*j+2;
                }    
                else if(grid[2*i][2*j+1] != '_'){  //check up
                    grid[2*i][2*j+1] = '_';
                    return (2*i+1)*10+2*j+2;
                }    
                else if(grid[2*i+2][2*j+1] != '_'){  //check down
                    grid[2*i+2][2*j+1] = '_';
                    return (2*i+1)*10+2*j+2;
                }  

                
            }
        }
    }
    for(int x = 0;x<3;x++){

        for(int i = 0; i<s; i++)
        {
            for(int j = 0;j<s;j++)
            {
                if(matrix[i][j] == x)
                {
                    if(grid[2*i+1][2*j+2] != '|'){  //check right
                    grid[2*i+1][2*j+2] = '|';
                    return (2*i+1)*10+2*j+2;
                    }  
                    else if(grid[2*i+1][2*j] != '|'){  // check left
                        grid[2*i+1][2*j] = '|';
                        return (2*i+1)*10+2*j+2;
                    }    
                    else if(grid[2*i][2*j+1] != '_'){  //check up
                        grid[2*i][2*j+1] = '_';
                        return (2*i+1)*10+2*j+2;
                    }    
                    else if(grid[2*i+2][2*j+1] != '_'){  //check down
                        grid[2*i+2][2*j+1] = '_';
                        return (2*i+1)*10+2*j+2;
                    }  
                }
            }
        }
    }
    return 0;
}


int comp_line_cont(int r,int c,)