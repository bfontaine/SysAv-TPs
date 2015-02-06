#include <sys/times.h>
#include <stdio.h>
#include <unistd.h>

float cpu_load(int seconds_interval)
{
        float SC_CLK_TCK = sysconf(_SC_CLK_TCK);

        struct tms t0, t1;
        clock_t c0, c1;

        c0 = times(&t0);

        sleep(seconds_interval);

        c1 = times(&t1);

        // if (c1 == c0) return 0; // Avoid division by zero.

        return SC_CLK_TCK * (t1.tms_utime - t0.tms_utime) / (c1 - c0);

}
