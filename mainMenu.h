#include <stdio.h>
#include "structs.h"
#include <stdlib.h>
#include <string.h>

player get_player_data();
settings newGameMenu();
settings load(FILE *f,int *p,int moves[]);

void printlogo()
{
printf(" ___           _             _____       ___   \n");                          
printf("(  _`\\        ( )_          (  _  )     (  _`\\   \n");                         
printf("| | ) |   _   | ,_)  ___    `\\  ,/'     | (_) )   _            __    ___ \n"); 
printf("| | | ) /'_`\\ | |  /',__)    /'_`\\/\\    |  _ <' /'_`\\ (`\\/') /'__`\\/',__)\n"); 
printf("| |_) |( (_) )| |_ \\__, \\   | (_> ,<`   | (_) )( (_) ) >  < (  ___/\\__, \\\n"); 
printf("(____/'`\\___/'`\\__)(____/   `\\___/\\/'   (____/'`\\___/'(_/\\_)`\\____)(____/\n"); 
                                                                         
printf("                                                               by ziad & logy\n\n");
printf("to exit press CTRL + c\n\n");
                                                            
}

settings mainmenu(int *p,int moves[])  //this function retuns a pointer to the game settings
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
        FILE *f;
        f = fopen("save.txt","r");

        settings = load(f,p,moves);
        return settings;
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
    else if (command == 4){
        exit(0);
    }
    return settings;
}


settings newGameMenu()
{
    int check = 1,mode,diff;
    

    settings settings;

    settings.player1.name = malloc(30);
    settings.player2.name = malloc(30);


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

void save(settings set,int moves[],int p,FILE *file)
{
    file = fopen("save.txt","w");
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

    f = fopen("save.txt","r");

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

