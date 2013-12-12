#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Stack/Stack.c"

typedef struct _TreeNode {
	char * data;
	_TreeNode * left;
	_TreeNode * right;
} TreeNode;

typedef struct Tree {
	TreeNode * root;
} Tree;


