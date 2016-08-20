#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct node {
	int data;
	struct node *next;
}node;


void push(struct node** ptr, int val) {
	node* newptr = new node;
	newptr->data = val;
	newptr->next = (*ptr);
	(*ptr) = newptr;
}

void printList(struct node* ptr) {
	while(ptr) {
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

node *swapNodes(node *head){
	node *fakeHead = new node;
	fakeHead->next = head;
	node *ptr = fakeHead;
	while(ptr->next != NULL && ptr->next->next != NULL){
		node *p1 = ptr->next;
		node *p2 = ptr->next->next;

		//Assignments
		ptr->next = p2;
		p1->next = p2->next;
		p2->next = p1;

		//Move to next pair
		ptr = p1;
	}
	return fakeHead->next;
}

int main () {
	node *head = NULL;
	int k = 100;
	while(k > 10) {
		push(&head,k);
		k -= 10;
	}
	cout<<"\nOriginal Link List"<<endl;
	printList(head);

	cout<<"\nLink List after swapping nodes"<<endl;
	node *temp = swapNodes(head);
	printList(temp);
	return 0;
}