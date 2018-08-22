//Find the maximum sum of a contiguous subarray

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int array[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int length; 
    length = sizeof(array)/sizeof(int);
    
    int *sum = new int[length];
    sum[0] = array[0];

    int k, max_value = 0;
    for( k = 1; k < length; ++k ){
        sum[k] = max(array[k], array[k]+sum[k-1]);
        max_value = max(max_value, sum[k]);
    }

    cout<<"Max Sum: "<<max_value<<endl;

    return 0;
}