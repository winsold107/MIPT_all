#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


struct Item
{
    int value;
    uint32_t next_pointer;
};

int main(int argc, char* argv[])
{
    int fd = open(argv[1], O_RDONLY);

    if(-1 == fd) {
        close (fd);
        return -1;
    }
    struct stat st;
    fstat(fd, &st);

    if (st.st_size < sizeof(struct Item)) {
        return -1;
    }

    char *file_mapping = mmap(NULL,
                              st.st_size,
                              PROT_READ,
                              MAP_PRIVATE,
                              fd,
                              0);

    if (file_mapping == MAP_FAILED) {
        close (fd);
        return -1;
    }

    char *entry = file_mapping;
    struct Item* it = (struct Item*)(entry);

    printf("%d", it->value);

    while (it->next_pointer != 0) {
        entry = file_mapping + it->next_pointer;
        it = (struct Item*) (entry);
        printf(" %d", it->value);
    }
    munmap(file_mapping, st.st_size);
    close (fd);
    return 0;
}