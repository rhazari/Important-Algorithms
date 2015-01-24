#include <iostream>
#include <cstdlib>

#define MIN 0

using namespace std;

typedef struct node
{
    int data;
    struct node* next;
}
node;

typedef struct tree
{
    int data;
    struct tree* left_child;
    struct tree* right_child;
}
tree;

void push(struct node **head, int value)
{
    node *newptr = new node();
    newptr->data = value;
    newptr->next = *head;
    *head = newptr;
}

void display(struct node *head)
{
    while(head != NULL)
    {
        cout <<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

tree *create_bst(struct node *& head, int start, int end)
{
    if (start > end)
        return NULL;
        
    int mid = start + (end-start)/2;
    tree *left = create_bst(head,start,mid-1);
    tree *parent = new tree();
    parent->data = head->data;
    parent->left_child = left;
    
    head = head->next;
    parent->right_child = create_bst(head,mid+1,end);
    
    return parent;
}

int min_value = MIN;

void is_bst(struct tree* root)
{
    if(root != NULL)
    {
        is_bst(root->left_child);
        if(min_value < root->data)
        {
            min_value = root->data;
            cout<<root->data<<" ";
        }
        else
        {
            cout <<"Not a BST"<<endl;
            return;
        }
        is_bst(root->right_child);
    }
}

bool is_bst(struct tree *head, int min, int max)
{
    if(head == NULL)
        return true;
    if(min < head->data && head->data < max)
    {
        return (is_bst(head->left_child,min,head->data) && is_bst(head->right_child,head->data,max));
    }
    else
    {
        return false;
    }
}

int main()
{
    node *head = NULL;
    push(&head,13);
    push(&head,11);
    push(&head,9);
    push(&head,15);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    
    cout <<"Display of the sorted link list"<<endl;
    display(head);
    cout<<endl;
    
    tree *root = create_bst(head,0,8);
    cout<<"Check for BST"<<endl;
    is_bst(root);
    cout <<endl;
    
    if(is_bst(root,0,14))
        cout<<"Is a BST"<<endl;
    else
        cout<<"Not a BST"<<endl;
            
    return 0;
}
