#include <stdio.h>

int main( int argc, char** argv)
{
	char str[] = "123456213 instrname NO(";
	
	long long int num; char inst[20], test[20];

	sscanf( str, "%lld %s %[^(]", &num, inst, test);

	printf("num = %lld\n", num);
	printf("inst = %s\n", inst);
	printf("test = %s\n", test);

	return 0;
}
