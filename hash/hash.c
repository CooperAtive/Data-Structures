//Cooper Trowbridge
//Hash Map in C
//1/15/2014

#include "hash.h"
#define TABLE_SIZE 55457
#define length(a) sizeof(a) / sizeof(*a)

int main(int argc, char **argv) {
    GList **table = inittable();
    filltable("words.txt", table);
    char *str = "Zimmerman"; 
    printf("hash(%s) %lu\n", str, hash(str));
    printf("If 1 Found it: %d\n", find(table[hash(str)], str));
    int i;
    double avg = 0;
    for (i = 0; i < TABLE_SIZE; i++) {
        avg += count(table[i]);
    }
    printf("total = %f\n", avg);
    avg /= TABLE_SIZE;
    printf("load facts = %f\n", avg);
    cleartable(table);
    /*
    fillgrid("prelab/4x7.grid.txt");
    */
    return 0;
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
    int max = 0;
    fp = fopen(dict, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((wordlen = getline(&line, &size, fp)) != -1 ) {
        {
        char *word = (char*) calloc(32, 1);
        strncpy(word, line, wordlen-1);
        push(table[hash(word)], word);
        if (wordlen > max) max = wordlen;
        j++;
        }
    }
    printf("max = %d\n", max);
    fclose(fp);
    free(line);
    return max;
}
/*
char ** fillgrid (char *input) {
    FILE *fp;
    int rows; 
    int cols;
    char *line = NULL;
    size_t size = 0;
    int linenumber = 1;
    fp = fopen(input, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while (getline(&line, &size, fp) != -1) {
        if (linenumber == 1) {
            rows = atoi(line);
        }
        if (linenumber == 2) {
            cols = atoi(line);
        }
        if (linenumber == 3) 
        {
            char **grid = (char **) calloc(rows, cols);
            int i = 0; 
            while (line[i]) {
                char *row = (char *) calloc(cols, sizeof(char));
                strncpy(grid[i]///////////////IMHERERERKJHGAKJHGKSAJDGFHKSJDHG
            break;
        }
        linenumber++;
    }
    printf("rows = %d, cols = %d" , rows, cols);
    fclose(fp);
    free(line);
    return NULL;
}        
*/        
        
        
        
        
        
            
 
