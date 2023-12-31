#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct  // the data of the player (name and score)
{
    /* data */
    int score ;
    char *name;
}player;




typedef struct  //a struct to represent the game settings
{
    /* data */
    int diff;
    int mode;
    player player1;
    player player2;

}settings;

#endif