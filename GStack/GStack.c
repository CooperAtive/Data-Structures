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
    if (s->head == NULL){
        s->head = newNode;
        s->tail = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    else{
        Node * temp = s->head;
        s->head = newNode;
        newNode->next = temp;
        temp->prev = newNode;
        newNode->prev = NULL;
    }
}

void * pop(GStack * s){
    if (s->head == NULL){
        return NULL;
    }
    void * ptr = s->head->data->p;
	if (s->head->next == NULL)
	{
      //  free(s->head->data->p);
        free(s->head->data);
		free(s->head);
        s->head = NULL;
		return ptr;
	}
	s->head = s->head->next;
    //free(s->head->prev->data->p);
    free(s->head->prev->data);
    free(s->head->prev);
	s->head->prev = NULL;
	return ptr;
}
