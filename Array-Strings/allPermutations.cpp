#include <iostream>
#include <cstring>
using namespace std;


void swap(char *x, char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *string, int j, int k){
    if( j == k ){
        cout<<string<<endl;
    }
    else{
        int i;
        for(i = j; i <= k; ++i){
            swap(string[i], string[j]);
            permute(string, j+1, k);
            swap(string[i], string[j]);
        }
    }
}

int main(){
    char stringArray[] = "ABC";
    int len = strlen(stringArray);
    permute(stringArray, 0, len-1);

    return 0;
}