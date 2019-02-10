//Program to find the in-order successor and predecessor 
//of a node with a given dataue
#include "TreeNode.h"

using namespace std;

void inorder(TreeNode* ptr){
    if(ptr){
        inorder(ptr->left);
        cout<<ptr->data<<" ";
        inorder(ptr->right);
    }
}

void createBST(TreeNode **root, int num){
    if(!(*root)){
        TreeNode* newNode = new TreeNode(num);
        *root = newNode;
    }
    else if((*root)->data < num)
        createBST(&(*root)->right, num);
    else
        createBST(&(*root)->left, num);
}

void predecessor(TreeNode* ptr, TreeNode** pred, int data){
    if(!ptr)
        return;
    if(ptr->data == data){
        if(ptr->left){
            ptr = ptr->left;
            while(ptr->right)
                ptr = ptr->right;
            (*pred) = ptr;
        }
        return;
    }
    else if(ptr->data > data){
        predecessor(ptr->left, pred, data);
    }
    else if(ptr->data < data){
        *pred = ptr;
        predecessor(ptr->right, pred, data);
    }
}

void successor(TreeNode* ptr, TreeNode** succ, int data){
    if(!ptr)
        return;
    if(ptr->data == data){
        if(ptr->right){
            ptr = ptr->right;
            while(ptr->left)
                ptr = ptr->left;
            (*succ) = ptr;
        }
    }
    else if(ptr->data > data){
        *succ = ptr;
        successor(ptr->left, succ, data);
    }
    else if(ptr->data < data){
        successor(ptr->right, succ, data);
    }
}

int main(){
    TreeNode *tree = nullptr;
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
     cout<<"Enter a dataue whose predecessor & successor needs to be found \n";
     cin >> num;
     predecessor(tree, &pred, num);
     successor(tree, &succ, num);

    if(pred)
        cout<<"Predecessor of "<<num<<": "<<pred->data<<"\n";
    else
        cout<<"Predecessor is a nullptr"<<"\n";

    if(succ)
        cout<<"Successor of "<<num<<": "<<succ->data<<"\n";
    else
        cout<<"Successor is a nullptr \n";

    return 0;
}