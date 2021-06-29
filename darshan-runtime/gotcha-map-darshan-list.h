#ifdef DARSHAN_GOTCHA
#include "gotcha/gotcha_types.h"
#include "gotcha/gotcha.h"

/* define gotcha-specific state to use with our wrapper */
#define DARSHAN_WRAPPEE_HANDLE_DECL(func) \
gotcha_wrappee_handle_t wrappee_handle_##func

#define DARSHAN_WRAPPEE_HANDLE(func) wrappee_handle_##func

/* posix I/O */
DARSHAN_WRAPPEE_HANDLE_DECL(open);
DARSHAN_WRAPPEE_HANDLE_DECL(open64);
DARSHAN_WRAPPEE_HANDLE_DECL(__open_2);
DARSHAN_WRAPPEE_HANDLE_DECL(openat);
DARSHAN_WRAPPEE_HANDLE_DECL(openat64);
DARSHAN_WRAPPEE_HANDLE_DECL(creat);
DARSHAN_WRAPPEE_HANDLE_DECL(creat64);
DARSHAN_WRAPPEE_HANDLE_DECL(dup);
DARSHAN_WRAPPEE_HANDLE_DECL(dup2);
DARSHAN_WRAPPEE_HANDLE_DECL(dup3);
DARSHAN_WRAPPEE_HANDLE_DECL(fileno);
DARSHAN_WRAPPEE_HANDLE_DECL(mkstemp);
DARSHAN_WRAPPEE_HANDLE_DECL(mkostemp);
DARSHAN_WRAPPEE_HANDLE_DECL(mkstemps);
DARSHAN_WRAPPEE_HANDLE_DECL(mkostemps);
DARSHAN_WRAPPEE_HANDLE_DECL(read);
DARSHAN_WRAPPEE_HANDLE_DECL(write);
DARSHAN_WRAPPEE_HANDLE_DECL(pread);
DARSHAN_WRAPPEE_HANDLE_DECL(pwrite);
DARSHAN_WRAPPEE_HANDLE_DECL(pread64);
DARSHAN_WRAPPEE_HANDLE_DECL(pwrite64);
DARSHAN_WRAPPEE_HANDLE_DECL(readv);
#ifdef HAVE_PREADV
DARSHAN_WRAPPEE_HANDLE_DECL(preadv);
DARSHAN_WRAPPEE_HANDLE_DECL(preadv64);
#endif
#ifdef HAVE_PREADV2
DARSHAN_WRAPPEE_HANDLE_DECL(preadv2);
DARSHAN_WRAPPEE_HANDLE_DECL(preadv64v2);
#endif
DARSHAN_WRAPPEE_HANDLE_DECL(writev);
#ifdef HAVE_PWRITEV
DARSHAN_WRAPPEE_HANDLE_DECL(pwritev);
DARSHAN_WRAPPEE_HANDLE_DECL(pwritev64);
#endif
#ifdef HAVE_PWRITEV2
DARSHAN_WRAPPEE_HANDLE_DECL(pwritev2);
DARSHAN_WRAPPEE_HANDLE_DECL(pwritev64v2);
#endif
DARSHAN_WRAPPEE_HANDLE_DECL(lseek);
DARSHAN_WRAPPEE_HANDLE_DECL(lseek64);
DARSHAN_WRAPPEE_HANDLE_DECL(__xstat);
DARSHAN_WRAPPEE_HANDLE_DECL(__xstat64);
DARSHAN_WRAPPEE_HANDLE_DECL(__lxstat);
DARSHAN_WRAPPEE_HANDLE_DECL(__lxstat64);
DARSHAN_WRAPPEE_HANDLE_DECL(__fxstat);
DARSHAN_WRAPPEE_HANDLE_DECL(__fxstat64);
#ifdef DARSHAN_WRAP_MMAP
DARSHAN_WRAPPEE_HANDLE_DECL(mmap);
DARSHAN_WRAPPEE_HANDLE_DECL(mmap64);
#endif /* DARSHAN_WRAP_MMAP */
DARSHAN_WRAPPEE_HANDLE_DECL(fsync);
DARSHAN_WRAPPEE_HANDLE_DECL(fdatasync);
DARSHAN_WRAPPEE_HANDLE_DECL(close);
DARSHAN_WRAPPEE_HANDLE_DECL(aio_read);
DARSHAN_WRAPPEE_HANDLE_DECL(aio_write);
DARSHAN_WRAPPEE_HANDLE_DECL(aio_read64);
DARSHAN_WRAPPEE_HANDLE_DECL(aio_write64);
DARSHAN_WRAPPEE_HANDLE_DECL(aio_return);
DARSHAN_WRAPPEE_HANDLE_DECL(aio_return64);
DARSHAN_WRAPPEE_HANDLE_DECL(lio_listio);
DARSHAN_WRAPPEE_HANDLE_DECL(lio_listio64);
DARSHAN_WRAPPEE_HANDLE_DECL(rename);


