#include <sys/times.h>
#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int VERBOSE = 1 ;

void load_ram (float load)
{
        // TODO
}


int main (int argc, char ** argv)
{
	if (argc > 1)
		load_ram (atoi(argv[1])) ;

	return 0 ;
}
