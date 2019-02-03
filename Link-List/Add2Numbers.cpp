/* Two numbers provided in two Link List 
   Add the two number */
#include "ListNode.h"
using namespace std;

ListNode* addNumber(ListNode *h1, ListNode *h2) {
    ListNode *fake = new ListNode(-1);
    ListNode *ptr = fake;
    int carry, sum;
    sum = carry = 0;
    while( h1 || h2 ){
        sum = carry;
        if( h1 ){
            sum += h1->data;
            h1 = h1->next;
        }
        if( h2 ){
            sum += h2->data;
            h2 = h2->next;
        }
        ListNode *node = new ListNode(sum%10);
        carry = sum/10;
        ptr->next = node;
        ptr = ptr->next;
    }
    if(1 == carry ){
        ListNode *node = new ListNode(1);
        ptr->next = node;
    }
    return fake->next;
}

int main() {
    ListNode* h1 = nullptr;
    ListNode* h2 = nullptr;

    push(&h1, 6);
    push(&h1, 4);
    push(&h1, 2);

    push(&h2, 4);
    push(&h2, 6);
    push(&h2, 5);

    cout<<"List 1"<<endl;
    display(h1);

    cout<<"List 2"<<endl;
    display(h2);

    cout<<"List 1 + List 2"<<endl;
    display(addNumber(h1,h2));
}