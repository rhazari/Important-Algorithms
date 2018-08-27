// Given a binary tree, find the length of the longest consecutive sequence path.
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

void inOrder(TreeNode *root ) {
    if(!root)
        return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
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

void dfs(TreeNode* root, int len, int& result){
    result = max(len, result);
    if(root->left){
        if(root->left->val == root->val+1)
            dfs(root->left, len+1, result);
        else
            dfs(root->left, 1, result);
    }
    if(root->right){
        if(root->right->val == root->val+1)
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