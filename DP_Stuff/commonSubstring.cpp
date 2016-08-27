#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

string longestCommonSubstring(const string &string1,const string &string2)
{
	int sz1, sz2;
	sz1 = string1.size(); 
	sz2 = string2.size();
	
	vector<vector<int> > dp(sz1, vector<int>(sz2,0));
	
	int mx, index;
	//mx will hold the maximum length of the common substring
	mx = 0; 
	//index will hold the last index of the longest common substring
	index = -1;

	for(int i = 0; i < sz1; ++i){
		for(int j = 0; j < sz2; ++j){
			if(string1[i] == string2[j]){
				if(i == 0 || j == 0){
					dp[i][j] = 1;
				}
				else{
					dp[i][j] = dp[i-1][j-1]+1;	
				}
				if(mx < dp[i][j]){
					mx = dp[i][j];
					index = j;
				}
			}
		}
	}
	return string2.substr(index-mx+1, mx);
} 

int main(){
	string s1("xzwabcdrvfg");
	string s2("mtrabcxdp");
	cout<<longestCommonSubstring(s1,s2)<<endl;
	return 0;
}