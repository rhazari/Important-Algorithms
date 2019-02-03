#include "ListNode.h"

using namespace std;

ListNode *revList(ListNode *head){
    ListNode *prev, *ptr, *temp;
    ptr = head;
    prev = NULL;
    while(ptr){
        temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }
    return prev;
}

ListNode *delListNode(ListNode *head, int value){
    ListNode *newHead = new ListNode(-1);
    newHead->next = head;
    ListNode *ptr, *prev;
    ptr = newHead;
    while(head){
        if(head->data == value){
            ptr->next = head->next;
            head = head->next;
        }
        else{
            head = head->next;
            ptr = ptr->next;
        }    
    }
    return newHead->next;
}

int main(){
    ListNode *head = NULL;
    push(&head,12);
    push(&head,17);
    push(&head,9);
    push(&head,7);
    push(&head,12);
    push(&head,19);
    push(&head,21);

    cout<<"Original List"<<"\n";
    display(head);

    cout<<"Reversed List"<<"\n";
    ListNode *rvList = revList(head);
    display(rvList);

    cout<<"Delete Node of value from List"<<"\n";
    ListNode *del = delListNode(rvList,12);
    display(del);

    return 0;
}

