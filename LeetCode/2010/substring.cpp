#include <iostream>
#include <cstring>
#define SZ 50

using namespace std;

int main()
{
    char *s1 = new char(SZ);
    char *s2 = new char(SZ);
    
    cout<<"Enter the primary string"<<endl;
    cin >> s1;
    
    cout<<"Enter the second string"<<endl;
    cin >> s2;
    
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    char *ptr, *p1, *p2;
    ptr = s1;
    while(*ptr && len1 >= len2)
    {
        int count = 0;
        if(*s1 == *s2)
        {
            p1 = s1;
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
            cout<<s2<<" is a substring of "<<s1<<endl;
            break;
        }
        ptr++;
        --len1;
    }
    
    return 0;
}
