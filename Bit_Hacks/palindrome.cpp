#include <iostream>
#include <cstdio>

using namespace std;

int isPalindrome(unsigned int num)
{
    int size = sizeof(unsigned int)*8;
    int left = 0, right = size-1, flag = 1;
    
    while(left < right)
    {
        if(((num>>left) & 1)^((num>>right) & 1) == 1)
        {
            cout << left <<" : "<< right<<endl; 
            flag = 0;
        }
        left++;
        right--;
    }
    return flag;
}

int main()
{
    unsigned int num = (1<<15) + (1<<17);
    //cout <<"Enter a number"<<endl;
    //cin >> num;
    printf("%u\n", num);
    
    if(isPalindrome(num))
    {
        cout << num <<": is a palindrome"<<endl;
    }
    else
    {
        cout << num<<": is not a palindrome"<<endl;
    }
    
    return 0;
}
