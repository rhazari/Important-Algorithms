#include <iostream>
#include <vector>
#include <utility>

using namespace std;

bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int current, int prev){
    if(visited[current])
        return false;
    visited[current] = true;
    for(const auto& v: graph[current]){
        if(v != prev){
            if(!dfs(graph, visited, v, current))
                return false;    
        }
    }
    return true;
}

bool validTree(int n, vector<pair<int, int>>& vec){
    vector<vector<int>> graph(n, vector<int>());
    for(const auto& elem: vec){
        graph[elem.first].push_back(elem.second);
        graph[elem.second].push_back(elem.first);
    }
    vector<bool> visited(n, false);
    if(!dfs(graph, visited, 0, -1))
        return false;
    for(const auto a: visited)
        if(!a)
            return false;
    return true;
}

void helper(int n, vector<pair<int, int>>& vec){
    if(validTree(n, vec))
        cout<<"Is a valid Tree ..."<<"\n";
    else
        cout<<"Not a valid Tree ..."<<"\n";
}

int main(){

    vector<pair<int, int>> v1 = { {0, 1}, {0, 2}, {0, 3}, {1, 4} };
    helper(5, v1);
    vector<pair<int, int>> v2 = { {0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4} };
    helper(5, v2);
    return 0;
}