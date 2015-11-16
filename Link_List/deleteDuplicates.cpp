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

void removeDuplicates(struct node **head) {
	node *prev, *ptr;
	prev = (*head);
	ptr = (*head)->next;
	while( NULL != ptr ){
		if( prev->data == ptr->data ){
			prev->next = ptr->next;
			ptr = ptr->next;
		}
		else {
			prev = prev->next;
			ptr = ptr->next;
		}
	}
}

struct node* uniqueElements(struct node *head) {
	node *newHead = new node;
	newHead->next = head;
	node *ptr = newHead;
	while( NULL != ptr->next && NULL != ptr->next->next ){
		if( ptr->next->data == ptr->next->next->data ) {
			int duplicate = ptr->next->data;
			while( NULL != ptr->next && duplicate == ptr->next->data ) {
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
	node *h1 = NULL;
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
	printList(h1);

	node *temp = uniqueElements(h1);
	cout<<"The unique elements of the link list"<<endl; 
	printList(temp);

	cout<<"Link List after removing duplicates"<<endl;
	removeDuplicates(&h1);
	printList(h1);
	return 0;
}