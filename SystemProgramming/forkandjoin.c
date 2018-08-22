#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> //exit
#include <sys/wait.h> //wait

int main(){
    pid_t child = fork();
    if (child < 0){
        perror("fork() error\n");
        exit(-1);
    }
    if(child != 0){
        printf("I am the parent: %d, my child is: %d\n",getpid(), child);
        wait(NULL);
    }
    else{
        printf("I am the child: %d, my parent is: %d\n",child, getppid());
        execl("/bin/echo","echo","Hello World!", NULL);
    }

    return 0;
}