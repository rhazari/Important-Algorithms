#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int> > vec(10,vector<int>(0));

void createGraph(int x, int y){
    vec[x].push_back(y);
}

void displayGraph(){
    for(const auto& v: vec){
        if(v.size() == 0)
            continue;
        for(const auto& elem: v)
            cout<<elem<<" ";
        cout<<endl;
    }
}

void dfs(int index, vector<int>& visited, stack<int> &s1){
    visited[index] = 1;
    for(const auto& v : vec[index]){
        if(!visited[v])
            dfs(v, visited, s1);
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
    //int *visited = new int[5];
    vector<int> visited(5); 
    int k;
    for(k = 0; k < 5; ++k)
        visited[k] = 0;

    stack<int> s1;
    for(k = 0; k < 5; ++k){
        if(!visited[k])
            dfs(k, visited, s1);
    }
    s1.push(k);

    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;

    return 0;
}