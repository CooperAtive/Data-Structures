//Cooper Trowbridge
//Hash Map in C
//1/15/2014

#include "hash.h"
#define length(a) (sizeof a / sizeof *a)
#define TABLE_SIZE 55457

int main(int argc, char **argv) {
    fill_table("words.txt");
}

unsigned long hash (unsigned char *str) {
    unsigned long hash = 3;
    int c, i;
    for (i = 0; i < strlen(str); i ++){
        hash = ((hash*311)>> 5) + str[i];
    }
    hash %= TABLE_SIZE;
    return hash;
}

int * init_table () {
    int *table;
    table = malloc(TABLE_SIZE*sizeof(int));
    return table;
}

int fill_table(char * words) {
    int *table = init_table();
    FILE *fp;
    char *line = NULL;
    int collisions = 0;
    size_t len = 0;
    ssize_t read;
    int max = 0;
    fp = fopen(words, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fp)) != -1) {
        if (table[hash(line)])
            collisions++;
        table[hash(line)] = 1;
    }
    printf("Collisions: %d\n", collisions);
    if (line)
        free(line);
    return EXIT_SUCCESS;
}
