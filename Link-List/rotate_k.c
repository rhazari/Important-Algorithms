/* Rotate a single link list at the kth node */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}
node;

void push(struct node** ptr, int val)
{
    node* newptr = (node*)malloc(sizeof(node));
    newptr->data = val;
    newptr->next = (*ptr);
    (*ptr) = newptr;
}

void printList(struct node* ptr)
{
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void rotateList(struct node** ptr, int val)
{
    int a = val-1;
    node* mkr_a = (*ptr);
    node *prev;
    while(a)
    {
        prev = mkr_a;
        mkr_a = mkr_a->next;
        a--;
    }
    prev->next = NULL;
    
    node* temp = mkr_a;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = (*ptr);
    
    (*ptr) = mkr_a;
}

int main()
{
    node* head = NULL;

    int k = 10;
    while(k)
    {
        push(&head,k);
        k--;
    }
    
    printList(head);

    int x = 5;
    rotateList(&head,x);

    printList(head);

    return 0;
}
