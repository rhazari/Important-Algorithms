/*
    *
   ***
  *****
 *******
*********
*/
#include <iostream>

using namespace std;

void func(int N){
    for(int k = 1; k <= N; ++k){
        int len = 2*k-1;
        int spaces = N-k;
        for(int j = 0; j < spaces; ++j){
            cout<<" ";
        }
        for(int j = 0; j < len; ++j){
            cout<<"*";
        }
        cout<<"\n";
    }
}

int main(){
    func(5);
}
