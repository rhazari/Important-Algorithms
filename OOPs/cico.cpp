#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

vector<int> v;

class new_ds
{
    int counter = 0;
    
    public:
    int checkout()
    {
        counter++;
        if(v.empty())
        {
            return counter;
        }
        else
        {
            if( counter < v.front() )
            {
                return counter;
            }
            else
            {
                int temp = v.front();
                pop_heap(v.begin(),v.end(),less<int>());
                v.pop_back();
                counter--;
                return temp;
            }
        }
    }
    
    void checkin(int value)
    {
        v.push_back(value);
        push_heap(v.begin(),v.end(),less<int>());
    }
};

int main()
{
    make_heap(v.begin(),v.end(),less<int>());
    new_ds D1;
    cout << D1.checkout() << endl;
    cout << D1.checkout() << endl;
    cout << D1.checkout() << endl;
}
