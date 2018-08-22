#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void permutate(vector<vector<int>>& result, vector<int>& vec, int start, int len){
    if(start >= len){
        result.push_back(vec);
        return;
    }
    set<int> mySet;
    for(int k = start; k <= len; ++k){
        if(mySet.find(vec[k]) != mySet.end())
            continue;
        mySet.insert(vec[k]);
        swap(vec[k], vec[start]);
        permutate(result, vec, start+1, len);
        swap(vec[k], vec[start]);
    }
}


int main(){
    vector<int> vec = {1,1,2};
    vector<vector<int>> result;
    permutate(result, vec, 0, vec.size()-1);

    cout<<"Permutation ..."<<endl;
    for(const auto& v: result){
        for(const auto& elem: v)
            cout<<elem<<" ";
        cout<<endl;
    }

    return 0;
}