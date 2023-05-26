#include <stdio.h>
#include <stdlib.h>

#include "wordsearch.h"
#include "word_func.h"
#include "game.h"

int main()
{
    //bool word_in;

    gameIntroduction();


    int option = 0;
    do
    {
        word finded;
        wordsearch board;
        word* words = NULL;
        
        inicializateGame(&board, &finded, words);

        do
        {
            printf("1-Vols jugar una partida?\n2-Sortir\n");
            scanf("%d", &option);
        } while (option < 1 || option > 2);

        while(strcmp(finded.word,"RENDICIO") && board.num_words != board.found_words && option == 1)
        {
            showWordsearch(board, false);
/*
            do
            {
                
                for (int w = 0; w < board.num_words; w++)
                    if (strcmp(finded.word, words[w].word) == 0)
                        word_in = true;
            } while (!word_in);
*/

            printf("Digues el nom de la paraula que has trobat: ");
            scanf("%s", finded.word);

            strupr(finded.word);
            finded.num_char = strlen(finded.word);
            
            do
            {
                printf("Digues la posicio de la primera lletra (Horizontal): ");
                scanf("%d", &finded.startPos[0]);
                finded.startPos[0]--;

                if (finded.startPos[0] < 0 || finded.startPos[0] > board.size)
                    printf("El numero ha de estar dins del rang!");
            } while (finded.startPos[0] < 0 || finded.startPos[0] > board.size);
            
            do
            {
                printf("Digues la posicio de la primera lletra (Vertical): ");
                scanf("%d", &finded.startPos[1]);
                finded.startPos[1]--;

                if (finded.startPos[1] < 0 || finded.startPos[1] > board.size)
                    printf("El numero ha de estar dins del rang!");
            } while (finded.startPos[1] < 0 || finded.startPos[1] > board.size);

            do
            {
                printf("Digues la orientacio de la paraula desde la primera posicio 1(Horizontal), 2(Vertical): ");
                scanf("%d", &finded.direction);
                finded.direction--;

                if (finded.direction < 0 || finded.direction > board.size)
                    printf("El numero ha de estar dins del rang!");
            } while (finded.direction < 0 || finded.direction > board.size);
            
            printf("\n%s,%d,%d,%d\n",finded.word,finded.startPos[0],finded.startPos[1],finded.direction);

            if (findWord(words, finded, &board))
            {
                printf("Has trobat la paraula %s! (%d/%d)\n", finded.word, board.found_words, board.num_words);
            } else
            {
                printf("%s no existeix.\n", finded.word);
            }    
        }

        if(strcmp(finded.word,"RENDICIO") == 0)
            showWordsearch(board, false); 

        while(option != 2)
        {
            printf("1-Vols jugar un altre cop?\n2-Sortir\n");
            scanf("%d", &option);
        }
        
    } while(option != 2);
    
    return 0;
}