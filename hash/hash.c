//Cooper Trowbridge
//Hash Map in C
//1/15/2014

#include "hash.h"
#define length(a) (sizeof a / sizeof *a)
#define TABLE_SIZE 55457

int main(int argc, char **argv) {
    void **table = init_table();
    void ***tblptr = &table;
    fill_table("words.txt", tblptr);
    /*
    char str[] = "Cooper";
    void *ptr = &str;
    push(table[1], ptr);
    printf("%s", pop(table[1]));
    */
    char str[] = "acorn";
    void *ptr = &str;
    //push(table[hash(str)], ptr);
    //printf("hash = %d", hash(str));
    printf("%d", find_node(table[hash(str)], str));
    printf("%s", pop(table[hash(str)]));
}
//Bob Jenkins One-at-a-Time hash
unsigned long hash (unsigned char *str) {
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

void ** init_table () {
    int i;
    void **table = (void**) calloc(TABLE_SIZE, sizeof(void*));
    printf("%d", (table == NULL));
    GList *temp = NULL;
    for (i = 0; i < TABLE_SIZE; i++){
        temp = initGList();
        table[i] = temp;
    }
    return table;
}

int fill_table(char * words, void ***tblptr) {
    FILE *fp;
    char line[60];
    int collisions = 0;
    int len = 60;
    ssize_t read;
    int max = 0;
    fp = fopen(words, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((fgets(line, len, fp)) != NULL) {
        char word[60] = (char *) malloc(sizeof(char));
        //strcpy(word, line);
        //void *ptr = word;
        printf("%s", line);
        push(*tblptr[hash(line)], line);       

    }
    if (line)
        free(line);
    return EXIT_SUCCESS;
}
