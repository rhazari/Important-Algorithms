#include <iostream>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

void inOrder(TreeNode *root ) {
    if( root ){
        inOrder(root->left);
        cout<<root->val<<" ";
        inOrder(root->right);
    }
}

void insert(TreeNode **root, int value) {
    if ( !(*root) ){
        TreeNode *temp = new TreeNode(value);
        (*root) = temp;
    }
    else {
        if( (*root)->val > value ) {
            insert(&((*root)->left), value);
        }
        else if ( (*root)->val < value ) {
            insert(&((*root)->right), value);
        }
    }
}

int main() {
    int N, tmp;
    TreeNode *root = nullptr;
    cout<<"Number of Elements to enter in BST"<<"\n";
    cin >> N;

    while(N) {
        cout<<"Enter a value"<<endl;
        cin >> tmp;
        insert(&root, tmp);
        --N;
    }
    cout<<"\nIn-Order traversal after BST insertion"<<"\n";
    inOrder(root);
    cout<<"\n";

    return 0;
}