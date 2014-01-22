//Cooper Trowbridge
//Hash Map in C
//1/15/2014

#include "hash.h"
#define length(a) (sizeof a / sizeof *a)
#define TABLE_SIZE 55457

int main(int argc, char **argv) {
    int size = 25000;
    char **words = inittable(size);
    int max = filltable("words.txt", words);
    int k;
    for (k = 0; k < 25000; k++)
      printf("k = %d, %s\n", k,  words[k]);
    printf("Max len = %d\n", max);

    return 0;
}
//Bob Jenkins One-at-a-Time hash
unsigned long hash (char *str) {
    unsigned h = 0;
    int i;

    for (i = 0; i < strlen(str); i++) {
        h += str[i];
        h += ( h << 10);
        h ^= ( h >> 6);
    }

    h += (h << 3);
    h ^= (h >> 11);
    h += (h << 15);

    return h % TABLE_SIZE;
}

char ** inittable(int size) {
    char **words;
    words = malloc(size * sizeof(char*));
    int i;
    for (i = 0; i < size; i++) {
        char *word = (char *) malloc(32 * sizeof(char));
        words[i] = word; 
    }
    return words;
}

int filltable (char *dict, char **words) {
    FILE *fp;
    char *line = NULL;
    size_t size = 0;
    int j = 0;
    int wordlen = 0;
    int max = 0;
    fp = fopen("words.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while (j < 25000 ) {
        wordlen = getline(&line, &size, fp);
        strcpy(words[j], line);
        if (wordlen > max) max = wordlen;
        j++;
    }
    return max;
}
