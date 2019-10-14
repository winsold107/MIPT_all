#include <stdio.h>
#include <sys/stat.h>
#include <memory.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

char* get_s(char* s, int n, FILE* stream) {
    char *r = fgets(s, n, stream), *nl;
    if (r) {
        nl = (char *) memchr(s, '\n', PATH_MAX);
        if (nl)
            *nl = '\0';
    }
    return r;
}

void insert_string(size_t pos, char* src, char* ins, char* dest) {
    strncpy(dest, src, pos);
    dest[pos] = '\0';
    strcat(dest, ins);
    strcat(dest, src + pos);
}

int main() {
    setbuf(stdout, NULL);
    char file_name[PATH_MAX], file_full_path[PATH_MAX], new_link_path[PATH_MAX];
    while (get_s(file_name, sizeof(file_name), stdin) ) {
        struct stat buf;
        if (lstat(file_name, &buf) != -1) {
            realpath(file_name, file_full_path);
            if (S_ISLNK(buf.st_mode)) {
                printf("%s\n", file_full_path);
            }
            else if (S_ISREG(buf.st_mode)) {
                size_t pos = strlen(file_full_path) - 1;
                for ( ; file_full_path[pos] != '/'; --pos);
                insert_string(pos+1, file_full_path, "link_to_", new_link_path);
                symlink(file_full_path, new_link_path);
            }
        }
    }
    return 0;
}