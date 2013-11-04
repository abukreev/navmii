#include <libio.h>
#include <mystring.h>

size_t mystrlen(const char *s) {

    size_t i = 0;
    if (NULL != s) {
        while ('\0' != s[i]) {
            ++i;
        }
    }
    return i;
}

