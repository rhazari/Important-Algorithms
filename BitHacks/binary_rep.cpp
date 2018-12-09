#include <iostream>

using namespace std;

void binary_rep(unsigned int val)
{
    int size, k;
    size = sizeof(val)*8;
    for(k = size; k > 0; --k)
    {
        (val & 1<<(k-1)) ? cout <<"1" : cout <<"0";
    }
    cout << endl;
}

int main()
{
    unsigned int num;
    cout <<"Enter a number"<< endl;
    cin >> num;
    binary_rep(num);
    
    return 0;
}
