#include <iostream>

using namespace std;

template <typename T>
class LinkList{
public:
    T m_data;
    LinkList *next;
    LinkList(T data): m_data(data), next(nullptr){}
};

template <typename T>
void insertFront(LinkList<T> **list, T data){
    LinkList<T> *node = new LinkList<T>(data);
    node->next = *list;
    *list = node;
}

template <typename T>
void insertBack(LinkList<T> **list, T data){
    LinkList<T> *node = new LinkList<T>(data);
    auto* ptr = *list;
    while(ptr->next){
        ptr = ptr->next;
    }
    ptr->next = node;
}

template <typename T>
void display(LinkList<T> *list){
    while(list){
        cout<<list->m_data<<"\t";
        list = list->next;
    }
    cout<<"\n";
}

int main(){
    LinkList<int> *list1 = new LinkList<int>(10);
    insertFront(&list1, 5);
    insertFront(&list1, 3);
    insertFront(&list1, 7);
    insertBack(&list1, 9);
    insertBack(&list1, 13);

    display(list1);

    LinkList<double> *list2 = new LinkList<double>(10.2);
    insertFront(&list2, 2.5);
    insertFront(&list2, 3.4);
    insertFront(&list2, 4.7);
    insertBack(&list2, 9.7);
    insertBack(&list2, 11.4);

    display(list2);
}