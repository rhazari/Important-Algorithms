#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int _val){
        val = _val;
        left = nullptr;
        right = nullptr;
    }
};

void createBST(TreeNode **root, int num){
    if(!(*root)){
        TreeNode* newNode = new TreeNode(num);
        *root = newNode;
    }
    else if((*root)->val < num)
        createBST(&(*root)->right, num);
    else
        createBST(&(*root)->left, num);
}

void preOrder(TreeNode *root){
    if(!root)
        return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int helper(vector<vector<int>> &vec, TreeNode* root){
    if(!root)
        return -1;
    int left = helper(vec, root->left)+1;
    int right = helper(vec, root->right)+1;
    int curr = max(left, right);

    if(curr >= vec.size())
        vec.resize(curr+1);
    vec[curr].push_back(root->val);
    return curr;
}

vector<vector<int>> findLeaves(TreeNode* root){
    vector<vector<int>> result;
    helper(result, root);
    return result;
}

int main(){

    TreeNode *tree;
    createBST(&tree, 6);
    createBST(&tree, 11);
    createBST(&tree, 7);
    createBST(&tree, 4);
    createBST(&tree, 5);
    createBST(&tree, 3);
    createBST(&tree, 8);
    createBST(&tree, 13);

    cout<<"Pre Order Traversal"<<endl;
    preOrder(tree);
    cout<<endl;

    vector<vector<int>> vec = findLeaves(tree);
    for(const auto& v: vec){
        for(const auto& elem: v)
            cout<<elem<<" ";
        cout<<endl;
    }

    return 0;
}