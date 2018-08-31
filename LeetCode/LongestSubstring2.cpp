#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestSubstringKDistinct(string str, int K){
    int len = str.size();
    int start = 0;
    int result = 0;
    unordered_map<char, int> mp;
    for(int k = 0; k < len; ++k){
        mp[str[k]]++;
        while(mp.size() > K){
            mp[str[start]]--;
            if(mp[str[start]] == 0){
                mp.erase(str[start]);
            }
            ++start;
        }
        result = max(result, k-start+1);
    }
    return result;
}

int main(){
    cout<<longestSubstringKDistinct("eceba", 2)<<"\n";
    cout<<longestSubstringKDistinct("abcadcacacaca", 3)<<"\n";
}