// 245
// This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

// word1 and word2 may be the same and they represent two individual words in the list.

// For example,
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

// Given word1 = “makes”, word2 = “coding”, return 1.
// Given word1 = "makes", word2 = "makes", return 3.

// Note:
// You may assume word1 and word2 are both in the list.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int shortestWordDistance(vector<string>& words, string word1, string word2) {
    int p1 = -1, p2 = -1, res = INT_MAX;
    for (int i = 0; i < words.size(); ++i) {
        int t = p1;
        if (words[i] == word1) p1 = i;
        if (words[i] == word2) p2 = i;
        if (p1 != -1 && p2 != -1) {
            if (word1 == word2 && t != -1 && t != p1) {
                res = min(res, abs(t - p1));
            } else if (p1 != p2) {
                res = min(res, abs(p1 - p2));
            }
        }
    }
    return res;
}

int main(){
    vector<string> vec = {"practice", "makes", "perfect", "coding", "makes"};

    cout<<shortestWordDistance(vec, "makes", "coding")<<"\n";
    cout<<shortestWordDistance(vec, "makes", "makes")<<"\n";
}