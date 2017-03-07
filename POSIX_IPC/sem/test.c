#include <stdio.h>
#include <semphore.h>


int main (int argc, char *argv[])
{
int value;
int rc = 0;
sem_t test_semaphore;
sem_init(&test_semaphore, 0, 1);
sem_getvalue(&test_semaphore, &value);
printf("The value of semaphore is %d\n", value);
while(rc == 0 & (value < 2147483647 & value > 0) )
{
rc = sem_post(&test_semaphore);
sem_getvalue(&test_semaphore, &value);
}

printf("sem_post returns %d\n", rc);
printf("The value of semaphore is %d\n", value);
rc = sem_post(&test_semaphore);
sem_getvalue(&test_semaphore, &value);
printf("sem_post returns %d\n", rc);
printf("The value of semaphore is %d\n", value);
}int main (int argc, char *argv[])
{
int value;
int rc = 0;
sem_t test_semaphore;
sem_init(&test_semaphore, 0, 1);
sem_getvalue(&test_semaphore, &value);
printf("The value of semaphore is %d\n", value);
while(rc == 0 & (value < 2147483647 & value > 0) )
{
rc = sem_post(&test_semaphore);
sem_getvalue(&test_semaphore, &value);
}

printf("sem_post returns %d\n", rc);
printf("The value of semaphore is %d\n", value);
rc = sem_post(&test_semaphore);
sem_getvalue(&test_semaphore, &value);
printf("sem_post returns %d\n", rc);
printf("The value of semaphore is %d\n", value);
}
