#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <errno.h>

#ifndef MAP_ANONYMOUS
/* OS X */
#define MAP_ANONYMOUS MAP_ANON
#endif

int load_ram (void)
{
        long SC_PAGE_SIZE = sysconf (_SC_PAGE_SIZE);
        long pages = 0;
        char *ptr;

        printf("Page size: %ld\n", SC_PAGE_SIZE);
        printf("Memlock limit: %d\n", RLIMIT_MEMLOCK);

        while (1) {
                ptr = mmap(NULL, SC_PAGE_SIZE, PROT_NONE,
                                MAP_SHARED|MAP_ANONYMOUS, -1, 0);
                if (ptr == MAP_FAILED) {
                        if (errno != ENOMEM) {
                                perror("mmap");
                                break;
                        }
                        printf("No more memory available \\o/\n");
                        printf("I successfully alloc'ed %ld pages\n", pages);
                        break;
                }

                if (mlock(ptr, SC_PAGE_SIZE) != 0) {
                        if (errno == EPERM) {
                                printf("You need to be superuser.\n");
                        }
                        perror("mlock");
                        return 1;
                }
                pages++;
        }

        pause();
        return 0;
}


int main (void)
{
        return load_ram () ;
}
