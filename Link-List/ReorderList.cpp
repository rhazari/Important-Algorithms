#include "ListNode.h"

using namespace std;

void reverseList(ListNode **head) {
    if( !(*head) || !(*head)->next ){
        return;
    }
    ListNode *prev, *curr, *next;
    prev = nullptr;
    curr = (*head);
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    (*head) = prev;
}

ListNode* reOrderList(ListNode *head) {
    ListNode *fast, *slow;
    slow = head;
    fast = head;
    while( fast && fast->next && fast->next->next ){
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *head2 = slow->next;
    slow->next = nullptr;

    reverseList(&head2);
    ListNode *h1 = head;
    while( head &&  head2 ){
        slow = head->next;
        fast = head2->next;
        
        head->next = head2;
        head2->next = slow;

        head = slow;
        head2 = fast;
    }
    return h1;
}

int main(){
    ListNode* h1 = nullptr;
    int k = 10;
    while(k <= 90) {
        push(&h1,k);
        k += 10;
    }
    cout<<"Original List"<<endl;
    display(h1);

    cout<<"Re-Ordered List"<<endl;
    display(reOrderList(h1));
    return 0;
}