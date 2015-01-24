#include <iostream>
#include <cstdlib>
#include <queue>
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

void inorder(struct tree* root)
{
    if(root != NULL)
    {
        inorder(root->left_child);
        cout <<root->data<<" ";
        inorder(root->right_child);
    }
}

void print_level_order(struct tree *head)
{
    if(head == NULL)
        return;
    queue <tree* > q1;
    int current_level = 1;
    int next_level = 0;
    
    q1.push(head);
    while(!q1.empty())
    {
        tree *ptr = q1.front();
        q1.pop();
        current_level--;
        if(ptr)
        {
            cout<<ptr->data<<" ";
            q1.push(ptr->left_child);
            q1.push(ptr->right_child);
            next_level += 2;
        }
        if(current_level == 0)
        {
            current_level = next_level;
            next_level = 0;
            cout<<endl;
        }
    }
}

void print_level_order(struct tree* head, int level)
{
    if(head == NULL)
        return;   
    if(level == 1)
        cout<<head->data<<" ";
    else
    {
        print_level_order(head->left_child,level-1);
        print_level_order(head->right_child,level-1);
    }
}

int tree_height(struct tree *head)
{
    if(head == NULL)
        return 0;
    int left_height, right_height;
    left_height = tree_height(head->left_child);
    right_height = tree_height(head->right_child);
    
    return 1+max(left_height,right_height);
}

int find_level(struct tree *head, int value, int level)
{
    if(head == NULL)
        return 0;
    if(head->data == value)
        return level;
    
    int l = find_level(head->left_child,value,level+1);
    if (l != 0) return l;
    return find_level(head->right_child,value,level+1);
}

int main()
{
    node *head = NULL;
    push(&head,13);
    push(&head,11);
    push(&head,9);
    push(&head,7);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    
    cout <<"Display of the sorted link list"<<endl;
    display(head);
    cout<<endl;
    
    tree *root = create_bst(head,0,8);
    cout<<"In-order display of BST"<<endl;
    inorder(root);
    cout <<endl;
    
    cout<<"Level-order display of BST - BFS"<<endl;
    print_level_order(root);
    
    cout<<"Level-order display of BST - DFS"<<endl;
    int height, k; 
    height = tree_height(root);
    for( k = 1; k <= height; k++)
    {
        print_level_order(root,k);    
    }
    cout<<endl;
    
    cout<<"Find level of a tree node"<<endl;
    cout<<find_level(root,11,0)<<endl;
        
    return 0;
}
