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

void printList(struct node* ptr)
{
    while(ptr != NULL)
    {
        printf("%d ",ptr->value);
        ptr = ptr->next;
    }
} 

void pairWiseSwap(struct node** ptr)
{
    node* prev = (*ptr);
    node* cur = (*ptr)->next;
    
    (*ptr) = cur;
    
    while(1)
    {
        node* p = cur->next;
        //node* p = prev->next;
        if (p != NULL && p->next != NULL)
        {
            cur->next = prev;
            prev->next = p->next;
            
            prev = p;
            cur = p->next;
        }
        else
        {
            cur->next = prev;
            prev->next = p;
            break;
        }
    }
}

int main()
{
    node *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    printf("\n Linked list before calling  pairWiseSwap() \n");
    printList(start);
 
    pairWiseSwap(&start);
 
    printf("\n Linked list after calling  pairWiseSwap() \n");
    printList(start);
    return 0;
}
