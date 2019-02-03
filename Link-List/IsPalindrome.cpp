#include "ListNode.h"

using namespace std;

void reverseList(ListNode **root){
    ListNode *ptr, *prev, *temp;
    ptr = *root;
    prev = nullptr;
    while(ptr){
        temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }
    *root = prev;
}

bool checkPalindrome(ListNode *root){
    ListNode *slow, *fast;
    slow = fast = root;
    while(fast && fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = slow->next;
    reverseList(&slow);
    fast = root;
    while(slow){
        if(fast->data != slow->data){
            return false;
        }
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}

int main(){
    ListNode *head = nullptr;
    push(&head,5);
    push(&head,7);
    push(&head,9);
    push(&head,3);
    push(&head,9);
    push(&head,7);
    push(&head,5);
    cout<<"Original List..."<<endl;
    display(head);

    if(checkPalindrome(head)){
        cout<<"Is a valid palindrome"<<endl;
    }
    else{
        cout<<"Not a palindrome"<<endl;
    }
    return 0;
}