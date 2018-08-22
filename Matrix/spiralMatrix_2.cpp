#include <iostream>

#define N 4
using namespace std;

int main(){

    int **array = new int*[N];

    int j, k;
    for(j = 0; j < N; ++j){
        array[j] = new int[N];
    }

    int row, value = 1;
    row = N;
    int x = 0, y = 0;

    while(row > 0){

        for(k = 0; k < row-1; ++k){
            array[x][y++] = value++;
        }

        for(k = 0; k < row-1; ++k){
            array[x++][y] = value++;
        }

        for(k = 0; k < row-1; ++k){
            array[x][y--] = value++;
        }

        for(k = 0; k < row-1; ++k){
            array[x--][y] = value++;
        }

        x++; y++;
        row -= 2;
    }

    cout<<endl;
    cout<<"N x N Spiral Matrix ..."<<endl;
    for(j = 0; j < N; ++j){
        for(k = 0; k < N; ++k){
            cout<<array[j][k]<<"";
        }
        cout<<endl;
    }
    return 0;
}