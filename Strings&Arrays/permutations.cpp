#include <iostream>

using namespace std;

void swap(string &str, int a1, int a2){
    char tmp = str[a1];
    str[a1] = str[a2];
    str[a2] = tmp;
}

void permutate(string &str, int left, int right){
    static int count;
    if(left == right){
        cout<<++count<<": "<<str<<endl;
        return;
    }
    else{
        for(int k = left; k <= right; ++k){
            swap(str,left,k);
            permutate(str,left+1, right);
            swap(str,left,k);
        }
    }
}

int main(){
    string str("Raihan");
    permutate(str, 0, str.size()-1);
    return 0;
}