#include "header.h"
void send_response (pthread_t tid);


int *
send_request (void *arg)
{
  void handle ();
  pthread_t t = pthread_self ();
  unsigned int w = t % 10000;
  static struct sigaction respond;
  respond.sa_handler = handle;
  sigfillset (&(respond.sa_mask));

  sigaction (SIGUSR1, &respond, NULL);

  printf ("\n THIS IS FLIGHT NO. %u ! \n  Please ALLOW ME TO LAND !\n ", w);
  pthread_kill (pthread_self (), SIGUSR1);
  return 0;
}

void
handle ()
{
  send_response (pthread_self ());
}
