// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
// You may assume all four edges of the grid are surrounded by water.

// Count the number of distinct islands. 
// An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

//[LeetCode] Number of Distinct Islands

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void helper(vector<vector<int>>& grid, 
            int x0, int y0, int x, int y, 
            vector<pair<int, int>>& v){
    int row = grid.size();
    int col = grid[0].size();
    if(x < 0 || x >= row || y < 0 || y >= col || grid[x][y] == 0)
        return;
    grid[x][y] = 0;
    v.push_back({x-x0, y - y0});
    for(auto& dir: dirs){
        helper(grid, x0, y0, x+dir[0], y + dir[1], v);
    }
}

int main(){
    vector<vector<int>> grid1;
    grid1.push_back({1, 1, 0, 0, 0});
    grid1.push_back({1, 1, 0, 0, 0});
    grid1.push_back({0, 0, 0, 1, 1});
    grid1.push_back({0, 0, 0, 1, 1});

    int row = grid1.size();
    int col = grid1[0].size();

    set<vector<pair<int, int>>> result;

    for(int j = 0; j < row; ++j){
        for(int k = 0; k < col; ++k){
            if(grid1[j][k] == 1){
                vector<pair<int, int>> vec;
                helper(grid1, j, k, j, k, vec);
                result.insert(vec);
            }
        }
    }
    cout<<result.size()<<"\n";

}