//Program to find if two nodes are cousins in a BST
#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct node
{
    int value;
    struct node *left, *right;
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

int getHeight(struct node* ptr, int val, int lev)
{
    if(ptr == NULL) return 0;
    if(ptr->value == val) return lev;
    
    int l =  getHeight(ptr->left, val, lev+1);
    if(l != 0) return l;
    
    return getHeight(ptr->right, val, lev+1);
        
}

int isSibling(int x, int y)
{
    node *prev1, *prev2;
    prev1 = root;
    prev2 = root;
    
    node* ptr = root;
    while(ptr != NULL)
    {
        if(ptr->value == x)
            break;
        else if(ptr->value > x)
        {
            prev1 = ptr;
            ptr = ptr->left;
        }
        else
        {
            prev1 = ptr;
            ptr = ptr->right;
        }      
    }
    
    ptr = root;
    while(ptr != NULL)
    {
        if(ptr->value == y)
            break;
        else if(ptr->value > y)
        {
            prev2 = ptr;
            ptr = ptr->left;
        }
        else
        {
            prev2 = ptr;
            ptr = ptr->right;
        }     
    }
    
    if(prev1 == prev2)
        return 1;
    else
        return 0;
}

int isCousin(int x, int y)
{   
    cout<< getHeight(root, x, 1)<<endl;
    cout<< getHeight(root, y, 1)<<endl;
    if((getHeight(root, x, 1) == getHeight(root, y, 1)) && !(isSibling(x,y)))
        return 1;
    else
        return 0;
}

int main()
{
    root = (node*)malloc(sizeof(node));
    root->value = 6;
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
    
    int n1, n2;
    cout <<"Enter values to check if they are cousins"<<endl;
    cin >> n1 >> n2;
    
    if(isCousin(n1,n2))
    {
        cout<<"The two values are cousins"<<endl;
    }
    else
    {
        cout <<"Not cousins" <<endl;
    }    
       
    return 0;
}
