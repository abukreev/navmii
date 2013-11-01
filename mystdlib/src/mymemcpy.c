#include <mymemcpy.h>

void *mymemcpy(void *dest, const void *src, size_t n) {

    int i;
    for (i = 0; i < n; ++i) {
        *((char *) dest + i) = *((const char *) src + i);
    }
}

