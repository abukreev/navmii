#include <mystring.h>

char *mystrstr(const char *haystack, const char *needle) {

    int haystack_len;
    int needle_len;
    const char *p;

    if (NULL != haystack && NULL != needle) {
        haystack_len = mystrlen(haystack);
        needle_len = mystrlen(needle);
        if (0 < needle_len && needle_len <= haystack_len) {
            for (p = haystack; *(p + needle_len) != '\0'; ++p) {
                if (mymemcmp(p, needle, needle_len) == 0) {
                    return (char*) p;
                }
            }
        }
    }
    return NULL;
}
