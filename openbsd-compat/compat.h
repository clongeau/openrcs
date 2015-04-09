#include <stdio.h>
#include <string.h>

#include "../config.h"

#include "defines.h"

#ifdef HAVE_SYS_DIRENT_H
#include <sys/dirent.h>
#else
	#ifdef HAVE_DIRENT_H
	#include <dirent.h>
	#else
	#error "no dirent"
	#endif
#endif

#ifndef SIZE_MAX
#include <stdint.h>
#endif

/* XXX */
#ifndef MAXBSIZE
#define MAXBSIZE 4096
#endif

/* From /usr/include/i386/limits.h */
#ifndef SIZE_T_MAX
#define SIZE_T_MAX UINT_MAX
#endif

/* From /usr/include/pwd.h */
#ifndef _PW_NAME_LEN
#define _PW_NAME_LEN            31      /* max length, not counting NUL */
#endif

#ifndef HAVE_FGETLN
char * fgetln(FILE *stream, size_t *len);
#endif

#ifndef HAVE_STRTONUM
long long strtonum(const char *nptr, long long minval, long long maxval, const char **errstr);
#endif

#ifndef HAVE_STRLCPY
size_t strlcpy(char *dst, const char *src, size_t size);
#endif

#ifndef HAVE_STRLCAT
size_t strlcat(char *dst, const char *src, size_t size);
#endif

#ifndef HAVE_REALLOCARRAY
void *reallocarray(void *, size_t, size_t);
#endif
