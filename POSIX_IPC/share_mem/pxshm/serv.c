#include "cliserv.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void err_exit( const char *msg)
{
	perror( msg);
	exit( EXIT_FAILURE);
}

int main( int argc, char* argv[])
{
	int fd, index, lastnoverflow, temp;
	long offset;
	shmstruct *ptr ;///= ( shmstruct*) malloc( sizeof( shmstruct));

	if( argc != 2)
		err_exit("usage: server <name>");

	const char* shm = argv[1];
	shm_unlink( shm);
	fd = shm_open( shm, O_RDWR | O_CREAT | O_EXCL, 0666);

	ptr = mmap( NULL, sizeof( shmstruct), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	ftruncate( fd, sizeof( shmstruct));
	
	close( fd);

	///initialize
	for( index = 0; index < NMESG; index++)
		ptr->msgoff[index] = index * MESGSIZE;
	
	///thrid arg is the initialize value
	sem_init( ptr->mutex, 1, 1);
	sem_init( ptr->nempty, 1, NMESG);
	sem_init( ptr->nstored, 1, 0);
	sem_init( ptr->noverflowmutex, 1, 1);

	///Consumer
	index = 0;
	lastnoverflow = 0;

	while(1)
	{
		sem_wait( ptr->nstored);
		sem_wait( ptr->mutex);

		offset = ptr->msgoff[ index];
		printf( "index = %d: %s\n", index, &ptr->msgdata[ offset]);

		if( ++index >= NMESG)
			index = 0;

		sem_post( ptr->mutex);
		sem_post( ptr->nempty);

		sem_wait( ptr->noverflowmutex);
		temp = ptr->noverflow;

		if( temp !=  lastnoverflow)
		{
			printf("noverflow = %d\n", temp);
			lastnoverflow = temp;
		}
	}

	exit(0);
}

