#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../GStack/GStack.c"

typedef struct TreeNode {
	struct TreeNode * left;
	struct TreeNode * right;
	char value;
} TreeNode;

int emptyTree(TreeNode *);
GStack * fillTree(char * word, GStack *);
void insert (char, GStack *);
TreeNode * createTreeNode(char);
int calculate(TreeNode *);
int is_leaf(TreeNode *);
void print_postfix(TreeNode *);
void print_prefix(TreeNode *);
void print_infix(TreeNode *);
int all_unique(char *);
