#include "ListNode.h"

using namespace std;

void removeDuplicates(ListNode **head) {
    ListNode *ptr;
    ptr = (*head);
    while( ptr ){
        if( ptr->next && ptr->data == ptr->next->data ){
            ListNode *q = ptr->next;
            int duplicate = ptr->data;
            while(q && duplicate == q->data){
                q = q->next;
            }
            if(nullptr == q){
                ptr->next = nullptr;
                break;
            }
            else{
                ptr->next = q;
            }
        }
        ptr = ptr->next;
    }
}

ListNode* uniqueElements(ListNode *head) {
    ListNode *newHead = new ListNode(-1);
    newHead->next = head;
    ListNode *ptr = newHead;
    while( ptr->next && ptr->next->next ){
        if( ptr->next->data == ptr->next->next->data ) {
            int duplicate = ptr->next->data;
            while( ptr->next && duplicate == ptr->next->data ) {
                ptr->next = ptr->next->next;
            }
        }
        else {
            ptr = ptr->next;
        }
    }
    return newHead->next;
}

int main(){
    ListNode *h1 = nullptr;
    push(&h1,9);
    push(&h1,9);
    push(&h1,7);
    push(&h1,6);
    push(&h1,5);
    push(&h1,5);
    push(&h1,5);
    push(&h1,4);
    push(&h1,3);
    push(&h1,3);
    push(&h1,2);
    push(&h1,1);
    push(&h1,1);

    cout<<"Original Link List"<<endl;
    display(h1);

    ListNode *temp = uniqueElements(h1);
    cout<<"The unique elements of the link list"<<endl; 
    display(temp);

    ListNode *h2 = nullptr;
    push(&h2,9);
    push(&h2,9);
    push(&h2,7);
    push(&h2,6);
    push(&h2,5);
    push(&h2,5);
    push(&h2,5);
    push(&h2,4);
    push(&h2,3);
    push(&h2,3);
    push(&h2,2);
    push(&h2,1);
    push(&h2,1);

    cout<<"Link List after removing duplicates"<<endl;
    removeDuplicates(&h2);
    display(h2);
}