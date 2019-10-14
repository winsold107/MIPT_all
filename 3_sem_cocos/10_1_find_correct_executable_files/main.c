#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <fcntl.h>


char* get_s(char* s, int n, FILE* stream) {
    char *r = fgets(s, n, stream), *nl;
    if (r) {
        nl = (char *) memchr(s, '\n', PATH_MAX);
        if (nl)
            *nl = '\0';
    }
    return r;
}

int is_elf(const char* s) {
    return s[0] == (char)127 && s[1] == 'E' && s[2] == 'L' && s[3] == 'F';
}

int is_interpreter(const char* s) {
    if (s[0] != '#' || s[1] != '!')
        return 0;
    s += 2;
    struct stat st;
    return (lstat(s, &st) != -1) && (st.st_mode & S_IXUSR);
}

int main() {
    setbuf(stdout, NULL);
    char file_name[PATH_MAX], first_line[PATH_MAX];
    struct stat st;
    while (get_s(file_name, sizeof(file_name), stdin)) {
        int fp = open(file_name, O_RDONLY);
        if (fstat(fp, &st) != -1) {
            if (!(st.st_mode & S_IXUSR))
                continue;
            if (!get_s(first_line, PATH_MAX, fdopen(fp, "r")) || !is_elf(first_line) && !is_interpreter(first_line))
                printf("%s\n", file_name);
        }
    }
    return 0;
}
