#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED

#include <stdio.h>
#include "structs.h"
#include <stdlib.h>
#include <string.h>


#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

player get_player_data();
settings newGameMenu();
settings load(FILE *f,int *p,int moves[]);

void printlogo()
{
printf(YELLOW" ___           _             _____       ___   \n"RESET);                          
printf(YELLOW"(  _`\\        ( )_          (  _  )     (  _`\\   \n"RESET);                         
printf(YELLOW"| | ) |   _   | ,_)  ___    `\\  ,/'     | (_) )   _            __    ___ \n"RESET); 
printf(YELLOW"| | | ) /'_`\\ | |  /',__)    /'_`\\/\\    |  _ <' /'_`\\ (`\\/') /'__`\\/',__)\n"RESET); 
printf(YELLOW"| |_) |( (_) )| |_ \\__, \\   | (_> ,<`   | (_) )( (_) ) >  < (  ___/\\__, \\\n"RESET); 
printf(YELLOW"(____/'`\\___/'`\\__)(____/   `\\___/\\/'   (____/'`\\___/'(_/\\_)`\\____)(____/\n"RESET); 
                                                                         
printf("                                                               by ziad & logy\n\n");
printf("to exit press CTRL + c\n\n");
                                                            
}

settings mainmenu(int *p,int moves[])  //this function retuns a pointer to the game settings
{
    settings settings;
    
    system("cls");
    int check = 1;
    int command;
    char commandc;

    
    printlogo();
    printf("(1) New Game: \n\n");
    printf("(2) Load Game: \n\n");
    printf("(3) Top 10: \n\n");
    printf("(4) Exit: \n\n");
    printf("Choose: ");
    while (check)
    {
        fflush(stdin);
        scanf("%c",&commandc);
        command = commandc-48;
        if (command == 1 || command == 2|| command == 3 ||command == 4 )
        {
            system("cls");
            break;
        }
        printf("Error !! Enter the right command\n");

    }
    if (command == 1)
    {
        settings = newGameMenu();
        //add a function to open the interface
        
    }
    else if (command == 2)
    {
        FILE *f;
        f = fopen("save.txt","r");

        settings = load(f,p,moves);
        return settings;
        //add a function to open a saved game
    }
    else if (command == 3)
    {
        
        printlogo();
        
        printf("The leaderboard:\n");
        int l = 0;
        char s[10][20];
        int x[20] = {0};
        
        FILE *f;
        f = fopen("leader.txt","r");

    while(1)
    {
        fscanf(f,"%s\n",s[l]);
        fscanf(f,"%i",&x[l]);
        if(x[l] == 0){break;}
        printf("%i : %s\t%i\n",l+1,s[l],x[l]);
        l++;
    }
        char w;
        printf("\npress Enter to go back");
        fflush(stdin);
        scanf("%c",&w);
        mainmenu(p,moves);      
    }
    else if (command == 4){
        exit(0);
    }
    return settings;
}


settings newGameMenu()
{
    int check = 1,mode,diff;
    char modec,diffc;
    

    settings settings;

    settings.player1.name = malloc(30);
    settings.player2.name = malloc(30);


    printlogo();
    printf("Select the game mode: \n\n (1) Human Vs Computer \n\n (2) Human vs Human\n\n Choose: ");
    while (check)
    {
        fflush(stdin);
        scanf("%c",&modec);
        mode = modec-48;
        if (mode == 1 || mode == 2)
        {
            settings.mode = mode;
            break;
        }
        printf("Error !! Enter the right command\n");
    }

    printf("Enter the name of player 1: ");

    //settings.player1 = get_player_data();
    scanf("%s",settings.player1.name);

    
    if (mode ==1){settings.player2.name = "Computer";}
    
    
    if (mode == 2)
    {
        printf("Enter the name of player 2: ");
        
        scanf("%s",settings.player2.name);

        
    }
    system("cls");
    printlogo();

    printf("Select the game difficulty: \n\n (1) Easy (2X2) \n\n (2) Hard (5X5)\n choose: ");
    while (check)
    {
        fflush(stdin);
        scanf("%c",&diffc);
        diff = diffc-48;
        if (mode == 1 || mode == 2)
        {
            settings.diff = diff;
            break;
        }
        printf("Error !! Enter the right command\n");
    }
    return settings; 

}

void save(settings set,int moves[],int p,FILE *file)
{
    
    fprintf(file,"%s\n%s\n %i\n %i\n%i\n%i\n%i\n",
                                    set.player1.name,
                                    set.player2.name,
                                    set.player1.score,
                                    set.player2.score,
                                    set.mode,
                                    set.diff,
                                    p);


    for (int i = 0;i<p;i++)
    {
        fprintf(file,"%i ",moves[i]);
    }
    fclose(file);
}

settings load(FILE *f,int *p,int moves[])
{
    settings set;
    set.player1.name = malloc(30);
    set.player2.name = malloc(30);
    char c ;
    int n;
    printf("Choose a slot:\n  (1) Save 1\n  (2) Save 2\n  (3) Save 3\n");
    fflush(stdin);
    scanf("%c",&c);
    while (c != '1' && c != '3'&&c != '2'){
        printf("Invalid Input!\n");
        fflush(stdin);
        scanf("%c",&c);
    }
    n = c-48;
    if(n ==1)
    {
        f = fopen("save1.txt","r");
    }
    if(n ==2)
    {
        f = fopen("save2.txt","r");
    }
    if(n ==3)
    {
        f = fopen("save3.txt","r");
    }

    fscanf(f,"%30s",set.player1.name);
    fscanf(f,"%30s",set.player2.name);
    fscanf(f,"%i",&set.player1.score);
    fscanf(f,"%i",&set.player2.score);
    fscanf(f,"%i",&set.mode);
    fscanf(f,"%i",&set.diff);
    fscanf(f,"%i",p);
    for (int i = 0;i<*p;i++)
    {
        fscanf(f,"%i",&moves[i]); 
    }
    fclose(f);
    return set;                                

}

#endif