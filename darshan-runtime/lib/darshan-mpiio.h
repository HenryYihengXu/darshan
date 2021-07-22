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
#include <search.h>
#include <assert.h>
#include <pthread.h>

#include <mpi.h>

#ifndef DARSHAN_DECL
#define DARSHAN_DECL(func) __darshan_gotcha_wrap_##func
#endif

int DARSHAN_DECL(MPI_File_close)(MPI_File *fh);
int DARSHAN_DECL(MPI_File_iread_at)(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request);
int DARSHAN_DECL(MPI_File_iread)(MPI_File fh, void  *buf, int  count, MPI_Datatype  datatype, __D_MPI_REQUEST  *request);
int DARSHAN_DECL(MPI_File_iread_shared)(MPI_File fh, void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request);
#ifdef HAVE_MPI_CONST
int DARSHAN_DECL(MPI_File_iwrite_at)(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request);
#else
int DARSHAN_DECL(MPI_File_iwrite_at)(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request);
#endif
#ifdef HAVE_MPI_CONST
int DARSHAN_DECL(MPI_File_iwrite)(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request);
#else
int DARSHAN_DECL(MPI_File_iwrite)(MPI_File fh, void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request);
#endif
#ifdef HAVE_MPI_CONST
int DARSHAN_DECL(MPI_File_iwrite_shared)(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request);
#else
int DARSHAN_DECL(MPI_File_iwrite_shared)(MPI_File fh, void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request);
#endif
#ifdef HAVE_MPI_CONST
int DARSHAN_DECL(MPI_File_open)(MPI_Comm comm, const char *filename, int amode, MPI_Info info, MPI_File *fh);
#else
int DARSHAN_DECL(MPI_File_open)(MPI_Comm comm, char *filename, int amode, MPI_Info info, MPI_File *fh);
#endif
int DARSHAN_DECL(MPI_File_read_all_begin)(MPI_File fh, void *buf, int count, MPI_Datatype datatype);
int DARSHAN_DECL(MPI_File_read_all)(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
int DARSHAN_DECL(MPI_File_read_at_all)(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
int DARSHAN_DECL(MPI_File_read_at_all_begin)(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype);
int DARSHAN_DECL(MPI_File_read_at)(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
int DARSHAN_DECL(MPI_File_read)(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
int DARSHAN_DECL(MPI_File_read_ordered_begin)(MPI_File fh, void *buf, int count, MPI_Datatype datatype);
int DARSHAN_DECL(MPI_File_read_ordered)(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
int DARSHAN_DECL(MPI_File_read_shared)(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
#ifdef HAVE_MPI_CONST
int DARSHAN_DECL(MPI_File_set_view)(MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, const char *datarep, MPI_Info info);
#else
int DARSHAN_DECL(MPI_File_set_view)(MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, char *datarep, MPI_Info info);
#endif
int DARSHAN_DECL(MPI_File_sync)(MPI_File fh);
#ifdef HAVE_MPI_CONST
int DARSHAN_DECL(MPI_File_write_all_begin)(MPI_File fh, const void *buf, int count, MPI_Datatype datatype);
#else
int DARSHAN_DECL(MPI_File_write_all_begin)(MPI_File fh, void *buf, int count, MPI_Datatype datatype);
#endif
#ifdef HAVE_MPI_CONST
int DARSHAN_DECL(MPI_File_write_all)(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
#else
int DARSHAN_DECL(MPI_File_write_all)(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
#endif
#ifdef HAVE_MPI_CONST
int DARSHAN_DECL(MPI_File_write_at_all_begin)(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype);
#else
int DARSHAN_DECL(MPI_File_write_at_all_begin)(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype);
#endif
#ifdef HAVE_MPI_CONST
int DARSHAN_DECL(MPI_File_write_at_all)(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
#else
int DARSHAN_DECL(MPI_File_write_at_all)(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
#endif
#ifdef HAVE_MPI_CONST
int DARSHAN_DECL(MPI_File_write_at)(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
#else
int DARSHAN_DECL(MPI_File_write_at)(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
#endif
#ifdef HAVE_MPI_CONST
int DARSHAN_DECL(MPI_File_write)(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
#else
int DARSHAN_DECL(MPI_File_write)(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
#endif
#ifdef HAVE_MPI_CONST
int DARSHAN_DECL(MPI_File_write_ordered_begin)(MPI_File fh, const void *buf, int count, MPI_Datatype datatype);
#else
int DARSHAN_DECL(MPI_File_write_ordered_begin)(MPI_File fh, void *buf, int count, MPI_Datatype datatype);
#endif
#ifdef HAVE_MPI_CONST
int DARSHAN_DECL(MPI_File_write_ordered)(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
#else
int DARSHAN_DECL(MPI_File_write_ordered)(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
#endif
#ifdef HAVE_MPI_CONST
int DARSHAN_DECL(MPI_File_write_shared)(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
#else
int DARSHAN_DECL(MPI_File_write_shared)(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
#endif

#endif /* DARSHAN_GOTCHA */
