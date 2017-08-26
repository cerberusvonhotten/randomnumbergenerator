#include <mysql/my_global.h>
#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

int main(int argc, char **argv)
{

int i=0;

char outs[20];

do{

//SQL Query

  MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }

  if (mysql_real_connect(con, "serverhost", "yourusername", "yourpassword","yourdatabase", 0, NULL, 0) == NULL)
  {
      finish_with_error(con);
  }

  if (mysql_query(con, "YOUR SQL QUERY TO READ "))
  {
      finish_with_error(con);
  }

system("sleep 1");


  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
      finish_with_error(con);
  }

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;

  while ((row = mysql_fetch_row(result)))
  {
      for(int  i = 0; i < num_fields; i++)
      {

sprintf(sqlqueryoutput,"%s",row[0]);
      }
  }


char thequery[100];
int numbergenerate,converttoint;
converttoint = atoi(sqlqueryoutput);

numbergenerate=rand()%5 + sqlqueryoutput;

printf("generated: %d\n",g1);


sprintf(thequery,"YOUR SQL QUERY TO INSERT values('%d')",g1);
  if (mysql_query(con, thequery))
  {
      finish_with_error(con);
  }






//close sql reading query connection
mysql_free_result(result);
mysql_close(con);




}while(i<10);



return(0);
}




