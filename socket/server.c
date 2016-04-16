#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

#define QLEN 3

typedef int skfd;
void serv( void *);

int main(){

skfd serv_sfd, clt_sfd;
struct sockaddr_in servip, clntip[QLEN];
int sq;


typedef struct tpool{

	pthread_t tid[QLEN];
}pool;

pool * t_pool = ( pool *) malloc (sizeof( pool));



int cilent_quit_msg;

/*int socket(int domain, int type, int protocol);*/
if( serv_sfd = socket( PF_INET, SOCK_STREAM, 0) < 0){/*save return socket descriptor*/
	
	perror("socket");
	exit(0);
}

printf("socket fd : %d  %u\n", serv_sfd, serv_sfd);

servip.sin_family = AF_INET;
servip.sin_port = htons(0);
servip.sin_addr.s_addr = INADDR_ANY;

if ( bind( serv_sfd, &servip, sizeof(servip)) < 0)/*know about my ip*/
{
	perror("bind");
	exit(0);
}

sq = 0;
listen(serv_sfd, QLEN );/*let wait queue be one ,because we just use one client*/

while(1){

	clt_sfd = accept( serv_sfd, &clntip[sq], sizeof( struct sockaddr_in));
	
	/*pthread( &t_pool->tid[sq], NULL, &serv, (void *) &clt_sfd);*/

	printf("Hellow clnt[%d]\n\n", sq);
	
	sq++;
}

close (serv_sfd);

return 0;

}

void serv(void* p_sfd){

	while(1){
		;
	}
	/*skfd clt_skfd =  *( (skdf *) p_sfd);

	char *buffer;

	while(1){
 
		if (read(clt_skfd, &buffer, sizeof( buffer))==0)
		
		text =(char*) malloc(len);
	
		read(client_socketfd,text,len);
		printf("%s\n",text);
	
		if (strcmp(text,"Q"))
			break;
 }*/
}
