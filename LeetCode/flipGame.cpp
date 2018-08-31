/*
You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip twoconsecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.
Write a function to compute all possible states of the string after one valid move.
For example, given s = "++++", after one move, it may become one of the following states:
[
  "--++",
  "+--+",
  "++--"
]
If there is no valid move, return an empty list []
*/

#include <iostream>
#include <vector>

using namespace std;
vector<string> generateNextMoves(string s){
    vector<string> result;
    if("" == s || s.size() < 2)
        return result;

    for(int k = 0, len = s.size(); k < len; ++k){
        if(s[k] == s[k+1] && s[k] == '+'){
            s[k] = '-';
            s[k+1] = '-';
            result.push_back(s);
            s[k] = '+';
            s[k+1] = '+';
        }
    }
    return result;
}

int main(){

    auto vec = generateNextMoves("++++");
    for(const auto& v: vec)
        cout<<v<<endl;
    return 0;
}