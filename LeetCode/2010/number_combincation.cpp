#include <iostream>
#include <queue>
#define SZ 4

using namespace std;

int main()
{
    int arr[SZ] = {2,3,6,7};
    int k, j, target = 7;
    
    queue<int> my_q;
    
    for(k = SZ-1; k >= 0; --k)
    {
        int remain = target - arr[k];
        my_q.push(arr[k]);
        for(j = k; j >= 0; --j)
        {
            if(remain == 0)
            {
                while(!my_q.empty())
                {
                    cout<<my_q.front()<<" ";
                    my_q.pop();
                }
                cout<<endl;
                break;
            }
            else
            {
                if(remain < arr[0])
                {
                    my_q.pop();
                    if(my_q.empty())
                    {
                        break;
                    }
                    remain += arr[j+1];
                }
                while(remain >= arr[0])
                {
                    remain -= arr[j];
                    my_q.push(arr[j]);
                }
                if(remain == 0)
                {
                    while(!my_q.empty())
                    {
                        cout<<my_q.front()<<" ";
                        my_q.pop();
                    }
                    cout<<endl;
                    break;
                 }
            }
        }
    }
    return 0;
}
