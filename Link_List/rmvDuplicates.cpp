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

struct node* removeDuplicates( struct node *head ) {
   node *ptr1, *ptr2, *temp, *prev;
   ptr1 = head;
   ptr2 = NULL;
   while(ptr1->next != NULL) {
      prev = ptr1;
      ptr2 = ptr1->next;
      while( NULL != ptr2 ){
         if(ptr1->data == ptr2->data) {
            temp = ptr2;
            if( NULL == ptr2->next ){
               prev->next = NULL;
            }
            else {
               prev->next = ptr2->next;
            }
            free(temp);
         }
         else {
            prev = ptr2;
            ptr2 = ptr2->next;
         }
      }
      if(ptr1->next){
         ptr1 = ptr1->next;
      }
   }
   return head;
}

int main(){
	node *h1 = NULL;
	push(&h1,1);
	push(&h1,6);
	push(&h1,7);
	push(&h1,6);
	push(&h1,8);
	push(&h1,9);
	push(&h1,5);
	push(&h1,5);
	push(&h1,3);
	push(&h1,3);
	push(&h1,2);
	push(&h1,7);
	push(&h1,1);

	cout<<"Unsorted original Link List with duplicates"<<endl;
	printList(h1);

   node *newList = removeDuplicates(h1);
   cout<<"The link list after removing duplicates"<<endl;
   printList(newList);

	return 0;
}
