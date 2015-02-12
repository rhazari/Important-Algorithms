#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int num;
    cout <<"Enter a number"<<endl;
    cin >> num;
    
    int divisor, remainder;
    divisor = num;
    stack<char> my_q;
    if(num >= 0 && num <= 25)
    {
        char buff = 'a'+num;
        cout<<buff<<endl;
    }
    else
    {
        while(divisor)
        {
            if(divisor > 0 && divisor <= 26)
            {
                my_q.push('a'+divisor-1);
                break;    
            }
            else
            {
                remainder = divisor%26;
                my_q.push('a'+remainder);
            }
            divisor = divisor/26;
        }
    
        while(!my_q.empty())
        {
            cout<<my_q.top();
            my_q.pop();
        }
        cout<<endl;
        return 0;
    }
}
