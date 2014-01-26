//Cooper Trowbridge
//Hash Map in C
//1/15/2014

#include "hash.h"
#define TABLE_SIZE 55457
#define length(a) sizeof(a) / sizeof(*a)
extern int rows, cols, maxwordlen, wordcount;
int rows = 0, cols = 0, maxwordlen = 0, wordcount = 0;

int main(int argc, char **argv) {
    GList **table = inittable();
    filltable(argv[1], table);
    char **grid = fillgrid(argv[2]);
    search_grid(grid, table);
    printf("%d\n", wordcount);
    open_outfile();
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

    for (i = 0; i < length(str)+2; i++) {
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
    char **grid;
    fp = fopen(input, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while (getline(&line, &size, fp) != -1) {
        if (linenumber == 1) rows = atoi(line);
        if (linenumber == 2) cols = atoi(line);
        if (linenumber == 3) 
        {
            grid = (char **) calloc(rows, cols);
            for (i = 0; i < rows; i++){
                char *row = (char *) calloc(cols, sizeof(char));
                grid[i] = row;
                for (j = 0; j < cols; j++) {
                    grid[i][j] = line[(cols * i) + j];
                }
            }
        }
        linenumber++;
    }
    fclose(fp);
    free(line);
    return grid;
}        
        
int search_grid(char **grid, GList **table) {
    FILE *outfile = open_outfile();
    int i, j, dir;
    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j++) {
            for(dir = 0; dir < 8; dir++) {
            search_letter(grid, i, j, dir, table, outfile);
            }
        }
    }
    fprintf(outfile, "%d words found\n", wordcount);
    //fclose(outfile);
    return 1;
}

int search_letter(char **grid, int i, int j, int dir, GList **table, FILE *outfile) {
    char str[23] = {0};
    int pos = 0, startrow = i, startcol = j;
    switch (dir) {
    case 0: //NORTH
        while(inbounds(i, j, pos)) {
            str[pos] = grid[i][j];
            if (find(table[hash(str)], str) && pos > 1) {
                fprintf(outfile, "N (%d, %d):  %s\n", startrow, startcol, str);
                wordcount++;
            }
            pos++;
            i--;
        }
        break;
    case 1: //NORTHEAST
        while(inbounds(i, j, pos)) {
            str[pos] = grid[i][j];
            if (find(table[hash(str)], str) && pos > 1) {
                fprintf(outfile, "NE (%d, %d):  %s\n", startrow, startcol, str);
                wordcount++;
            }
            pos++;
            i--;
            j++;
        }
        break;
    case 2: //EAST
        while(inbounds(i, j, pos)) {
            str[pos] = grid[i][j];
            if (find(table[hash(str)], str) && pos > 1) {
                fprintf(outfile, "E (%d, %d):  %s\n", startrow, startcol, str);
                wordcount++;
            }
            pos++;
            j++;
        }
        break;
    case 3: //SOUTHEAST
        while(inbounds(i, j, pos)) {
            str[pos] = grid[i][j];
            if (find(table[hash(str)], str) && pos > 1) {
                fprintf(outfile, "SE (%d, %d):  %s\n", startrow, startcol, str);
                wordcount++;
            }
            pos++;
            j++;
            i++;
        }
        break;
    case 4: //SOUTH
        while(inbounds(i, j, pos)) {
            str[pos] = grid[i][j];
            if (find(table[hash(str)], str) && pos > 1) {
                fprintf(outfile, "S (%d, %d):  %s\n", startrow, startcol, str);
                wordcount++;
            }
            pos++;
            i++;
        }
        break;
    case 5: //SOUTHWEST
        while(inbounds(i, j, pos)) {
            str[pos] = grid[i][j];
            if (find(table[hash(str)], str) && pos > 1) {
                fprintf(outfile, "SW (%d, %d):  %s\n", startrow, startcol, str);
                wordcount++;
            }
            pos++;
            j--;
            i++;
        }
        break;
    case 6: //WEST
        while(inbounds(i, j, pos)) {
            str[pos] = grid[i][j];
            if (find(table[hash(str)], str) && pos > 1) {
                fprintf(outfile, "W (%d, %d):  %s\n", startrow, startcol, str);
                wordcount++;
            }
            pos++;
            j--;
        }
        break;
    case 7: //NORTHWEST
        while(inbounds(i, j, pos)) {
            str[pos] = grid[i][j];
            if (find(table[hash(str)], str) && pos > 1) {
                fprintf(outfile, "NW (%d, %d):  %s\n", startrow, startcol, str);
                wordcount++;
            }
            pos++;
            j--;
            i--;
        }
        break;
    }
    return 1;
}
int inbounds(int i, int j, int pos) {
    if (i < rows && j < cols && i > -1 && j > -1 && pos < maxwordlen)
        return 1;
    else
        return 0;
}
FILE * open_outfile() {
    char filename[50];
    sprintf(filename, "%dx%d.out.txt", rows, cols);
    printf("%s\n", filename);
    FILE *fp = fopen(filename, "w");
    return fp;
}
            
