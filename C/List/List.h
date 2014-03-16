#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	struct _Node * next;
	struct _Node * prev;
	int data;
} Node;
typedef struct _List {
	Node * head;
	Node * tail;
} List;

void addToTail(List *,int);
void addToHead(List *, int); //aka push
int stackPop(List *); //remove from the top(aka head) of a stack and return value
void removeNode(List *, int); //remove a node by value
void viewList(List *);
void clearList(List *);
int stackTop(List *);
