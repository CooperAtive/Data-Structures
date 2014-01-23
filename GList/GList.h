#include <stdio.h>
#include <stdlib.h>
typedef struct data_t{
	void * p;
} data_t;
typedef struct Node {
	struct Node * next;
	struct Node * prev;
	data_t * data;
} Node;
typedef struct GList {
	Node * head;
	Node * tail;
} GList;

GList * initGList();
void push(GList *, void *); 
void * pop(GList *); 
void * retrieve(void *);
int find(GList *, char *);
void clearList(GList *);
int count(GList *);
