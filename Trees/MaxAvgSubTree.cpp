// Given a binary tree, find the subtree with maximum average. Return the root of the subtree

/*
    Example 1:
    Input：
        1
      /   \
    -5     11
    / \   /  \
    1   2 4    -2 
    Output：11(it's a TreeNode)
    
    Example 2
    Input：
        1
      /   \
    -5     11
    Output：11(it's a TreeNode)
*/

#include <iostream>
#include <utility>
 class TreeNode {
 public:
     int val;
     TreeNode *left, *right;
     TreeNode(int val) {
         this->val = val;
         this->left = this->right = nullptr;
     }
 };

using namespace std;

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    TreeNode *cache = nullptr;
    double avg = INT_MIN;
    
    pair<int,int> helper(TreeNode* node){
        if(!node)
            return make_pair(0,0);
        
        pair<int,int> left = helper(node->left);
        pair<int, int> right = helper(node->right);
        
        int count = 1 + left.second + right.second;
        double x = (node->val + left.first*left.second + right.first*right.second)/double(count);
        if(x > avg){
            avg = x;
            cache = node;
        }
        return make_pair(x, count);
    }
     
    TreeNode * findSubtree2(TreeNode * root) {
        // write your code here
        if(!root)
            return nullptr;
        helper(root);
        return cache;
    }
};