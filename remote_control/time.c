#include <time.h>
#include <assert.h>

time_t get_time(){

  time_t temp;
  assert(((temp = time( NULL)) > 0) && "Can't get time");
  return temp;
}

double diff_time( time_t t1, time_t t2){

  double result;
  assert(((result = difftime( t1, t2)) > 0) && "t1 - t2 is negative");
  return result;
}
