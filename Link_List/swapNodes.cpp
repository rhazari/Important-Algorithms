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

struct node* swapNodes(struct node *head) {
	if( NULL == head && NULL == head->next ){
		return head;
	}
	struct node *newHead = new node;
	newHead->next = head;
	node *ptr = newHead;
	node *p1, *p2, *tmp;
	tmp = head;
	while( NULL != head->next && NULL != head->next->next){
		p1 = head;
		p2 = head->next;
		tmp = head->next->next;

		ptr->next = p2;
		ptr = ptr->next;
		ptr->next = p1;
		ptr = ptr->next;

		head = tmp;
	}
	if( NULL == head->next ){
		ptr->next = head;
	}
	else if (NULL == head->next->next ){
		ptr->next = head->next;
		ptr = ptr->next;
		ptr->next = head;
		ptr->next->next = NULL;
	}
	return newHead->next;
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