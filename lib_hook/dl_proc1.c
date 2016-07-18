#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

void file1( int *i);
void file2( int *i);

int main( void)
{
	void* handler;
	int (*fn) (int *);
	int x;
	char *error;

	printf("before dlopen()\n");
	handler = dlopen("/home/awei/PracticeMakePerfect/lib_hook/libfile.so", RTLD_LAZY);
	printf("after dlopen()\n");
	
	if( !handler)
	{
		fprintf( stderr, "%s\n", dlerror());
		exit(1);
	}

	fn = dlsym( handler, "file1");
	if( (error = dlerror()) != NULL)
	{
		fprintf( stderr, "%s\n", error);
		exit(1);
	}

	(*fn)(&x);
	printf("The value of x is %d\n", x);

	dlclose( handler);
	return 0;
}
