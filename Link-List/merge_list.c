#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
}
node;

void push(struct node** ptr, int data)
{
    node* newptr = (node*)malloc(sizeof(node));
    newptr->value = data;
    
    newptr->next = (*ptr);
    (*ptr) = newptr;       
}

void printList(struct node* head)
{
    node* ptr = head;
    while(ptr != NULL)
    {
        printf("%d ",ptr->value);
        ptr = ptr->next;
    }
}

void merge(struct node** x, struct node** y)
{
    node* ptr = (*x);
    node* prev;
    while(ptr != NULL)
    {
        node* next = (*y)->next;
        prev = ptr;
        if(ptr->next != NULL)
        {   
            ptr = ptr->next;           
            prev->next = (*y);
            (*y)->next = ptr;
        }
        else
        {
            prev->next = (*y);
            ptr = NULL;
            (*y)->next = NULL;
        }
        (*y) = next;
    }
}

int main()
{
     node *p = NULL, *q = NULL;
     push(&p, 3);
     push(&p, 2);
     push(&p, 1);
     printf("\nFirst Linked List:\n");
     printList(p);
 
     push(&q, 8);
     push(&q, 7);
     push(&q, 6);
     push(&q, 5);
     push(&q, 4);
     printf("\nSecond Linked List:\n");
     printList(q);
 
     merge(&p, &q);
 
     printf("\nModified First Linked List:\n");
     printList(p);
 
     printf("\nModified Second Linked List:\n");
     printList(q);
     return 0;
} 
