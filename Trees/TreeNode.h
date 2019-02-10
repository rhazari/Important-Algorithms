#include <iostream>

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr){}
};

void inOrder(TreeNode* root){
    if(root->left){
        inOrder(root->left);
    }
    std::cout<<root->data<<" ";
    if(root->right){
        inOrder(root->right);
    }
}