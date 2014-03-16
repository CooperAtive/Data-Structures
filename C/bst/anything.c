treenode * find(treenode * root, data) {
    treenode *cur = root;
    while(cur != NULL) {
        if(cur->data == data)
            return cur;
        else if (data > cur->data) {
            p = cur;
            cur = cur->right;
        }
        else { 
            p = cur;
            cur = cur->left;
        }
    }
    return NULL;
} 

int successor_swap(treenode * cur, treenode * parent, treenode * succ, int data) {
    parent = cur;
    succ = cur->right;
    while (succ->left != NULL) {
        parent = succ;
        succ = succ->left;
    }
    cur->data = succ->data;
    parent->left = succ->left;
    free(succ);
}
