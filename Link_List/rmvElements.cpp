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

struct node* removeElement(struct node *head, int value){
   node *newHead = new node;
   node *prev, *ptr, *temp;
   newHead->next = head;
   ptr = head;
   prev = newHead;
   while(NULL != ptr){
      if( value == ptr->data ){
         prev->next = ptr->next;
         temp = ptr;
         ptr = ptr->next;
         free(temp);      
      }
      else {
         prev = ptr;
         ptr = ptr->next;
      }
   }
   return newHead->next;
}

int main(){
	node *h1 = NULL;
	push(&h1,7);
	push(&h1,6);
	push(&h1,7);
	push(&h1,6);
	push(&h1,8);
	push(&h1,9);
	push(&h1,2);
	push(&h1,7);
	push(&h1,7);

	cout<<"Unsorted original Link List ..."<<endl;
	printList(h1);

   cout<<endl;
   node *newList = removeElement(h1,7);
   cout<<"Link List with 7 removed"<<endl;
   printList(newList);
	return 0;
}
