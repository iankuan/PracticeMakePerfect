#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mqueue.h>
#include <fcntl.h>


#include "debug.h"

int main(int argc, char *argv[])
{
    mqd_t mqd;
    unsigned int rec_prio;
    struct mq_attr attr;
    char *buf;

    if(argc < 2)
        elog("arg[1] = mq_name");
 
    syserr(
        (mqd = mq_open(argv[1], O_RDONLY| O_NONBLOCK)) < 0,
        "mq_open\n");

    syserr(
        mq_getattr(mqd, &attr) < 0,
        "mq_getattr");

    
    syserr(
        (buf = (char *) malloc(attr.mq_msgsize)) == NULL,
        "malloc");

    syserr(
        mq_receive(mqd, buf, attr.mq_msgsize, &rec_prio) < 0,
      /*mq_receive(mqd, buf, sizeof(buf), &rec_prio) < 0, FIXME: why fault? Ans: ... sizeof(buf) = 8*/
        "mq_recieve");

    printf("Reciever get: %s", buf);

    syserr(
        mq_close(mqd),
        "mq_close");

    syserr(
        mq_unlink(argv[1]),
        "mq_unlink");
}

