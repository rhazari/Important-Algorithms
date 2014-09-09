#include <iostream>
#include <cstdlib>
#include <algorithm>

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

int checkHeight(struct node* root)
{
    if(root == NULL) return 0;
    
    int left_height = checkHeight(root->left);
    if(left_height == -1) return -1;
    
    int right_height = checkHeight(root->right);
    if(right_height == -1) return -1;
    
    int height_diff = left_height-right_height;
    if(abs(height_diff) > 1) return -1;
    else
    {
        return max(checkHeight(root->left),checkHeight(root->right))+1;
    }    
}

int isBalanced()
{
    if(checkHeight(root) == -1)
        return 0;
    else
        return 1;
    
}

int main()
{ 
    root = (node*)malloc(sizeof(node));
    root->value = 13;
    root->left = NULL;
    root->right = NULL;
    
    int read = 6;
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
    
    if(isBalanced())
    {
        cout <<"The tree is a balanced BST"<<endl;
    }
    else
    {
        cout <<"The tree is not a balanced BST"<<endl;
    }

    return 0;
}
