#include <stdio.h>
#include <stdlib.h>

void line_contribution(int s,int arr[s][s],int r1,int r2,int c1,int c2)
{
    r1 = (r1+2)/2;r2 = (r2+2)/2;c1 = (c1+2)/2;c2 = (c2+2)/2;

    if(r1==r2)
    {
        if (r1-2>-1)
        {
            arr[r1-2][c1-1] += 1;
        }
        if (r1-1 < s)
        {
            arr[r1-1][c1-1] += 1;
        }
    }
    else{
        if (c1-2>-1)
        {
            arr[r1-1][c1-2] += 1;
        }
        if(c1-1 < s){
            arr[r1-1][c1-1] += 1;
        }
    }
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