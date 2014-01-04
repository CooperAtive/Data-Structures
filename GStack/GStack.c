#include "GStack.h"
/*
void main( ){

}*/
GStack * initGStack(){
        GStack * gStack = (GStack *) malloc( sizeof( GStack));
        gStack->head = NULL;
        return gStack;
}
void push(GStack * s, void * dataptr){
	data_t * nodeData = (data_t *) malloc( sizeof( data_t));	  
	nodeData->p = dataptr;
	Node * newNode = (Node *) malloc( sizeof( Node));
    newNode->data = nodeData;
    Node * temp = s->head;
    if (temp == NULL){
        s->head = newNode;
        s->tail = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
        return;
    }
    s->head = newNode;
    newNode->next = temp;
    temp->prev = newNode;
    newNode->prev = NULL;
    return;
}

void * pop(GStack * s){
	Node * temp = s->head;
	if (s->head->next == NULL)
	{
		free(s->head);
		return temp->data->p;
	}
	s->head = s->head->next;
    free(s->head->prev);
	s->head->prev = NULL;
	return temp->data->p;
}
