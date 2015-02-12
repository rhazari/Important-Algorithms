#include <iostream>
#include <cstdlib>
#include <stack>

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

void in_order_traversal(struct tree *head)
{
    int max_depth = 0;
    stack<tree*> t1;
    tree *current = head;
    int read = 1;
    while(read)
    {
        if(current)
        {
            t1.push(current);
            current = current->left_child;
        }
        else
        {
            if(t1.empty())
            {
                read = 0;
            }
            else
            {
                current = t1.top();
                t1.pop();
                cout<<current->data<<" ";
                current = current->right_child;
            }
        }
    }
    cout<<endl;   
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
    
    cout <<"The sorted link list"<<endl;
    display(head);
    cout<<endl;
    
    tree *root = create_bst(head,0,8);
    
    cout<<"In order display of the BST"<<endl;
    in_order_traversal(root);
    cout<<endl;
    
    return 0;
}
