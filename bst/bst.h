#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct treenode {
    struct treenode *left;
    struct treenode *right;
    int data;
} treenode;

typedef struct tree {
    treenode *root;
} tree;

tree * init_tree();
treenode * make_treenode(int);
int insert(tree *, int);
treenode * r_insert(treenode*, int);
int search(tree *, int);
int r_search(treenode *, int);
int delete(tree *, int);
int r_delete(treenode *, int);
void print_tree(treenode *);
void destroy(tree *);
void r_destroy(treenode *);
