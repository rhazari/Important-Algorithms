#include <iostream>

using namespace std;

void rotate_array(char *array, int start, int end)
{
    char temp;
    while(start < end)
    {
        temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    char str_array[7] = {'a','b','c','d','e','f','g'};
    rotate_array(str_array,0,6);
    rotate_array(str_array,0,2);
    rotate_array(str_array,3,6);
    
    int k;
    for(k = 0; k < 7; k++)
    {
        cout<<str_array[k]<<" ";
    }
    cout<<endl;
    return 0;
}
