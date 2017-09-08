// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] 
// find the minimum number of conference rooms required.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){

	vector<pair<int, int>> vec = {{0, 30},{5, 10},{15, 20}};

	sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b){
		return (a.first <  b.first);
	});

	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(vec[0].second);

	int count = 1;
	for(int k = 1; k < vec.size(); ++k){
		if(pq.top() <= vec[k].first)
			pq.pop();
		pq.push(vec[k].second);
		count  = max(count, (int)pq.size());
	}

	cout<<"Maximum number of rooms needed "<<count<<"\n";
	return 0;
}