#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#ifndef STRUCTS
#define STRUCTS

#define MAX_LEN 8 //The maximum lenght of the words.
#define MAX_WORDS 10 //The maximum number of words in a list.

/*
 * Struct to save a word and its information needed for the game.
 */
typedef struct
{
    char word[MAX_LEN]; //The word saved.
    int num_char; //The lenght of the word.
    int direction; //The orientation where the word is writed
    bool found; //Boolean that checks if this word was found by the player
    int startPos[2];    //Starting position of the word in the tabl
} word;

/*
 * Struct with the game board and settings of the game.
 */
typedef struct
{
    char** table; //The game board with all the characters.
    int size; //The size of the board generated.
    int num_words; //The number of words in the game.
    int found_words;    //Number of words founded
    int found_pos[MAX_LEN*MAX_WORDS][2];    //Positions of word characters that had been found
    int posFound_num;   //Number of positions saved on found_pos
    int solutions[MAX_LEN*MAX_WORDS][2];    //Positions of word characters
} wordsearch;

#endif