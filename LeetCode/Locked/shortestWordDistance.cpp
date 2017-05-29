/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int shortestDistance(vector<string> vec, string w1, string w2){
	int id1 = -1, id2 = -1;
	int dist = INT_MAX;
	for(int k = 0, len = vec.size(); k < len; ++k){
		if(w1 == vec[k]){
			id1 = k;
			if(id2 != -1)
				dist = min(dist, id1-id2);
		}			
		else if(w2 == vec[k]){
			id2 = k;
			if(id1 != -1)
				dist = min(dist, id2-id1);
		}
	}
	return dist;
}

int main(){

	vector<string> v1 = {"practice", "makes", "perfect", "coding", "makes"};
	cout<<shortestDistance(v1, "coding", "practice")<<endl;
	cout<<shortestDistance(v1, "makes", "coding")<<endl;
	return 0;
}