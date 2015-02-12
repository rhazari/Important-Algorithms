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

void level_order_zigzag(struct tree *head)
{
    stack<tree *> current_level, next_level;
    current_level.push(head);
    bool left_to_right = true;
    tree *curr;
    while(!current_level.empty())
    {
        curr = current_level.top();
        current_level.pop();
        if(curr)
        {
            cout << curr->data<<" ";
            if(left_to_right)
            {
                next_level.push(curr->left_child);
                next_level.push(curr->right_child);
            }
            else
            {
                next_level.push(curr->right_child);
                next_level.push(curr->left_child);
            }   
        }
        if(current_level.empty())
        {
            cout <<endl;
            left_to_right = !left_to_right;
            swap(current_level,next_level);
        }
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
    
    cout<<"Print the binary tree in Zig Zag"<<endl;
    level_order_zigzag(root);        
    return 0;
}
