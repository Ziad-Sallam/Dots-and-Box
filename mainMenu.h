#include <stdio.h>
#include "structs.h"
#include <stdlib.h>
#include <string.h>

player get_player_data();
settings newGameMenu();

void printlogo()
{
printf(" ___           _             _____       ___   \n");                          
printf("(  _`\\        ( )_          (  _  )     (  _`\\   \n");                         
printf("| | ) |   _   | ,_)  ___    `\\  ,/'     | (_) )   _            __    ___ \n"); 
printf("| | | ) /'_`\\ | |  /',__)    /'_`\\/\\    |  _ <' /'_`\\ (`\\/') /'__`\\/',__)\n"); 
printf("| |_) |( (_) )| |_ \\__, \\   | (_> ,<`   | (_) )( (_) ) >  < (  ___/\\__, \\\n"); 
printf("(____/'`\\___/'`\\__)(____/   `\\___/\\/'   (____/'`\\___/'(_/\\_)`\\____)(____/\n"); 
                                                                         
printf("                                                               by ziad & logy\n\n");
                                                            

}

settings mainmenu()  //this function retuns a pointer to the game settings
{
    settings settings;
    
    system("cls");
    int check = 1;
    int command;
    
    printlogo();
    printf("(1) New Game: \n\n");
    printf("(2) Load Game: \n\n");
    printf("(3) Top 10: \n\n");
    printf("(4) Exit: \n\n");
    printf("Choose: ");
    while (check)
    {
        scanf("%i",&command);
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
        //add a function to open a saved game
    }
    else if (command == 3)
    {
        FILE *file;
        char *str;
        char x[1024];
        printlogo();
        file = fopen("leaderboard.csv","r");
        printf("The leaderboard:\n");
        int line = 0;
        while((fgets(x,1024,file) != NULL)&& line <10)
        {
            if (line ==0)
            {
                line++;
                continue;
            }
            str = strtok(x,",");
            printf("%i : %s\t",line,str);
            str = strtok(NULL,",");
            printf("%s",str);
            line++;

        }      
    }
    return settings;
}


settings newGameMenu()
{
    int check = 1,mode,diff;

    player p1,p2;

    settings settings;
    printlogo();
    printf("Select the game mode: \n\n (1) Human Vs Computer \n\n (2) Human vs Human\n\n Choose: ");
    while (check)
    {
        scanf("%i",&mode);
        if (mode == 1 || mode == 2)
        {
            settings.mode = mode;
            break;
        }
        printf("Error !! Enter the right command\n");
    }

    printf("Enter the name of player 1: ");

    p1 = get_player_data();

    settings.player1=p1;

    settings.player2.name = "Computer";
    settings.player2.score = 0;
    
    if (mode == 2)
    {
        printf("Enter the name of player 2: ");
        
        p2 = get_player_data();

        settings.player2=p2;
    }
    system("cls");
    printlogo();

    printf("Select the game difficulty: \n\n (1) Easy (2X2) \n\n (2) Hard (5X5)\n choose: ");
    while (check)
    {
        scanf("%i",&diff);
        if (mode == 1 || mode == 2)
        {
            settings.diff = diff;
            break;
        }
        printf("Error !! Enter the right command\n");
    }
    return settings; 

}


player get_player_data()
{
    char name[30];
    player player;
    scanf("%s",name);
    player.name = name;
    player.score = 0;
    return player;
}