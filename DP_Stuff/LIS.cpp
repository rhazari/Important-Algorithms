#include <iostream>

using namespace std;

void lis(int *array, int length){
	int *dp = new int[length];

	int j, k;
	for(j = 0; j < length; ++j){
		dp[j] = 1;
	}

	for(j = 1; j < length; ++j){
		for(k = 0; k < j; ++k){
			if( array[j] > array[k] && dp[j] < dp[k]+1 ){
				dp[j] = dp[k]+1;
			}
		}
	}

	int idx = 1;
	cout<<"Longest Increasing Subsequence ...\n";
	for(j = 0; j < length; ++j){
		if(dp[j] == idx){
			cout<<array[j]<<" ";
			++idx;
		}
	}
	cout<<endl;
}

int main(){
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60};
	int length = sizeof(arr)/sizeof(int);

	lis(arr, length);

	return 0;
}