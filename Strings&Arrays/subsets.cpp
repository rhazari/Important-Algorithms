#include <iostream>
#include <cmath>

using namespace std;

int main(){
	string str("raihan");
	int sz = str.size();
	int j, k, num;
	static int count;
	num = pow(2,sz);
	for(k = 1; k < num; ++k){
		cout<<++count<<"->";
		for(j = 0; j < sz; ++j){
			if( k & (1<<j)){
				cout<<str[j];
			}
		}
		cout<<endl;
	}
	return 0;
}