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

struct node* partitionList(struct node* head, int element) {
	node *h1, *h2;
	h1 = new node;
	h2 = new node;

	node *ptr, *p1, *p2;
	ptr = head;
	p1 = h1;
	p2 = h2;
	while( NULL != ptr ){
		if( ptr->data < element ){
			p1->next = ptr;
			p1 = p1->next;			
		}
		else {
			p2->next = ptr;
			p2 = p2->next;
		}
		ptr = ptr->next;
	}
	p1->next = h2->next;
	return h1->next;
}

int main() {
	node *h1 = NULL;
	push(&h1,10);
	push(&h1,7);
	push(&h1,5);
	push(&h1,8);
	push(&h1,4);
	push(&h1,3);
	push(&h1,5);
	push(&h1,1);
	push(&h1,6);
	push(&h1,2);

	cout<<"The original Link List"<<endl;
	printList(h1);

	int partitionElement;
	cout<<"Enter the value to partition about"<<endl;
	cin >> partitionElement;
	cout<<"List partitioned about element "<<partitionElement<<endl;
	node *temp = partitionList(h1,partitionElement);
	printList(temp);

	return 0;
}