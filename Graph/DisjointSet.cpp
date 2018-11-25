#include <iostream>
#include <unordered_map>

using namespace std;

class Node{
public:
    int data;
    Node *parent;
    int rank;
    Node(){
        parent = this;
        data = 0;
        rank = 0;
    }
};

unordered_map<int, Node*> mp;

void makeSet(int data){
    Node* node = new Node();
    node->data = data;
    node->rank = 0;
    mp[data] = node;
}

int findSet(int data){
    return mp[data]->parent->data;
}

Node* findSet(Node* node){
    Node *parent = node->parent;
    if(parent == node)
        return parent;
    node->parent = findSet(node->parent);
    return node->parent;
}

bool Union(int data1, int data2){
    Node *node1 = mp[data1];
    Node* node2 = mp[data2];

    Node* parent1 = findSet(node1);
    Node* parent2 = findSet(node2);

    if(parent1->data == parent2->data)
        return false;
    
    if(parent1->rank >= parent2->rank){
        parent1->rank = (parent1->rank == parent2->rank) ? parent1->rank+1: parent1->rank;
        parent2->parent = parent1;
    }
    else{
        parent1->parent = parent2;
    }
    return true;
}

int main(){

    makeSet(1);
    makeSet(2);
    makeSet(3);
    makeSet(4);
    makeSet(5);
    makeSet(6);
    makeSet(7);

    Union(1, 2);
    Union(2, 3);
    Union(4, 5);
    Union(6, 7);
    Union(5, 6);
    Union(3, 7);

    cout<<findSet(1)<<"\n";
    cout<<findSet(2)<<"\n";
    cout<<findSet(3)<<"\n";
    cout<<findSet(4)<<"\n";
    cout<<findSet(5)<<"\n";
    cout<<findSet(6)<<"\n";
    cout<<findSet(7)<<"\n";
}