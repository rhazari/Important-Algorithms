#include <iostream>
#define SZ 6
using namespace std;

int main()
{
    int arr[SZ] = {2,2,6,5,1,4};
    int min, buy, sell;
    int i, max_value = 0;
    min = arr[0];
    for(i = 0; i < SZ; i++)
    {
        if(arr[i] < arr[min])
        {
            min = i;
        }
        if(arr[i] - arr[min] > max_value)
        {
            max_value = arr[i] - arr[min];
            buy = min;
            sell = i;
        }
    }
    
    cout<<"Buy value: "<<arr[buy]<<endl;
    cout<<"Sell value: "<<arr[sell]<<endl;
    cout<<"Max profit: "<<max_value<<endl;
    return 0;
}
