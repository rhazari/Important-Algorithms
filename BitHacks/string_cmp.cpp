//String comparison ignoring cases
#include <iostream>
#include <string>

using namespace std;

int string_comp(string s1, string s2)
{
    int flag = 1;
    size_t len1, len2;
    len1 = s1.size();
    len2 = s2.size();
    
    if (len1 != len2)
    {
        flag = 0;
    }
    else
    {
        for(string::size_type i = 0; i < len1; i++)
        {
            if(s1[i] == s2[i] || (s1[i] | 32) == (s2[i] | 32))
            {
                continue;
            }
            else
            {
                flag = 0;
            }
        }
    }
  
  return flag;  
}

int main()
{
    string s1, s2;
    cout << "Enter string 1"<<endl;
    cin >> s1;
    cout << "Enter string 2"<<endl;
    cin >> s2;
    
    if(string_comp(s1,s2))
    {
        cout << "Strings are equal" << endl;
    }
    else
    {
        cout << "String are not equal" << endl;
    }
    
    return 0;
}
