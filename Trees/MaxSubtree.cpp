// Given a binary tree, find the subtree with maximum sum. Return the root of the subtree

/*
    Example 1:
    Input : 
        1
      /   \
    -5     2
    / \   /  \
    0   3 -4  -5
    Output : 3
*/

#include <iostream>
 class TreeNode {
 public:
     int val;
     TreeNode *left, *right;
     TreeNode(int val) {
         this->val = val;
         this->left = this->right = nullptr;
     }
 };

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the maximum weight node
     */
    TreeNode *cache = nullptr;
    int sum = 0;
    int helper(TreeNode* node){
        if(!node)
            return 0;
        int left = helper(node->left);
        int right = helper(node->right);
        if(node->val + left + right > sum){
            sum = node->val + left + right;
            cache = node;
        }
        return node->val + left + right;
    }
    
    TreeNode * findSubtree(TreeNode * root) {
        // write your code here
        if(!root)
            return nullptr;
        helper(root);
        return cache;
    }
};