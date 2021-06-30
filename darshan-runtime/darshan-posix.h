#ifdef DARSHAN_GOTCHA

#define _XOPEN_SOURCE 500
#define _GNU_SOURCE

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
#include <aio.h>
#include <pthread.h>
#include <limits.h>

#ifndef HAVE_OFF64_T
typedef int64_t off64_t;
#endif
#ifndef HAVE_AIOCB64
#define aiocb64 aiocb
#endif

#ifndef DARSHAN_DECL
#define DARSHAN_DECL(func) __gotcha_wrap_##func
#endif

int DARSHAN_DECL(open)(const char *path, int flags, ...);
int DARSHAN_DECL(open64)(const char *path, int flags, ...);
int DARSHAN_DECL(__open_2)(const char *path, int oflag);
int DARSHAN_DECL(openat)(int dirfd, const char *pathname, int flags, ...);
int DARSHAN_DECL(openat64)(int dirfd, const char *pathname, int flags, ...);
int DARSHAN_DECL(creat)(const char* path, mode_t mode);
int DARSHAN_DECL(creat64)(const char* path, mode_t mode);
int DARSHAN_DECL(dup)(int oldfd);
int DARSHAN_DECL(dup2)(int oldfd, int newfd);
int DARSHAN_DECL(dup3)(int oldfd, int newfd, int flags);
int DARSHAN_DECL(fileno)(FILE *stream);
int DARSHAN_DECL(mkstemp)(char *template);
int DARSHAN_DECL(mkostemp)(char *template, int flags);
int DARSHAN_DECL(mkstemps)(char *template, int suffixlen);
int DARSHAN_DECL(mkostemps)(char *template, int suffixlen, int flags);
ssize_t DARSHAN_DECL(read)(int fd, void *buf, size_t count);
ssize_t DARSHAN_DECL(write)(int fd, const void *buf, size_t count);
ssize_t DARSHAN_DECL(pread)(int fd, void *buf, size_t count, off_t offset);
ssize_t DARSHAN_DECL(pwrite)(int fd, const void *buf, size_t count, off_t offset);
ssize_t DARSHAN_DECL(pread64)(int fd, void *buf, size_t count, off64_t offset);
ssize_t DARSHAN_DECL(pwrite64)(int fd, const void *buf, size_t count, off64_t offset);
ssize_t DARSHAN_DECL(readv)(int fd, const struct iovec *iov, int iovcnt);
#ifdef HAVE_PREADV
ssize_t DARSHAN_DECL(preadv)(int fd, const struct iovec *iov, int iovcnt, off_t offset);
ssize_t DARSHAN_DECL(preadv64)(int fd, const struct iovec *iov, int iovcnt, off64_t offset);
#endif
#ifdef HAVE_PREADV2
ssize_t DARSHAN_DECL(preadv2)(int fd, const struct iovec *iov, int iovcnt, off_t offset, int flags);
ssize_t DARSHAN_DECL(preadv64v2)(int fd, const struct iovec *iov, int iovcnt, off64_t offset, int flags);
#endif
ssize_t DARSHAN_DECL(writev)(int fd, const struct iovec *iov, int iovcnt);
#ifdef HAVE_PWRITEV
ssize_t DARSHAN_DECL(pwritev)(int fd, const struct iovec *iov, int iovcnt, off_t offset);
ssize_t DARSHAN_DECL(pwritev64)(int fd, const struct iovec *iov, int iovcnt, off64_t offset);
#endif
#ifdef HAVE_PWRITEV2
ssize_t DARSHAN_DECL(pwritev2)(int fd, const struct iovec *iov, int iovcnt, off_t offset, int flags);
ssize_t DARSHAN_DECL(pwritev64v2)(int fd, const struct iovec *iov, int iovcnt, off64_t offset, int flags);
#endif
off_t DARSHAN_DECL(lseek)(int fd, off_t offset, int whence);
off64_t DARSHAN_DECL(lseek64)(int fd, off64_t offset, int whence);
int DARSHAN_DECL(__xstat)(int vers, const char* path, struct stat *buf);
int DARSHAN_DECL(__xstat64)(int vers, const char* path, struct stat64 *buf);
int DARSHAN_DECL(__lxstat)(int vers, const char* path, struct stat *buf);
int DARSHAN_DECL(__lxstat64)(int vers, const char* path, struct stat64 *buf);
int DARSHAN_DECL(__fxstat)(int vers, int fd, struct stat *buf);
int DARSHAN_DECL(__fxstat64)(int vers, int fd, struct stat64 *buf);
#ifdef DARSHAN_WRAP_MMAP
void* int DARSHAN_DECL(mmap)(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
void* DARSHAN_DECL(mmap64)(void *addr, size_t length, int prot, int flags, int fd, off64_t offset);
#endif /* DARSHAN_WRAP_MMAP */
int DARSHAN_DECL(fsync)(int fd);
int DARSHAN_DECL(fdatasync)(int fd);
int DARSHAN_DECL(close)(int fd);
int DARSHAN_DECL(aio_read)(struct aiocb *aiocbp);
int DARSHAN_DECL(aio_write)(struct aiocb *aiocbp);
int DARSHAN_DECL(aio_read64)(struct aiocb64 *aiocbp);
int DARSHAN_DECL(aio_write64)(struct aiocb64 *aiocbp);
ssize_t DARSHAN_DECL(aio_return)(struct aiocb *aiocbp);
ssize_t DARSHAN_DECL(aio_return64)(struct aiocb64 *aiocbp);
int DARSHAN_DECL(lio_listio)(int mode, struct aiocb *const aiocb_list[], int nitems, struct sigevent *sevp);
int DARSHAN_DECL(lio_listio64)(int mode, struct aiocb64 *const aiocb_list[], int nitems, struct sigevent *sevp);
int DARSHAN_DECL(rename)(const char *oldpath, const char *newpath);

#endif /* DARSHAN_GOTCHA */
