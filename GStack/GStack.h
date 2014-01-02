#include <stdio.h>
#include <stdlib.h>
/* 
---------------------------
** type refers to variable typed to be used for any single instance of a GStack
** type = 0 - Integer
** type = 1 - TreeNode
** More to come....
----------------------
*/
typedef struct data_t{
	int type;
	void * p;
} data_t;
typedef struct _Node {
	struct _Node * next;
	struct _Node * prev;
	data_t * data;
} Node;
typedef struct _GStack {
	Node * head;
	Node * tail;
} GStack;

GStack * initGStack();
void push(GStack *, void *); 
void * pop(GStack *); 
//void * top(GStack *);
