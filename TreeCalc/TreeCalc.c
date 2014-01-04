#include "TreeCalc.h"
int main(){

    GStack * myStack = initGStack(); 
    myStack = fillTree("test.txt", myStack);
    printf("Result = %d\n", calculate(myStack->head->data->p));
    return 0;
}
int calculate(TreeNode * tn){
	switch(tn->value)
	{
	case '+' :
		return calculate(tn->left) + calculate(tn->right);
		break;
	case '-' :
		return calculate(tn->left) - calculate(tn->right);
		break;
	case '*' :
		return calculate(tn->left) * calculate(tn->right);
		break;
	case '/' :
		return calculate(tn->left) / calculate(tn->right);
		break;
    default :
        return (tn->value - '0'); 
	}
}
TreeNode * createTreeNode(char value){
	TreeNode * treeNode = (TreeNode *) malloc( sizeof( TreeNode));
	treeNode->value = value;
    treeNode->left = NULL;
	treeNode->right = NULL;
    return treeNode;
}	
	
GStack * fillTree(char * word, GStack * myStack){
	FILE *fp;
	char input[50];
	fp = fopen(word, "r");
	if ( fp == NULL) perror("Error opening file");
	else{	
		if ( fgets (input, sizeof(input), fp) != NULL ) {
			puts(input);
			int i;
            printf("Input Length = %d\n", strlen(input));
			for (i = 0; i < strlen(input) - 1; i++){
                insert(input[i], myStack);
			}		
		}	
	}
    return myStack;
}
void insert(char val, GStack * myStack){
    TreeNode * tn = createTreeNode(val);
    void * ptr = tn;
    char * operators = "/+-*";
    if (isdigit(val)){
        printf("in isdigit\n");
        printf("%c\n", tn->value);
        push( myStack, ptr);
        return;
    }
    if (strchr(operators, val) != NULL){
        printf("in operators\n");
        printf("%c\n", tn->value);
        tn->left = pop( myStack);
        tn->right = pop( myStack);
        push( myStack, ptr);
        return;
    }
    else{
        printf("Invalid character %c in input file...Exiting\n", val);
        return;
    }
}
