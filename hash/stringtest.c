#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

int filltable(char *, char **);
char ** inittable(int);

int main(int argc, char **argv) {
    /*
    char **words;
    words = malloc(2000 * sizeof(char));
    int i;
    for (i = 0; i < 2000; i++)
        words[i] = malloc(32 * sizeof(char));
    FILE *fp;
    char *line = NULL;
    size_t size = 0;
    int j = 0;
    fp = fopen("words.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while (j < 10 ) {
        getline(&line, &size, fp);
        printf("%s", line);
        strcpy(words[j], line);
        j++;
    }
    */
    //mallopt(M_MMAP_THRESHOLD, 2048);
    int size = 25000;
    char **words = inittable(size);
    int max = filltable("words.txt", words);
    int k;
    for (k = 0; k < 25000; k++)
      printf("k = %d, %s\n", k,  words[k]);
    printf("Max len = %d\n", max);

    return 0;
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
