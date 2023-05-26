#include "types.h"

#include "wordsearch.h"

/*
 * Quick introdution to the game and information about the authors.
 */
void gameIntroduction()
{
    printf("*******************************************************\n");
    printf("Us donem la benvinguda al joc de la sopa de lletres!\n");
    printf("Autors: Javier Fuentes, Kevin Chafla, Francisco Quevedo\n");
    printf("*******************************************************\n");
}

/*
 * Start all the variables to make the game work.
 *
 * @param board The game board to save all information needed.
 * @param finded The variable to start it.
 * @param words The array to save all the words the game will have.
 */
void inicializateGame(wordsearch* board, word* finded, word words[])
{
    strcpy(finded->word, "");

    //Ask for the size of the board. Won't stop untill the player puts a number inside the specified range. (MIN 10 - MAX 40)
    do
    {
        printf("\nIndica la mida de la sopa de lletres (10-40): ");
        scanf("%d", &board->size);

        if (board->size > 40 || board->size < 10)
            printf("\nTens que indicar una mida dins del rang!\n");
    } while (board->size > 40 || board->size < 10);

    board->num_words = getNumWords();
    board->found_words = 0;
    board->posFound_num = 0;

    getWords(words);

    inicializateWordsearch(board);

    fillWordsearch(board, words, board->num_words);
}