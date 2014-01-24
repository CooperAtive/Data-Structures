//Cooper Trowbridge
//Hash Map in C
//1/15/2014

#include "hash.h"
#define TABLE_SIZE 55457
#define length(a) sizeof(a) / sizeof(*a)
extern int rows, cols, maxwordlen;
int rows = 0, cols = 0, maxwordlen = 0;

int main(int argc, char **argv) {
    GList **table = inittable();
    filltable("words.txt", table);
    fillgrid("prelab/3x3.grid.txt");
    cleartable(table);
    return 0;
}
double loadfactor(GList ** table){
    double avg = 0;
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        avg += count(table[i]);
    }
    avg /= TABLE_SIZE;
    return avg;
}
int cleartable(GList **table) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        clearList(table[i]);
        free(table[i]);
    }
    free(table);
    return 1;
}
//Bob Jenkins One-at-a-Time hash
unsigned long hash (char *str) {
    unsigned h = 0;
    int i;

    for (i = 0; i < length(str); i++) {
        h += str[i];
        h += ( h << 10);
        h ^= ( h >> 6);
    }

    h += (h << 3);
    h ^= (h >> 11);
    h += (h << 15);

    return h % TABLE_SIZE;
}

GList ** inittable() {
    GList **table;
    table = malloc(TABLE_SIZE * sizeof(GList *));
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        GList *list = initGList(); 
        table[i] = list; 
    }
    return table;
}

int filltable (char *dict, GList **table) {
    FILE *fp;
    char *line = NULL;
    size_t size = 0;
    int j = 0;
    int wordlen = 0;
    fp = fopen(dict, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((wordlen = getline(&line, &size, fp)) != -1 ) {
        {
        char *word = (char*) calloc(32, 1);
        strncpy(word, line, wordlen-1);
        push(table[hash(word)], word);
        if (wordlen > maxwordlen) maxwordlen = wordlen;
        j++;
        }
    }
    fclose(fp);
    free(line);
    return 1;
}

char ** fillgrid (char *input) {
    FILE *fp;
    int linenumber = 1, i, j; 
    char *line = NULL;
    size_t size = 0;
    fp = fopen(input, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while (getline(&line, &size, fp) != -1) {
        if (linenumber == 1) rows = atoi(line);
        if (linenumber == 2) cols = atoi(line);
        if (linenumber == 3) 
        {
            char **grid = (char **) calloc(rows, cols);
            for (i = 0; i < rows; i++){
                char *row = (char *) calloc(cols, sizeof(char));
                grid[i] = row;
                for (j = 0; j < cols; j++) {
                    grid[i][j] = line[(cols * i) + j];
                }
            }
            for (i = 0; i < rows; i++) printf("%s\n", grid[i]);
            search_grid(grid);
        }
        linenumber++;
    }
    printf("rows = %d, cols = %d" , rows, cols);
    fclose(fp);
    free(line);
    return NULL;
}        
        
int search_grid(char **grid) {
    int i, j;
    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j++) {
            search_letter(&grid[i][j], i, j);
        }
    }
    return 1;
}

int search_letter(char *start, int row, int col) {
    printf("%c\n", *start);
    return 1;
}


        
        
        
            
 
