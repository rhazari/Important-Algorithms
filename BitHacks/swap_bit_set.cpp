//Program to swap n bits from 2 positions of a number
#include <iostream>
#include <cmath>

using namespace std;

int swap_bitSet(int num, int x, int y, int z)
{
    int mask = (1<<z)-1;
    int a1 = num & mask << x;
    int a2 = num & mask << y;
    int a3 = num & ~(mask << x | mask << y);
    
    return (a3 | a1 <<(y-x) | a2 >> (y-x));
}

int main()
{
    int num, p1, p2, n;
    cout << "Enter a number"<<endl;
    cin >> num;
    
    cout << "Enter the two positions where the swap occurs"<<endl;
    cin >> p1 >> p2;
    
    cout << "The number of bits to swap?"<<endl;
    cin >> n;
    
    cout << swap_bitSet(num,p1,p2,n)<<endl;
    return 0;
}

