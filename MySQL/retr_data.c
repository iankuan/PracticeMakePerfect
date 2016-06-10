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

 if (mysql_query(con_hdlr, "SELECT * FROM Family")) 
  {
      finish_with_error(con_hdlr);
  }
  
  MYSQL_RES *result = mysql_store_result(con_hdlr);
  
  if (result == NULL) 
  {
      finish_with_error(con_hdlr);
  }

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;
	MYSQL_FIELD *field;

  int i;
  while ((row = mysql_fetch_row(result))) 
  {
      for( i = 0; i < num_fields; i++) 
      {
					if( i == 0)
					{
						while( field = mysql_fetch_field( result))
							printf("%s ", field->name);
						printf("\n");
					}

          printf("%s ", row[i] ? row[i] : "NULL"); 
      } 
  }
	printf("\n");
  
  mysql_free_result(result);
	mysql_close( con_hdlr);
	exit(0);
}
