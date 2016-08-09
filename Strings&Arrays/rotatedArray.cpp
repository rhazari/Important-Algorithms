// Searching for the minimum in a rotated sorted array
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int searchMin(vector<int> &vec, int left, int right){
	if(left == right){
		return vec[left];
	}
	if(left+1 == right){
		return min(vec[left], vec[right]);
	}
	int mid = left +(right-left)/2;
	//No longer rotated
	if(vec[left] < vec[right]){
		return vec[left];
	}
	
	else if(vec[mid] > vec[left]){
		return searchMin(vec, mid, right);
	}
	else{
		return searchMin(vec, left, mid);
	}
}

int main(){
	int arr[] = {21,6,9,5,13,17,19,31};
	vector<int> vec(arr, arr+sizeof(arr)/sizeof(arr[0]));

	sort(vec.begin(), vec.end(), greater<int>());
	sort(vec.begin(), vec.begin()+3);
	sort(vec.begin()+3, vec.end());


	cout<<"Rotated Array ..."<<endl;
	for(auto ii = vec.begin(); ii != vec.end(); ++ii){
		cout<<*ii<<" ";
	}
	cout<<endl;

	cout<<"Minimum value: "<< searchMin(vec, 0, vec.size()-1)<<endl;

	return 0;	
}