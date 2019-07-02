#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1,2,3,4};
    
    int len = v.size();
    for(int size = 1; size <= len; ++size){
        for(int start = 0; start <= len - size; ++start){
            for(int k = start; k < start + size; ++k){
                cout<<v[k]<<" ";
            }
            cout<<"\n";
        }
    }
}
