#include "ListNode.h"

using namespace std;

ListNode* reverse(ListNode* pre, ListNode* last){
    ListNode *prev, *curr;
    prev = pre->next;
    curr = prev->next;
    while(curr){
        prev->next = curr->next;
        curr->next = pre->next;
        pre->next = curr;
        curr = prev->next;
    }
    return prev;
}

ListNode* reverseKListNode(ListNode *head, int k){
    if(!head || 1 == k){
        return head;
    }

    ListNode *fakeHead = new ListNode(-1);
    fakeHead->next = head;
    ListNode *pre = fakeHead;
    int i = 0;
    ListNode *ptr = head;
    while(ptr){
        ++i;
        if(0 == i%k){
            pre = reverse(pre, ptr->next);
            ptr = pre->next;
        }
        else{
            ptr = ptr->next;
        }
    }
    return fakeHead->next;
}

int main(){
    ListNode *head = nullptr;
    push(&head,7);
    push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    cout<<"Original List ...\n";
    display(head);

    ListNode *list = reverseKListNode(head,3);
    cout<<"Modified List ...\n";
    display(list);
}