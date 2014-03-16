#include "Stack.h"
/*
void main(){
	Stack * myStack = initStack();
	push( myStack, 1);
	printf("%d\n", top( myStack));
	push( myStack, 2);
	push( myStack, 3);
	printf("%d\n", pop( myStack));
	printf("%d\n", top( myStack));
	clear( myStack);
	if (top( myStack) == -1)
	{
		printf("No top, list is empty\n");
	}
	else
	{
	printf("%d\n", top( myStack));
	}
}
*/
Stack * initStack(){
	Stack * stack = (Stack *) malloc( sizeof( Stack));
	List * myList = (List *) malloc( sizeof ( List));
	stack->list = myList;
	return stack;
}
int push (Stack *s, int value){
	addToHead(s->list, value);
}
int top(Stack *s){
	 List * l = s->list;
         if (l->head == NULL)
         {
                 return -1;
         }
         return l->head->data;
}
int pop(Stack *s){
	 List * l = s->list;
	 if (l->head == NULL)
	 {
		printf("Stack is empty\n");
		return -1;//error code for using Stack in PFC
	 }
	 int data = l->head->data;
	 Node * temp = l->head;
	 l->head = l->head->next;
	 if (l->head != NULL)
         {
		l->head->prev = NULL;
         }
	 free(temp);
         return data;
}
void clear(Stack *s){
	clearList(s->list);
}
