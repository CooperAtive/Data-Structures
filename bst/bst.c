//Cooper Trowbridge
//Binary Search Tree in C
//1/10/2014

#include "bst.h"

int main(int argc, char **argv) {
    tree *mytree = init_tree();
    int myint = 20;
    int myint2 = 15;
    int myint3 = 25;
    int myint4 = 7;
    int myint5 = 24;
    int myint6 = 18;
    int myint7 = 26;
    int myint8 = 17;
    
    insert(mytree, myint);
    insert(mytree, myint2);
    insert(mytree, myint3);
    insert(mytree, myint4);
    insert(mytree, myint5);
    insert(mytree, myint6);
    insert(mytree, myint7);
    insert(mytree, myint8);

    print_tree(mytree->root);
    delete(mytree, 7);
    printf("after_delete: \n");
    print_tree(mytree->root);
    destroy(mytree);
    return 0;
}


//Constructors
tree * init_tree() {
    tree *t = (tree *) malloc(sizeof(tree));
    t->root = NULL;
    return t;
}

treenode * make_treenode(int data) {
    treenode *tn = (treenode *) malloc(sizeof(treenode));
    tn->data = data;
    tn->left = NULL;
    tn->right = NULL;
    return tn;
}
//Deconstructor
void destroy(tree *t) {
    r_destroy(t->root);
    free(t);
}

void r_destroy(treenode *root) {
   if (root != NULL) {
       r_destroy(root->left);
       r_destroy(root->right);
       free(root);
   }
}


/// Print

void print_tree(treenode *tn) {
    if(tn != NULL){
        printf("%d\n", tn->data);
        print_tree(tn->left);
        print_tree(tn->right);
    }
}

int p_search(treenode **cur_ptr, treenode **parent_ptr, int data) {
    while(*cur_ptr != NULL) {
        if((*cur_ptr)->data == data)
            return 1;
        else if (data > (*cur_ptr)->data) {
            *parent_ptr = *cur_ptr;
            *cur_ptr = (*cur_ptr)->right;
        }
        else { 
            *parent_ptr = *cur_ptr;
            *cur_ptr = (*cur_ptr)->left;
        }
    }
    return 1;
} 


int successor_swap(treenode **cur_ptr, treenode **parent_ptr, treenode **succ_ptr, int data) {
    *parent_ptr = *cur_ptr;
    *succ_ptr = (*cur_ptr)->right;
    while ((*succ_ptr)->left != NULL) {
        *parent_ptr = *succ_ptr;
        *succ_ptr = (*succ_ptr)->left;
    }
    (*cur_ptr)->data = (*succ_ptr)->data;
    (*parent_ptr)->left = (*succ_ptr)->left;
    free(*succ_ptr);
    return 1;
}

//Insert/Search/Delete
//
//Some functions have 2 versions
//For example: insert(tree*, int); and r_insert(treenode*, int);
//User can use insert as a blackbox to access a tree
//The actual meat (recursion) will occur in r_insert;

int insert(tree* t, int data){
    t->root = r_insert(t->root, data);
    return 1;
}

//return 0 if node is a duplicate
treenode * r_insert(treenode *root, int data) {
    if (root == NULL)
        root = make_treenode(data);
    if (root->data == data)
        return root;
    if (root->data > data)
        root->left = r_insert(root->left, data);
    if(root->data < data)
        root->right = r_insert(root->right, data);
    return root;
}

int search(tree *t, int data) {
    return r_search(t->root, data);
}

int r_search(treenode *root, int data) {
    if (root == NULL)
        return 0;
    if (root->data == data)
        return 1;
    if (root->data < data) 
        r_search(root->left, data);
    if (root->data > data)
        r_search(root->right, data);
}

int delete(tree *t, int data) {
    return r_delete(t->root, data);
}

int r_delete(treenode *root, int data) {
    treenode *cur = root;
    treenode *succ, *parent;
    treenode **cur_ptr = &cur;
    treenode **parent_ptr = &parent;
    treenode **succ_ptr = &succ;
    treenode arr[2];
    int dir;

    p_search(cur_ptr, parent_ptr, data);

    if (cur->left != NULL && cur->right != NULL) {
        successor_swap(cur_ptr, parent_ptr, succ_ptr, data);
        /*
        parent = cur;
        succ = cur->right;
        while (succ->left != NULL){
            parent = succ;
            succ = succ->left;
        }
        cur->data = succ->data;
        parent->left = succ->left;

        free(succ);
        */
    }
    else {
        dir = parent->left == NULL;
        if (parent == NULL){
            if (dir)
                cur = cur->right;
            else
                cur = cur->left;
        }
        else {
            if (parent->right == cur)
                parent->right = cur->right;
            else
                parent->left = cur->left;
        }
        free(cur);
    }
}
