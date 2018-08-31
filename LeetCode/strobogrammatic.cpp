/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/
#include <iostream>
#include <map>

using namespace std;

bool isStrobogrammatic(string s, map<char, char> &myMap){
    int n = s.size();
    for(int l = 0, r = n - 1; l <= r; l++, r--){
        if(myMap.find(s[l]) == myMap.end() || 
            myMap.find(s[r]) == myMap.end() || 
            myMap[s[l]] != s[r])
            return false;
    }
    return true;
}

void result(string s, map<char, char> &m){
    if(isStrobogrammatic(s, m))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
}

int main(){
    map<char, char> myMap;
    myMap['0'] = '0';
    myMap['1'] = '1';
    myMap['6'] = '9';
    myMap['8'] = '8';
    myMap['9'] = '6';

    result("69", myMap);
    result("68", myMap);
    result("88", myMap);
    result("818", myMap);
    result("889", myMap);

    return 0;
}