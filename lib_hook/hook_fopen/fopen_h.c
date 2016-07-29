#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>

FILE* fopen( const char* fname, const char* mode)
{
	printf("fname = %s, mode = %s\n", fname, mode);

	FILE* (* fopen_fn)( const char*, const char*) = NULL;
	fopen_fn = dlsym( RTLD_NEXT, "dlsym");

	return ( *fopen)( fname, mode);
}
