#include "ListNode.h"

using namespace std;

ListNode* removeDuplicates( ListNode *head ) {
   ListNode *ptr1, *ptr2, *temp, *prev;
   ptr1 = head;
   ptr2 = nullptr;
   while(ptr1->next) {
      prev = ptr1;
      ptr2 = ptr1->next;
      while( ptr2 ){
         if(ptr1->data == ptr2->data) {
            temp = ptr2;
            if( !ptr2->next ){
               prev->next = nullptr;
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
    ListNode *h1 = nullptr;
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

   cout<<"Unsorted original Link List with duplicates"<<"\n";
   display(h1);

   ListNode *newList = removeDuplicates(h1);
   cout<<"The link list after removing duplicates"<<"\n";
   display(newList);
}
