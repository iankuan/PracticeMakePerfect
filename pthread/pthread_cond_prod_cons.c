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
int buff[ MAXNITEMS];

/* public data for produce and consume */
struct{
	pthread_mutex_t mutex;
	int nput;
	int nval;
} put = {
		PTHREAD_MUTEX_INITIALIZER
};

struct{
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	int nready;
}	nready = {
		PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER
};

void *produce( void*), *consume( void*);

int main( int argc, char** argv)
{
	int i, nthreads, count[ MAXNTHREADS];

	pthread_t tid_produce[ MAXNTHREADS], tid_consume;

	assert( argc == 3 && "usage: prodcons2 <#item> <#thread>");

	nitems = Min( atoi( argv[1]), MAXNITEMS);
	nthreads = Min( atoi( argv[2]), MAXNTHREADS);

	pthread_setconcurrency( nthreads + 1);//

	for ( int i = 0; i < nthreads; i++){
		count[i] = 0;
																				/*Notice we should use &, functio is kind of data, we should */
																						 /*v*/
		pthread_create( &tid_produce[i], NULL, &produce, &count[i]);
	}

	pthread_create( &tid_consume, NULL, &consume, NULL);

	for ( int i = 0; i < nthreads; i++){
		pthread_join( tid_produce[i], NULL);
		printf("count[ %d] = %d\n", i, count[i]);
	}

	pthread_join( tid_consume, NULL);

	return 0;
}

void *
produce( void *arg)
{
	while( 1){
		pthread_mutex_lock( &put.mutex);

		if( put.nput >= nitems){
			pthread_mutex_unlock( &put.mutex);
			return NULL;
		}

		buff[ put.nput] = put.nval;
		put.nput++;
		put.nval++;

		pthread_mutex_unlock( &put.mutex);

		pthread_mutex_lock( &nready.mutex);
		if( nready.nready == 0)
			pthread_cond_signal( &nready.cond);//only wake up one mutex
			//pthread_cond_broadcast( &nready,cond); //It will wake all up

		nready.nready++;
		pthread_mutex_unlock( &nready.mutex);

		*((int *) arg) += 1;
	}
}

void *
consume( void *arg)
{
	for( int i = 0; i < nitems; i++){
		pthread_mutex_lock( &nready.mutex);

		while( nready.nready == 0)
			pthread_cond_wait( &nready.cond, &nready.mutex);//wait for signal the condition

		nready.nready--;
		pthread_mutex_unlock( &nready.mutex);

		if( buff[i] != i)
			printf( "buff[%d] = %d\n", i, buff[i]);
	}

	return NULL;
}
