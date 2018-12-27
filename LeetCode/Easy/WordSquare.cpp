// 422 Valid Word Square
// Given a sequence of words, check whether it forms a valid word square.

// A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤k < max(numRows, numColumns).

// Note:

// The number of words given is at least 1 and does not exceed 500.
// Word length will be at least 1 and does not exceed 500.
// Each word contains only lowercase English alphabet a-z.

#include <iostream>
#include <vector>

using namespace std;

bool validWordSquare(vector<string>& words) {
    if (words.empty()) 
        return true;
    if (words.size() != words[0].size()) 
        return false;
    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < words[i].size(); ++j) {
            if (j >= words.size() || i >= words[j].size() || words[i][j] != words[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<string> v1 = { "abcd", "bnrt", "crmy", "dtye" };
    vector<string> v2 = { "abcd", "bnrt", "crm", "dt" };
    vector<string> v3 = { "ball", "area", "read", "lady"};

    cout<<validWordSquare(v1)<<"\n";
    cout<<validWordSquare(v2)<<"\n";
    cout<<validWordSquare(v3)<<"\n";
}