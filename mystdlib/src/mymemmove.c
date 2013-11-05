#include <mystring.h>

void *mymemmove(void *dest, const void *src, size_t n) {

    int overlap_size;
    if (NULL != dest && NULL != src && 0 < n) {
        if (dest < src && (dest + n) > src) {
            overlap_size = dest + n - src;
            mymemcpy(dest, src, n - overlap_size);
            mymemcpy(dest + (n - overlap_size), src + n - (overlap_size), overlap_size);
        } else if (src < dest && (src + n) > dest) {
            overlap_size = src + n - dest;
            mymemcpy(dest + overlap_size, src + overlap_size, n - overlap_size);
            mymemcpy(dest, src, overlap_size);
        } else {
            mymemcpy(dest, src, n);
        }
    }
    return dest;
}
