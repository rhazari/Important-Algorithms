/* Two numbers provided in two Link List 
   Add the two number */
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct node {
    int data;
    struct node *next;
}node;


void push(struct node** ptr, int val) {
    node* newptr = (node*)malloc(sizeof(node));
    newptr->data = val;
    newptr->next = (*ptr);
    (*ptr) = newptr;
}

void printList(struct node* ptr) {
    while(ptr != NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node* addNumber(struct node *h1, struct node *h2) {
    
    node *head = (node*)malloc(sizeof(node));
    node *h3 = head;
    int carry = 0;
    while( NULL != h1 || NULL != h2 ){
        if( NULL != h1 ){
            carry += h1->data;
            h1 = h1->next;
        }
        if( NULL != h2 ){
            carry += h2->data;
            h2 = h2->next;
        }
        h3->data = carry%10;
        h3->next = (node*)malloc(sizeof(node));
        h3 = h3->next;
        carry = carry/10;
    }
    if(1 == carry ){
        h3->data = 1;
    }
    printList(head);
}

int main() {
    node* h1 = NULL;
    node* h2 = NULL;

    push(&h1, 6);
    push(&h1, 4);
    push(&h1, 2);

    push(&h2, 4);
    push(&h2, 6);
    push(&h2, 5);

    
    cout<<"List 1"<<endl;
    printList(h1);

    cout<<"List 2"<<endl;
    printList(h2);

    cout<<"List 1 + List 2"<<endl;
    addNumber(h1,h2);

    return 0;    
}