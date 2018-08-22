#include <iostream>

using namespace std;

typedef struct node{
    int data;
    struct node *next;
}node;

void push(node **head, int value){
    node *p = new node;
    p->data = value;
    p->next = *head;
    *head = p;
}

void display(node *head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void reverseList(node **root){
    node *ptr, *prev, *temp;
    ptr = *root;
    prev = NULL;
    while(ptr){
        temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }
    *root = prev;
}

bool checkPalindrome(node *head){
    node *slow, *fast;
    slow = fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast){
        slow = slow->next;
    }
    reverseList(&slow);
    fast = head;
    while(slow){
        if(fast->data != slow->data){
            return false;
        }
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}

int main(){
    node *head = NULL;
    push(&head,5);
    push(&head,7);
    push(&head,9);
    push(&head,3);
    push(&head,9);
    push(&head,7);
    push(&head,5);
    cout<<"Original List..."<<endl;
    display(head);

    if(checkPalindrome(head)){
        cout<<"Is a valid palindrome"<<endl;
    }
    else{
        cout<<"Not a palindrome"<<endl;
    }

    return 0;
}