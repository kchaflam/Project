#include "types.h"

#include "wordsearch.h"

/*
 * Generate a random upper case character.
 *
 * @return The randomly upper case character.
*/
char randomChar()
{
    return (rand() % (90-65+1))+65;
}

/*
 * Sorts alphabetically the words saved.
 *
 * @param words[] The words to sort and also store in.
 * @param numWords The number of words saved.
*/
void alphaSort(word words[], int numWords)
{
    bool sorted = false;

    for (int i = 0; i < numWords - 1 && !sorted; i++) 
    {
        sorted = true;

        for (int j = 0; j < numWords - i - 1; j++) 
        {
            if (strcmp(words[j].word, words[j + 1].word) > 0) 
            {
                word temp = words[j];

                words[j] = words[j + 1];
                words[j + 1] = temp;
                
                sorted = false;
            }
        }
    }
}

/*
 * Checks if two values exists in an array.
 *
 * @param value The values to check.
 * @param array All the values stored.
 * @param length The lenght of the array with all the values.
 */
bool exists(int value[], int array[][2], int length) 
{
    bool result = false;

    for (int i = 0; i < length; i++)
        if (array[i][0] == value[0] && array[i][1] == value[1])
            result = true;

    return result;
}