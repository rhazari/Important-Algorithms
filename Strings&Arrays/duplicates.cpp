#include <iostream>
#include <cstdlib>

using namespace std;

void printDuplicates(int *ar, int size){
    int k;
    for(k = 0; k < size; ++k){
        if(ar[abs(ar[k])] > 0){
            ar[abs(ar[k])] = -ar[abs(ar[k])];    
        }
        else{
            cout<<abs(ar[k])<<"";
        }
    }
    cout<<endl;
}

int main(){

    int arr[] = {1,2,3,1,3,6,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    //cout<<size<<endl;
    printDuplicates(arr, size);
    return 0;
}