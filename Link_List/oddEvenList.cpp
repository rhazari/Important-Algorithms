#include <iostream>

using namespace std;

typedef struct node {
    int data;
    struct node *next;
}node;

void push(struct node **ptr, int val) {
    node* newptr = new node;
    newptr->data = val;
    newptr->next = (*ptr);
    (*ptr) = newptr;
}

void display(struct node* ptr) {
    while(ptr != NULL) {
        cout<<ptr->data<<"";
        ptr = ptr->next;
    }
    cout<<endl;
}

node* oddEven(struct node *head){
    node *p1, *p2, *ptr;
    if(NULL == head && NULL == head->next){
        return head;
    }
    p1 = head; p2 = head->next;
    ptr = head->next;
    while(NULL != p1 && p2 != NULL){
        node *tp = p2->next;
        if(NULL == tp){
            break;
        }
        p1->next = p2->next;
        p1 = p1->next;

        p2->next = p1->next;
        p2 = p2->next;
    }
    p1->next = ptr;
    return head;
}

int main(){
    node *head = NULL;
    push(&head,18);
    push(&head,17);
    push(&head,16);
    push(&head,15);
    push(&head,14);
    push(&head,13);
    push(&head,12);
    push(&head,11);

    display(head);
    node *list = oddEven(head);
    display(list);

    return 0;
}