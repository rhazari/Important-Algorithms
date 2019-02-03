#include "ListNode.h"

using namespace std;

ListNode* partitionList(ListNode* head, int element) {
    ListNode *h1, *h2;
    h1 = new ListNode(-1);
    h2 = new ListNode(-1);

    ListNode *ptr, *p1, *p2;
    ptr = head;
    p1 = h1;
    p2 = h2;
    while( ptr ){
        if( ptr->data < element ){
            p1->next = ptr;
            p1 = p1->next;
        }
        else {
            p2->next = ptr;
            p2 = p2->next;
        }
        ptr = ptr->next;
    }
    p1->next = h2->next;
    return h1->next;
}

int main() {
    ListNode *h1 = nullptr;
    push(&h1,10);
    push(&h1,7);
    push(&h1,5);
    push(&h1,8);
    push(&h1,4);
    push(&h1,3);
    push(&h1,5);
    push(&h1,1);
    push(&h1,6);
    push(&h1,2);

    cout<<"The original Link List"<<endl;
    display(h1);

    int partitionElement;
    cout<<"Enter the value to partition about"<<endl;
    cin >> partitionElement;
    cout<<"List partitioned about element "<<partitionElement<<endl;
    ListNode *temp = partitionList(h1,partitionElement);
    display(temp);

    return 0;
}