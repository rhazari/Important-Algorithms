#include <iostream>
#include <cstring>

#define SZ 50
using namespace std;

int main()
{
    char *s1 = new char(SZ);
    char *s2 = new char(SZ);
    
    cout<<"Enter a primary string"<<endl;
    cin >> s1;
    
    cout <<"Enter the string pattern"<<endl;
    cin >> s2;
    
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *p1, *p2, *fast_ptr, *slow_ptr;
    fast_ptr = s1;
    slow_ptr = s1; 
    while(*fast_ptr)
    {
        int count = 0;
        if(*fast_ptr == *s2)
        {
            p1 = fast_ptr;
            p2 = s2;
            while(*p2 && *p1 == *p2)
            {
                p1++;
                p2++;
                count++;
            }
        }
        if(count == len2)
        {
            fast_ptr += len2;
            *slow_ptr++ = 'X';
        }
        if(fast_ptr != NULL)
        {
            *slow_ptr = *fast_ptr;
        }
    }
    *slow_ptr = '\0';
    
    cout<<"The new string pattern: "<<s1<<endl;
    return 0;
}
