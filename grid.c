#include <stdio.h>

int main()
{
    char size[5][5];
    for (int i = 0;i<5;i++)
    {
        for (int j = 0;j<5;j+=2)
        {
            if (i % 2 == 0)
            {
                size[i][j] = '.';
            }
            else
            {
                size[i][j] = ' ';
            }
            size[i][j+1] = ' ';
            printf("%c %c",size[i][j],size[i][j+1]);
        }
        printf("\n");

    }
}