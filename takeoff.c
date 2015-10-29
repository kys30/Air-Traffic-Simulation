#include "header.h"

takeoff ()
{
  int c = 0;


  while (logg[c] != 0)
    {
      int z = c + 1;
      printf ("\tFlight no. %d ..\n \tPlease Takeoff..\n\n\n", logg[c]);
    
      while (logg[z] != 0)
	{
	  printf ("\t\t\t  Flight no. - %d ... Please wait for takeoff !! \n\n", logg[z]);
	  z++;
	}

      c++;
      sleep (2);

    }


}
