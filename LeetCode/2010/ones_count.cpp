#include <iostream>

using namespace std;

int main()
{
    unsigned int num;
    cout <<"Enter a number"<<endl;
    cin >> num;
    
    int count_ones = 0;
    while(num)
    {
        num = num & (num-1);
        count_ones++;
    }
    
    cout<<"The number of ones is: "<<count_ones<<endl;
    return 0;
}
