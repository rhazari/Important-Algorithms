// 624 Maximum Distance in Arrays
// Given m arrays, and each array is sorted in ascending order. 
// Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance.
// We define the distance between two integers a and b to be their absolute difference |a-b|. Your task is to find the maximum distance.

// Example 1:

// Input: 
// [[1,2,3],
//  [4,5],
//  [1,2,3]]
// Output: 4
// Explanation: 
// One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxDistance(vector<vector<int>>& arrays) {
    int result = 0;
    int start = arrays[0][0], stop = arrays[0].back();
    for(int k = 1; k < arrays.size(); ++k){
        result = max(result, max(abs(arrays[k].back() - start), abs(stop - arrays[k][0])));
        start = min(start, arrays[k][0]);
        stop = max(stop, arrays[k].back());
    }
    return result;
}

int main(){
    vector<vector<int>> vec = {{1, 2, 3}, {4, 5}, {1, 2, 3}};
    cout<<maxDistance(vec)<<"\n";
}