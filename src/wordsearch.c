#include "types.h"

#include "word_func.h"

/*
 * Makes space to store all the characters in the board and then generates characters randomly to make the game board.
 *
 * @param board The struct with the array where the game board is stored and also the size of the board.
 */
void inicializateWordsearch(wordsearch* board) 
{
    srand(time(NULL));

    //Makes the space necessary for the specified size. (size * size)
    board->table = (char**) malloc((board->size*board->size) * sizeof(char*));

    //In each row of the array, save up space for the specified size.
    for (int i = 0; i < board->size; i++)
        board->table[i] = (char*) malloc(board->size * sizeof(char));

    //Store in the array random characters.
    for(int i = 0; i < board->size; i++) 
        for(int j = 0; j < board->size; j++) 
            board->table[i][j] = randomChar();

    board->found_words = 0;
}

/*
 * Shows the board of the game. 
 *
 * @param board The struct with the array where the game board is stored. 
 */
void showWordsearch(wordsearch board, bool answer) 
{
    answer = answer;
    int t = 0; //Used to keep track of the positions of the letter that has to be colored when found.

    //This and the next one of these kind are to show bars and make like a grid to show position numbers and letters clearer. 
    printf("\n   |");

    //Shows number in the upper side of the board. (X axis)
    for(int h = 0; h < board.size; h++) 
        if (h < 9) 
            printf(" %d  ", h + 1);
        else
            printf(" %d ", h + 1);

    printf("\n");

    printf("---|");
    for(int g = 0; g < board.size; g++)          
        printf("----");
        
    printf("\n");

    for(int y = 0; y < board.size; y++) 
    {
        //Shows numbers in the right side of the board. (Y axis)
        if (y < 9) 
            printf("%d  |", y + 1);
        else
            printf("%d |", y + 1);

        //Shows all the letters in the board.
        for(int x = 0; x < board.size; x++)
        {
            //Check the positions of the found words to change the color to make it clearer for the user. 
            if(board.found_pos[t][0] == x && board.found_pos[t][1] == y)
            {
                //We use ANSI escape sequences to change the terminal color to make clear the words that the user has found.
                //"\x1b[32m" is for green and "\x1b[0m" is to make it white again.
                printf(" \x1b[32m%c\x1b[0m  ", board.table[y][x]);
                t++;
            } else 
            {
                printf(" %c  ", board.table[y][x]);
            }
        } 
        
        printf("\n");
    }
    
    printf("\n");    
}

/*
 * Returns the numbers of rows in the text file words.txt. It requires the file words.txt to work properly. 
 *
 * @return The number of rows in words.txt. 
 */
int getNumWords() {
    FILE *file = fopen("./words.txt", "r");

    int num_rows;
    
    //This function only works if the file words.txt can be opened. 
    if (file == NULL) 
    {
        printf("word.txt not found/can't open it.\n");        
        num_rows = 0; 
    } 
    else 
    {
        num_rows = 0;

        //Iterates through all the file while counting the rows.
        while (fscanf(file, "%*[^\n]\n") != EOF) //This while uses a regular expression to ignore all characters in a row and also blank rows.
            num_rows++;
    }

    fclose(file);

    return num_rows;
}

/*
 * This function asks for a row to find a word saved in it. It requires the file words.txt to work properly. 
 *
 * @param row The number of the row you want to search a word in. 
 * @return The word of the row you specified. 
 */
void getWords(word words[]) {
    FILE* file = fopen("./words.txt", "r");

    int i;
    
    //This function only works if the file words.txt can be opened. 
    if (file == NULL) 
    {
        printf("word.txt not found/can't open it.\n");
    } else 
    {
        i = 0;

        //Iterates trough all the rows in the file, saves the words found and also saves their lenght.
        char tempword[MAX_LEN];
        while (fscanf(file, "%s", tempword) != EOF)
        {
            strupr(tempword);
            strcpy(words[i].word, tempword);
            words[i].num_char = strlen(words[i].word);
            words[i].found = false;

            i++;
        }

        alphaSort(words, i); //Sorts the words alphabetically.
    }
    
    fclose(file);
}

