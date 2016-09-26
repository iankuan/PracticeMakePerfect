#define _GNU_SOURCE //pthread_setconcurrency()

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <unistd.h>
#include <pthread.h>

#define MAXNITEMS 100000
#define MAXNTHREADS	 100

#define Min( x, y) (x > y? y: x)

/* number of items we have*/
int nitems; /* read-only by producer and consumer*/

/* public data for produce and consume */
struct{
	pthread_mutex_t mutex;
	int buff[ MAXNITEMS];
	int nput;
	int nval;
} shared = {
	PTHREAD_MUTEX_INITIALIZER
};

void *produce( void*), *consume( void*);

int main( int argc, char** argv)
{
	int i, nthreads, count[ MAXNTHREADS];

	pthread_t tid_produce[ MAXNTHREADS], tid_consume;

	assert( argc == 3 && "usage: prodcons2 <#item> <#thread>");

	nitems = Min( atoi( argv[1]), MAXNITEMS);
	nthreads = Min( atoi( argv[2]), MAXNTHREADS);

	pthread_setconcurrency( nthreads + 1);

	for ( int i = 0; i < nthreads; i++){
		count[i] = 0;
																				/*Notice we should use &, functio is kind of data, we should */
																						 /*v*/
		pthread_create( &tid_produce[i], NULL, &produce, &count[i]);
	}

	for ( int i = 0; i < nthreads; i++){
		pthread_join( tid_produce[i], NULL);
		printf("count[ %d] = %d\n", i, count[i]);
	}

	pthread_create( &tid_consume, NULL, &consume, NULL);
	pthread_join( tid_consume, NULL);

	return 0;
}

void *
produce( void *arg)
{
	while( 1){
		pthread_mutex_lock( &shared.mutex);

		if( shared.nput >= nitems){
			pthread_mutex_unlock( &shared.mutex);
			return NULL;
		}

		shared.buff[ shared.nput] = shared.nval;
		shared.nput++;
		shared.nval++;

		pthread_mutex_unlock( &shared.mutex);

		*((int *) arg) += 1;
	}
}

void *
consume( void *arg)
{
	for( int i = 0; i < nitems; i++)
		if( shared.buff[i] != i)
			printf( "buff[%d] = %d\n", i, shared.buff[i]);

	return NULL;
}
