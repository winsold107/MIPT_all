#include <cstdlib>
#include <cassert>
#include <string>
#include <fstream>

using namespace std;

char getChar(int i) {
    switch(i) {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '?';
        default:
            assert(false);
            return NULL;
    }
}

void genTest(int i) {

    int maxL = 10;
    string s, p;
    srand(time(NULL));
    int psize = 1 + rand() % maxL;
    int ssize = psize + (rand() % (maxL-psize));
    for (int i = 0; i < ssize; ++i) {
        s += getChar(rand()%3);
    }

    for (int i = 0; i < psize; ++i) {
        p += getChar(rand()%3);
    }

    ofstream str(to_string(i) + ".txt", ios_base::trunc);
    str << s << endl << p;

}
