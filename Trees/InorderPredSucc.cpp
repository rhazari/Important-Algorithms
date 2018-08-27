//Program to find the in-order successor and predecessor 
//of a node with a given value
#include <iostream>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data): val(data), left(nullptr), right(nullptr){}
};


void inorder(TreeNode* ptr){
    if(ptr){
        inorder(ptr->left);
        cout<<ptr->val<<" ";
        inorder(ptr->right);
    }
}

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

void predecessor(TreeNode* ptr, TreeNode** pred, int value){
    if(!ptr)
        return;
    if(ptr->val == value){
        if(ptr->left){
            ptr = ptr->left;
            while(ptr->right)
                ptr = ptr->right;
            (*pred) = ptr;
        }
        return;
    }
    else if(ptr->val > value){
        predecessor(ptr->left, pred, value);
    }
    else if(ptr->val < value){
        *pred = ptr;
        predecessor(ptr->right, pred, value);
    }
}

void successor(TreeNode* ptr, TreeNode** succ, int value){
    if(!ptr)
        return;
    if(ptr->val == value){
        if(ptr->right){
            ptr = ptr->right;
            while(ptr->left)
                ptr = ptr->left;
            (*succ) = ptr;
        }
    }
    else if(ptr->val > value){
        *succ = ptr;
        successor(ptr->left, succ, value);
    }
    else if(ptr->val < value){
        successor(ptr->right, succ, value);
    }
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

    cout<<"Inorder BST traversal\n";
    inorder(tree);
    cout<<"\n";

     TreeNode* pred = nullptr;
     TreeNode* succ = nullptr;
     int num;
     cout<<"Enter a value whose predecessor & successor needs to be found"<<"\n";
     cin >> num;
     predecessor(tree, &pred, num);
     successor(tree, &succ, num);

    if(pred)
        cout<<"Predecessor of "<<num<<": "<<pred->val<<"\n";
    else
        cout<<"Predecessor is a nullptr"<<"\n";

    if(succ)
        cout<<"Successor of "<<num<<": "<<succ->val<<"\n";
    else
        cout<<"Successor is a nullptr"<<"\n";

    return 0;
}