//Program for generating a Binary Search Tree
//Also outputs the in-order, pre-order & post-order traversal of the BST

#include <iostream>
#include <cstdlib>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

int contains(TreeNode* root, int num) {
    TreeNode* ptr = root;
    
    if(nullptr == ptr) {
        return false;
    }
    
    while(nullptr != ptr){
        if(ptr->val ==  num) {
            return true;
        }
        else if(ptr->val > num) {
            ptr = ptr->left;
        }
        else if(ptr->val < num) {
            ptr = ptr->right;
        }
    }
    return false;
}

bool insert(TreeNode* root, int num) {
    TreeNode* ptr = new TreeNode(num);
    
    TreeNode* curr = root;
    TreeNode* prev = NULL;
    
    if(contains(root, num)) {
        cout<< num<<" already exits in the tree\n";
        return false;
    }
    else {
        while(nullptr != curr) {
            if(curr->val > num) {
                prev = curr;
                curr = curr->left;
            }
            else {
                prev = curr;
                curr = curr->right;
            }
        }
    }
    
    if(nullptr == curr) {
        if(prev->val > num) {
            prev->left = ptr;
            return true;
        }
        else {
            prev->right = ptr;
            return true;
        }   
    }
    return false;
}

void inorder(TreeNode* ptr) {
    if(nullptr != ptr) {
        inorder(ptr->left);
        cout<<ptr->val<<" ";
        inorder(ptr->right);
    }
}

void preorder(TreeNode* ptr) {
    if(nullptr != ptr) {
        cout << ptr->val<<" ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(TreeNode* ptr) {
    if(nullptr != ptr) {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->val <<" "; 
    }
}

int main() {

    TreeNode* root = new TreeNode(13);
    int read = 5;
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
    
    cout<<"Preorder BST traversal\n";
    preorder(root);
    cout<<"\n";
    
    cout<<"Postorder BST traversal\n";
    postorder(root);
    cout<<"\n";
    return 0;
}
