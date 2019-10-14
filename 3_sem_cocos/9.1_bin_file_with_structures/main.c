#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

struct Item
{
    int value;
    uint32_t next_pointer;
};

int main(int argc, char* argv[])
{
    int in = open(argv[1], O_RDONLY);

    if(-1 == in) {
        goto finally;
    }

    ssize_t in_read;
    struct Item out;

    in_read = read (in, &out, sizeof(out));
    if(in_read > 0) {
        printf("%d", out.value);
    }


    while (out.next_pointer != 0 && in_read > 0) {
        lseek (in, out.next_pointer, SEEK_SET);
        in_read = read (in, &out, sizeof(out));
        printf(" %d", out.value);
    }

    if (-1 == in_read) {
        goto finally;
    }

    finally:
        close (in);
    return 0;
}