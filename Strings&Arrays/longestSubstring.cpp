#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	string str = "abcabcababb";
	int len = str.size();
	int j = 0, k = 0, maxlen;
	int exist[26] = {0};
	while(j < len){
		if(exist[str[j]-'a']){
			maxlen = max(maxlen, j-k);	
			while(str[k] != str[j]){
				exist[str[k]-'a'] = 0;
				++k;
			}
			++k; ++j;
		}
		else{
			exist[str[j]-'a'] = 1;
			++j;
		}
	}
	maxlen = max(maxlen,len-k);
	cout<<maxlen<<endl;

	return 0;
}