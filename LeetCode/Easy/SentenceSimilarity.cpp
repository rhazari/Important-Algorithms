// 734
// Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.

// For example, "great acting skills" and "fine drama talent" are similar, if the similar word pairs are pairs = [["great", "fine"], ["acting","drama"], ["skills","talent"]].

// Note that the similarity relation is not transitive. For example, if "great" and "fine" are similar, and "fine" and "good" are similar, "great" and "good" are not necessarily similar.

// However, similarity is symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.

// Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, 
//even though there are no specified similar word pairs.

// Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
    if (words1.size() != words2.size()) return false;
    unordered_map<string, unordered_set<string>> m;
    for (auto pair : pairs) {
        m[pair.first].insert(pair.second);
    }
    for (int i = 0; i < words1.size(); ++i) {
        if (words1[i] == words2[i]) continue;
        if (!m[words1[i]].count(words2[i]) && !m[words2[i]].count(words1[i])) return false;
    }
    return true;
}

int main(){
    vector<string> v1 = {"great", "acting", "skills"};
    vector<string> v2 = {"fine", "drama", "talent"};
    vector<pair<string, string>> mp = {{"great", "fine"}, {"acting","drama"}, {"skills","talent"}};

    cout<<areSentencesSimilar(v1, v2, mp)<<"\n";
}