#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


/**
 * struct option {
 * 	const char *name;		 //	option name
 * 	int					has_arg; // 0 = no arg, 1 = required arg, 2 = no or require
 *	int					*flag;
 *	int 				val;
 */

int main( int argc, char* argv[])
{
	int c;
	int digit_optind = 0;

	while( 1){
		
		int this_option_optind = optind ? optind: 1;
		int option_index = 0;

		static struct option long_options[] = {
			{"add" , 			required_argument, 0, 0},///< --add 10
			{"append" , 	no_argument, 			 0, 0},
			{"delete" , 	required_argument, 0, 0},
			{"verbose" , 	no_argument, 			 0, 0},///< return 'verbose'
			{"create" , 	required_argument, 0, 'c'},///< return 'c' not create
			{"file" , 		required_argument, 0, 0},
			{0,														0, 0, 0}
		};

	///< It can input -a -b ... and also --add --append ...
	c = getopt_long( argc, argv, "abc:012", long_options, &option_index);

	if( c == -1)//< no more argument
		break;

	switch( c){
		case 0:/// long option will jump to here
			printf( "option %s", long_options[ option_index].name);
			if( optarg)
				printf(" with arg %s", optarg);
			printf("\n");
			break;
		case '0':
		case '1':
		case '2':
			if( digit_optind != 0 && digit_optind != this_option_optind)
				printf( "digits occur in two different argv-element.\n");
			digit_optind = this_option_optind;
			printf("option %c\n", c);
			break;

		case 'a':
			printf("option a\n");
			break;

		case 'b':
			printf("option b\n");
			break;

		case 'c':
			printf("option c with value '%s'\n", optarg);
			break;
		
		case 'd':
			printf("option d with value '%s'\n", optarg);

		case '?':
			break;

		default:
			printf(" ?? getopt returned character code 0%o ??\n", c);
		}
	}

	if ( optind < argc){
		printf("non-option ARGV-elements: ");
		while( optind < argc)
			printf("%s ", argv[ optind++]);

		printf("\n");
	}

	exit(EXIT_SUCCESS);
}
