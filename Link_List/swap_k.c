/*Perform swap of kth node from beginning with kth node from the end*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}
node;

void push(struct node** ptr, int val)
{
	node* newptr = (node*)malloc(sizeof(node));
	newptr->data = val;
	newptr->next = (*ptr);
	(*ptr) = newptr;
}

void printList(struct node* ptr)
{
	while(ptr != NULL)
	{
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

void swapNodes(struct node** ptr, int val)
{
	node* mkr_a = (*ptr);
	node *prev_a, *next_a;
	int a = val-1;
	while(a)
	{
		prev_a = mkr_a;
		mkr_a = mkr_a->next;
		a--;
	}
	next_a = mkr_a->next;

	node* mkr_b = (*ptr);
	node* tmp = mkr_a;
	node *prev_b, *next_b;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
		prev_b = mkr_b;
		mkr_b = mkr_b->next;
	}
	next_b = mkr_b->next;

    //Performing the swap	
	prev_a->next = mkr_b;
	mkr_b->next = next_a;
	
	prev_b->next = mkr_a;
	mkr_a->next = next_b;
	
}

int main()
{
	node* head = NULL;

	int k = 10;
	while(k)
	{
		push(&head,k);
		k--;
	}
	
	printList(head);

	int x = 3;
	swapNodes(&head,x);

	printList(head);

	return 0;
}
