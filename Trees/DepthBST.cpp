#include <iostream>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};


void insert(TreeNode **root, int value) {
    if ( nullptr == (*root) ){
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

int maxHeight(TreeNode* root) {
    if(nullptr == root){
        return 0;
    }

    int left = maxHeight(root->left);
    int right = maxHeight(root->right);

    return 1+max(left, right);
}

int minHeight(TreeNode* root){
    if(nullptr == root) {
        return 0;
    }
    int left = minHeight(root->left);
    int right = minHeight(root->right);

    if(nullptr == root->left){
        return right;
    }

    if(nullptr == root->right){
        return left;
    }

    return 1+min(left, right);
}

int minDepth(TreeNode* root){
    queue<TreeNode*> treeQ;
    queue<int> depth;

    if(nullptr == root){
        return 0;
    }

    treeQ.push(root);
    depth.push(1);
    int minDepth;
    while( !treeQ.empty() ){
        auto* temp = treeQ.front();
        treeQ.pop();
        minDepth = depth.front();
        depth.pop();

        if(nullptr != temp->left){
            treeQ.push(temp->left);
            depth.push(1+minDepth);
        }

        if(nullptr != temp->right){
            treeQ.push(temp->right);
            depth.push(1+minDepth);
        }

        if (nullptr == temp->left && nullptr == temp->right){
            return minDepth;
        }
    }
    return 0;
}

int main() {
    TreeNode *root = nullptr;
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