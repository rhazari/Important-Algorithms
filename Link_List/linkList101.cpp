#include <iostream>

using namespace std;

typedef struct node{
	int data;
	struct node *next;
}node;

void push(node **head, int value){
	node *ptr = new node;
	ptr->data = value;
	ptr->next = *head;
	*head = ptr;
}

void display(node *ptr){
	while(ptr){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

node *revList(node *head){
	node *prev, *ptr, *temp;
	ptr = head;
	prev = NULL;
	while(ptr){
		temp = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = temp;
	}
	return prev;
}

node *delNode(node *head, int value){
	node *newHead = new node;
	newHead->next = head;
	node *ptr, *prev;
	ptr = newHead;
	while(head){
		if(head->data == value){
			ptr->next = head->next;
			head = head->next;
		}
		else{
			head = head->next;
			ptr = ptr->next;	
		}	
	}
	return newHead->next;
}

int main(){
	node *head = NULL;
	push(&head,12);
	push(&head,17);
	push(&head,9);
	push(&head,7);
	push(&head,12);
	push(&head,19);
	push(&head,21);

	//Original List
	display(head);

	//Reversed List
	node *rvList = revList(head);
	display(rvList);

	//Delete Node
	node *del = delNode(rvList,12);
	display(del);

	return 0;
}

