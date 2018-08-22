#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

typedef struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
} Tree;

void insert(struct Tree **root, int value) {
    if ( NULL == (*root) ){
        Tree *temp = new Tree;
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;
        (*root) = temp;
    }
    else {
        if( (*root)->data > value ) {
            insert(&((*root)->left), value);
        }
        else if ( (*root)->data < value ) {
            insert(&((*root)->right), value);
        }
    }
}

int maxHeight(struct Tree* root) {
    if(NULL == root){
        return 0;
    }

    int left = 1+maxHeight(root->left);
    int right = 1+maxHeight(root->right);

    return (left < right) ? right:left;
}

int minHeight(struct Tree* root){
    if(NULL == root) {
        return 0;
    }
    int left = 1+minHeight(root->left);
    int right = 1+minHeight(root->right);

    if(NULL == root->left){
        return right;
    }

    if(NULL == root->right){
        return left;
    }

    return (left < right) ? left: right;
}

int minDepth(struct Tree* root){
    queue<Tree*> treeQ;
    queue<int> depth;

    if(NULL == root){
        return 0;
    }

    treeQ.push(root);
    depth.push(1);
    Tree* temp;
    int minDepth;
    while( !treeQ.empty() ){
        temp = treeQ.front();
        treeQ.pop();
        minDepth = depth.front();
        depth.pop();

        if(NULL != temp->left){
            treeQ.push(temp->left);
            depth.push(1+minDepth);
        }

        if(NULL != temp->right){
            treeQ.push(temp->right);
            depth.push(1+minDepth);
        }

        if (NULL == temp->left && NULL == temp->right){
            return minDepth;
        }
    }
    return 0;
}

int main() {
    Tree *root = NULL;
    insert(&root, 17);
    insert(&root, 9);
    insert(&root, 23);
    insert(&root, 11);
    insert(&root, 21);
    insert(&root, 7);
    insert(&root, 31);
    insert(&root, 13);

    cout<<"Max depth of the BST: ";
    cout<<maxHeight(root)<<endl;

    cout<<"Min depth of the BST: ";
    cout<<minHeight(root)<<endl;

    cout<<"Iterative solution: Min depth of the BST: ";
    cout<<minDepth(root)<<endl;

    return 0;
}