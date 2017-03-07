#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/mman.h>
#include <sys/wait.h>

void err_exit( const char *msg)
{
	perror( msg);
	exit( EXIT_FAILURE);
}

int main( int argc, char* argv[])
{
	int r;///<return
	const char* memname = "sample";

	/**
	 *
	 * sysconf( const char* name): it will return the meaning of name
	 *
	 */
	const size_t region_size = sysconf( _SC_PAGE_SIZE);///<TODO: figure out

	int fd = shm_open( memname, O_CREAT | O_TRUNC | O_RDWR, 0666);///< Just like opening file

	if( fd == -1)
		err_exit("shm_open");
	
	r = ftruncate( fd, region_size);///<TODO: file truncate to specified length

	if( r != 0)
		err_exit("ftruncate");

	void *ptr = mmap( 0, region_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);/// first arg is void* addr, so we choose the 0 address(by man)

	if( ptr == MAP_FAILED)
		err_exit( "mmap");

	close( fd);///<TODO: finish maping and we can close the fd

	pid_t pid = fork();

	if( pid == 0)///<child
	{
		u_long *d = ( u_long*) ptr;
		*d = 0xdbeebee;
		exit(0);
	}
	else
	{
		int status;
		waitpid( pid, &status, 0);
		printf("child wrote %#lx\n", *(u_long *) ptr);
	}

	r = munmap( ptr, region_size);///< unmap

	if( r != 0)
		err_exit("munmap");

	r = shm_unlink( memname);///< unlink
	if( r != 0)
		err_exit("shm_unlink");

	return 0;
}
