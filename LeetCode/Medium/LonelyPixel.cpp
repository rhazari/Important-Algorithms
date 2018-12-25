// 531
// Given a picture consisting of black and white pixels, find the number of black lonely pixels.
// The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.
// A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.

// Example:

// Input: 
// [['W', 'W', 'B'],
//  ['W', 'B', 'W'],
//  ['B', 'W', 'W']]

// Output: 3
// Explanation: All the three 'B's are black lonely pixels.

#include <iostream>
#include <vector>

using namespace std;

void helper(vector<vector<char>>& vec, int j, int k){
    int row = vec.size();
    int col = vec[0].size();
    if(j < 0 || j >= row || k < 0 || k >= col || vec[j][k] != 'B')
        return;
    vec[j][k] = 'W';
    helper(vec, j+1, k);
    helper(vec, j-1, k);
    helper(vec, j, k+1);
    helper(vec, j, k-1);
}

int main(){
    vector<vector<char>> vec = {{'W', 'W', 'B'}, {'W', 'B', 'W'}, {'B', 'W', 'W'}};
    int count = 0;
    int row = vec.size();
    int col = vec[0].size();
    for(int j = 0; j < row; ++j){
        for(int k = 0; k < col; ++k){
            if(vec[j][k] == 'B'){
                helper(vec, j, k);
                ++count;
            }
        }
    }
    cout<<"No. of Lonely Pixels: "<<count<<"\n";

}