#include <stdio.h>
#include <tgmath.h>

/*
_Generic( 'a', char: 1, int: 2, long: 3, default: 0)

#define type_idx(T) _Generic( (T), char: 1, int: 2, long: 3, default: 0)
///type_idx('a')

#define acos(X) _Generic( (X), \
	long double complex: cacos1, \
	double complex: cacos, \
	float complex: cacosf, \
	long double: acos1, \
	float: acosf, \
	default: acos \
)(X)
*/


#define printf_dec_format(x) _Generic( (x), \
	char: "%c", \
	signed char: "%hhd", \
	unsigned char: "%hhu", \
	signed short: "%hd", \
	unsigned short: "%hd", \
	signed int: "%d", \
	unsigned int: "%u", \
	unsigned long int: "%ld", \
	long long int: "%lld", \
	unsigned long long int: "%llu", \
	float: "%f", \
	double: "%lf", \
	long double: "%Lf", \
	char *: "%s", \
	void *: "%p")

#define print(x) 		printf( printf_dec_format(x), x)
#define printnl(x) 	printf( printf_dec_format(x), x); printf("\n")

int main( int argc, char* argv)
{
	printnl('a');
	printnl( (char)'a');
	printnl( 123);
	printnl( 1.234);

	//printnl( "abc");

	return 0;
}
