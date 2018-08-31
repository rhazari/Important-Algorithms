// Find the longest substring without repeating characters
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestSubstring(string str){
    int len = str.size();
    if(0 == len)
        return 0;
    unordered_set<char> st;
    int maxLen = 0;
    int start, end;
    start = end = 0;
    while(end < len){
        if(st.find(str[end]) == st.end()){
            st.insert(str[end]);
            ++end;
            maxLen = max(maxLen, (int)st.size());
        }
        else{
            st.erase(str[start]);
            ++start;
        }
    }
    return maxLen;
}

int main(){
    vector<string> vec = {"abcabcbb", "bbbbb", "pwwkew"};
    for(auto& s: vec){
        cout<<s<<":"<<longestSubstring(s)<<"\n";
    }
    cout<<"\n";
}