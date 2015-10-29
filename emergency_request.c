#include "header.h"
void send_emergencyresponse (pthread_t tid);

int *
send_emergencyrequest (void *arg)
{
  void handle2 ();
  pthread_t tr = pthread_self ();
  unsigned int wr = tr % 10000;
  static struct sigaction respond;
  respond.sa_handler = handle2;
  sigfillset (&(respond.sa_mask));

  sigaction (SIGUSR1, &respond, NULL);

  printf
    ("\n THIS IS FLIGHT NO. %u! \n There is an EMERGENCY ....\n\nPlease ALLOW ME TO LAND !\n ",
     wr);
  pthread_kill (pthread_self (), SIGUSR1);
  return 0;
}

void
handle2 ()
{
  send_emergencyresponse (pthread_self ());
}
