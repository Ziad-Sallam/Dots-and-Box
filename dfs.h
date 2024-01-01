#include <stdio.h>
#include "structs.h"
#include "mainMenu.h"
#include <stdlib.h>
#include <string.h>
#include "computer.h"

int checkCont(int r, int c, char grid[r][c], int visited[r][c], int r1, int c1, int r2, int c2){           //function checks around the input
    int nextr, nextc;
    visited[r1][c1]=1; visited[r2][c2]=1;

    if (r1==r2) {
        //general case
        if(r1!=0 && r1!=r && c1!=0) {
            if (grid[r1][c1-1] != ' ') {
                nextr=r1; nextc=c1-2; 
                visited[r1][c1-2]=1;
                if(nextr==r2&&nextc==c2) return 1;
                checkCont(r,c,grid,visited,nextr,nextc,r2,c2);
            }
            if (grid[r1-1][c1] != ' ') {
                nextr=r1-2; nextc=c1;
                visited[r1-2][c1]=1;
                if(nextr==r2&&nextc==c2) return 1;
                checkCont(r,c,grid,visited,nextr,nextc,r2,c2);
            }
            if (grid[r1+1][c1] != ' ') {
                nextr=r1+2; nextc=c1; 
                visited[r1+2][c1]=1;
                if(nextr==r2&&nextc==c2) return 1;
                checkCont(r,c,grid,visited,nextr,nextc,r2,c2);
            } 
        }
        //special cases
        else if(r1==0){
            if (grid[r1][c1-1] != ' ') {
                nextr=r1; nextc=c1-2; 
                visited[r1][c1-2]=1;
                if(nextr==r2&&nextc==c2) return 1;
                checkCont(r,c,grid,visited,nextr,nextc,r2,c2);
            }
            if (grid[r1+1][c1] != ' ') {
                nextr=r1+2; nextc=c1; 
                visited[r1+2][c1]=1;
                if(nextr==r2&&nextc==c2) return 1;
                checkCont(r,c,grid,visited,nextr,nextc,r2,c2);
            }
        }
        else if(r1==r) { 
            if (grid[r1][c1-1] != ' ') {
                nextr=r1; nextc=c1-2; 
                visited[r1][c1-2]=1;
                if(nextr==r2&&nextc==c2) return 1;
                checkCont(r,c,grid,visited,nextr,nextc,r2,c2);
            }
            if (grid[r1-1][c1] != ' ') {
                nextr=r1-2; nextc=c1;
                visited[r1-2][c1]=1;
                if(nextr==r2&&nextc==c2) return 1;
                checkCont(r,c,grid,visited,nextr,nextc,r2,c2);
            }
        }
        else if(c1==0) {
            if (grid[r1-1][c1] != ' ') {
                nextr=r1-2; nextc=c1;
                visited[r1-2][c1]=1;
                if(nextr==r2&&nextc==c2) return 1;
                checkCont(r,c,grid,visited,nextr,nextc,r2,c2);
            }
            if (grid[r1+1][c1] != ' ') {
                nextr=r1+2; nextc=c1; 
                visited[r1+2][c1]=1;
                if(nextr==r2&&nextc==c2) return 1;
                checkCont(r,c,grid,visited,nextr,nextc,r2,c2);
            }
        }
    }

    if (c1==c2){
        //general case
        if(c1!=0 && c1!=c && r1!=0){
            if (grid[r1][c1-1] != ' '){
                nextr=r1; nextc=c1-2;
                visited[r1][c1-2]=1;
                if(nextr==r2&&nextc==c2) return 1;
                checkCont(r,c,grid,visited,nextr,nextc,r2,c2);
            }
            if (grid[r1][c1+1] != ' ') {
                nextr=r1; nextc=c1+2;
                visited[r1][c1+2]=1;
                if(nextr==r2&&nextc==c2) return 1;
                checkCont(r,c,grid,visited,nextr,nextc,r2,c2);
            }
            if (grid[r1-1][c1] != ' ') {
                nextr=r1-2; nextc=c1;
                visited[r1-2][c1]=1;
                if(nextr==r2&&nextc==c2) return 1;
                checkCont(r,c,grid,visited,nextr,nextc,r2,c2);
            }
        }
        //special cases
        else if(c1==0){
            if (grid[r1][c1+1] != ' ') {
                nextr=r1; nextc=c1+2;
                visited[r1][c1+2]=1;
                if(nextr==r2&&nextc==c2) return 1;
                checkCont(r,c,grid,visited,nextr,nextc,r2,c2);
            }
            if (grid[r1-1][c1] != ' ') {
                nextr=r1-2; nextc=c1;
                visited[r1-2][c1]=1;
                if(nextr==r2&&nextc==c2) return 1;
                checkCont(r,c,grid,visited,nextr,nextc,r2,c2);
            }
        }
        else if(c1==c){
            if (grid[r1][c1-1] != ' '){
                nextr=r1; nextc=c1-2;
                visited[r1][c1-2]=1;
                if(nextr==r2&&nextc==c2) return 1;
                checkCont(r,c,grid,visited,nextr,nextc,r2,c2);
            }
            if (grid[r1-1][c1] != ' ') {
                nextr=r1-2; nextc=c1;
                visited[r1-2][c1]=1;
                if(nextr==r2&&nextc==c2) return 1;
                checkCont(r,c,grid,visited,nextr,nextc,r2,c2);
            }
        }
        else if(r1==0){
            if (grid[r1][c1-1] != ' '){
                nextr=r1; nextc=c1-2;
                visited[r1][c1-2]=1;
                if(nextr==r2&&nextc==c2) return 1;
                checkCont(r,c,grid,visited,nextr,nextc,r2,c2);
            }
            if (grid[r1][c1+1] != ' ') {
                nextr=r1; nextc=c1+2;
                visited[r1][c1+2]=1;
                if(nextr==r2&&nextc==c2) return 1;
                checkCont(r,c,grid,visited,nextr,nextc,r2,c2);
            }
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            visited[i][j]=0;
        }
    }
    return 0;
}

int drawCont(int r, int c, char grid[r][c], int visited[r][c],int moves[],int *p,int turn,int s,int matrix[s][s]){
    int count = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if (visited[i][j] == 1 && visited[i][j+2] == 1) {
                grid[i][j+1] = '_';
                count+=comp_line_cont(i,j+1,s,matrix);
                moves[*p] = i*1000+(j+1)*10+turn;
                *p+=1;
            }
            if (visited[i][j] == 1 && visited[i+2][j] == 1) {
                grid[i+1][j] = '|';
                count+=comp_line_cont(i+1,j,s,matrix);
                moves[*p] = (i+1)*1000+j*10+turn;
                *p+=1;
            }
        }
    }
    return count;
}
