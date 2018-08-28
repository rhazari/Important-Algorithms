#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    vector<int> vec  = {11, 2, 4, 5, 7, 2, 4, 13, 17, 21, 23, 11, 5, 7, 8, 3, 2, 7 };
    unordered_map<int, int> mp;
    for(const auto& v: vec){
        mp[v]++;
    }

    auto compare = [](pair<int, int> A, pair<int, int> B){
        return (A.second < B.second) || (A.second == B.second) && (A.first < B.first);
    };

    priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(compare)> pq(compare);

    for(auto elem: mp){
        pq.push(make_pair(elem.first, elem.second));
    }

    int K = 4;
    cout<<"Top "<<K<<" frequent elements are"<<"\n";
    while(K){
        auto temp = pq.top();
        cout<<temp.first<<" "<<temp.second<<"\n";
        pq.pop();
        --K;
    }

}