#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
void printVector(vector<T> &myVec){
	for(auto jj = myVec.begin(); jj != myVec.end(); ++jj){
		cout<<*jj<<"\t";
	}
	cout<<endl;
}

bool compare(string a, string b){
	return (a.compare(b) > 0);
}

bool comp(int a, int b){
	return (a>b);
}

void bsearchString(vector<string> &myVec, int left, int right, string needle){
	if(left > right){
		cout<<"Pattern not found"<<endl;
		return;
	}
	int mid = (left+right)/2;
	if(needle == myVec[mid]){
		cout<<"Pattern found"<<endl;
		return;
	}
	else if(needle.compare(myVec[mid]) > 0){
		bsearchString(myVec, mid+1, right, needle);
	}
	else{
		bsearchString(myVec, left, mid-1, needle);	
	}
}

int main(){

	string arr[] = {"www","ggg","bbb","ssss","aaa","ccc","vvv","gfd","qqa","srtf"};
	vector<string> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));
	sort(vec.begin(), vec.end(), greater<string>());
	//sort(vec.begin(), vec.end(), compare);
	printVector(vec);

	vector<int> vc = {11,13,17,19,23,15,31,9};
	sort(vc.begin(), vc.end(), greater<int>());
	//sort(vc.begin(), vc.end(), comp);
	printVector(vc);

	sort(vec.begin(), vec.end());
	bsearchString(vec, 0, vec.size()-1, "gfd");
	return 0;
}
