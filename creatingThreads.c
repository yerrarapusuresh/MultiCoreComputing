#include <stdio.h>
#include <pthread.h>


#define NUM_OF_THREADS 10
int j;
void * sampleThreadFunction(int num)
{
	
	printf("thread number %d\n",(int)num );
	pthread_exit(NULL);
}

int main()
{
	pthread_t threads[NUM_OF_THREADS];
	int i = 0;
	int j = 0;
	for(; i < NUM_OF_THREADS; i++)
		pthread_create(&threads[i], NULL, sampleThreadFunction, (void *)i);
	for(i = 0; i < NUM_OF_THREADS; i++)
		pthread_join(threads[i], NULL);
	
}