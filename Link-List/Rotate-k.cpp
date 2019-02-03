/* Rotate a single link list at the kth ListNode */
#include "ListNode.h"

using namespace std;

void rotateList(ListNode** head, int val){
    ListNode* ptr = (*head);
    ListNode *prev;
    while(val > 1){
        prev = ptr;
        ptr = ptr->next;
        --val;
    }
    prev->next = nullptr;
    
    ListNode* temp = ptr;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = (*head);
    (*head) = ptr;
}

int main(){
    ListNode* head = nullptr;

    int k = 10;
    while(k){
        push(&head,k);
        k--;
    }
    
    cout<<"Original Link List\n";
    display(head);

    int x = 5;
    cout<<"After rotating\n";
    rotateList(&head,x);

    display(head);
}
