#include <stdio.h>
#include <stdlib.h>
typedef struct data_t{
	void * p;
    //int type; <--- to be expanded later if GStack used with other types
} data_t;
typedef struct Node {
	struct Node * next;
	struct Node * prev;
	data_t * data;
} Node;
typedef struct GStack {
	Node * head;
	Node * tail;
} GStack;

GStack * initGStack();
void push(GStack *, void *); 
void * pop(GStack *); 
void * retrieve(void *);
