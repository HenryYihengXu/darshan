#ifdef DARSHAN_GOTCHA

#define _XOPEN_SOURCE 500
#define _GNU_SOURCE

#include "darshan-runtime-config.h"

#include <stdio.h>
#include <stdlib.h>
#ifdef HAVE_MPI
#include <mpi.h>
#endif

#ifndef DARSHAN_DECL
#define DARSHAN_DECL(func) __darshan_gotcha_wrap_##func
#endif

#ifdef HAVE_MPI
int DARSHAN_DECL(MPI_Finalize)();
int DARSHAN_DECL(MPI_Init)(int *argc, char ***argv);
int DARSHAN_DECL(MPI_Init_thread)(int *argc, char ***argv, int required, int *provided);

#endif

#endif /* DARSHAN_GOTCHA */
