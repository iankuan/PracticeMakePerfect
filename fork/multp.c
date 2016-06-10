#include <stdio.h>
#include <unistd.h>


int main( int argc, char **argv){

	pid_t pid;
	pid = fork();
	int i;
	if( pid > 0){
		wait();/*wait for CHILD complete*/
		for( i = 0; i < 3; i++)
			printf("I am parent my child is %d\n", pid);
	}
	/*TODO: fork() create another PROCESS, so not affected by retrun*/
	else if( pid == 0){
		for( i = 0; i < 8; i++)
			printf("I am child\n");
		exit(0);
	}
	else{

		perror("fork");
		exit(0);
	}
}
