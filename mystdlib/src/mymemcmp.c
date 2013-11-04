#include <libio.h>

#include <mystring.h>

int mymemcmp(const void *s1, const void *s2, size_t n) {

    size_t i;
    if (NULL != s1 && NULL != s2) {
        for (i = 0; i < n; ++i) {
            if (*(char *)(s1 + i) > *(char *)(s2 + i)) {
                return (*(char *)(s1 + i) > *(char *)(s2 + i)) ? 1 : -1;
            }
        }
    }
    return 0;
}
