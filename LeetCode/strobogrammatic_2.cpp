/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Find all strobogrammatic numbers that are of length = n.+
For example, Given n = 2, return ["11","69","88","96"].
*/

#include <iostream>
#include <vector>

using namespace std;

vector<string> find(int n, int target){
    vector<string> result;
    if(0 == n){
        result.push_back("");
        return result;
    }
    
    if(1 == n){
        result = {"1","0","8"};
        return result;
    }
        
    auto prev = find(n-2, target);

    for(const auto& s: prev){
        if(n != target)
            result.push_back("0"+s+"0");
        result.push_back("1"+s+"1");
        result.push_back("8"+s+"8");
        result.push_back("6"+s+"9");
        result.push_back("9"+s+"6");
    }
    return result;
}

vector<string> findStrobogrammatic(int n){
    cout<<"With n = "<<n<<endl;
    return find(n, n);
}

void display(const vector<string>& vec){
    for(const auto& v: vec){
        cout<<v<<" ";
    }
    cout<<endl;
    cout<<endl;
}

int main(){
    display(findStrobogrammatic(2));
    display(findStrobogrammatic(3));
    return 0;
}