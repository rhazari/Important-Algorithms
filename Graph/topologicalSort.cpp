#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int> > vec(10,vector<int>());

void createGraph(int x, int y){
	vec[x].push_back(y);
}

void displayGraph(){
	for(auto ii = vec.begin(); ii != vec.end(); ++ii){
		if( (*ii).size() == 0){
			continue;
		}
		for(auto jj = (*ii).begin(); jj != (*ii).end(); ++jj){
			cout<<*jj<<" ";
		}
		cout<<endl;
	}
}

void dfs(int index, int *visited, stack<int> &s1){
	visited[index] = 1;
	for(auto ii = vec[index].begin(); ii != vec[index].end(); ++ii){
		if(!visited[*ii]){
			dfs(*ii, visited, s1);
		}
	}
	s1.push(index);
}

int main(){

	vector<vector<int> > vec;
	createGraph(5,2);
	createGraph(5,0);
	createGraph(4,0);
	createGraph(4,1);
	createGraph(2,3);
	createGraph(3,1);

	//displayGraph();
	int *visited = new int[5];
	int k;
	for(k = 0; k < 5; ++k){
		visited[k] = 0;
	}

	stack<int> s1;
	for(k = 0; k < 5; ++k){
		if(!visited[k]){
			dfs(k, visited, s1);
		}
	}
	s1.push(k);

	while(!s1.empty()){
		cout<<s1.top()<<" ";
		s1.pop();
	}
	cout<<endl;

	return 0;
}