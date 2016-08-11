#include <iostream>

using namespace std;

int main(){

	string str("BANANA");
	int sz = str.size();
	int **dp = new int*[sz];
	int j, k, maxLen = 1;
	for(k = 0; k < sz; ++k){
		dp[k] = new int[sz];
		for(j = 0; j < sz; ++j){
			dp[k][j] = 0;
		}
	}

	for(k = 0; k < sz; ++k){
		dp[k][k] = 1;
	}

	int start = 0;
	for(k = 0; k < sz-1; ++k){
		if(str[k] == str[k+1]){
			dp[k][k+1] = 1;
			start = k;
			maxLen = 2;
		}
	}

	for(k = 3; k <= sz; ++k){
		for(j = 0; j < sz-k+1; ++j){
			int i = j+k-1;
			if(dp[j+1][i-1] == 1 && str[j] == str[i]){
				if(maxLen < k){
					maxLen = k;
					start = j;	
				}
				dp[j][i] = 1;
			}
		}
	}
	cout<<"Longest Palindromic substring: "<<maxLen<<endl;
	cout<<str.substr(start,maxLen)<<endl;



	return 0;
}