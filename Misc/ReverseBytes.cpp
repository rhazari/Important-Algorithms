#include <iostream>

using namespace std;

void displayBytes(uint32_t num){
    unsigned int mask = (1<<8)-1;
    for(int k = 0; k < 4; ++k){
        auto temp = (num & (mask<<8*k)) >> (8*k);
        cout<<temp<<" ";
    }
    cout<<"\n";
}

void reverseBytes(uint32_t num){
    unsigned int mask = (1<<8)-1;
    for(int k = 0; k < 2; ++k){
        int a = (num & mask<<8*k) >>(8*k);
        int b = (num & mask<<8*(3-k)) >>(8*(3-k));

        num &= ~(mask << 8*k);
        num |= b<<8*k;

        num &= ~(mask << 8*(3-k));
        num |= a<<8*(3-k);
    }
    displayBytes(num);
}

int main(){
    uint32_t num = 987651234;
    displayBytes(num);
    reverseBytes(num);
}