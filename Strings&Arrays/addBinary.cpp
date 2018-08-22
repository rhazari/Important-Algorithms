#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void binary(int value){
    int rem;

    if(value <= 1){
        cout<<value;
        return;
    }
    rem = value%2;
    binary(value>>1);
    cout<<rem;
}

int stringToDec(char* str){
    int len;
    len = strlen(str);
    int k = 0, decNum = 0;
    while(k < len){
        if('1' == str[k]){
            decNum += pow(2.0,len-k-1);
        }
        ++k;
    }
    return decNum;
}

int main() {
    char s1[] = "110";
    char s2[] = "11";

    cout<<"Binary sum of "<<s1 <<" & "<<s2<<endl;
    binary(stringToDec(s1)+stringToDec(s2));
    cout<<endl;

    return 0;
}