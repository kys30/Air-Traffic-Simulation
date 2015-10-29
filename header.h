#include<errno.h>
#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include<signal.h>
#include<pthread.h>
#include<math.h>

int *send_request (void *arg);
int *send_emergencyrequest (void *arg);
extern int i, k, j;
static int runway = 0;
static int count = 0;
pthread_t pending[10];
pthread_t logg[30];
