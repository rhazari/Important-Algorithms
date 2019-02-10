#include "TreeNode.h"
#include <queue>

using namespace std;

void insert(TreeNode **root, int data) {
    if ( nullptr == (*root) ){
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
    int left = minHeight(root->left)+1;
    int right = minHeight(root->right)+1;

    if(nullptr == root->left){
        return right;
    }
    if(nullptr == root->right){
        return left;
    }
    return min(left, right);
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

    cout<<"Max depth of the BST \n";
    cout<<maxHeight(root)<<"\n";

    cout<<"Min depth of the BST \n";
    cout<<minHeight(root)<<"\n";

    cout<<"Iterative solution: Min depth of the BST \n";
    cout<<minDepth(root)<<"\n";
}