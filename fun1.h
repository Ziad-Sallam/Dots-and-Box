
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


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
void printGrid(int r, int c, char grid[r][c]){
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

//check if a player completed a box function)
/*int checkBox(int i,int r1,int r2,int c1,int c2,int n,int m,char a[][],int round){
        if (c1==c2){
            if(r1<r2){
                if(i==1){a[r1+1][c1]='1';}
                else{a[r1+1][c1]='2';}
            }
            else{
                if(i==1){a[r2+1][c1]='1';}
                else{a[r2+1][c1]='2';}
            }
            }
        else {
            if(c1<c2){
                if(i==1){a[r1][c1+1]='a';}
                else {a[r1][c1+1]='b';}
            }
            else {
                if(i==1){a[r1][c2+1]='a';}
                else {a[r1][c2+1]='b';}
            }
        }

    int flag = 0;
    for (int m=1;m<n;m+=2){
        for (int j=1;j<n;j+=2){
            if(((a[m][j-1] =='1')(a[m][j-1]=='2'))&&((a[m][j+1]=='1')(a[m][j+1]=='2'))&&((a[m-1][j]=='a')(a[m-1][j]=='b'))&&((a[m+1][j]=='a')(a[m+1][j]=='b'))&&(a[m][j]=='S')){
                    if(round==1){
                        a[m][j]='A';
                        flag++;
                    }
                    else if(round==2){
                        a[m][j]='B';
                        flag++;

                    }
            }
        }
    }
   return flag; }*/