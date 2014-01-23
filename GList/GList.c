#include "GList.h"

/*
void main( ){
}
*/
GList * initGList(){
        GList * gList = (GList *) malloc( sizeof( GList));
        gList->head = NULL;
        return gList;
}
void push(GList * l, void * dataptr){
	data_t * nodeData = (data_t *) malloc( sizeof( data_t));	  
	nodeData->p = dataptr;
	Node * newNode = (Node *) malloc( sizeof( Node));
    newNode->data = nodeData;
    if (l->head == NULL){
        l->head = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    else{
        Node * temp = l->head;
        l->head = newNode;
        newNode->next = temp;
        temp->prev = newNode;
        newNode->prev = NULL;
    }
}

void * pop(GList * l){
    if (l->head == NULL){
        return NULL;
    }
    void * ptr = l->head->data->p;
	if (l->head->next == NULL)
	{
        free(l->head->data);
		free(l->head);
        l->head = NULL;
		return ptr;
	}
	l->head = l->head->next;
    free(l->head->prev->data);
    free(l->head->prev);
	l->head->prev = NULL;
	return ptr;
}
int find(GList *l, char *target){
	if(l->head == NULL)
	{
		printf("The list you are referencing is empty\n");
        return 0;
	}
	Node * temp = l->head;
    char * str = (char *) temp->data->p;
	while (temp != NULL) {
		if (strcmp(str, target) == 0)
		{
            return 1;
		}
		temp = temp->next;
	}
	printf("Target data not found in list.\n");
    return 0;
}

int delete(GList *l, char *target){
	if(l->head == NULL)
	{
		printf("The list you are referencing is empty\n");
	}
	Node * temp = l->head;
	if (l->head->data->p == target)
	{
		printf("Node with data = %s was removed from the list.\n", (char *) l->head->data->p);
		l->head = l->head->next;
		free(temp);
		return 1;
	}
	while (temp != NULL)
	{
		if (temp->data->p == target)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			printf("Node with data = %s was removed from the list.\n", (char *) temp->data->p);
			free(temp);
			return 1;
		}
		temp = temp->next;
	}
	printf("The data you wanted to delete was not found in list.\n");
    return 0;
}
void clearList(GList *l){
        Node * temp = l->head;
        while (temp != NULL)
        {
                l->head = l->head->next;
                free(temp->data->p);
                free(temp->data);
                free(temp);
                temp = l->head;
        }
	return;
}
    
