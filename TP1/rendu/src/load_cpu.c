#include <sys/times.h>
#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int VERBOSE = 1 ;

void load_cpu (float load)
{
	float
		NUMBER_OF_LOOPS = 100000000,
		SC_CLK_TCK = sysconf (_SC_CLK_TCK),
		CPU_USAGE_RATE ;

	struct tms t0, t1 ;
	clock_t c0, c1 ;

	while (1)
	{
		c0 = times (&t0) ;

		for (int i = 0; i < NUMBER_OF_LOOPS; i++) ;
		sleep (1) ;

		c1 = times (&t1) ;

		if (c1 - c0 == 0) continue ; // Avoid division by zero.

		CPU_USAGE_RATE =
			SC_CLK_TCK * (t1.tms_utime - t0.tms_utime)
			/ (c1 - c0) ;

		NUMBER_OF_LOOPS *= (load / CPU_USAGE_RATE) ;

		if (VERBOSE)
		{
			printf("CPU usage: %f%% with %d loops.\n",
			       CPU_USAGE_RATE,
			       (int) NUMBER_OF_LOOPS) ;
		}
	}
}


int main (int argc, char ** argv)
{
	if (argc > 1)
		load_cpu (atoi(argv[1])) ;

	return 0 ;
}
