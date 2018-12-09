#include <iostream>
#include <vector>
#include <string>

using namespace std;

void helper(vector<string>& vec, int left, int right, string str){
    if(left > right)
        return;
    if(left == 0 && right == 0){
        vec.push_back(str);
        return;
    }
    if(left > 0)
        helper(vec, left-1, right, str+"(");
    if(right > 0)
        helper(vec, left, right-1, str+")");
}

int main(){
    vector<string> vec;
    helper(vec, 3, 3, "");

    cout<<"Valid Parentheses..."<<endl;
    for(const auto& s: vec)
        cout<<s<<"\n";
    cout<<endl;
    return 0;
}