#include "TreeCalc.h"
#define OPERATORS "/+-*"
int main(){

    GStack * myStack = initGStack(); 
    myStack = fillTree("test.txt", myStack);
    TreeNode * myTree = myStack->head->data->p;
    printf("Result = %d\n", calculate(myStack->head->data->p));
    printf("Prefix: \n");
    print_prefix(myTree);
    printf("\n");
    printf("Postfix: \n");
    print_postfix(myTree);
    printf("\n");
    printf("Infix: \n");
    print_infix(myTree);
    printf("\n");
    emptyTree(myStack->head->data->p);
    free(myStack->head->data);
    free(myStack->head);
    free(myStack);
    return 0;
}
int emptyTree(TreeNode * tn){
    if(tn != NULL){
        emptyTree(tn->left);
        emptyTree(tn->right);
        free(tn);
        tn = NULL;
    }
    return 1;
}
void print_infix(TreeNode * tn){
    if (tn == NULL){
        return;
    }
    if (tn->left){
        printf("( ");
        print_infix(tn->left);
    }
    printf("%c",tn->value);
    if(tn->right){
        print_infix(tn->right);
        printf(" )");
    }
}
void print_prefix(TreeNode * tn){
    if(tn != NULL){
        printf("%c ", tn->value);
        print_prefix(tn->left);
        print_prefix(tn->right);
    }
}
void print_postfix(TreeNode * tn){
    if(tn == NULL){
        return;
    }
    if(tn->right){
        print_postfix(tn->right);
    }
    if(tn->left){
        print_postfix(tn->left);
    }
    printf("%c ", tn->value);
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
            printf("Input is: ");
			puts(input);
			int i;
            printf("Input Length = %d\n", strlen(input));
			for (i = 0; i < strlen(input) - 1; i++){
                insert(input[i], myStack);
			}		
		}	
	}
    fclose(fp);
    return myStack;
}
void insert(char val, GStack * myStack){
    TreeNode * tn = createTreeNode(val);
    void * ptr = tn;
    if (isdigit(val)){
        push( myStack, ptr);
        return;
    }
    if (strchr(OPERATORS, val) != NULL){
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
