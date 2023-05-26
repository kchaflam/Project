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
 * Sorts the positions of vectors.
 *
 * @param positions[][2] The vectors to sort.
 * @param length The count of vectors to sort.
*/
void positionSort(int positions[][2], int length)
{
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (positions[j][1] > positions[j + 1][1] || (positions[j][1] == positions[j + 1][1] && positions[j][0] > positions[j + 1][0])) {
                int tempX = positions[j][0];
                int tempY = positions[j][1];

                positions[j][0] = positions[j + 1][0];
                positions[j][1] = positions[j + 1][1];

                positions[j + 1][0] = tempX;
                positions[j + 1][1] = tempY;
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
 * 
 * @return True if the value exists. False if not exists.
 */
bool exists(int value[], int array[][2], int length) 
{
    bool result = false;

    for (int i = 0; i < length; i++)
        if (array[i][0] == value[0] && array[i][1] == value[1])
            result = true;

    return result;
}

/*
 * Counts the lenght of a word.
 *
 * @param word[] The word.
 * 
 * @return The lenght of the word.
*/
int countStr(char word[])
{
    int counter = 0;

    for(int i = 0; i < (int) strlen(word); i++)
        if(word[i] != '\0')
            counter++;

    return counter;
}

/*
 * Compares two strings.
 *
 * @param word1[] A string.
 * @param word2[] The string to compare to.
 * 
 * @return True if the words are the same, False otherwise.
*/
bool compareStr(char word1[], char word2[])
{
    bool result = true;

    //Checks if the strings have the same lenght.
    if(countStr(word1) == countStr(word2))
    {
        for(int x = 0; x < countStr(word1); x++)
        {
            if(word1[x] != word2[x])
            {
                result = false;
                x = strlen(word1);
            }
        }
    } else 
        result = false;
    
    return result;
}