#include "TreeCalc.h"
int main(){
    
    GStack * myStack = fillTree("test.txt");
    /*
    char z = '4';
    void * s = &z;
    char e = '2';
    void * r = &e;
    push( myStack, s);
    push( myStack, r);
    */
    char ch = *(char *) pop( myStack);
    printf("First pop = %c\n", ch);
    char ch1 = *(char *) pop( myStack);
    printf("Second pop = %c\n", ch1);
    //char ch2 = *(char *) pop( myStack);
    //printf("%c\n", ch);


    /*
    char ch[2];
    ch[0] = 'a';
    ch[1] = '\0';
    TreeNode * tn = createTreeNode('a');
    printf("%c\n", tn->value);
    void * ptr = tn;
    push(myStack, ptr);
    TreeNode * atn = pop(myStack);
    printf("%c\n", atn->value);
    */
}
    /*

int calculate(Tree * tree){
	if (tree->root == NULL){
		printf("Tree is empty, exiting\n");
		return;
	}
	switch(tree->root->data)
	{
	case '+' :
		return tree->root->left->data + tree->root->right->data;
		break;
	case '-' :
		return tree->root->left->data - tree->root->right->data;
		break;
	case '*' :
		return tree->root->left->data * tree->root->right->data;
		break;
	case '/' :
		return tree->root->left->data / tree->root->right->data;
		break;
	}
	
}
*/

Tree * initTree(){
	Tree * tree = (Tree *) malloc( sizeof( Tree));
    tree->root = NULL;
	return tree;
}

TreeNode * createTreeNode(char value){
	TreeNode * treeNode = (TreeNode *) malloc( sizeof( TreeNode));
	treeNode->value = value;
    treeNode->left = NULL;
	treeNode->right = NULL;
    return treeNode;
}	
	
GStack * fillTree(char * word){
    GStack * myStack = initGStack();
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
            return myStack;
		}	
	}
}
void insert(char val, GStack * myStack){
    TreeNode * tn = createTreeNode(val);
    void * ptr = tn;
    char * operators = "/+-*";
    if (isdigit(val)){
        push( myStack, ptr);
        return;
    }
    if (strchr(operators, val) != NULL){
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
