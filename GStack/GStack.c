#include "GStack.h"
void main( ){
    GStack * myStack = initGStack();
    int num = 1;
    int num2 = 2;
    int num3 = 3;
    void * ptr = &num;
    void * ptr1 = &num2;
    void * ptr2 = &num3;
    push( myStack, ptr);     
    push( myStack, ptr1);     
    push( myStack, ptr2);     
    void * aptr2 = pop( myStack);
    int anum2 = *(int *) aptr2;
    printf("%d\n", anum2);
    void * aptr1 = pop( myStack);
    int anum1 = *(int *) aptr1;
    printf("%d\n", anum1);
    void * aptr = top( myStack);
    int anum = *(int *) aptr;
    printf("%d\n", anum);

}
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
