// Given a singly linked list, modify the value of first half nodes such that :

// 1st node’s new value = the last node’s value - first node’s current value
// 2nd node’s new value = the second last node’s value - 2nd node’s current value,
// and so on …

// Given linked list 1 -> 2 -> 3 -> 4 -> 5
// You should return 4 -> 2 -> 3 -> 4 -> 5

#include <iostream>

using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int data): val(data), next(nullptr){}
};

void push(ListNode** head, int val){
    ListNode *ptr = new ListNode(val);
    ptr->next = *head;
    *head = ptr;
}

void display(ListNode *head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<"\n";
}

void reverseList(ListNode **root){
    ListNode *prev, *curr, *temp;
    prev = nullptr;
    curr = *root;
    while(curr){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    *root = prev;
}

ListNode* subtract(ListNode* root){
    if(!root)
        return nullptr;
    ListNode *slow, *fast;
    slow = root;
    fast = root;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *ptr = slow->next;
    reverseList(&ptr);
    slow->next = ptr;

    slow = root;
    fast = root;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow = root;
    while(fast){
        slow->val = fast->val - slow->val;
        slow = slow->next;
        fast = fast->next;
    }
    display(root);
}

int main(){
    ListNode *head = nullptr;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    display(head);
    subtract(head);
}