#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../GList/GList.c"

unsigned long hash (char *);
int filltable(char *, char **);
char ** inittable(int);
