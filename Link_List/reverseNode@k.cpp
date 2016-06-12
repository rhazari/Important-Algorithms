#include <iostream>

using namespace std;

typedef struct node {
	int data;
	struct node *next;
}node;

void push(node **ptr, int val) {
	node* newptr = new node;
	newptr->data = val;
	newptr->next = (*ptr);
	(*ptr) = newptr;
}

void display(node* ptr) {
	while(ptr != NULL) {
		cout<<ptr->data<<"\t";
		ptr = ptr->next;
	}
	cout<<endl;
}

node* reverse(node* pre, node* last){
	node *prev, *curr;
	prev = pre->next;
	curr = prev->next;
	while(curr != last){
		prev->next = curr->next;
		curr->next = pre->next;
		pre->next = curr;
		curr = prev->next;
	}
	return prev;
}

node* reverseKNode(node *head, int k){
	if(NULL == head || 1 == k){
		return head;
	}

	node *fakeHead = new node;
	fakeHead->next = head;
	node *pre = fakeHead;
	int i = 0;
	node *ptr = head;
	while(NULL != ptr){
		++i;
		if(0 == i%k){
			pre = reverse(pre,ptr->next);
			ptr = pre->next;
		}
		else{
			ptr = ptr->next;
		}
	}
	return fakeHead->next;
}

int main(){
	node *head = NULL;
	push(&head,7);
	push(&head,6);
	push(&head,5);	
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	cout<<"Original List ..."<<endl;
	display(head);

	node *list = reverseKNode(head,3);
	cout<<"Modified List ..."<<endl;
	display(list);


	return 0;
}