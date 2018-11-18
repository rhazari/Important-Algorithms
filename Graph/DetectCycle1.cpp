// Detect cycle in an undirected graph using DFS
// Time Complexity: O(V+E)

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void addEdge(unordered_map<int, vector<int>>& g, int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
}

bool dfs(unordered_map<int, vector<int>>& g, vector<bool>& visited, int u, int parent){
    visited[u] = true;
    for(const auto& e: g[u]){
        if(!visited[e]){
            if(dfs(g, visited, e, u))
                return true;
        }
        else if(e != u)
            return true;
    }
    return false;
}

bool hasCycle(unordered_map<int, vector<int>>& g, int V){
    vector<bool> visited(V, false);

    for(int k = 0; k < V; ++k){
        if(!visited[k]){
            if(dfs(g, visited, k, -1))
                return true;
        }
    }
    return false;
}

int main(){
    unordered_map<int, vector<int>> g1;
    int V = 4;
    addEdge(g1, 1, 0);
    addEdge(g1, 0, 2);
    addEdge(g1, 2, 0);
    addEdge(g1, 0, 3);
    addEdge(g1, 3, 4);

    if(hasCycle(g1, V)){
        cout<<"Graph has cycle"<<"\n";
    }
    else{
        cout<<"Graph doesn't have cycle"<<"\n";
    }

    unordered_map<int, vector<int>> g2;
    addEdge(g2, 0, 1);
    addEdge(g2, 1, 2);

    if(hasCycle(g2, 0)){
        cout<<"Graph has cycle"<<"\n";
    }
    else{
        cout<<"Graph doesn't have cycle"<<"\n";
    }

}