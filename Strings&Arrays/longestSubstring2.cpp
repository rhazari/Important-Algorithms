//Length of the longest substring with unique characters
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    string str = "abcdabcbb";
    int sz = str.size();

    map<char, int> m1;
    int maxSize = 0;
    int k, start = 0;
    for(k = start; k < sz; ++k){
        if(m1.find(str[k]) == m1.end()){
            m1[str[k]] += 1;
        }
        else{
            maxSize = max(maxSize, (int)m1.size());
            m1.clear();
            ++start;
        }
    }
    cout<<maxSize<<endl;

    return 0;
}