#include <stdio.h>
#include <stdlib.h>

#include "wordsearch.h"
#include "word_func.h"
#include "game.h"

int main()
{
    int option = 0;
    wordsearch blank;
    
    gameIntroduction();

    do
    {
        word finded;
        wordsearch board = blank;
        word words[MAX_WORDS];

        do
        {
            printf("\n1 - Vols jugar una partida?\n2 - Sortir\n");
            scanf("%d", &option);
        } while (option < 1 || option > 2);

        if(option == 1)
            inicializateGame(&board, &finded, words);

        while(!compareStr(finded.word, "RENDICIO") && board.num_words != board.found_words && option == 1)
        {
            bool word_in;

            showList(words);
            showWordsearch(board, false);

            do
            {
                word_in = false;

                printf("\nDigues el nom de la paraula que has trobat (Si vols rendirte escriu la paraula RENDICIO): ");
                scanf("%s", finded.word);
                strupr(finded.word);

                for(int w = 0; w < board.num_words; w++)
                    if(strcmp(finded.word, words[w].word) == 0)
                        word_in = true;

                if (!word_in && !compareStr(finded.word, "RENDICIO"))
                    printf("\nEscriu una paraula que estigui dins de la sopa de lletres!\n");
            } while (!word_in && !compareStr(finded.word, "RENDICIO"));

            if(word_in)
            {
                finded.num_char = strlen(finded.word);

                do
                {
                    printf("Digues la posicio de la primera lletra (Horizontal): ");
                    scanf("%d", &finded.startPos[0]);
                    finded.startPos[0]--;

                    if (finded.startPos[0] < 0 || finded.startPos[0] > board.size)
                        printf("\nEl numero ha de estar dins del rang!\n\n");
                } while (finded.startPos[0] < 0 || finded.startPos[0] > board.size);
                
                do
                {
                    printf("Digues la posicio de la primera lletra (Vertical): ");
                    scanf("%d", &finded.startPos[1]);
                    finded.startPos[1]--;

                    if (finded.startPos[1] < 0 || finded.startPos[1] > board.size)
                        printf("\nEl numero ha de estar dins del rang!\n\n");
                } while (finded.startPos[1] < 0 || finded.startPos[1] > board.size);

                do
                {
                    printf("Digues la orientacio de la paraula desde la primera posicio 1(Horizontal), 2(Vertical): ");
                    scanf("%d", &finded.direction);
                    finded.direction--;

                    if (finded.direction < 0 || finded.direction > board.size)
                        printf("\nLa posicio ha de ser 1 (Horizontal) o 2 (Vertical)!\n\n");
                } while (finded.direction < 0 || finded.direction > board.size);
                
                if (findWord(words, finded, &board))
                {
                    printf("\nHas trobat la paraula %s!!! (%d/%d)\n", finded.word, board.found_words, board.num_words);
                } else
                {
                    printf("%s no existeix en la posicio especificada! (%d, %d, ", finded.word, finded.startPos[0] + 1,finded.startPos[1] + 1);
                    if (finded.direction == 0)
                        printf("Horizontal)\n");
                    else
                        printf("Vertical)\n");
                } 
            } 
        }

        if(strcmp(finded.word,"RENDICIO") == 0)
            showWordsearch(board, true); 
        else if (board.num_words != board.found_words)
            printf("Has guanyat!\n Has esbrinat totes les paraules de la sopa!\n");
            
        while(option < 1 || option > 2)
        {
            printf("1 - Vols jugar un altre cop?\n2 - Sortir\n");
            scanf("%d", &option);
        }
        
    } while(option != 2);
    
    return 0;
}