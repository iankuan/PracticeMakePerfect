#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <errno.h>

#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
} while (0)

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void func(void *arg) {
    struct timespec tm = {
        .tv_sec = 100000,
        .tv_nsec = 0,
        };

    int msg = pthread_mutex_timedlock(&mtx, &tm);
    //int msg = pthread_mutex_trylock(&mtx);

    if (msg != 0) {
        printf("msg = %d\n", msg);
        /* pthread_mutex_timedlock() don't set errno automatically */
        errno = msg;
        perror("pthread_mutex_timedlock\n");
    }

    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    pthread_t thrd;

    /* Lock it first */
    pthread_mutex_lock(&mtx);

    pthread_create(&thrd, NULL, (void *) &func, NULL);

    int msg = pthread_join(thrd, NULL);
    if (msg != 0) {
        printf("msg = %d\n", msg);
        /* pthread_mutex_timedlock() don't set errno automatically */
        errno = msg;
        perror("pthread_join\n");
    }

    pthread_mutex_unlock(&mtx);

    return 0;
}
