#include "ListNode.h"

using namespace std;

ListNode* pairWiseSwap(ListNode* head){
    ListNode *fake = new ListNode(-1);
    fake->next = head;

    ListNode *ptr = fake;
    ListNode *curr = head;
    while(curr->next){
        ptr->next = curr->next;
        ListNode *t = curr->next->next;
        if(!t)
            break;
        curr->next->next = curr;
        curr->next = t;
        ptr = curr;
        curr = t;
    }
    return fake->next;
}

int main()
{
    ListNode *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    cout<<"\nLinked list before calling  pairWiseSwap()"<<"\n";
    display(start);
 
    auto* list = pairWiseSwap(start);

    /* Result after PairWise Swap 
    2->1->4->3->6->5->7 */
    cout<<"\nLinked list after calling  pairWiseSwap()"<< "\n";
    display(list);
    return 0;
}
