// Assume you have an array of length n initialized with all 0's and are given k update operations.
// Each operation is represented as a triplet: [startIndex, endIndex, inc] 
// which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
// Return the modified array after all k operations were executed.

#include <iostream>
#include <vector>

using namespace std;

int main(){
	int length = 5;
	vector<vector<int>> vec = { {1,  3,  2}, {2,  4,  3}, {0,  2, -2} };
	vector<int> result, temp(length+1, 0);
	for(const auto& a: vec){
		temp[a[0]] += a[2];
		temp[a[1]] -= a[2];
	}

	int sum = 0;
	for(const auto& s: temp){
		sum += s;
		result.push_back(sum);
	}

	result.pop_back();
	
	for(const auto& elem: result)
		cout<<elem<<" ";
	cout<<endl;	

	return 0;
}