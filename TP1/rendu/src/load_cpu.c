#include <sys/times.h>
#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static int VERBOSE = 1 ;

void load_cpu (float load)
{
        float
                loops_count = 100000000,
                SC_CLK_TCK = sysconf (_SC_CLK_TCK),
                cpu_usage_rate ;

        struct tms t0, t1 ;
        clock_t c0, c1 ;

        while (1)
        {
                c0 = times (&t0) ;

                for (int i = 0; i < loops_count; i++) ;
                sleep (1) ;

                c1 = times (&t1) ;

                if (c1 == c0) continue ; // Avoid division by zero.

                cpu_usage_rate =
                        SC_CLK_TCK * (t1.tms_utime - t0.tms_utime)
                        / (c1 - c0) ;

                loops_count *= (load / cpu_usage_rate) ;

                if (VERBOSE)
                {
                        printf("CPU usage: %f%% with %d loops.\n",
                               cpu_usage_rate,
                               (int) loops_count) ;
                }
        }
}

int print_usage (char **argv)
{
        printf("Usage:\n\t%s [-s] <percentage>\n", argv[0]);
        return 1 ;
}


int main (int argc, char ** argv)
{
        int args_start = 1;

        if (argc == 1) return print_usage(argv);

        if (strcmp("-s", argv[1]) == 0) {
                args_start++;
                VERBOSE = 0;
        }

        if (argc <= args_start) return print_usage(argv);

        load_cpu (atoi(argv[args_start])) ;

        return 0 ;
}
