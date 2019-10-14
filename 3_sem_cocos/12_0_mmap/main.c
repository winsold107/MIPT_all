#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[]) {
    char *file_name = argv[1];
    char *pattern = argv[2];

    int fd = open(file_name, O_RDONLY);
    if (fd == -1) {
        return -1;
    }

    struct stat st;
    fstat(fd, &st);

    if (st.st_size <= 0) {
        return 0;
    }

    char *file_mapping = mmap(NULL,
                          st.st_size,
                          PROT_READ,
                          MAP_PRIVATE,
                          fd,
                          0);

    char *entry = file_mapping;


    while (NULL != (entry=strstr(entry, pattern))) {
        size_t diff = entry - file_mapping;
        printf("%lu ", diff);
        entry++;
    }
    printf("\n");
    munmap(file_mapping, st.st_size);
    close(fd);

    return 0;
}