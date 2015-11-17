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

struct node* reverseList_iter(struct node *head) {
	if( NULL == head && NULL == head->next ){
		return head;
	}
	node *prev, *ptr, *tmp;
	prev = NULL;
	ptr = head;
	while( NULL != ptr ){
		tmp = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = tmp;
	}
	return prev;
}

struct node* reverseList_recur(struct node *head) {
	if ( NULL == head && NULL == head->next ){
		return head;
	}

	node *second = head->next;
	head->next = NULL;

	node *rest = reverseList_recur(second);
	second->next = head;

	return rest;
}

int main () {
	node *head = NULL;
	int k = 100;
	while(k > 0) {
		push(&head,k);
		k -= 10;
	}
	cout<<"\nOriginal Link List"<<endl;
	printList(head);

	cout<<"\nLink List reversed - Iteratively"<<endl;
	node *temp = reverseList_iter(head);
	printList(temp);

	cout<<"\nLink List reversed - Recursively"<<endl;
	printList(temp);
	return 0;
}