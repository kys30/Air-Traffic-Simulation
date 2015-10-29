#include "header.h"

void
send_emergencyresponse (pthread_t tid)
{
  unsigned int q = tid % 10000;
  printf ("FLIGHT NO.%u \n PLEASE LAND\n\n\n", q);
  sleep (2);


}
