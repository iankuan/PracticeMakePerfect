#include <stdio.h>

int main( int argc, char* argv[])
{
	char* fname = argv[1];

	FILE* file = fopen( fname, "r");

	if( file)
		printf("OPEN\n");
	else
		printf("CANT OPEN\n");

	fclose( file);

	return 0;
}
