#include "ListNode.h"

using namespace std;

ListNode* oddEven(ListNode *head){
    ListNode *p1, *p2, *ptr;
    if(!head && !head->next){
        return head;
    }
    p1 = head; p2 = head->next;
    ptr = head->next;
    while(p1 && p2){
        ListNode *tp = p2->next;
        if(!tp){
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
    ListNode *head = nullptr;
    push(&head,18);
    push(&head,17);
    push(&head,16);
    push(&head,15);
    push(&head,14);
    push(&head,13);
    push(&head,12);
    push(&head,11);

    display(head);
    ListNode *list = oddEven(head);
    display(list);

    return 0;
}