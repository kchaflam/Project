#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#ifndef STRUCTS
#define STRUCTS

#define MAX_LEN 8 //The maximum lenght of the words.

/*
 * Struct with all the information about the player.
 */
typedef struct
{
    int finds;
    int mistakes;
    int score;
} player;

/*
 * Struct to save a word and its information needed for the game.
 */
typedef struct
{
    char word[MAX_LEN]; //The word saved.
    int num_char; //The lenght of the word.
    int direction;
    int startPos[2];
} word;

/*
 * Struct with the game board and settings of the game.
 */
typedef struct
{
    char** table; //The game board with all the characters.
    int size; //The size of the board generated.
    int num_words; //The number of words in the game.
} wordsearch;

#endif