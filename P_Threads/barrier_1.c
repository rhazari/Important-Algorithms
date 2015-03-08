#include <stdio.h>
#include <pthread.h>

pthread_barrier_t b;

void task(void* arg)
{
	int id = (int)arg;
	printf("Before the barrier, thread id: %d\n", id);
	pthread_barrier_wait(&b);
	printf("After the barrier, thread id: %d\n", id);
}

int main()
{
	int nThread = 5;
	int i; 

	pthread_t thread[nThread];
	pthread_barrier_init(&b,0,nThread);
	
	for( i = 0; i < nThread; i++ )
	{
		pthread_create(&thread[i], NULL, task, (void*)i);
	}
	
	for( i = 0; i < nThread; i++)
	{
		pthread_join(thread[i], 0);
	}

	pthread_barrier_destroy(&b);
	pthread_exit(NULL);	
	return 0;
}
