#include <iostream>
#include <queue>

using namespace std;

/* Running Median from a data stream */

int main(){
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;

    int arr[] = {5,10,13,12,17,9,11,23};
    int size = sizeof(arr)/sizeof(arr[0]);

    max_heap.push(arr[0]);
    min_heap.push(arr[1]);

    int k, sz1, sz2;
    for(k = 2; k <size; ++k){
        if(arr[k] > max_heap.top()){
            min_heap.push(arr[k]);
        }
        else{
            max_heap.push(arr[k]);
        }
        sz1 = max_heap.size();
        sz2 = min_heap.size();
        if(sz1 > sz2 + 1){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(sz2 > sz1 + 1){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        if(min_heap.size() == max_heap.size()){
            cout<<(float)(min_heap.top()+max_heap.top())/2.0<<" ";
        }
        else if(min_heap.size() > max_heap.size()){
            cout<<min_heap.top()<<" ";
        }
        else{
            cout<<max_heap.top()<<" ";
        }
    }
    cout<<endl;
    return 0;
}