#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> arr(6);
    arr.push_back(-1);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(-1);
    arr.push_back(4);
    
    int sz = arr.size();
    sort(arr.begin(),arr.end());
    set <vector<int> > triplets;
    vector<int> triplet(3);
    
    int i, j, k, sum;
    for(i = 0; i< sz; i++)
    {
        j = i+1;
        k = sz-1;
        while(j<k)
        {
            sum = arr[i]+arr[j];
            if(sum+arr[k] < 0)
            {
                j++;
            }
            else if(sum+arr[k] > 0)
            {
                k--;
            }
            else
            {
                triplet[0] = arr[i];
                triplet[1] = arr[j];
                triplet[2] = arr[k];
                triplets.insert(triplet);
                j++; k--;                
            }
        }
    }
    
    for(set<vector<int> >::iterator it = triplets.begin(); it != triplets.end(); it++)
    {
        for(vector<int>::const_iterator tt = it->begin(); tt != it->end(); tt++)
        {
            cout<<*tt<<" ";
        }
        cout<<endl;
    }
    return 0;
}

