#include <stdio.h>
#include <fcntl.h>
#include <semaphore.h>

#include "debug.h"

int main(int argc, char *argv[]){

	sem_t *tes_sem;
    
    //sem_unlink(argv[1]);
    syserr(
        (tes_sem = sem_open(argv[1], O_CREAT | O_EXCL, 0666, 1)) == SEM_FAILED,
        "sem_open");

	int sem_v;
	sem_getvalue(tes_sem, &sem_v);
	printf("sem valure is : %d\n", sem_v);

	sem_post(tes_sem);
	/*sem_trywait( &tes_sem);*/
	sem_getvalue(tes_sem, &sem_v);
	printf("trywait sem valure is : %d\n", sem_v);

	/*sem_post( &tes_sem);*/
	sem_trywait( tes_sem);
	sem_getvalue( tes_sem, &sem_v);
	printf("trywait sem valure is : %d\n", sem_v);

    sem_close(tes_sem);
    sem_unlink(argv[1]);
}
