//Program to check if a binary tree is balanced or not
#include "TreeNode.h"

using namespace std;

int contains(TreeNode* root, int num) {
    if(!root)
        return 0;
    while(root) {
        if(root->data ==  num) {
            return 1;
        }
        else if(root->data > num) {
            root = root->left;
        }
        else if(root->data < num) {
            root = root->right;
        }
    }
    return 0;
}

int insert(TreeNode* root, int num) {
    TreeNode* ptr = new TreeNode(num); 
    TreeNode *curr = root;
    TreeNode *prev = nullptr;
    
    if(contains(root, num)) {
        cout<< num<<" already exits in the tree\n";
        return 0;
    }
    else {
        while(curr) {
            if(curr->data > num) {
                prev = curr;
                curr = curr->left;
            }
            else {
                prev = curr;
                curr = curr->right;
            }
        }
    }    
    if(!curr) {
        if(prev->data > num)
        {
            prev->left = ptr;
            return 1;
        }
        else{
            prev->right = ptr;
            return 1;
        }   
    }
    return 0;
}

void inorder(TreeNode* ptr) {
    if(ptr) {
        inorder(ptr->left);
        cout<<ptr->data<<" ";
        inorder(ptr->right);
    }
}

int checkHeight(TreeNode* root) {
    if(!root) 
        return 0;
    
    int left = checkHeight(root->left);
    if(left == -1) 
        return -1;
    
    int right = checkHeight(root->right);
    if(right == -1) 
        return -1;
    
    int heightDiff = left - right;
    if(abs(heightDiff) > 1) 
        return -1;
    else
        return max(left,right)+1;
}

int isBalanced(TreeNode* root) {
    if(checkHeight(root) == -1)
        return 0;
    else
        return 1;
}

int main() { 
    TreeNode *root = new TreeNode(13);
    
    int read = 6;
    int x;
    while(read) {
        cout<<"Enter a value into the BST\n";
        cin >> x;
        
        if(insert(root, x)){
            read--;
        }
    }
    cout<<"Inorder BST traversal\n";
    inorder(root);
    cout<<"\n";
    
    if(isBalanced(root))
        cout <<"The tree is a balanced BST \n";
    else
        cout <<"The tree is not a balanced BST \n";
}
