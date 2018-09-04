#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dfs(map<int, vector<int>>& mp, vector<bool>& visited, int node){
    if(visited[node])
        return;
    visited[node] = true;
    for(auto elem: mp[node]){
        dfs(mp, visited, elem);
    }
}

int countComponents(int n, vector<pair<int, int>>& graph){
    map<int, vector<int>> mp;
    for(auto& edge: graph){
        mp[edge.first].push_back(edge.second);
    }
    int count = 0;
    vector<bool> visited(n ,false);
    for(auto& elem: mp){
        if(!visited[elem.first]){
            ++count;
            dfs(mp, visited, elem.first);
        }
    }
    return count;
}

int main(){
    vector<pair<int,int>> graph1 = {{0, 1}, {1, 2}, {3, 4}};
    cout<<countComponents(4, graph1)<<"\n";

    vector<pair<int,int>> graph2 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    cout<<countComponents(4, graph2)<<"\n";
}