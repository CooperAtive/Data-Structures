#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../GStack/GStack.c"

typedef struct _TreeNode {
	char value;
	struct _TreeNode * left;
	struct _TreeNode * right;
} TreeNode;

typedef struct Tree {
	TreeNode * root;
} Tree;
Tree * initTree();
//Tree * fillTree(char *);
TreeNode * createTreeNode(char *);
//int calculate(Tree *);
