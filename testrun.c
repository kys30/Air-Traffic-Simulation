#include "header.h"

int
main ()
{
  int j;
  pthread_t t[30], te[3];

  printf
    ("\n This is Airport Terminal !! \n 20 Flights are going to send their request. \n In addition to that, 2 emergency landing will be shown. \n");
  sleep (2);
  printf
    (" \n After sucessful execution of Landing, the flights will be asked to take off, one by one at the interval of 2 sec.! \n");
  sleep (2);

  for (i = 0; i < 30; i++)	//WE GENERATE 30 THREADS , WHICH ARE SENDING A REQUEST TO LAND .
    {

      pthread_create (&t[i], NULL, send_request, NULL);
    }
  for (j = 0; j < 3; j++)	//THESE 3 THREADS ARE SENDING A REQUEST FOR EMERGENCY LANDING.
    {

      pthread_create (&te[j], NULL, send_emergencyrequest, NULL);

    }


  sleep (15);
  printf ("\n The landing is finished sucessfully !\n\n\n");
  sleep (2);
  takeoff ();			//ALL THE FLIGHTS WHICH HAD LANDED WILL NOW TAKEOFF.

  for (i = 0; i < 30; i++)
    {
      pthread_join (t[i], NULL);	// MAIN WAITS UNTIL ALL 30 THREADS ARE TERMINATED !
    }

  for (j = 0; j < 3; j++)
    {
      pthread_join (te[j], NULL);
    }
  printf
    ("\n All the flights have taken off.\n The Airport Terminal is free now!!\n");
  return 0;
}
