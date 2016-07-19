//Program to find the in-order successor and predecessor 
//of a node with a given value
#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct node{
    int value;
    struct node* left;
    struct node* right;
}node;

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

void predecessor(struct node* ptr, struct node** pred, int val)
{
	(*pred) = ptr;
	if(ptr->value == val)
	{
		if(ptr->left != NULL)
		{
			ptr = ptr->left;
			while(ptr->right)
			{
				ptr = ptr->right;
			}
			(*pred) = ptr;
		}
	}
	else if(ptr->value > val)
	{
		if(ptr->left != NULL)
		{
			predecessor(ptr->left, pred, val);
		}
	}
	else if(ptr->value < val)
	{
		if(ptr->right != NULL && ptr->right->value < val)
		{
			predecessor(ptr->right, pred, val);	
		}
	}	
}

void successor(struct node* ptr, struct node** pred, int val)
{
	(*pred) = ptr;
	if(ptr->value == val)
	{
		if(ptr->right != NULL)
		{
			ptr = ptr->right;
			while(ptr->left)
			{
				ptr = ptr->left;
			}
			(*pred) = ptr;
		}
	}
	else if(ptr->value > val)
	{
		if(ptr->left != NULL && ptr->left->value > val)
		{
			successor(ptr->left, pred, val);
		}
	}
	else if(ptr->value < val)
	{
		if(ptr->right != NULL)
		{
			successor(ptr->right, pred, val);	
		}
	}	
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

	 node* pred = NULL;
	 node* succ = NULL;	
	 int num;	
	 cout<<"Enter a value whose predecessor & successor needs to be found"<<endl;
	 cin >> num;		
	 predecessor(root, &pred, num);
	 successor(root, &succ, num);
	
	 cout<<"Predecessor of "<<num<<": "<<pred->value<<endl;
	 cout<<"Successor of "<<num<<": "<<succ->value<<endl;

    return 0;
}
