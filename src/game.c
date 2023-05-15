#include "types.h"

#include "wordsearch.h"

/*
 * This is the core of the game. In here we call all the functions to start a game of word search.
 */
void game() {
    wordsearch board;

    //Quick introdution to the game and information about the authors.
    printf("******************************************************\n");
    printf("Us donem la benvinguda al joc de la sopa de lletres!\n");
    printf("Autors: Javier Fuentes, Kevin Chafla, Fran\n");
    printf("******************************************************\n");

    //Ask for the size of the board. Won't stop untill the player puts a number inside the specified range. (MIN 10 - MAX 40)
    do
    {
        printf("Indica la mida de la sopa de lletres (10-40):");
        scanf("%d", &board.size);

        if (board.size > 40 || board.size < 10)
            printf("Tens que indicar una mida dins del rang!\n");
        
    } while (board.size >= 40 && board.size <= 10);

    board.num_words = getNumWords();

    word words[board.num_words];
    getWords(words);
    showList(words);
    inicializateWordsearch(&board);
    fillWordsearch(board,words,board.num_words);
    showWordsearch(board);

    return;
}
