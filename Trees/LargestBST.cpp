// Given a binary tree, find the largest subtree which is a Binary Search Tree (BST)
// Largest means the subtree with the largest number of nodes.
#include "TreeNode.h"
#include <climits>

using namespace std;

class Info{
public:
    int sz;     // size of the subtree
    int max;    // Min value in subtree
    int min;    // Max value in subtree
    int ans;    // Size of the largest BST
    bool isBST; // If subree is BST
};

Info largestBST(TreeNode *root){
    if(!root)
        return {0, INT_MIN, INT_MAX, 0, true};
    
    if(!root->left && !root->right)
        return {1, root->data, root->data, 1, true};

    Info left = largestBST(root->left);
    Info right = largestBST(root->right);

    Info result;
    result.sz = 1 + left.sz + right.sz;

    if(left.isBST && right.isBST && 
        left.max < root->data && 
        right.min > root->data){
        
        result.min = min(left.min, min(right.min, root->data));
        result.max = max(right.max, max(left.max, root->data));

        result.ans = result.sz;
        result.isBST = true;
        return result;
    }

    result.ans = max(left.ans, right.ans);
    result.isBST = false;

    return result;
}

int main(){

    TreeNode *root = new TreeNode(60);
    root->left = new TreeNode(65);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(50);

    cout<<largestBST(root).ans<<"\n";
}

