#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(0 == a)
        return b;
    gcd(b%a, a);
}

int main(){
    cout<<gcd(4, 6)<<"\n";
    cout<<gcd(5, 9)<<"\n";
    cout<<gcd(7, 21)<<"\n";
    cout<<gcd(6, 9)<<"\n";
}