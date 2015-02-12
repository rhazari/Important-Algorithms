#include <iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}
node;

void push(struct node **head, int value)
{
    node *newptr = new node();
    newptr->data = value;
    
    newptr->next = *head;
    *head = newptr;
}

void display(struct node *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void reverse(struct node **head)
{
    node *prev, *ptr, *next_ptr;
    prev = NULL;
    ptr = *head;
    next_ptr = ptr;
    while(next_ptr)
    {
        next_ptr = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next_ptr;
    }
    *head = prev;
}

void reverse_recursion(struct node **head)
{
    node *first, *rest;
    first = *head;
    rest = (*head)->next;
    
    if(rest == NULL)
        return;
    reverse_recursion(&rest);
    first->next->next = first;
    first->next = NULL;
    
    *head = rest;
}

int main()
{
    node *head = NULL;
    push(&head,10);
    push(&head,14);
    push(&head,21);
    //push(&head,25);
    //push(&head,33);
    //push(&head,41);
    //push(&head,47);
    
    display(head);
    cout<<"Reversing the link list"<<endl;
    reverse(&head);
    display(head);
    
    cout<<"Again Reversing the link list"<<endl;
    reverse_recursion(&head);
    display(head);
    
    return 0;    
}
