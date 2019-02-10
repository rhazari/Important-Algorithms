#include "TreeNode.h"

using namespace std;

void insert(TreeNode **root, int data) {
    if ( !(*root) ){
        TreeNode *temp = new TreeNode(data);
        (*root) = temp;
    }
    else {
        if( (*root)->data > data ) {
            insert(&((*root)->left), data);
        }
        else if ( (*root)->data < data ) {
            insert(&((*root)->right), data);
        }
    }
}

int main() {
    int N, tmp;
    TreeNode *root = nullptr;
    cout<<"Number of Elements to enter in BST"<<"\n";
    cin >> N;

    while(N) {
        cout<<"Enter a data"<<endl;
        cin >> tmp;
        insert(&root, tmp);
        --N;
    }
    cout<<"\nIn-Order traversal after BST insertion"<<"\n";
    inOrder(root);
    cout<<"\n";
}