#include <iostream>
#include <vector>

using namespace std;

void longestCommonSubsequence(const string &s1, const string &s2){
	int sz1, sz2;
	sz1 = s1.size(); sz2 = s2.size();
	vector<vector<int> > dp(sz1+1, vector<int> (sz2+1, 0));
	int j, k;
	for(j = 1; j <= sz1; ++j){
		for(k = 1; k <= sz2; ++k){
			if(s1[j-1] == s2[k-1]){
				dp[j][k] = dp[j-1][k-1]+1;
			}
			else{
				dp[j][k] = max(dp[j-1][k],dp[j][k-1]);
			}
		}
	}
	cout<<"Length of the longest common subsequence: "<<dp[sz1][sz2]<<endl;
}

int main(){
	string s1("abcdef");
	string s2("abdger");
	longestCommonSubsequence(s1, s2);
	return 0;
}