#ifndef MYSTRING_H
#define MYSTRING_H

#ifdef __cplusplus
extern "C" {
#endif

void *mymemcpy(void *dest, const void *src, int n);
int mystrlen(const char *s);
int mymemcmp(const void *s1, const void *s2, int n);

#ifdef __cplusplus
}
#endif

#endif // MYSTRING_H
