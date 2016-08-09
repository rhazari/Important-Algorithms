//Length of the longest substring with 2 unique characters
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
	string str = "abcbbbbcccbdddadacb";
	int sz = str.size();

	map<char, int> m1;
	int maxSize = 0;
	int k, start = 0, count = 0;
	for(k = start; k < sz; ++k){
		auto ii = m1.find(str[k]);
		if( ii == m1.end() && m1.size() < 2){
			m1[str[k]] += 1;
			++count;
		}
		else if( ii != m1.end()){
			m1[str[k]] += 1;
			++count;
		}  
		else{
			maxSize = max(maxSize, count);
			cout<<str.substr(start,count)<<endl;
			m1.clear();
			count = 0;
			++start;
		}
	}
	cout<<maxSize<<endl;

	return 0;
}