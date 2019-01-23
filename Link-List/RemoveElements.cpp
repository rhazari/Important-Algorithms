// Given Link List 3->3->2->1->4>3->5->3->3
// return 2->1->4->5

#include <iostream>

using namespace std;

struct ListNode {
    int data;
    ListNode *next;
};

void push(ListNode **ptr, int val) {
    ListNode *node = new ListNode;
    node->data = val;
    node->next = (*ptr);
    (*ptr) = node;
}

void display(ListNode *ptr) {
    while(ptr){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<"\n";
}

void *removeElement(ListNode **head, int value) {
    ListNode *fake = new ListNode;
    fake->data = 0;
    fake->next = (*head);

    ListNode *ptr, *prev;
    ptr = fake;
    prev = nullptr;
    while (ptr) {
        if (value == ptr->data) {
            if(ptr->next){
                prev->next = ptr->next;
                ptr = ptr->next;
            }
            else{
                prev->next = nullptr;
                break;
            }
        }
        else {
            prev = ptr;
            ptr = ptr->next;
        }
    }
    *head = fake->next;
}

int main() {
    ListNode *h1 = new ListNode;
    h1->data = 3;
    push(&h1, 3);
    push(&h1, 5);
    push(&h1, 3);
    push(&h1, 4);
    push(&h1, 1);
    push(&h1, 2);
    push(&h1, 3);
    push(&h1, 3);

    cout << "Unsorted original Link List ..." << "\n";
    display(h1);

    cout << "\n";
    removeElement(&h1, 3);
    cout << "Link List with 3 removed" << endl;
    display(h1);
}
