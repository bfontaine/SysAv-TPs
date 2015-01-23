#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "cpu.h"

#define MAX_LONG_CHAR_SIZE 32

int cpu_times(struct cpu_time *cpt) {
        FILE *statf;
        long user, nice, system, idle;
        long timeunit;

        memset(cpt, 0, sizeof(struct cpu_time));

        statf = fopen("/proc/stat", "r");
        timeunit = sysconf(_SC_CLK_TCK); // 100 on most architectures

        if (statf == NULL) {
                fclose(statf);
                return -1;
        }

        fscanf(statf, "cpu  %ld %ld %ld %ld", &user, &nice, &system, &idle);

        cpt->user_time = user * timeunit;
        cpt->nice_time = nice * timeunit;
        cpt->system_time = system * timeunit;
        cpt->idle_time = idle * timeunit;

        fclose(statf);
        return 0;
}

void diff_cpu_times(struct cpu_time *c1, struct cpu_time *c2,
                struct cpu_time *res) {
        memset(res, 0, sizeof(struct cpu_time));

        res->user_time = c2->user_time - c1->user_time;
        res->nice_time = c2->nice_time - c1->nice_time;
        res->system_time = c2->system_time - c1->system_time;
        res->idle_time = c2->idle_time - c1->idle_time;
}

float cpu_load(struct cpu_time *c1, struct cpu_time *c2) {
        struct cpu_time res;
        long active, inactive;

        diff_cpu_times(c1, c2, &res);

        active = res.user_time + res.nice_time + res.system_time;
        inactive = active + res.idle_time;

        return active / (double)inactive;
}
