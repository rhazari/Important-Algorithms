#include "ListNode.h"

using namespace std;

ListNode* mergeSortedList(ListNode *l1, ListNode *l2){
    ListNode *head, *ptr;
    head = new ListNode(-1);
    ptr = head;

    while(l1 && l2){
        if(l1->data < l2->data){
            ptr->next = l1;
            l1 = l1->next;
        }
        else{
            ptr->next = l2;
            l2 = l2->next;
        }
        ptr = ptr->next;
    }
    if(l1){
        ptr->next = l2;
    }
    else{
        ptr->next = l1;
    }
    return head->next;
}

int main(){

    ListNode *h1 = NULL, *h2 = NULL;
    push(&h1,8);
    push(&h1,6);
    push(&h1,3);
    push(&h1,1);
    cout<<"List 1 ..."<<endl;
    display(h1);

    push(&h2,9);
    push(&h2,7);
    push(&h2,5);
    push(&h2,2);
    cout<<"List 2 ..."<<endl;
    display(h2);

    ListNode *list = mergeSortedList(h1, h2);
    cout<<"Sorted merged list ..."<<endl;
    display(list);

    return 0;
}