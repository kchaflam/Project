#include "types.h"

#include "wordsearch.h"

/*
 * This is the core of the game. In here we call all the functions to start a game of word search.
 */
void game() {
    wordsearch board;
    word finded;
    strcpy(finded.word, "");

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
    board.found_words = 0;

    word words[board.num_words];
    getWords(words);
    inicializateWordsearch(&board);
    fillWordsearch(board,words,board.num_words);
    showList(words);
    showWordsearch(board);
    
    while(strcmp(finded.word,"RENDICIO") && board.num_words != board.found_words)
    {
        printf("Digues el nom de la paraula que has trobat: ");
        scanf("%s", finded.word);
        
        strupr(finded.word);
        finded.num_char = strlen(finded.word);
        
        printf("Digues la posicio de la primera lletra (Horizontal): ");
        scanf("%d", &finded.startPos[0]);
        finded.startPos[0]--;

        printf("Digues la posicio de la primera lletra (Vertical): ");
        scanf("%d", &finded.startPos[1]);
        finded.startPos[1]--;

        printf("Digues la orientacio de la paraula desde la primera posicio 1(Horizontal), 2(Vertical): ");
        scanf("%d", &finded.direction);
        finded.direction--;
        
        printf("\n%s,%d,%d,%d\n",finded.word,finded.startPos[0],finded.startPos[1],finded.direction);

        if (findWord(words, finded, board))
        {
            printf("Has trobat la paraula %s! (%d/%d)\n", finded.word, board.found_words, board.num_words);
        } else
        {
            printf("%s no existeix.\n", finded.word);
        }
        
        
    }
    return;
}
