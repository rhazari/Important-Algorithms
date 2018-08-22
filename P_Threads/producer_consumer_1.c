#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX 100

sem_t empty;
sem_t full;
int loop;

int buffer[MAX];
int fill = 0;
int use = 0;

void put(int value)
{
    buffer[fill] = value;
    fill = (fill+1)%MAX;
} 

int get()
{
    int b = buffer[use];
    use = (use+1)%MAX;
    return b;    
}

void *producer(void* arg)
{
    int i;
    for( i = 0; i < loop; i++)
    {
        sem_wait(&empty);
        put(i);
        sem_post(&full);
    }    
}

void *consumer(void* arg)
{
    int i;
    for( i = 0; i < loop; i++)
    {
        sem_wait(&full);
        printf("%d\n",get());
        sem_wait(&empty);
    }
}

int main()
{
    printf("Enter a number less than 100\n");
    scanf("%d",&loop);
    
    sem_init(&empty, 0, MAX);
    sem_init(&full, 0, 0);

    pthread_t prod, cons;
    pthread_create(&prod, 0, producer, 0);
    pthread_create(&cons, 0, consumer, 0);
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    return 0;
}
