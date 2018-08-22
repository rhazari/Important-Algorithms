#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Kth largest number in an un-sorted array
// Time complexity O(Nlog(K))
int main(){
    vector<int> vec = {12, 9, 5, 11, 21, 27, 17, 7};

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> pq;

    int K = 3;
    for(auto& v: vec){
        pq.push(v);
        if(pq.size() > K){
            pq.pop();
        }
    }

    cout<<K<<" largest element in the un-sorted array: "<<pq.top()<<"\n";
}