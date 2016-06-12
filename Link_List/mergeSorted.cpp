#include <iostream>

using namespace std;

typedef struct node {
	int data;
	struct node *next;
}node;

void push(struct node **ptr, int val) {
	node* newptr = new node;
	newptr->data = val;
	newptr->next = (*ptr);
	(*ptr) = newptr;
}

void display(struct node* ptr) {
	while(ptr != NULL) {
		cout<<ptr->data<<"\t";
		ptr = ptr->next;
	}
	cout<<endl;
}

node* mergeSortedList(node *l1, node *l2){
	node *head, *ptr;
	head = new node;
	ptr = head;

	while(NULL != l1 && NULL != l2){
		if(l1->data < l2->data){
			ptr->next = l1;
			l1 = l1->next;
		}
		else{
			ptr->next = l2;
			l2 = l2->next;
		}
		ptr = ptr->next;
	}
	if(NULL == l1){
		ptr->next = l2;
	}
	else{
		ptr->next = l1;
	}
	return head->next;
}

int main(){

	node *h1 = NULL, *h2 = NULL;
	push(&h1,8);
	push(&h1,6);
	push(&h1,3);
	push(&h1,1);
	cout<<"List 1 ..."<<endl;
	display(h1);

	push(&h2,9);
	push(&h2,7);
	push(&h2,5);
	push(&h2,2);
	cout<<"List 2 ..."<<endl;
	display(h2);

	node *list = mergeSortedList(h1, h2);
	cout<<"Sorted merged list ..."<<endl;
	display(list);

	return 0;
}