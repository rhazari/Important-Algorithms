/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
determine if a person could attend all meetings. 
For example, Given [[0, 30],[5, 10],[15, 20]], return false.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool canAttendMeetings(vector<pair<int, int>> vec){
    sort(vec.begin(), vec.end(), [](const pair<int, int> &x, const pair<int, int> &y){
        return (x.first < y.first) || (x.first == y.first && x.second < y.second);
    });
    
    for(int k = 0, len = vec.size(); k < len-1; ++k){
        if(vec[k].second > vec[k+1].first)
            return false;
    }
    return true;
}

void result(vector<pair<int, int>> vec){
    if(canAttendMeetings(vec))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}

int main(){

    vector<pair<int, int>> v1{{0,30}, {15,20}, {5,10}};
    result(v1);

    vector<pair<int, int>> v2{{0,4}, {15,20}, {5,10}, {11, 14}};
    result(v2);

    return 0;
}