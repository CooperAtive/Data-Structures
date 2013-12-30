#include "TreeCalc.h"
int main(){
    
    GStack * myStack = initGStack();
    char ch[2];
    ch[0] = 'a';
    ch[1] = '\0';
    TreeNode * tn =  malloc(sizeof(TreeNode));
    tn->left = NULL;
    tn->right = NULL;
    tn->value = 'a';
    printf("%c\n", tn->value);
    void * ptr = tn;
    TreeNode * atn = (TreeNode *) tn;
    printf("%c\n", atn->value);

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

TreeNode * createTreeNode(char * value){
	TreeNode * treeNode = (TreeNode *) malloc( sizeof( TreeNode));
	treeNode->value = value;
    treeNode->left = NULL;
	treeNode->right = NULL;
    return treeNode;
}	
/*	
Tree * fillTree(char * word){
	GStack * operands = initGStack();
    GStack * treeNodes = initGStack();
	Tree * myTree = initTree();
	FILE *fp;
	char input[50];

	fp = fopen(word, "r");
	if ( fp == NULL) perror("Error opening file");
	else{	
		if ( fgets (input, sizeof(input), fp) != NULL ) {
			puts(input);
			int i;
			for (i = 0; i < strlen(input) - 1; i++){
			//	char * operators = "/+-*";
				if (isdigit(input[i])){
					char operandArr[2];
					operandArr[0] = input[i];
					operandArr[1] = '\0';
					int operand = atoi( operandArr);	
					push( myStack, operand);
				}
				else if (strchr(operators, input[i]) != NULL)
					char operatorArr[2];
					operatorArr[0] = input[i];
					operatorArr[1] = '\0';
					char operator = input[i];
					TreeNode * newTreeNode = createTreeNode( operator);
					
					if (myTree->root == NULL){
						myTree->root = newTreeNode;
						TreeNode * rightNode = createTreeNode( pop( myStack));
						TreeNode * leftNode = createTreeNode( pop( myStack));
						newTreeNode->right = rightNode;
						newTreeNode->left = leftNode;

					}
					else{
						
					}
				else{
					printf("Invalid character %c in input file...Exiting\n", input[i]);
					return;
				}
			}		
		return myTree;
		}	
	}
}
*/
