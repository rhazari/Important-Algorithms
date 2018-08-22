#include <unistd.h>
#include <stdio.h>

int main(){
    int x = 1;
    if(fork() == 0){
        //Only child executes here
        printf("Child, x = %d\n",++x);
    }
    else{
        //Parent executes here
        printf("Parent, x = %d\n",--x);
    }

    printf("Both parent and child are here. Exiting with x = %d\n",x);

    return 0;
}