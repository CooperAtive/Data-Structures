//Cooper Trowbridge
//Hash Map in C
//1/15/2014

#include "hash.h"
#define length(a) (sizeof a / sizeof *a)
#define TABLE_SIZE 55457

int main(int argc, char **argv) {
    GList **table = inittable();
    filltable("words.txt", table);
    char *str = (char*)  malloc(sizeof(char)*4);
    str = "AAA\n";
    //void *ptr = str;
    //push(table[hash(str)], ptr);
    printf("hash(AAA) %d\n", hash(str));
    printf("%d\n", find(table[hash(str)], str));
    /*
    int max = filltable("words.txt", words);
    int k;
    printf("Max len = %d\n", max);
    */
    cleartable(table);
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

GList ** inittable() {
    GList **table;
    table = malloc(TABLE_SIZE * sizeof(GList *));
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        GList *list = initGList(); 
        table[i] = list; 
    }
    char *str = "gg";
    void *ptr = str;
    push(table[1], ptr);
    //printf("%d\n", i);
    return table;
}

int filltable (char *dict, GList **table) {
    FILE *fp;
    char *line = NULL;
    size_t size = 0;
    int j = 0;
    int wordlen = 0;
    int max = 0;
    fp = fopen("words.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((wordlen = getline(&line, &size, fp)) != -1 ) {
        //if (j < 10)
        {
        char *word = (char *) malloc(32 * sizeof(char));
        strcpy(word, line);
        void *wordptr = word;
        push(table[hash(word)], wordptr);
        if (wordlen > max) max = wordlen;
        j++;
        }
    }
    fclose(fp);
    free(line);
    return max;
}
