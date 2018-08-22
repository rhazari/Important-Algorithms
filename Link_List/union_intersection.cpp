/* Union and Intersection of two Link List */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;


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

struct node* union_list(struct node* l1, struct node* l2)
{
    int key = 1;
    map<int,int> union_map;
    
    node* temp = l1;
    while(temp != NULL)
    {
        union_map[temp->data] = key++;
        temp = temp->next;
    }

    temp = l2;
    while(temp != NULL)
    {
        union_map[temp->data] = key++;
        temp = temp->next;
    }

    node* union_list = NULL;
    for(map<int,int>::reverse_iterator it = union_map.rbegin(); it != union_map.rend(); ++it)
    {
        push(&union_list,it->first);
    }
    return union_list;
}

struct node* intersection_list(struct node* l1, struct node* l2)
{
    int key = 1;
    map<int,int> intersect_map;

    node* temp = l1;
    while(temp != NULL)
    {
        intersect_map[temp->data] = key;
        temp = temp->next;
    }

    temp = l2;
    node* intersect_list = NULL;
    while(temp != NULL)
    {
        if(intersect_map.find(temp->data)->second == 1)
        {
            push(&intersect_list,temp->data);
        }
        temp = temp->next;
    }

    return intersect_list;
}


int main()
{
    node* h1 = NULL;
    node* h2 = NULL;

    int k = 100;
    while(k)
    {
        push(&h1,k);
        k -= 10;
    }

    k = 140;
    while(k > 80)
    {
        push(&h2,k);
        k -= 10;
    }
    
    cout<<"List 1"<<endl;
    printList(h1);

    cout<<"List 2"<<endl;
    printList(h2);

    cout<<"Union of List 1 & 2"<<endl;
    printList(union_list(h1,h2));

    cout<<"Intersection of List 1 & 2"<<endl;
    printList(intersection_list(h1,h2));

    return 0;    
}
