#include <iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node* next;
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
    while(head != NULL)
    {
        cout <<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void split_link_list(struct node *head, struct node **front, struct node **back)
{
    node *fast, *slow, *front_end;
    fast = slow = head;
    while(fast)
    {
        front_end = slow;
        slow = slow->next;
        fast = (fast->next)? fast->next->next: NULL;
    }
    
    *back = slow;
    front_end->next = NULL;
    *front = head;
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
    
    cout <<"The link list"<<endl;
    display(head);
    
    node *front, *back;
    split_link_list(head, &front, &back);
    cout<<"The front list"<<endl;
    display(front);
    
    cout<<"The back list"<<endl;
    display(back);
    return 0;
}
