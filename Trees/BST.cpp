//Program for generating a Binary Search Tree
//Also outputs the in-order, pre-order & post-order traversal of the BST

#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct node{
    int value;
    struct node* left;
    struct node* right;
}
node;

node* root = NULL;

int contains(int num)
{
    node* index = root;
    
    if(index == NULL)
    {
        return 0;
    }
    
    while(index != NULL)
    {
        if(index->value ==  num)
        {
            return 1;
        }
        else if(index->value > num)
        {
            index = index->left;
        }
        else if(index->value < num)
        {
            index = index->right;
        }
    }
    return 0;
    
}

int insert(int num)
{
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = num;
    ptr->left = NULL;
    ptr->right = NULL;
    
    node* index = root;
    node* prev = NULL;
    
    if(contains(num))
    {
        cout<< num<<" already exits in the tree\n";
        return 0;
    }
    else
    {
        while(index != NULL)
        {
            if(index->value > num)
            {
                prev = index;
                index = index->left;
            }
            else
            {
                prev = index;
                index = index->right;
            }
        }
    }
    
    if(index == NULL)
    {
        if(prev->value > num)
        {
            prev->left = ptr;
            return 1;
        }
        else
        {
            prev->right = ptr;
            return 1;
        }   
    }
    return 0;
}

void inorder(node* ptr)
{
    if(ptr != NULL)
    {
        inorder(ptr->left);
        cout<<ptr->value<<" ";
        inorder(ptr->right);
    }
}

void preorder(node* ptr)
{
    if(ptr != NULL)
    {
        cout << ptr->value<<" ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(node* ptr)
{
    if(ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->value <<" "; 
    }
}

int main()
{
    
    root = (node*)malloc(sizeof(node));
    root->value = 13;
    root->left = NULL;
    root->right = NULL;
    
    int read = 5;
    int x;
    while(read)
    {
        cout<<"Enter a value into the BST\n";
        cin >> x;
        
        if(insert(x))
        {
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
