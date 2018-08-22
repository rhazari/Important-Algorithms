#include <iostream>
#include <cstdlib>

#define SZ 10

using namespace std;

typedef struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
} Tree;

struct Tree* createBST(int *array, int left, int right) {
    if(left < right) {
        int mid = (left+right)/2;
        Tree* root = new Tree;
        root->data = array[mid];
        root->left = createBST(array, left, mid);
        root->right = createBST(array, mid+1, right);
        return root;
    }
    else{
        return NULL;
    }
}

void inOrder( struct Tree* root ){
    if(NULL != root){
        inOrder(root->left);
        cout<<root->data<<"";
        inOrder(root->right);
    }
}

int main() {
    int *array = (int*)malloc(SZ*sizeof(int));
    int k;
    for( k = 0; k < SZ; ++k ){
        array[k] = k+2;
    }

    Tree* temp = createBST(array, 0, SZ);
    cout<<"In Order traversal of the BST"<<endl;
    inOrder(temp);
    cout<<endl;
    return 0;
}