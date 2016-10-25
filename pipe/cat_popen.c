#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>

#include "debug.h"

#define MAX_LINE_SIZE 8192

void print_wait_exit(int status)
{
    printf("status = %d\n", status);

    if(WIFEXITED(status))
        printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
    else if(WIFSIGNALED(status))
        printf("abnormal termination, signal number = %d%s\n",
            WTERMSIG(status),
#ifdef WCOREDUMP
            WCOREDUMP(status)?"core file generated" : "");
#else
            "");
#endif
}


int main(int argc, char *argv[])
{
    FILE *fp  = NULL;
    char cmd[MAX_LINE_SIZE], buf[MAX_LINE_SIZE];

    if(argc != 2)
    {
        elog("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    snprintf(cmd, sizeof(cmd), "cat %s", argv[1]);

    fp = popen(cmd, "r");//TODO: init shell pipe just like " | "
    syserr(!fp, "popen");

    while(fgets(buf, MAX_LINE_SIZE, fp))
        fprintf(stdout, "%s", buf);

    int ret = pclose(fp);

    if(ret == 127)
    {
        elog("bad command:%s\n", cmd);
        exit(EXIT_FAILURE);
    }
    else if(ret == -1)
        syserr(ret == -1, "pclose");
    //else
        print_wait_exit(ret);
    
    return 0;
}
