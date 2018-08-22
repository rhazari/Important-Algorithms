#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s;

void *task(void* arg)
{
    printf("%s work completed\n",(char*)arg);
    sem_post(&s);
    
    //return NULL;
}

int main()
{
    sem_init(&s, 0, 0);
    
    printf("Main thread starts\n");
    pthread_t thread;
    pthread_create(&thread, 0, task, (void*)"Child thread");
    
    sem_wait(&s);
    printf("Main thread ends here\n");
    return 0;
}
