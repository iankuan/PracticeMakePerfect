#include <stdio.h>
#include <stdatomic.h>
#include <pthread.h>
#include <assert.h>

#define THREAD_COUNT 10000

void add_one(void* d)
{
	int *i = (int *) d;
	(*i)++;
	printf("counter = %d\n", *i);
}

int main(int argc, char* argv[])
{
	//_Atomic int counter = ATOMIC_VAR_INIT(0);
	int counter = 0;

	//_Atomic int _Atomic *counter;
	//*counter = ATOMIC_VAR_INIT(0); FIXME:SEG FAULT
	//*counter = 0;FIXME:SEG FAULT

	//_Atomic int* pi; // pointer to atomic int
	//int* _Atomic pi; // atomic pointer (to int)

	pthread_t tid[THREAD_COUNT];

	for(int i = 0; i < THREAD_COUNT; i++)
		pthread_create(tid + i, NULL, (void *) &add_one, (void *) &counter);

	for(int i = 0; i < THREAD_COUNT; i++)
		pthread_join(tid[i], NULL);

  assert(counter == THREAD_COUNT);
	return 0;
}
