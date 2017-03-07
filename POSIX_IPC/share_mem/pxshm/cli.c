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
#include <errno.h>

void err_exit( const char *msg)
{
	perror( msg);
	exit( EXIT_FAILURE);
}

int main( int argc, char* argv[])
{
	int fd, i, nloop, nusec;
	pid_t pid;
	char mesg[MESGSIZE];
	long offset;
	shmstruct *ptr;

	if( argc != 4)
		err_exit("usage: cli <name> <#loops> <#usec>");

	nloop = atoi( argv[2]);
	nusec = atoi( argv[3]);

	///open and map shared memory
	fd = shm_open( argv[1], O_RDWR, 0666);
	ptr = mmap( NULL, sizeof( shmstruct), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	close(fd);


	pid = getpid();
	for( i = 0; i < nloop; i++)
	{
		usleep( nusec);///< sleep for microsecond
		
		snprintf( mesg, MESGSIZE, "pid %ld: message %d", ( long) pid, i);

		if( sem_trywait( ptr->nempty) == -1)
		{
			if( errno == EAGAIN)
			{
				sem_wait( ptr->noverflowmutex);
				ptr->noverflow++;
				sem_post( ptr->noverflowmutex);
				continue;
			}
			else
				err_exit("sem_trywait error");
		}

		sem_wait( ptr->mutex);
		offset = ptr->msgoff[ ptr->nput];

		if( ++(ptr->nput) >= NMESG)
			ptr->nput = 0;

		sem_post( ptr->mutex);
		strcpy( &ptr->msgdata[ offset], mesg);
		sem_post( ptr->nstored);
	}

	exit(0);
}
