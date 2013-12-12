#include <stdio.h>
#include <stdlib.h>
void printData(void *);

int main(){
	int num = 1;
	void * val = &num;
	printData(val);
}

void printData(void * data){
	int result = (*(int *) data)*2; 
	printf("%d\n", result);
}
