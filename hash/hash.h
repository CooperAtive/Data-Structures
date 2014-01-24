#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../GList/GList.c"

unsigned long hash (char *);
int filltable(char *, GList **);
GList ** inittable();
int cleartable(GList **);
char ** fillgrid(char *);
int search_grid(char **);
int search_letter(char *, int, int);
double loadfactor(GList **);
