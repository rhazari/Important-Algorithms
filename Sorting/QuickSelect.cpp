#include <iostream>
#include <vector>

using namespace std;

// Find the kth smallest element in an unsorted array in O(n) (best case)

int partition(vector<int>& vec, int left, int right, int pivot){
    while(left <= right){
        while(vec[left] < vec[pivot]){
            ++left;
        }

        while(vec[pivot] < vec[right]){
            --right;
        }

        if(left <= right){
            swap(vec[left], vec[right]);
            ++left;
            --right;
        }
    }
    return left;
}

int quickSelect(vector<int>& vec, int left, int right, int K){
    if(left == right)
        return vec[left];
    int pivot = left + (right-left)/2;
    pivot = partition(vec, left, right, pivot);
    if(K == pivot){
        return vec[K];
    }
    if(K < pivot)
        return quickSelect(vec, left, pivot-1, K);
    else
        return quickSelect(vec, pivot+1, right, K);
}

int main(){
    vector<int> vec = {10, 9, 13, 5, 7, 21, 37, 23, 45, 16, 25};
    int K = 4;
    cout<<K<<" smallest element: "<<quickSelect(vec, 0, vec.size()-1, K-1)<<"\n";
}