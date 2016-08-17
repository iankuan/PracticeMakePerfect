#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <libgen.h>
#include <string.h>

int main( int argc, char** argv[])
{
	char *dirc, *basec, *bname, *dname;
	char *apath = "/etc/passwd/fake";
	char *rpath0 = "path.c";
	char *rpath1 = "./path.c";

	printf("apath = %s, rpath0 = %s, rpath1 = %s\n", apath, rpath0, rpath1);

	dirc = strdup(apath);///< string copy
	basec = strdup(apath);
	dname = dirname(dirc);
	bname = basename(basec);
	printf("absolutle path: dirname=%s, basename=%s\n", dname, bname);///< it is interesting, dir will be "." , not " "

	dirc = strdup(rpath0);///< string copy
	basec = strdup(rpath0);
	dname = dirname(dirc);
	bname = basename(basec);
	printf("relative path: dirname=%s, basename=%s\n", dname, bname);

	dirc = strdup(rpath1);///< string copy
	basec = strdup(rpath1);
	dname = dirname(dirc);
	bname = basename(basec);
	printf("relative path: dirname=%s, basename=%s\n", dname, bname);
	
	char abPath0[100];
	realpath( rpath0, abPath0);
	char abPath1[100];
	realpath( rpath1, abPath1);
	printf("realpath(): rapth0 = %s, rapth1 = %s\n", abPath0, abPath1);

	return 0;
}
