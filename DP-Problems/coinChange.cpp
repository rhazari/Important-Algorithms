//The coin change problem
//The Minimum and Total coins required to sum to a total

#include <iostream>
#include <cstring>

#define INFI 10000

using namespace std;

int total_ways(int *array, int M, int sum){
    int *dp = new int[sum+1];
    memset(dp, 0, sizeof(dp));


    int j, k;

    dp[0] = 1;
    for(j = 0; j < M; ++j){
        for(k = array[j]; k <= sum; ++k){
            dp[k] += dp[k-array[j]]; 
        }
        /*for(k = 1; k <= sum; k++){
            cout<<dp[k]<<" ";
        }
        cout<<endl;*/
    }

    return dp[sum];

}

int min_ways(int *array, int M, int sum){
    int *dp = new int[sum+1];
    int j, k;

    for(j = 0; j <= sum; ++j){
        dp[j] = INFI;
    }

    dp[0] = 0;
    for(j = 0; j < M; ++j){
        for(k = array[j]; k <= sum; ++k){
            if(array[j] <= sum && dp[k-array[j]]+1 < dp[k]){
                dp[k] = dp[k-array[j]]+1;    
            }
        }
    }

    return dp[sum];

}

int main(){
    int coins[] = {2,3,5,6};
    int length = sizeof(coins)/sizeof(int);
    int sum = 10;

    cout<<"Total ways: "<<total_ways(coins, length, sum)<<endl;
    cout<<"Minimum ways: "<<min_ways(coins, length, sum)<<endl;


    return 0;
}