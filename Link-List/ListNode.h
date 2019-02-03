#pragma once

#include <iostream>

class ListNode {
public:
    int data;
    ListNode *next;
    ListNode(int val): data(val), next(nullptr){}
};

void push(ListNode** root, int val) {
    ListNode* ptr = new ListNode(val);
    ptr->next = (*root);
    (*root) = ptr;
}

void display(ListNode* ptr) {
    while(ptr) {
        std::cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    std::cout<<"\n";
}