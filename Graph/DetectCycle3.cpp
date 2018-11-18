// Detect cycle in a directed graph using DFS
// Time Complexity: O(V+E)

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

void addEdge(unordered_map<int, vector<int>>& g, int u, int v){
    g[u].push_back(v);
}

bool dfs(unordered_map<int, vector<int>>& g, 
        vector<bool>& visited, 
        vector<bool>& recStack, int u){
    
    if(!visited[u]){
        visited[u] = true;
        recStack[u] = true;

        for(auto v: g[u]){
            if(!visited[v] && dfs(g, visited, recStack, v)){
                return true;
            }
            else if(recStack[v])
                return true;
        }
    }
    recStack[u] = false;
    return false;
}

bool hasCycle(unordered_map<int, vector<int>>& g, int V){
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for(int k = 0; k < V; ++k){
        if(dfs(g, visited, recStack, k))
            return true;
    }
    return false;
}

int main() { 
    // Create a graph given in the above diagram 
    unordered_map<int, vector<int>> g1;
    int V = 4;
    addEdge(g1, 0, 1); 
    addEdge(g1, 0, 2); 
    addEdge(g1, 1, 2); 
    addEdge(g1, 2, 0); 
    addEdge(g1, 2, 3); 
    addEdge(g1, 3, 3); 
  
    if(hasCycle(g1, V)) 
        cout << "Graph contains cycle"<<"\n"; 
    else
        cout << "Graph doesn't contain cycle"<<"\n";
} 