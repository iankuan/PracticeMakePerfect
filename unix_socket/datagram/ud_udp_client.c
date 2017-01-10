#include "ud.h"

int main(int argc, char **argv)
{
    struct sockaddr_un ser_addr, cli_addr;

    int cli_fd;
    socklen_t len;
    size_t msgLen;
    char resp[BUF_SIZE];
    ssize_t nBytes;

    syserr(argc < 2, "argc < 2");

    cli_fd = socket(AF_UNIX, SOCK_DGRAM, 0);
    syserr(cli_fd == -1, "socket\n");

    //syserr(remove(UN_SOCK_PATH) == -1 && errno != ENOENT, "Can't remove socket\n")

    //init client
    memset(&cli_addr, 0, sizeof(struct sockaddr_un));
    cli_addr.sun_family = AF_UNIX;
    //TODO: take care
    snprintf(cli_addr.sun_path, sizeof(cli_addr.sun_path),
                "/tmp/ud_udp_client.%ld", (long) getpid());

    syserr(bind(cli_fd, (struct sockaddr *) &cli_addr, sizeof(struct sockaddr_un)) == -1, "client bind\n");

    //construct server
    memset(&ser_addr, 0, sizeof(struct sockaddr_un));
    ser_addr.sun_family = AF_UNIX;
    strncpy(ser_addr.sun_path, UN_SOCK_PATH, sizeof(ser_addr.sun_path) - 1);
 
    //work
    for(int i; i < argc; i++) {
        msgLen = strlen(argv[i]);
        len = sizeof(struct sockaddr_un);
        
        syserr(sendto(cli_fd, argv[i], msgLen, 0, (struct sockaddr *) &ser_addr, len) != msgLen, "client sendto\n");

        nBytes  = recvfrom(cli_fd, resp, BUF_SIZE, 0, NULL, NULL);
        syserr(nBytes == -1,  "cleint recvfrom\n");
        
        printf("Response %d: %.*s\n", i, (int) nBytes, resp);
    }

    syserr(remove(cli_addr.sun_path) == -1 && errno != ENOENT, "Can't remove socket\n")
}
