#include <stdio.h> 
#include <time.h> 
 
int main(void)
{
  time_t now;
  now = time( NULL );
  printf( "%s", ctime ( &now ));
  return 0;
}