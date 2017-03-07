#include <semaphore.h>

#define MESGSIZE	256
#define NMESG		16

typedef struct shmstruct
{
	sem_t*	mutex;
	sem_t* nempty;
	sem_t*	nstored;
	int		nput;
	long 	noverflow;
	sem_t* noverflowmutex;
	long msgoff[ NMESG];
	char msgdata[ NMESG * MESGSIZE];
}shmstruct;
