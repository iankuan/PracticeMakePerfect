#include <stdio.h>
#include <semaphore.h>

int main(){

	sem_t tes_sem;
	sem_init( &tes_sem, 0, 1);

	int sem_v;
	sem_getvalue( &tes_sem, &sem_v);
	printf("sem valure is : %d\n", sem_v);

	sem_post( &tes_sem);
	/*sem_trywait( &tes_sem);*/
	sem_getvalue( &tes_sem, &sem_v);
	printf("trywait sem valure is : %d\n", sem_v);

	/*sem_post( &tes_sem);*/
	sem_trywait( &tes_sem);
	sem_getvalue( &tes_sem, &sem_v);
	printf("trywait sem valure is : %d\n", sem_v);
}
