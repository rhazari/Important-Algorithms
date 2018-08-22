#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> mergeSortedArray(vector<vector<int> >& vec){
    priority_queue<int, vector<int>, greater<int> > min_heap;
    for(auto ii = vec.begin(); ii != vec.end(); ++ii){
        for(auto jj = (*ii).begin(); jj != (*ii).end(); ++jj){
            min_heap.push(*jj);
        }
    }
    vector<int> result;
    while(!min_heap.empty()){
        result.push_back(min_heap.top());
        min_heap.pop();
    }
    return result;
}

int main(){
    vector<int> v1, v2, v3, final;
    v1 = { 1, 3, 5, 7 };
    v2 = { 2, 4, 6, 8 };
    v3 = { 0, 9, 10, 11 };

    vector<vector<int> > vec;
    vec.push_back(v1);
    vec.push_back(v2);
    vec.push_back(v3);
    final = mergeSortedArray(vec);
    for(auto tt = final.begin(); tt != final.end(); ++tt){
        cout<<*tt<<"";
    }
    cout<<endl;

    return 0;
}