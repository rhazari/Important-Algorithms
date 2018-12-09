//Remove duplicates from an array in 0(n) time
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
void display(vector<T> &vec){
    for(auto ii = vec.begin(); ii != vec.end(); ++ii){
        cout<<*ii<<" ";
    }
    cout<<endl;
}

int main(){

    int array[] = {3,5,6,7,3,2,1,4,1,3,8,5,2};
    vector<int> vec(array, array+sizeof(array)/sizeof(array[0]));

    sort(vec.begin(), vec.end());
    display(vec);
    int sz;
    sz = vec.size();
    int i = 0, j = 1;
    while(j < sz){
        if(vec[i] == vec[j]){
            ++j;
        }
        else{
            ++i;
            vec[i] = vec[j];
            ++j;
        }
    }
    display(vec);
    return 0;
}