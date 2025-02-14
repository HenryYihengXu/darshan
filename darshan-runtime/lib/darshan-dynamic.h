/*
 * Copyright (C) 2015 University of Chicago.
 * See COPYRIGHT notice in top-level directory.
 *
 */

#ifndef __DARSHAN_DYNAMIC_H
#define __DARSHAN_DYNAMIC_H

#ifdef HAVE_MPI
#include <mpi.h>
#endif

#ifdef DARSHAN_PRELOAD

#define DARSHAN_EXTERN_DECL(name,ret,args) \
  extern ret (*__real_ ## name)args;

#ifdef HAVE_MPI
DARSHAN_EXTERN_DECL(PMPI_File_close, int, (MPI_File *fh));
DARSHAN_EXTERN_DECL(PMPI_File_iread_at, int, (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request));
DARSHAN_EXTERN_DECL(PMPI_File_iread, int, (MPI_File fh, void  *buf, int  count, MPI_Datatype  datatype, __D_MPI_REQUEST  *request));
DARSHAN_EXTERN_DECL(PMPI_File_iread_shared, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request));
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_File_iwrite_at, int, (MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request));
#else
DARSHAN_EXTERN_DECL(PMPI_File_iwrite_at, int, (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_File_iwrite, int, (MPI_File fh, const void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request));
#else
DARSHAN_EXTERN_DECL(PMPI_File_iwrite, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_File_iwrite_shared, int, (MPI_File fh, const void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request));
#else
DARSHAN_EXTERN_DECL(PMPI_File_iwrite_shared, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_File_open, int, (MPI_Comm comm, const char *filename, int amode, MPI_Info info, MPI_File *fh));
#else
DARSHAN_EXTERN_DECL(PMPI_File_open, int, (MPI_Comm comm, char *filename, int amode, MPI_Info info, MPI_File *fh));
#endif
DARSHAN_EXTERN_DECL(PMPI_File_read_all_begin, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype));
DARSHAN_EXTERN_DECL(PMPI_File_read_all, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
DARSHAN_EXTERN_DECL(PMPI_File_read_at_all, int, (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
DARSHAN_EXTERN_DECL(PMPI_File_read_at_all_begin, int, (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype));
DARSHAN_EXTERN_DECL(PMPI_File_read_at, int, (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
DARSHAN_EXTERN_DECL(PMPI_File_read, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
DARSHAN_EXTERN_DECL(PMPI_File_read_ordered_begin, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype));
DARSHAN_EXTERN_DECL(PMPI_File_read_ordered, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
DARSHAN_EXTERN_DECL(PMPI_File_read_shared, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_File_set_view, int, (MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, const char *datarep, MPI_Info info));
#else
DARSHAN_EXTERN_DECL(PMPI_File_set_view, int, (MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, char *datarep, MPI_Info info));
#endif
DARSHAN_EXTERN_DECL(PMPI_File_sync, int, (MPI_File fh));
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_File_write_all_begin, int, (MPI_File fh, const void *buf, int count, MPI_Datatype datatype));
#else
DARSHAN_EXTERN_DECL(PMPI_File_write_all_begin, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_File_write_all, int, (MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#else
DARSHAN_EXTERN_DECL(PMPI_File_write_all, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_File_write_at_all_begin, int, (MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype));
#else
DARSHAN_EXTERN_DECL(PMPI_File_write_at_all_begin, int, (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_File_write_at_all, int, (MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#else
DARSHAN_EXTERN_DECL(PMPI_File_write_at_all, int, (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_File_write_at, int, (MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#else
DARSHAN_EXTERN_DECL(PMPI_File_write_at, int, (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_File_write, int, (MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#else
DARSHAN_EXTERN_DECL(PMPI_File_write, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_File_write_ordered_begin, int, (MPI_File fh, const void *buf, int count, MPI_Datatype datatype));
#else
DARSHAN_EXTERN_DECL(PMPI_File_write_ordered_begin, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_File_write_ordered, int, (MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#else
DARSHAN_EXTERN_DECL(PMPI_File_write_ordered, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_File_write_shared, int, (MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#else
DARSHAN_EXTERN_DECL(PMPI_File_write_shared, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#endif
DARSHAN_EXTERN_DECL(PMPI_Finalize, int, ());
DARSHAN_EXTERN_DECL(PMPI_Init, int, (int *argc, char ***argv));
DARSHAN_EXTERN_DECL(PMPI_Init_thread, int, (int *argc, char ***argv, int required, int *provided));
DARSHAN_EXTERN_DECL(PMPI_Wtime, double, ());
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_Allreduce, int, (const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm));
#else
DARSHAN_EXTERN_DECL(PMPI_Allreduce, int, (void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm));
#endif
DARSHAN_EXTERN_DECL(PMPI_Bcast, int, (void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm));
DARSHAN_EXTERN_DECL(PMPI_Comm_rank, int, (MPI_Comm comm, int *rank));
DARSHAN_EXTERN_DECL(PMPI_Comm_size, int, (MPI_Comm comm, int *size));
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_Scan, int, (const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm));
#else
DARSHAN_EXTERN_DECL(PMPI_Scan, int, (void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm));
#endif
DARSHAN_EXTERN_DECL(PMPI_Type_commit, int, (MPI_Datatype *datatype));
DARSHAN_EXTERN_DECL(PMPI_Type_contiguous, int, (int count, MPI_Datatype oldtype, MPI_Datatype *newtype));
DARSHAN_EXTERN_DECL(PMPI_Type_extent, int, (MPI_Datatype datatype, MPI_Aint *extent));
DARSHAN_EXTERN_DECL(PMPI_Type_free, int, (MPI_Datatype *datatype));
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_Type_hindexed, int, (int count, const int *array_of_blocklengths, MPI_Aint *array_of_displacements, MPI_Datatype oldtype, MPI_Datatype *newtype));
#else
DARSHAN_EXTERN_DECL(PMPI_Type_hindexed, int, (int count, int *array_of_blocklengths, MPI_Aint *array_of_displacements, MPI_Datatype oldtype, MPI_Datatype *newtype));
#endif
DARSHAN_EXTERN_DECL(PMPI_Type_get_envelope, int, (MPI_Datatype datatype, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner));
DARSHAN_EXTERN_DECL(PMPI_Type_size, int, (MPI_Datatype datatype, int *size));
DARSHAN_EXTERN_DECL(PMPI_Op_create, int, (MPI_User_function *function, int commute, MPI_Op *op));
DARSHAN_EXTERN_DECL(PMPI_Op_free, int, (MPI_Op *op));
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_Reduce, int, (const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm));
#else
DARSHAN_EXTERN_DECL(PMPI_Reduce, int, (void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_Send, int, (const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm));
#else
DARSHAN_EXTERN_DECL(PMPI_Send, int, (void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm));
#endif
DARSHAN_EXTERN_DECL(PMPI_Recv, int, (void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status));
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(PMPI_Gather, int, (const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm));
#else
DARSHAN_EXTERN_DECL(PMPI_Gather, int, (void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm));
#endif
DARSHAN_EXTERN_DECL(PMPI_Barrier, int, (MPI_Comm comm));
#endif /* HAVE_MPI */

#elif DARSHAN_GOTCHA

#define DARSHAN_EXTERN_DECL(name,ret,args) \
  extern ret (*__darshan_real_ ## name)args;

#ifdef HAVE_MPI
DARSHAN_EXTERN_DECL(MPI_File_close, int, (MPI_File *fh));
DARSHAN_EXTERN_DECL(MPI_File_iread_at, int, (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request));
DARSHAN_EXTERN_DECL(MPI_File_iread, int, (MPI_File fh, void  *buf, int  count, MPI_Datatype  datatype, __D_MPI_REQUEST  *request));
DARSHAN_EXTERN_DECL(MPI_File_iread_shared, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request));
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_File_iwrite_at, int, (MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request));
#else
DARSHAN_EXTERN_DECL(MPI_File_iwrite_at, int, (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_File_iwrite, int, (MPI_File fh, const void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request));
#else
DARSHAN_EXTERN_DECL(MPI_File_iwrite, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_File_iwrite_shared, int, (MPI_File fh, const void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request));
#else
DARSHAN_EXTERN_DECL(MPI_File_iwrite_shared, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, __D_MPI_REQUEST *request));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_File_open, int, (MPI_Comm comm, const char *filename, int amode, MPI_Info info, MPI_File *fh));
#else
DARSHAN_EXTERN_DECL(MPI_File_open, int, (MPI_Comm comm, char *filename, int amode, MPI_Info info, MPI_File *fh));
#endif
DARSHAN_EXTERN_DECL(MPI_File_read_all_begin, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype));
DARSHAN_EXTERN_DECL(MPI_File_read_all, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
DARSHAN_EXTERN_DECL(MPI_File_read_at_all, int, (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
DARSHAN_EXTERN_DECL(MPI_File_read_at_all_begin, int, (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype));
DARSHAN_EXTERN_DECL(MPI_File_read_at, int, (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
DARSHAN_EXTERN_DECL(MPI_File_read, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
DARSHAN_EXTERN_DECL(MPI_File_read_ordered_begin, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype));
DARSHAN_EXTERN_DECL(MPI_File_read_ordered, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
DARSHAN_EXTERN_DECL(MPI_File_read_shared, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_File_set_view, int, (MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, const char *datarep, MPI_Info info));
#else
DARSHAN_EXTERN_DECL(MPI_File_set_view, int, (MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, char *datarep, MPI_Info info));
#endif
DARSHAN_EXTERN_DECL(MPI_File_sync, int, (MPI_File fh));
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_File_write_all_begin, int, (MPI_File fh, const void *buf, int count, MPI_Datatype datatype));
#else
DARSHAN_EXTERN_DECL(MPI_File_write_all_begin, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_File_write_all, int, (MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#else
DARSHAN_EXTERN_DECL(MPI_File_write_all, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_File_write_at_all_begin, int, (MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype));
#else
DARSHAN_EXTERN_DECL(MPI_File_write_at_all_begin, int, (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_File_write_at_all, int, (MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#else
DARSHAN_EXTERN_DECL(MPI_File_write_at_all, int, (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_File_write_at, int, (MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#else
DARSHAN_EXTERN_DECL(MPI_File_write_at, int, (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_File_write, int, (MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#else
DARSHAN_EXTERN_DECL(MPI_File_write, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_File_write_ordered_begin, int, (MPI_File fh, const void *buf, int count, MPI_Datatype datatype));
#else
DARSHAN_EXTERN_DECL(MPI_File_write_ordered_begin, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_File_write_ordered, int, (MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#else
DARSHAN_EXTERN_DECL(MPI_File_write_ordered, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_File_write_shared, int, (MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#else
DARSHAN_EXTERN_DECL(MPI_File_write_shared, int, (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status));
#endif
DARSHAN_EXTERN_DECL(MPI_Finalize, int, ());
DARSHAN_EXTERN_DECL(MPI_Init, int, (int *argc, char ***argv));
DARSHAN_EXTERN_DECL(MPI_Init_thread, int, (int *argc, char ***argv, int required, int *provided));
DARSHAN_EXTERN_DECL(MPI_Wtime, double, ());
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_Allreduce, int, (const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm));
#else
DARSHAN_EXTERN_DECL(MPI_Allreduce, int, (void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm));
#endif
DARSHAN_EXTERN_DECL(MPI_Bcast, int, (void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm));
DARSHAN_EXTERN_DECL(MPI_Comm_rank, int, (MPI_Comm comm, int *rank));
DARSHAN_EXTERN_DECL(MPI_Comm_size, int, (MPI_Comm comm, int *size));
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_Scan, int, (const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm));
#else
DARSHAN_EXTERN_DECL(MPI_Scan, int, (void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm));
#endif
DARSHAN_EXTERN_DECL(MPI_Type_commit, int, (MPI_Datatype *datatype));
DARSHAN_EXTERN_DECL(MPI_Type_contiguous, int, (int count, MPI_Datatype oldtype, MPI_Datatype *newtype));
DARSHAN_EXTERN_DECL(MPI_Type_extent, int, (MPI_Datatype datatype, MPI_Aint *extent));
DARSHAN_EXTERN_DECL(MPI_Type_free, int, (MPI_Datatype *datatype));
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_Type_hindexed, int, (int count, const int *array_of_blocklengths, MPI_Aint *array_of_displacements, MPI_Datatype oldtype, MPI_Datatype *newtype));
#else
DARSHAN_EXTERN_DECL(MPI_Type_hindexed, int, (int count, int *array_of_blocklengths, MPI_Aint *array_of_displacements, MPI_Datatype oldtype, MPI_Datatype *newtype));
#endif
DARSHAN_EXTERN_DECL(MPI_Type_get_envelope, int, (MPI_Datatype datatype, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner));
DARSHAN_EXTERN_DECL(MPI_Type_size, int, (MPI_Datatype datatype, int *size));
DARSHAN_EXTERN_DECL(MPI_Op_create, int, (MPI_User_function *function, int commute, MPI_Op *op));
DARSHAN_EXTERN_DECL(MPI_Op_free, int, (MPI_Op *op));
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_Reduce, int, (const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm));
#else
DARSHAN_EXTERN_DECL(MPI_Reduce, int, (void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm));
#endif
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_Send, int, (const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm));
#else
DARSHAN_EXTERN_DECL(MPI_Send, int, (void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm));
#endif
DARSHAN_EXTERN_DECL(MPI_Recv, int, (void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status));
#ifdef HAVE_MPI_CONST
DARSHAN_EXTERN_DECL(MPI_Gather, int, (const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm));
#else
DARSHAN_EXTERN_DECL(MPI_Gather, int, (void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm));
#endif
DARSHAN_EXTERN_DECL(MPI_Barrier, int, (MPI_Comm comm));
#endif /* HAVE_MPI */

#endif /* DARSHAN_GOTCHA */

#endif /* __DARSHAN_DYNAMIC_H */
