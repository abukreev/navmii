#include <libio.h>
#include <mystring.h>

int mystrlen(const char *s) {

    int i = 0;
    if (NULL != s) {
        while ('\0' != s[i]) {
            ++i;
        }
    }
    return i;
}

