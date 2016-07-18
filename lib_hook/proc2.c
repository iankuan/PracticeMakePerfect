#define _GNU_SOURCE
#include <stdio.h>
#include <stdint.h>
#include <dlfcn.h>

void leak_check( void);

void* malloc( size_t size)
{
	static void* (*my_malloc)(size_t) = NULL;
	printf("inside shared object ... \n");
	printf("size = %d \n", (int) size);
	
	if( !my_malloc)
		my_malloc = dlsym( RTLD_NEXT, "malloc");/*TODO: RTLD_NEXT?
																						 define by GNU_SOURCE*/
	
	void *p =  my_malloc( size);
	printf("malloc(%d) = %p\n", (int) size, p);

	leak_check();
	
	printf("returning from shared object ...\n");
	return p;
}

void leak_check( void)
{
	printf("displaying memory leaks ... \n");
	/*TODO: fill required stuff here*/
}
