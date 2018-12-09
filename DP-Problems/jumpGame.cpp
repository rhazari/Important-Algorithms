#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void minJumps(vector<int> &vec){
    int sz = vec.size();
    vector<int> jump(sz,INT_MAX);
    int j, k;
    jump[0] = 0;
    for(j = 1; j < sz; ++j){
        for(k = 0; k < j; ++k){
            if(j <= k+vec[k] && jump[k] != INT_MAX){
                jump[j] = min(jump[k]+1,jump[j]);
                break;
            }
        }
    }
    cout<<"Minimum Jumps needed: "<<jump[sz-1]<<endl;
}

int main(){
    vector<int> vec = {1,3,6,1,0,9};
    minJumps(vec);
    return 0;
}