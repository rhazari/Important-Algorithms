#include <iostream>
#include <vector>

using namespace std;

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

void quickSort(vector<int>& vec, int left, int right){
    if(left >= right)
        return;
    int pivot = left + (right-left)/2;
    int index = partition(vec, left, right, pivot);
    quickSort(vec, left, index-1);
    quickSort(vec, index+1, right);
}

int main(){
    vector<int> vec = {10, 9, 13, 5, 7, 21, 37, 23, 45, 16, 25};
    quickSort(vec, 0, vec.size()-1);

    // After Quick Sort
    for(const auto& v: vec){
        cout<<v<<" ";
    }
    cout<<"\n";
}