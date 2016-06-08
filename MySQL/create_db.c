#include <my_global.h>
#include <mysql.h>
#include <stdio.h>
#include <error.h>

int main( int argc, char* argv[])
{

	//init connection handler
	MYSQL *con_hdlr = mysql_init( NULL);
	if( con_hdlr == NULL)
	{
		fprintf( stderr, "%s\n", mysql_error( con_hdlr));
		exit(1);
	}
	printf("Init connection handler\n");

	//Connect with MySQL DB
	if( argc != 2) { perror("Argument is not two\n"); exit(1);}
	else{
		if( mysql_real_connect( con_hdlr, "localhost", "root", argv[1],
															NULL, 0, NULL, 0) == NULL)
		{
			fprintf( stderr, "%s\n", mysql_error( con_hdlr));
			mysql_close( con_hdlr);
			exit(1);
		}
	}
	printf("Connect with MySQL DB\n");

	//Query
	if( mysql_query( con_hdlr, "CREATE DATABASE testdb"))
	{
			fprintf( stderr, "%s\n", mysql_error( con_hdlr));
			mysql_close( con_hdlr);
			exit(1);
	}
	printf("Instruction import\n");

	mysql_close( con_hdlr);
	exit(0);
}
