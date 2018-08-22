#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>&  vec, int left, int mid, int right){
    int len = right-left+1;
    vector<int> temp(len);

    int leftStart, rightStart, leftEnd, rightEnd;
    leftStart = left;
    leftEnd = mid;
    rightStart = mid+1;
    rightEnd = right;
    int index = 0;

    while(leftStart <= leftEnd && rightStart <= rightEnd){
        if(vec[leftStart] <= vec[rightStart]){
            temp[index] = vec[leftStart++];
        }
        else{
            temp[index] = vec[rightStart++];
        }
        index++;
    }
    while(leftStart <= leftEnd){
        temp[index++] = vec[leftStart++];
    }
    while(rightStart <= rightEnd){
        temp[index++] = vec[rightStart++];
    }

    for(int k = 0; k < len; ++k){
        vec[left+k] = temp[k];
    }

}

void mergeSort(vector<int>& vec, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        mergeSort (vec, left, mid);
        mergeSort (vec, mid + 1, right);

        merge (vec, left, mid, right);
    }
}

int main (){
    vector<int> vec = { 23, 37, 17, 41, 33, 57, 47, 31, 1, 12, 9 };
    mergeSort (vec, 0, vec.size () - 1);

    for(const auto& v:vec){
        cout << v << " ";
    }
    cout <<"\n";
}
