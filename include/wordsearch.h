#include "types.h"

void inicializateWordsearch(wordsearch* board);

void showWordsearch(wordsearch board);

int getNumWords();

void getWords(word words[]);

void showList(word words[]);

void fillWordsearch(wordsearch board, word words[], int num_words);

bool findWord(word words[], word finded, wordsearch board);