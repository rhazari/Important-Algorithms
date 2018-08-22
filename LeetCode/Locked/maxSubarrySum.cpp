//Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

//Example 1:
//Given nums = [1, -1, 5, -2, 3], k = 3,
//return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxSubarrayLen(vector<int>& vec, int k){
    unordered_map<int, int> myMap;
    int sum = 0;
    int len = 0;
    for(int j = 0, z = vec.size(); j < z; ++j){
        sum += vec[j];
        if(sum == k)
            len = k+1;
        if(myMap.find(sum - k) != myMap.end())
            len = max(len, k - myMap[sum-k]);
        else
            myMap[sum] = k;
    }
    return len;
}


int main(){
    vector<int> vec = {1, -1, 5, -2, 3};
    cout<<maxSubarrayLen(vec, 3)<<endl;

    return 0;
}