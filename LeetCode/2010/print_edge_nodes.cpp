#include <iostream>
#include <cstdlib>
#include <stack>
#include <algorithm>

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

void print_left_edges(struct tree *root, bool print)
{
    if(root == NULL)
        return;
    if(print || (root->left_child == NULL && root->right_child == NULL))
        cout<<root->data<<" ";
    print_left_edges(root->left_child,print);
    print_left_edges(root->right_child,false);
}

void print_right_edges(struct tree *root, bool print)
{
    if(root == NULL)
        return;
    print_right_edges(root->left_child,false);
    print_right_edges(root->right_child,print);
    if(print || (root->left_child == NULL && root->right_child == NULL))
        cout<<root->data<<" ";
}

void print_edges(struct tree *head)
{
    if(head == NULL)
        return;
    cout<<head->data<<endl;
    print_left_edges(head->left_child,true);
    print_right_edges(head->right_child,true);
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
    cout<<"Display of the edge nodes of tree"<<endl;
    print_edges(root);
    
    return 0;
}
