#ifndef _CPU_H
#define _CPU_H

struct cpu_time {
        long user_time;
        long nice_time;
        long system_time;
        long idle_time;
};

int cpu_times(struct cpu_time*);

void diff_cpu_times(struct cpu_time *c1, struct cpu_time *c2,
                struct cpu_time *res);

float cpu_load(struct cpu_time *c1, struct cpu_time *c2);

#endif
