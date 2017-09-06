#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int>& vec, vector<vector<int>>& result, vector<int>& temp, int start, int target){
	if(0 == target){
		result.push_back(temp);
		return;
	}
	for(int k = start; k < vec.size(); ++k){
		if(vec[k] > target)
			continue;
		temp.push_back(vec[k]);
		helper(vec, result, temp, k, target - vec[k]);
		temp.pop_back();
	}
}

int main(){
	vector<int> vec = {2,3,6,7};
	vector<vector<int>> result;
	vector<int> temp;
	helper(vec, result, temp, 0, 7);

	for(const auto& v: result){
		for(const auto& elem: v)
			cout<<elem<<" ";
		cout<<endl;
	}
	return 0;
}