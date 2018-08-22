/*
Given a string, determine if a permutation of the string could form a palindrome.
For example,
"code" -> False, "aab" -> True, "carerac" -> True.
*/
#include <iostream>
#include <map>
using namespace std;

bool canPermutate(string s){
    if("" == s || 1 == s.size())
        return true;
    map<char, int> myMap;
    for(const auto& c: s){
        myMap[c]++;
    }
    int count = 0;
    for(const auto& m:myMap){
        if(m.second %2 != 0)
            ++count;
    }
    if(s.size()%2 == 0)
        return count == 0;
    else
        return count == 1;
}

void result(string s){
    if(canPermutate(s))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
}


int main(){

    result("code");
    result("aab");
    result("carerac");
    return 0;
}