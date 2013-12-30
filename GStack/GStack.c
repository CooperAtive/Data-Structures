#include "GStack.h"
/*
void main( ){

}*/
GStack * initGStack(){
        GStack * gStack = (GStack *) malloc( sizeof( GStack));
        gStack->head = NULL;
        return gStack;
}
void push(GStack *s, void * dataptr){
	Node * newNode = (Node *) malloc( sizeof( Node ));
	data_t * nodeData = (data_t *) malloc( sizeof( data_t));	  
	nodeData->p = dataptr;
    newNode->data = nodeData;
    Node * temp = s->head;
    if (temp == NULL){
        s->tail = newNode;
        s->head = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
        return;
    }
    s->head = newNode;
    newNode->prev= NULL;
	temp->prev = newNode;
	newNode->next = temp;
}

void * pop(GStack *s){
	Node * temp = s->head;
	if (s->head->next == NULL){
		free(s->head);
		return temp->data->p;
	}
	s->head = s->head->next;
	s->head->prev = NULL;
	return temp->data->p;
}

void * top(GStack *s){
	if (s->head == NULL){
		printf("No top, list is empty");
		return;
	}
	return s->head->data->p;
}
