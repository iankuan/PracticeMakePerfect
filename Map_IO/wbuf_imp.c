#include <sys/types,h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

/*int wbuf( int fd, char* buf, size_t sz); we should use void pointer*/
int wbuf( int fd, void *buf, int count);

int main()
{
  int infd,outfd;

  char *map;
  char *ptr;

  if ( ( infd = open( "test_map_io.txt", O_RDWR| O_CREAT| O_TRUNC, 0640)) == -1)
  {
    printf("infile cant open\n");
    exit(254);/* why 254? maybe error num*/
  }

  lseek( infd, 1000, SEEK_SET);// we need to allocate an 1000 byte space

  if( wbuf( infd, '\0', 1) == -1)
  {
    printf("Error write\n");
    exit(254);
  }

  map = mmap( NULL, 1000, PROT_READ|PROT_WRITE, MAP_SHARED, infd, 0);/*TODO:IMPORTENT "mmap"*/

  if( map == NULL)
  {
    printf("error map\n");
    exit(254);
  }

  ptr = map;

  printf("Please enter a number");
  fgets( map, stdin, 80);
  ptr += strlen( map);
  ptr++;
  sprintf(ptr, "Your number times two is: %d\n",atoi( map) * 2);
  printf("Your number times two is: %d\n",atoi( map) * 2);
  msync( map, 1000, MS_ASYNC);//TODO:msync - synchronize a file with a memory map
  mumap( map, 1000);//TODO unlink map
  
  if( close( infile) == -1){

    printf("Close file failed\n");
    exit(254);
  }

  return 0;
}

int wbuf( int fd, const void *buf, int count)
{
  const void *cpt = buf;
  int status = 0, n;

  if( count < 0)
    return -1;

  while( status != count)
  {
    if( ( n = write( fd, "\0", 1)) == -1)
    {
      printf("Error writr\n");
      exit(254);
    }
    if( n< 0)
      return n;
    status += n;
  }

  return status;
}
