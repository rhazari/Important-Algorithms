#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void helper(vector<vector<int>>& result, vector<int>& temp, vector<int>& vec, int target, int start){
	if(0 == target){
		result.push_back(temp);
		return;
	}
	for(int k = start; k < vec.size(); ++k){
		if(vec[k] > target)
			return;
		if(k > start && vec[k] == vec[k-1])
			continue;
		temp.push_back(vec[k]);
		helper(result, temp, vec, target - vec[k], k+1);
		temp.pop_back();
	}
}

int main(){
	vector<int> vec = {10, 1, 2, 7, 6, 1, 5};
	sort(vec.begin(), vec.end());
	vector<vector<int>> result;
	vector<int> temp;
	helper(result, temp, vec, 8, 0);

	for(const auto& v: result){
		for(const auto& elem: v)
			cout<<elem<<" ";
		cout<<"\n";
	}
	return 0;
}