#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 5
#define L 20

typedef struct
{
    int *array;
    int length;
    int sum;
}
MyData;

MyData mData;
pthread_t myThread[N];
pthread_mutex_t mutex;

void *threadWork(void *arg)
{
    int offset = (int)arg;
    int j, sum = 0;
    int start, end;
    start = offset*mData.length;
    end = start + mData.length;

    for( j = start; j < end; j++ )
    {
        sum += mData.array[j];
    }
    printf("Thread id: %d, Sum calculated: %d\n",offset, sum);
    
    pthread_mutex_lock(&mutex);
    mData.sum += sum;
    pthread_mutex_unlock(&mutex);
    
    pthread_exit((void*) 0);
}

int main()
{
    void *status;
    
    int k;
    int *a = (int*)malloc(sizeof(int)*L*N);
    for( k = 0; k < N*L; k++ )
    {
        a[k] = k+1; 
    }
    
    mData.length = L;
    mData.array = a;
    mData.sum = 0;

    pthread_mutex_init(&mutex, NULL);
    
    for( k = 0; k < N; k++    )
    {
        pthread_create(&myThread[k], NULL, threadWork, (void*)k );
    }

    for( k = 0; k < N; k++ )
    {
        pthread_join(myThread[k], &status);
    }

    printf("Total sum from threads = %d\n", mData.sum);
    free(a);
    
    pthread_mutex_destroy(&mutex);
    pthread_exit(NULL);
    
    return 0;
}
