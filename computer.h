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
                    return (2*i+1)*100+2*j+2;
                }  
                else if(grid[2*i+1][2*j] != '|'){  // check left
                    grid[2*i+1][2*j] = '|';
                    return (2*i+1)*100+2*j;
                }    
                else if(grid[2*i][2*j+1] != '_'){  //check up
                    grid[2*i][2*j+1] = '_';
                    return (2*i)*100+2*j+1;
                }    
                else if(grid[2*i+2][2*j+1] != '_'){  //check down
                    grid[2*i+2][2*j+1] = '_';
                    return (2*i+2)*100+2*j+1;
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
                    return (2*i+1)*100+2*j+2;
                    }  
                    else if(grid[2*i+1][2*j] != '|'){  // check left
                        grid[2*i+1][2*j] = '|';
                        return (2*i+1)*100+2*j;
                    }    
                    else if(grid[2*i][2*j+1] != '_'){  //check up
                        grid[2*i][2*j+1] = '_';
                        return (2*i)*100+2*j+1;
                    }    
                    else if(grid[2*i+2][2*j+1] != '_'){  //check down
                        grid[2*i+2][2*j+1] = '_';
                        return (2*i+2)*100+2*j+1;
                    }  
                }
            }
        }
    }
    return 0;
}


int comp_line_cont(int r,int c,int s,int matrix[s][s])
{
    int cont = 0;
    if(r%2==0)
    {
        if((r/2)-1>=0){
            matrix[(r/2)-1][(c-1)/2] +=1;
            if(matrix[(r/2)-1][(c-1)/2] ==4 ){cont+=1;}
        }
        if(r/2<s){
            matrix[(r/2)][(c-1)/2] +=1;
            if(matrix[(r/2)][(c-1)/2] ==4 ){cont+=1;}
        }
    }
    else if(r%2==1)
    {
        if((c/2)-1>=0){
        matrix[(r-1)/2][(c/2)-1]+=1;
        if(matrix[(r-1)/2][(c/2)-1] ==4 ){cont+=1;}
        }
        if(c/2<s){
            matrix[(r-1)/2][(c/2)]+=1;
            if(matrix[(r-1)/2][(c/2)] ==4 ){cont+=1;}
        }

    }
    return cont;
}

int anti_move(int r,int c,int s,int matrix[s][s])
{
    int cont = 0;
    printf("undoing\n");
    if(r%2==0)
    {
        if((r/2)-1>=0){
            if(matrix[(r/2)-1][(c-1)/2] ==4 ){cont-=1;}
            matrix[(r/2)-1][(c-1)/2] -=1;
            
        }
        if(r/2<s){
            if(matrix[(r/2)][(c-1)/2] ==4 ){cont-=1;}
            matrix[(r/2)][(c-1)/2] -=1;
            
        }
    }
    else if(r%2==1)
    {
        if((c/2)-1>=0){
        matrix[(r-1)/2][(c/2)-1]-=1;
        if(matrix[(r-1)/2][(c/2)-1] ==4 ){cont-=1;}
        }
        if(c/2<s){
            if(matrix[(r-1)/2][(c/2)] ==4 ){cont-=1;}
            matrix[(r-1)/2][(c/2)]-=1;
            
        }

    }
    return cont;
}