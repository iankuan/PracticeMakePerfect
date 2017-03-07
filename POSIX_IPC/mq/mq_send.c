#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mqueue.h>
#include <fcntl.h>


#include "debug.h"

int main(int argc, char *argv[])
{
    mqd_t mqd;
    struct mq_attr tmp_attr, old_attr, new_attr;
    unsigned int prio = 0;

    if(argc < 2)
        elog("arg[1] = mq_name");
    
    struct mq_attr attr = {
        .mq_flags   =    0,/// 0 => normal
        .mq_maxmsg  =   10,
        .mq_msgsize = 2048,
        .mq_curmsgs =    0,
    };

    syserr(
        (mqd = mq_open(argv[1], O_CREAT | O_EXCL | O_WRONLY, 0666, &attr)) < 0,
        "mq_open: Notice that Path should begin with '/', such as /mq_test \n");

    syserr(
        mq_getattr(mqd, &tmp_attr) < 0,
        "mq_getattr");

    new_attr = tmp_attr;
    new_attr.mq_flags = O_NONBLOCK;
    new_attr.mq_maxmsg = 20;

    syserr(
        mq_setattr(mqd, &new_attr, &old_attr) < 0,
        "mq_setattr\n");

    syserr(
        mq_getattr(mqd, &tmp_attr) < 0,
        "mq_getattr");


    dlog("mq_attr.flag = %d\n", tmp_attr.mq_flags);
    

    char msg[] = "Hello, I'm message queue sender\n";

    syserr(
        mq_send(mqd, msg, strlen(msg) + 1, prio) < 0,
        "mq_send\n");

    syserr(
        mq_close(mqd),
        "mq_close");
}
