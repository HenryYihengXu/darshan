#ifdef DARSHAN_GOTCHA

#define _XOPEN_SOURCE 500
#define _GNU_SOURCE

#include "darshan-runtime-config.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <search.h>
#include <assert.h>
#include <pthread.h>
#include <mpi.h>

#ifndef DARSHAN_DECL
#define DARSHAN_DECL(func) __gotcha_wrap_##func
#endif

int DARSHAN_DECL(ncmpi_create)(MPI_Comm comm, const char *path, int cmode, MPI_Info info, int *ncidp);
int DARSHAN_DECL(ncmpi_open)(MPI_Comm comm, const char *path, int omode, MPI_Info info, int *ncidp);
int DARSHAN_DECL(ncmpi_close)(int ncid);

#endif /* DARSHAN_GOTCHA */
