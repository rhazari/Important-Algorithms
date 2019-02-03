#include "ListNode.h"

using namespace std;

ListNode* reverseList_iter(ListNode *head) {
    if( !head && !head->next ){
        return head;
    }
    ListNode *prev, *ptr, *tmp;
    prev = nullptr;
    ptr = head;
    while( ptr ){
        tmp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = tmp;
    }
    return prev;
}

ListNode* reverseList_recur(ListNode *head) {
    if ( !head && !head->next ){
        return head;
    }

    ListNode *second = head->next;
    head->next = nullptr;

    ListNode *rest = reverseList_recur(second);
    second->next = head;

    return rest;
}

int main () {
    ListNode *head = nullptr;
    int k = 100;
    while(k > 0) {
        push(&head,k);
        k -= 10;
    }
    cout<<"\nOriginal Link List"<<"\n";
    display(head);

    cout<<"\nLink List reversed - Iteratively"<<"\n";
    ListNode *temp = reverseList_iter(head);
    display(temp);

    cout<<"\nLink List reversed - Recursively"<<"\n";
    display(temp);
}