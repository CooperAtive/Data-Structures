#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../GList/GList.c"

unsigned long hash (unsigned char *);
int fill_table (char *, void ***);
void ** init_table();
