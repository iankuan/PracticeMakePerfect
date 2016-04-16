#include <stdio.h>
#include <unistd.h>


int main( int argc, char **argv){

	pid_t pid;
	pid = fork();
	if( pid > 0){

		printf("I am parent my child is %d\n", pid);
	}
	else if( pid == 0){

		printf("I am child\n");
		exit(0);
	}
	else{

		perror("fork");
		exit(0);
	}
}
