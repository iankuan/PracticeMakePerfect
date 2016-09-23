#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main( int argc, char* argv[])
{
	int opt, n, d;
																	///< if u want to accept the argument after -n, you need to use "n:"
	while ( (opt = getopt( argc, argv, "n:d:")) != -1){
		switch( opt) {
			case 'n':
				n = atoi( optarg);
				break;
			case 'd':
				d = atoi( optarg);
				break;
			default:
				fprintf( stderr, "Usage: %s [-n num] [-d deviceID]", argv[0]);
				exit( EXIT_FAILURE);
		}
	}

	if ( optind != argc){
		fprintf( stderr, "Expected arg\n");
		exit( EXIT_FAILURE);
	}

	printf("arg: n = %d, d = %d\n", n, d);

	return 0;
}
