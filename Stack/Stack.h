//includes
//LList.c
//stack has a linked list called list or the list 
//functions
//	take a stack instead of list
//	Push, pop returns it
//	empty stack
//	isEmpty
#include <stdio.h>
#include <stdlib.h>
#include "../List/List.c"

typedef struct
{
	List *  list;
} Stack
;
int push(Stack *, int);
int pop(Stack *);
int top(Stack *);
void clear(Stack *);
Stack * initStack();
