// Baptiste Fontaine & Julien Sagot -- TP 3
#include <stdio.h>
#include <unistd.h>

#include "cpu.h"
#include "collecter.h"

int main(int argc, char **argv) {

        char *output_filename;

        int c;

        opterr = 0;

        while ((c = getopt(argc, argv, "o:")) != -1)
        {
                switch (c)
                {
                        case 'o':
                                output_filename = optarg;
                                break;
                        case '?':
                                if (optopt == 'o') {
                                        fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                                } else {
                                        fprintf(stderr, "Unknown option '-%c'\n", optopt);
                                }
                                return 1;
                }
        }

        return 0;
}
