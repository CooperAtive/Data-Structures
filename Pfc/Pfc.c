#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pfc.h"
#include "../Stack/Stack.c"

int main()
{
	calculate("test.txt");
}
int calculate(char * word){
	Stack * myStack = initStack();
	FILE *fp;
	char input[50];

	fp = fopen(word, "r");
	if ( fp == NULL) perror("Error opening file");
	else
	{	
		if ( fgets (input, sizeof(input), fp) != NULL ) {
			puts(input);
			int i;
			for (i = 0; i < strlen(input) - 1; i++)
			{
				char * operators = "+-*/";
				if (isdigit(input[i]))
				{
					char array[2];
					array[0] = input[i];
					array[1] = '\0';
					int operand = atoi(array);	
					push( myStack, operand);
				}
				else if (strchr(operators, input[i]) != NULL)
				{
					int result;
					int value;
					switch(input[i])
					{
					case '+' :
						result = pop( myStack) + pop( myStack);
						push( myStack, result);
						break;
					case '-' :
						value = pop( myStack);
						result = pop( myStack) - value;
						push( myStack, result);
						break;
					case '*' :
						result = pop( myStack) * pop( myStack);
						push( myStack, result);
						break;
					case '/' :
						value = pop( myStack);
						result = pop( myStack) / value;
						push( myStack, result);
						break;
					}
					printf("found an operator %c\n", input[i]);
				}
				else
				{
					printf("Invalid character %c in input f							ile...Exiting\n", input[i]);
					return 0;
				}
			}		
	int final = pop ( myStack);
	if (top( myStack) == -1){
		printf("%d, if you see 'Stack is empty' printed above, the input contains too many operators for the number of integers entered.\n", final);
		return 0;
		}
	printf("Input contains too many integers for the amout of operators entered.\n");
		}	
	}
}
