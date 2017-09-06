#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permutate(vector<vector<int>> &result, vector<int> & vec, int start, int size){
	if(start >= size){
		result.push_back(vec);
		return;
	}
	for(int k = start; k <= size; ++k){
		swap(vec[start], vec[k]);
		permutate(result, vec, start+1, size);
		swap(vec[start], vec[k]);
	}
}

int main(){
	vector<int> vec = {1,2,3};
	vector<vector<int>> result;
	permutate(result, vec, 0, vec.size()-1);

	cout<<"Permutation ..."<<endl;
	for(const auto& v: result){
		for(const auto& elem: v)
			cout<<elem<<" ";
		cout<<endl;
	}
}