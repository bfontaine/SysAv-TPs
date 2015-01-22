// Baptiste Fontaine -- TP 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "cpu.h"
#include "main.h"

int main(int argc, char **argv) {

        unsigned long loops = 100000;
        double expected_load = 0,
               actual_load = 0;
        struct cpu_time t1, t2;

        if (argc != 2) {
                printf("Usage:\n\t%s <CPU load>\n", argv[0]);
                exit(1);
        }

        expected_load = strtod(argv[1], NULL); // TODO check errors

        printf("Expected load: %f\n", expected_load);

        while (1) {
                unsigned long i = 0;

                if (cpu_times(&t1) != 0) { perror("cpu_times"); return 1; }

                while (i++ < loops);

                if (cpu_times(&t2) != 0) { perror("cpu_times"); return 1; }

                actual_load = cpu_load(&t1, &t2);

                printf("Load: %f, using %lu loops\n", actual_load, loops);

                loops *= actual_load <= 0.001 ? 1000 : (expected_load / actual_load);
        }

        return 0;
}