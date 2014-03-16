#include "List.h"
/*
void main( ){
	List * myList = (List *) malloc( sizeof( List ));
	addToHead( myList, 5);
	addToTail( myList, 4);
	addToHead( myList, 2);
	addToTail( myList, 3);
	addToHead( myList, 1);
	viewList( myList);
	removeNode( myList, 3);
	viewList( myList);
	removeNode( myList, 5);
	viewList( myList);
	viewList( myList);
	clearList( myList);
	viewList( myList);
}
*/
void addToTail(List *l, int value){
          Node * newNode = (Node *) malloc( sizeof( Node ));
          newNode->data = value;
          Node * temp = l->tail;
          if (temp == NULL)
	  {
         	 l->tail = newNode;
		 l->head = newNode;
          	 newNode->next = NULL;
                 newNode->prev = NULL;
		 return;
          }
          l->tail = newNode;
          newNode->prev= temp;
	  temp->next = newNode;
	  newNode->next = NULL;
}

void addToHead(List *l, int value){
    Node * newNode = (Node *) malloc( sizeof( Node ));
    newNode->data = value;
    Node * temp = l->head;
    if (temp == NULL){
       	 l->head = newNode;
    	 l->tail = newNode;
         newNode->next = NULL;
         newNode->prev = NULL;
         return;
    }
    l->head = newNode;
    newNode->next = temp;
	  temp->prev = newNode;
	  newNode->prev = NULL;
}
void viewList (List *l){
        if (l->head == NULL)
        {
                printf("List is empty\n");
                return;
        }
        Node * temp  = l->head;

        while (temp != NULL)
	{
		printf("%d\n", temp->data);
                temp = temp->next;
        }

        printf("End\n");


}
void removeNode(List *l, int target){
	if(l->head == NULL)
	{
		printf("The list you are referencing is empty\n");
	}
	Node * temp = l->head;
	if (l->head->data == target)
	{
		l->head = l->head->next;
		free(temp);
		return;
	}
	while (temp != NULL)
	{
		if (temp->data == target)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			printf("Node with data = %d was removed from the list.\n", temp->data);
			free(temp);
			return;
		}
		temp = temp->next;
	}
	printf("Target data not found in list.\n");

}
int stackPop(List *l){
	Node * temp = l->head;
	if (l->head->next == NULL)
	{
		free(l->head);
		return temp->data;
	}
	l->head = l->head->next;
	l->head->prev = NULL;
	return temp->data;
}
void clearList(List *l){
        Node * temp = l->head;
        while (temp != NULL)
        {
                l->head = l->head->next;
                free(temp);
                temp = l->head;
        }
	return;
}
int stackTop(List *l){
	if (l->head == NULL)
	{
		printf("No top, list is empty");
		return;
	}
	return l->head->data;
}

