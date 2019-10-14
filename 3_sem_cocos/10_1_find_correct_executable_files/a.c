#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


int is_elf(const char* s) {
    return s[0] == (char)127 && s[1] == 'E' && s[2] == 'L' && s[3] == 'F';
}

int is_interpreter(const char* s) {
    if (s[0] != '#' || s[1] != '!') return 0;
    s += 2;

    struct stat st;
    return (lstat(s, &st) != -1) && (st.st_mode & S_IXUSR);
}

int main() {

    setbuf(stdout, NULL);

    char file_name[PATH_MAX];
    struct stat st;
    struct stat st1;
    char * nl;

    while (fgets(file_name, sizeof(file_name), stdin) ) {
        nl = (char*)memchr(file_name, '\n', sizeof(file_name));
        if (nl) {
            *nl = '\0';
        }

//        ssize_t in_read;

        int fp = open(file_name, O_RDONLY);

        if (fstat(fp, &st) != -1) {

            if(!(st.st_mode & S_IXUSR)) {
                continue;
            }

            // Если в файле меньше двух байт, то он неправильный
//            if (st.st_size < 2) {
//                printf("%s\n", file_name);
//                continue;
//            }
            char first_line[PATH_MAX];
//            char interpreter_name[PATH_MAX];

            FILE* f = fdopen(fp, "r");
            fgets(first_line, PATH_MAX, f);

            nl = (char*)memchr(first_line, '\n', PATH_MAX);
            if (nl) {
                *nl = '\0';
            }
//            in_read = read(fp, &first_line, sizeof(first_line));

//            if (in_read < 2) {
//                printf("%s\n", file_name);
//                continue;
//            }

            if (!is_elf(first_line) && !is_interpreter(first_line)) {
                printf("%s\n", file_name);
            }
//
//            if (first_line[0] == (char)127) {
//                if (first_line[1] == 'E') {
//                    ssize_t n = read(fp, &first_line, sizeof(first_line));
//                    if (n < 2 || first_line[0] != 'L' || first_line[1] != 'F') {
//                        printf("%s\n", file_name);
//                    }
//                }
//                else {
//                    printf("%s\n", file_name);
//                }
//            }
//            else if (first_line[0] == '#' && first_line[1] == '!') {
//                int iter = 0;
//                char inter_sym = ' ';
//
//                while (inter_sym == ' ') {
//                    read(fp, &inter_sym, sizeof(inter_sym));
//                }
//
//
//                while (inter_sym != '\n') {
//                    interpreter_name[iter++] = inter_sym;
//                    read(fp, &inter_sym, sizeof(inter_sym));
//                }
//
//                interpreter_name[iter] = '\0';
//
//                if (lstat(interpreter_name, &st1) != -1) {
//                    if (!(st1.st_mode & S_IXUSR)) {
//                        printf("%s\n", file_name);
//                    }
//                }
//                else {
//                    printf("%s\n", file_name);
//                }
//            }
//            else {
//                printf("%s\n", file_name);
//            }
//        } else {
//            // такого файла не существует, выведем его
//            printf("%s\n", file_name);
//        }
        }
        fflush(stdout);
        return 0;
    }
