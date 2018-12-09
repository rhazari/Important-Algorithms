//Program to swap even odd bits
#include <iostream>

using namespace std;

unsigned int swap_bits(unsigned int val)
{
    unsigned odd_bits = val & 0x55555555;
    unsigned even_bits = val & 0xAAAAAAAA;
    
    odd_bits <<= 1;
    even_bits >>= 1;
    
    return (odd_bits | even_bits);
}


int main()
{
    unsigned int num;
    cout << "Enter a number"<<endl;
    cin >> num;
    
    cout<<swap_bits(num)<<endl;
    return 0;
}
