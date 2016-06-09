#include <my_global.h>
#include <mysql.h>
#include <stdio.h>
#include <error.h>

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

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
	/*MYSQL *mysql_real_connect(MYSQL *mysql, const char *host, const char *user,
																const char *passwd, const char *db, unsigned int port,
																	const char *unix_socket, unsigned long client_flag) */
		if( mysql_real_connect( con_hdlr, "localhost", "root", argv[1],
															"testdb", 0, NULL, 0) == NULL)
		{
			fprintf( stderr, "%s\n", mysql_error( con_hdlr));
			mysql_close( con_hdlr);
			exit(1);
		}
	}
	printf("Connect with MySQL DB\n");

  if (mysql_query(con_hdlr, "DROP TABLE IF EXISTS Family")) {
      finish_with_error(con_hdlr);
  }
  
  if (mysql_query(con_hdlr, "CREATE TABLE Family(Relationship TEXT, Age INT)")) {      
      finish_with_error(con_hdlr);
  }
  
  if (mysql_query(con_hdlr, "INSERT INTO Family VALUES( 'Mom', 49)")) {
      finish_with_error(con_hdlr);
  }

  if (mysql_query(con_hdlr, "INSERT INTO Family VALUES( 'Dad', 51)")) {
      finish_with_error(con_hdlr);
  }

  if (mysql_query(con_hdlr, "INSERT INTO Family VALUES( 'Younger Brother', 16)")) {
      finish_with_error(con_hdlr);
  }

	mysql_close( con_hdlr);
	exit(0);
}