/* stdio */
DARSHAN_WRAPPEE_HANDLE_DECL(fopen);
DARSHAN_WRAPPEE_HANDLE_DECL(fopen64);
DARSHAN_WRAPPEE_HANDLE_DECL(fdopen);
DARSHAN_WRAPPEE_HANDLE_DECL(freopen);
DARSHAN_WRAPPEE_HANDLE_DECL(freopen64);
DARSHAN_WRAPPEE_HANDLE_DECL(fclose);
DARSHAN_WRAPPEE_HANDLE_DECL(fflush);
DARSHAN_WRAPPEE_HANDLE_DECL(fwrite);
DARSHAN_WRAPPEE_HANDLE_DECL(fputc);
DARSHAN_WRAPPEE_HANDLE_DECL(putw);
DARSHAN_WRAPPEE_HANDLE_DECL(fputs);
DARSHAN_WRAPPEE_HANDLE_DECL(fprintf);
DARSHAN_WRAPPEE_HANDLE_DECL(printf);
DARSHAN_WRAPPEE_HANDLE_DECL(vfprintf);
DARSHAN_WRAPPEE_HANDLE_DECL(vprintf);
DARSHAN_WRAPPEE_HANDLE_DECL(fread);
DARSHAN_WRAPPEE_HANDLE_DECL(fgetc);
DARSHAN_WRAPPEE_HANDLE_DECL(getw);
DARSHAN_WRAPPEE_HANDLE_DECL(_IO_getc);
DARSHAN_WRAPPEE_HANDLE_DECL(_IO_putc);
DARSHAN_WRAPPEE_HANDLE_DECL(fscanf);
#ifndef HAVE_FSCANF_REDIRECT
DARSHAN_WRAPPEE_HANDLE_DECL(__isoc99_fscanf);
#endif
DARSHAN_WRAPPEE_HANDLE_DECL(vfscanf);
DARSHAN_WRAPPEE_HANDLE_DECL(fgets);
DARSHAN_WRAPPEE_HANDLE_DECL(fseek);
DARSHAN_WRAPPEE_HANDLE_DECL(fseeko);
DARSHAN_WRAPPEE_HANDLE_DECL(fseeko64);
DARSHAN_WRAPPEE_HANDLE_DECL(fsetpos);
DARSHAN_WRAPPEE_HANDLE_DECL(fsetpos64);
DARSHAN_WRAPPEE_HANDLE_DECL(rewind);

/* mpiio */
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_close);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_iread_at);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_iread);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_iread_shared);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_iwrite_at);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_iwrite);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_iwrite_shared);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_open);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_read_all_begin);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_read_all);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_read_at_all);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_read_at_all_begin);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_read_at);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_read);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_read_ordered_begin);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_read_ordered);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_read_shared);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_set_view);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_sync);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_write_all_begin);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_write_all);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_write_at_all_begin);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_write_at_all);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_write_at);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_write);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_write_ordered_begin);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_write_ordered);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_File_write_shared);

/* core-init-finalize */
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_Init);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_Init_thread);
DARSHAN_WRAPPEE_HANDLE_DECL(MPI_Finalize);

/* hdf5 */
DARSHAN_WRAPPEE_HANDLE_DECL(H5Fcreate);
DARSHAN_WRAPPEE_HANDLE_DECL(H5Fopen);
DARSHAN_WRAPPEE_HANDLE_DECL(H5Fflush);
DARSHAN_WRAPPEE_HANDLE_DECL(H5Fclose);
DARSHAN_WRAPPEE_HANDLE_DECL(H5Dcreate1);
DARSHAN_WRAPPEE_HANDLE_DECL(H5Dcreate2);
DARSHAN_WRAPPEE_HANDLE_DECL(H5Dopen1);
DARSHAN_WRAPPEE_HANDLE_DECL(H5Dopen2);
DARSHAN_WRAPPEE_HANDLE_DECL(H5Dread);
DARSHAN_WRAPPEE_HANDLE_DECL(H5Dwrite);
#ifdef DARSHAN_HDF5_VERS_1_10_PLUS
DARSHAN_WRAPPEE_HANDLE_DECL(H5Dflush);
#endif
DARSHAN_WRAPPEE_HANDLE_DECL(H5Dclose);

/* mdhim */
DARSHAN_WRAPPEE_HANDLE_DECL(mdhimPut);
DARSHAN_WRAPPEE_HANDLE_DECL(mdhimGet);
DARSHAN_WRAPPEE_HANDLE_DECL(mdhimInit);

/* null */
DARSHAN_WRAPPEE_HANDLE_DECL(foo);

/* pnetcdf */
DARSHAN_WRAPPEE_HANDLE_DECL(ncmpi_create);
DARSHAN_WRAPPEE_HANDLE_DECL(ncmpi_open);
DARSHAN_WRAPPEE_HANDLE_DECL(ncmpi_close);

int setup_gotcha_wrappers(void);
#endif /* DARSHAN_GOTCHA */