// Write a function that takes an integer n and 
// return all possible combinations of its factors
#include <iostream>
#include <vector>

using namespace std;

void helper(vector<vector<int>>& result, vector<int>& temp, int start, int product, int n){
	if(start > n || product > n)
		return;
	if(product == n){
		result.push_back(temp);
		return;
	}
	for(int k = start; k < n; ++k){
		if(k * product > n)
			break;
		if(n % k == 0){
			temp.push_back(k);
			helper(result, temp, k, k*product, n);
			temp.pop_back();
		}
	}
}


int main(){
	int n = 20;
	vector<vector<int>> result;
	vector<int> temp;
	helper(result, temp, 2, 1, n);

	for(const auto& vec: result){
		for(const auto& elem: vec){
			cout<<elem<<" ";
		}
		cout<<endl;
	}
		

	return 0;
}