// Given a 01 matrix M, find the longest line of consecutive one in the matrix. 
// The line could be horizontal, vertical, diagonal or anti-diagonal.

// Example:

// Input:
// [[0,1,1,0],
//  [0,1,1,0],
//  [0,0,0,1]]
// Output: 3

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> vec;
    vec.push_back({0, 1, 1, 0});
    vec.push_back({0, 1, 1, 0});
    vec.push_back({0, 0, 0, 1});

    int row = vec.size();
    int col = vec[0].size();
    int result = 0;
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 1}, {-1, -1}};

    for(int j = 0; j < row; ++j){
        for(int k = 0; k < col; ++k){
            if(vec[j][k] == 0)
                continue;
            for(auto dir: dirs){
                int r, c, count;
                count = 0;
                r = j; c = k;
                while(r >= 0 && r < row && c >= 0 && c < col && vec[r][c] == 1){
                    r += dir[0];
                    c += dir[1];
                    ++count;
                }
                result = max(result, count);
            }
        }
    }
    cout<<result<<"\n";
}