/*
 * Shows the word and its lenght.
 *
 * @param words Array with the words and their lenght. 
 */
void showList(word words[])
{
    for (int i = 0; i < getNumWords(); i++) 
        printf("%s, %d, %d, %d, %d\n", words[i].word, words[i].num_char, words[i].startPos[0], words[i].startPos[1], words[i].direction );
}

/*
 * Fills the game board with the words to search.
 *
 * @param board The struct with the game board.
 * @param words Array with the words.
 * @param num_words The number of words.
 */
void fillWordsearch(wordsearch* board, word words[], int num_words)
{
    int x, y;
    int orientation;
    bool taken;
    
    int length = getNumWords() * MAX_LEN; //Number of words by the max length of a word.
    int num_fill = 0; //Counter of length used of board->solutions.

    for(int t = 0; t < num_words; t++)
    {
        do {
            x = rand() % board->size;
            y = rand() % board->size;

            //Sets the orientation of the word. 0 = Horizontal, 1 = Vertical.
            if ((words[t].num_char + x) <= board->size)
                orientation = 0;
            else if ((words[t].num_char + y) <= board->size)
                orientation = 1;
            else 
                orientation = 99; //If overlaps, sets the variable in a value equal to NULL.

            taken = false;
            
            if (orientation != 99) 
            {
                for (int j=0; j < words[t].num_char; j++)
                {
                    //Checks position by position if the word overlaps with any other word.
                    int position[2] = {x + (orientation == 0) * j, y + (orientation == 1) * j};
                    
                    for (int i = 0; i < length; i++)
                        if ((board->solutions[i][0] == position[0] && board->solutions[i][1] == position[1]) && board->table[board->solutions[i][0]][board->solutions[i][1]] != words[t].word[j])
                            taken = true;

                }
            }

        } while (orientation == 99 || taken); //If the word fits and didn't overlap with other words it will be written in the wordsearch board.

        //Saves the position info of the word.
        words[t].startPos[0] = x;
        words[t].startPos[1] = y;
        words[t].direction = orientation;
        
        for (int i = 0; i < words[t].num_char; i++)
        {
            board->table[y + (orientation == 1) * i] [x + (orientation == 0) * i]= words[t].word[i]; //Writes the word into the board.

            //Make record that this position is used in filled array.
            board->solutions[num_fill][0] = x + (orientation == 0) * i; 
            board->solutions[num_fill][1] = y + (orientation == 1) * i;

            num_fill++;
        }
    }
    positionSort(board->solutions, num_fill);
}

/*
 * Fills the game board with the words to search.
 *
 * @param words
 * @param num_words
 * @param finded
 */
bool findWord(word words[], word finded, wordsearch* board)
{
    bool exists = false;
    int save = 0;
    
    for(int x = 0; x < board->num_words; x++)
    {
        if(strcmp(finded.word, words[x].word) == 0)
        {
            exists = true;
            save = x;
            x = board->num_words;
        }
    }
    printf("\n%s,%d,%d,%d\n",words[save].word,words[save].startPos[0],words[save].startPos[1],words[save].direction);

    if(exists && !words[save].found)
    {

        if((finded.startPos[0] == words[save].startPos[0] && finded.startPos[1] == words[save].startPos[1]) && finded.direction == words[save].direction)
        {
            words[save].found = true;
            board->found_words += 1;
            
            for(int i = 0; i < words[save].num_char; i++)
            {
                board->found_pos[board->posFound_num][0] = words[save].startPos[0] + (words[save].direction == 0) * i; 
                board->found_pos[board->posFound_num][1] = words[save].startPos[1] + (words[save].direction == 1) * i; 
                board->posFound_num++;
            }
            
            positionSort(board->found_pos, board->posFound_num);
        }
    }

    return words[save].found;
}