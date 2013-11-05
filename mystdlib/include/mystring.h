#ifndef MYSTRING_H
#define MYSTRING_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void *mymemcpy(void *dest, const void *src, size_t n);
size_t mystrlen(const char *s);
int mymemcmp(const void *s1, const void *s2, size_t n);
void *mymemmove(void *dest, const void *src, size_t n);

#ifdef __cplusplus
}
#endif

#endif // MYSTRING_H
