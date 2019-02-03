/* Union and Intersection of two Link List */
#include "ListNode.h"
#include <map>

using namespace std;

ListNode* union_list(ListNode* l1, ListNode* l2){
    int key = 1;
    map<int,int> union_map;
    
    ListNode* temp = l1;
    while(temp) {
        union_map[temp->data] = key++;
        temp = temp->next;
    }

    temp = l2;
    while(temp) {
        union_map[temp->data] = key++;
        temp = temp->next;
    }

    ListNode* union_list = nullptr;
    for(auto it = union_map.rbegin(); it != union_map.rend(); ++it) {
        push(&union_list,it->first);
    }
    return union_list;
}

ListNode* intersection_list(ListNode* l1, ListNode* l2) {
    int key = 1;
    map<int,int> intersect_map;

    ListNode* temp = l1;
    while(temp) {
        intersect_map[temp->data] = key;
        temp = temp->next;
    }

    temp = l2;
    ListNode* intersect_list = nullptr;
    while(temp) {
        if(intersect_map.count(temp->data)) {
            push(&intersect_list,temp->data);
        }
        temp = temp->next;
    }
    return intersect_list;
}


int main() {
    ListNode* h1 = nullptr;
    ListNode* h2 = nullptr;

    int k = 100;
    while(k) {
        push(&h1,k);
        k -= 10;
    }

    k = 140;
    while(k > 80) {
        push(&h2,k);
        k -= 10;
    }
    
    cout<<"List 1"<<endl;
    display(h1);

    cout<<"List 2"<<endl;
    display(h2);

    cout<<"Union of List 1 & 2"<<endl;
    display(union_list(h1,h2));

    cout<<"Intersection of List 1 & 2"<<endl;
    display(intersection_list(h1,h2));
}
