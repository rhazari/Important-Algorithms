//Print the top K frequent characters in a stream
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

typedef pair<char,int> P;

int main(){

	char arr[] = {'a','b','c','d','a','d','a','f','g','h','a','b','c','a','r','t','x','c','d'};
	int k, len;
	len = sizeof(arr)/sizeof(arr[0]);

	unordered_map<char, int> um;
	for(k = 0; k < len; ++k){
		um[arr[k]] += 1;
	}

	priority_queue< P, vector<P>, greater<P> > pq;
	//priority_queue<P> pq;
	for(auto ii = um.begin(); ii != um.end(); ++ii){
		pq.push(make_pair( (*ii).first, (*ii).second));
	}

	while(!pq.empty()){
		auto ii = pq.top();
		pq.pop();
		cout<<(ii).first<<" "<<(ii).second<<endl;
	}	

	return 0;
}