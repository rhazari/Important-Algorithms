// Detect cycle in an undirected graph using BFS
// Time Complexity: O(V+E)

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

void addEdge(unordered_map<int, vector<int>>& g, int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
}

bool helper(unordered_map<int, vector<int>>& g, int u, int V, vector<bool>& visited){
    vector<int> parent(V, -1);
    queue<int> q;

    visited[u] = true;
    q.push(u);
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto& v: g[x]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                parent[v] = x;
            }
            else if(parent[v] != x)
                return true;
        }
    }
    return false;
}

bool hasCycle(unordered_map<int, vector<int>>& g, int V){
    vector<bool> visited(V, false);
    for(int k = 0; k < V; ++k){
        if(!visited[k] && helper(g, k, V, visited))
            return true;
    }
    return false;
}

int main(){
    unordered_map<int, vector<int>> g1;
    int V = 4;
    addEdge(g1, 0, 1); 
    addEdge(g1, 1, 2); 
    addEdge(g1, 2, 0); 
    addEdge(g1, 2, 3);

    if(hasCycle(g1, V)){
        cout<<"Graph has cycle"<<"\n";
    }
    else{
        cout<<"Graph doesn't have cycle"<<"\n";
    }
}