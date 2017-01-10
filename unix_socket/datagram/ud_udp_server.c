#include "ud.h"

int main(int argc, char **argv)
{
    struct sockaddr_un ser_addr, cli_addr;

    int ser_fd;
    socklen_t len;
    char buf[BUF_SIZE];
    ssize_t nBytes;


    ser_fd = socket(AF_UNIX, SOCK_DGRAM, 0);
    syserr(ser_fd == -1, "socket\n");

    syserr(remove(UN_SOCK_PATH) == -1 && errno != ENOENT, "Can't remove socket\n")

    //init
    memset(&ser_addr, 0, sizeof(struct sockaddr_un));
    ser_addr.sun_family = AF_UNIX;
    strncpy(ser_addr.sun_path, UN_SOCK_PATH, sizeof(ser_addr.sun_path) - 1);

    ///bind
    ///FIXME: second argument should take care
    //syserr(bind(ser_fd, &ser_addr, sizeof(struct sockaddr_un)) == -1, "bind\n");
    syserr(bind(ser_fd, (struct sockaddr *) &ser_addr, sizeof(struct sockaddr_un)) == -1, "serv bind\n");

    ///work
    while(1)
    {
        len = sizeof(struct sockaddr_un);
        nBytes = recvfrom(ser_fd, buf, BUF_SIZE, 0, (struct sockaddr *) &cli_addr, &len);
        syserr(nBytes == -1,  "serv recvfrom\n");

        printf("Server recived %ld bytes from %s\n", (long) nBytes, cli_addr.sun_path);

        for(int i = 0; i < nBytes; i++)
            buf[i] = toupper(buf[i]);

        syserr(sendto(ser_fd, buf, nBytes, 0, (struct sockaddr *) &cli_addr, len) != nBytes, "serv sendto\n");
    }

    syserr(1,"out of while loop\n");
}
