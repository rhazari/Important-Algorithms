
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct node {
	int data;
	struct node *next;
}node;


void push(struct node** ptr, int val) {
	node* newptr = (node*)malloc(sizeof(node));
	newptr->data = val;
	newptr->next = (*ptr);
	(*ptr) = newptr;
}

void printList(struct node* ptr) {
	while(ptr != NULL) {
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

void reverseList(struct node **head) {
	if( NULL == *head || NULL == (*head)->next ){
		return;
	}
	node *prev, *curr, *next;
	prev = NULL;
	curr = (*head);
	while(curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	(*head) = prev;
}

struct node* reOrderList(struct node *head) {
	node *fast, *slow;
	slow = head;
	fast = head;
	while( NULL != fast && NULL != fast->next && NULL != fast->next->next ){
		fast = fast->next->next;
		slow = slow->next;
	}
	node *head2 = slow->next;
	slow->next = NULL;

	reverseList(&head2);
	node *h1 = head;
	while( NULL != head && NULL != head2 ){
		slow = head->next;
		fast = head2->next;
		
		head->next = head2;
		head2->next = slow;

		head = slow;
		head2 = fast;
	}
	return h1;
}

int main(){
	node* h1 = NULL;
	int k = 10;
	while(k <= 100) {
		push(&h1,k);
		k += 10;
	}
	cout<<"Original List"<<endl;
	printList(h1);

	cout<<"Re-Ordered List"<<endl;
	printList(reOrderList(h1));
	return 0;
}