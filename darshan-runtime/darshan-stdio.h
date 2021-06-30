#ifdef DARSHAN_GOTCHA

#define _XOPEN_SOURCE 500
#define _GNU_SOURCE

#include "darshan-runtime-config.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/uio.h>
#include <sys/mman.h>
#include <search.h>
#include <assert.h>
#include <libgen.h>
#include <pthread.h>
#include <stdint.h>
#include <limits.h>

#include "darshan.h"
#include "darshan-dynamic.h"

#ifndef HAVE_OFF64_T
typedef int64_t off64_t;
#endif

#define DARSHAN_DECL(func) __wrap_##func

FILE* DARSHAN_DECL(fopen)(const char *path, const char *mode);
FILE* DARSHAN_DECL(fopen64)(const char *path, const char *mode);
FILE* DARSHAN_DECL(fdopen)(int fd, const char *mode);
FILE* DARSHAN_DECL(freopen)(const char *path, const char *mode, FILE *stream);
FILE* DARSHAN_DECL(freopen64)(const char *path, const char *mode, FILE *stream);
int DARSHAN_DECL(fclose)(FILE *fp);
int DARSHAN_DECL(fflush)(FILE *fp);
size_t DARSHAN_DECL(fwrite)(const void *ptr, size_t size, size_t nmemb, FILE *stream);
int DARSHAN_DECL(fputc)(int c, FILE *stream);
int DARSHAN_DECL(putw)(int w, FILE *stream);
int DARSHAN_DECL(fputs)(const char *s, FILE *stream);
int DARSHAN_DECL(fprintf)(FILE *stream, const char *format, ...);
int DARSHAN_DECL(printf)(const char *format, ...);
int DARSHAN_DECL(vfprintf)(FILE *stream, const char *format, va_list);
int DARSHAN_DECL(vprintf)(const char *format, va_list);
size_t DARSHAN_DECL(fread)(void *ptr, size_t size, size_t nmemb, FILE *stream);
int DARSHAN_DECL(fgetc)(FILE *stream);
int DARSHAN_DECL(getw)(FILE *stream);
int DARSHAN_DECL(_IO_getc)(FILE *stream);
int DARSHAN_DECL(_IO_putc)(int, FILE *stream);
int DARSHAN_DECL(fscanf)(FILE *stream, const char *format, ...);
#ifndef HAVE_FSCANF_REDIRECT
int DARSHAN_DECL(__isoc99_fscanf)(FILE *stream, const char *format, ...);
#endif
int DARSHAN_DECL(vfscanf)(FILE *stream, const char *format, va_list ap);
int DARSHAN_DECL(fgets)(char *s, int size, FILE *stream);
int DARSHAN_DECL(fseek)(FILE *stream, long offset, int whence);
int DARSHAN_DECL(fseeko)(FILE *stream, off_t offset, int whence);
int DARSHAN_DECL(fseeko64)(FILE *stream, off64_t offset, int whence);
int DARSHAN_DECL(fsetpos)(FILE *stream, const fpos_t *pos);
int DARSHAN_DECL(fsetpos64)(FILE *stream, const fpos64_t *pos);
int DARSHAN_DECL(rewind)(FILE *stream);

#endif /* DARSHAN_GOTCHA */
