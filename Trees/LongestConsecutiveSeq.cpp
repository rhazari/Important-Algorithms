// Given a binary tree, find the length of the longest consecutive sequence path.
#include "TreeNode.h"
#include <algorithm>
#include <vector>

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

void dfs(TreeNode* root, int len, int& result){
    result = max(len, result);
    if(root->left){
        if(root->left->data == root->data+1)
            dfs(root->left, len+1, result);
        else
            dfs(root->left, 1, result);
    }
    if(root->right){
        if(root->right->data == root->data+1)
            dfs(root->right, len+1, result);
        else
            dfs(root->right, 1, result);
    }
}

int longestConsecutiveSequence(TreeNode * root){
    if(!root)
        return 0;
    int result = 0;
    dfs(root, 1, result);
    return result;
}

int main(){
    TreeNode *tree = nullptr;
    insert(&tree, 6);
    insert(&tree, 11);
    insert(&tree, 7);
    insert(&tree, 4);
    insert(&tree, 5);
    insert(&tree, 3);
    insert(&tree, 8);
    insert(&tree, 13);

    cout<<"In Order Traversal"<<endl;
    inOrder(tree);
    cout<<endl;

    cout<<"Longest Consecutive Sequence: "<<longestConsecutiveSequence(tree)<<"\n";

    return 0;
}