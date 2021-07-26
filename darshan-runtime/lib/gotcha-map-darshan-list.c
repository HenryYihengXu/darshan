#ifdef DARSHAN_GOTCHA
#include "darshan-runtime-config.h"
#include <stdio.h>
#include <stdlib.h>
#include "darshan.h"
#include "gotcha-map-darshan-list.h"
#include "darshan-posix.h"
#include "darshan-stdio.h"
#include "darshan-mpiio.h"
#include "darshan-core-init-finalize.h"
#include "darshan-hdf5.h"
#include "darshan-null.h"
#include "darshan-pnetcdf.h"

#ifdef BUILD_MDHIM_MODULE
#include "darshan-mdhim.h"
#endif

struct gotcha_binding_t darshan_wrappers[] = {

#ifdef BUILD_POSIX_MODULE
    /* posix */
    { "open", DARSHAN_DECL(open), &DARSHAN_WRAPPEE_HANDLE(open) },
    { "open64", DARSHAN_DECL(open64), &DARSHAN_WRAPPEE_HANDLE(open64) },
    { "__open_2", DARSHAN_DECL(__open_2), &DARSHAN_WRAPPEE_HANDLE(__open_2) },
    { "openat", DARSHAN_DECL(openat), &DARSHAN_WRAPPEE_HANDLE(openat) },
    { "openat64", DARSHAN_DECL(openat64), &DARSHAN_WRAPPEE_HANDLE(openat64) },
    { "creat", DARSHAN_DECL(creat), &DARSHAN_WRAPPEE_HANDLE(creat) },
    { "creat64", DARSHAN_DECL(creat64), &DARSHAN_WRAPPEE_HANDLE(creat64) },
    { "dup", DARSHAN_DECL(dup), &DARSHAN_WRAPPEE_HANDLE(dup) },
    { "dup2", DARSHAN_DECL(dup2), &DARSHAN_WRAPPEE_HANDLE(dup2) },
    { "dup3", DARSHAN_DECL(dup3), &DARSHAN_WRAPPEE_HANDLE(dup3) },
    { "fileno", DARSHAN_DECL(fileno), &DARSHAN_WRAPPEE_HANDLE(fileno) },
    { "mkstemp", DARSHAN_DECL(mkstemp), &DARSHAN_WRAPPEE_HANDLE(mkstemp) },
    { "mkostemp", DARSHAN_DECL(mkostemp), &DARSHAN_WRAPPEE_HANDLE(mkostemp) },
    { "mkstemps", DARSHAN_DECL(mkstemps), &DARSHAN_WRAPPEE_HANDLE(mkstemps) },
    { "mkostemps", DARSHAN_DECL(mkostemps), &DARSHAN_WRAPPEE_HANDLE(mkostemps) },
    { "read", DARSHAN_DECL(read), &DARSHAN_WRAPPEE_HANDLE(read) },
    { "write", DARSHAN_DECL(write), &DARSHAN_WRAPPEE_HANDLE(write) },
    { "pread", DARSHAN_DECL(pread), &DARSHAN_WRAPPEE_HANDLE(pread) },
    { "pwrite", DARSHAN_DECL(pwrite), &DARSHAN_WRAPPEE_HANDLE(pwrite) },
    { "pread64", DARSHAN_DECL(pread64), &DARSHAN_WRAPPEE_HANDLE(pread64) },
    { "pwrite64", DARSHAN_DECL(pwrite64), &DARSHAN_WRAPPEE_HANDLE(pwrite64) },
    { "readv", DARSHAN_DECL(readv), &DARSHAN_WRAPPEE_HANDLE(readv) },
#ifdef HAVE_PREADV
    { "preadv", DARSHAN_DECL(preadv), &DARSHAN_WRAPPEE_HANDLE(preadv) },
    { "preadv64", DARSHAN_DECL(preadv64), &DARSHAN_WRAPPEE_HANDLE(preadv64) },
#endif
#ifdef HAVE_PREADV2
    { "preadv2", DARSHAN_DECL(preadv2), &DARSHAN_WRAPPEE_HANDLE(preadv2) },
    { "preadv64v2", DARSHAN_DECL(preadv64v2), &DARSHAN_WRAPPEE_HANDLE(preadv64v2) },
#endif
    { "writev", DARSHAN_DECL(writev), &DARSHAN_WRAPPEE_HANDLE(writev) },
#ifdef HAVE_PWRITEV
    { "pwritev", DARSHAN_DECL(pwritev), &DARSHAN_WRAPPEE_HANDLE(pwritev) },
    { "pwritev64", DARSHAN_DECL(pwritev64), &DARSHAN_WRAPPEE_HANDLE(pwritev64) },
#endif
#ifdef HAVE_PWRITEV2
    { "pwritev2", DARSHAN_DECL(pwritev2), &DARSHAN_WRAPPEE_HANDLE(pwritev2) },
    { "pwritev64v2", DARSHAN_DECL(pwritev64v2), &DARSHAN_WRAPPEE_HANDLE(pwritev64v2) },
#endif
    { "lseek", DARSHAN_DECL(lseek), &DARSHAN_WRAPPEE_HANDLE(lseek) },
    { "lseek64", DARSHAN_DECL(lseek64), &DARSHAN_WRAPPEE_HANDLE(lseek64) },
    { "__xstat", DARSHAN_DECL(__xstat), &DARSHAN_WRAPPEE_HANDLE(__xstat) },
    { "__xstat64", DARSHAN_DECL(__xstat64), &DARSHAN_WRAPPEE_HANDLE(__xstat64) },
    { "__lxstat", DARSHAN_DECL(__lxstat), &DARSHAN_WRAPPEE_HANDLE(__lxstat) },
    { "__lxstat64", DARSHAN_DECL(__lxstat64), &DARSHAN_WRAPPEE_HANDLE(__lxstat64) },
    { "__fxstat", DARSHAN_DECL(__fxstat), &DARSHAN_WRAPPEE_HANDLE(__fxstat) },
    { "__fxstat64", DARSHAN_DECL(__fxstat64), &DARSHAN_WRAPPEE_HANDLE(__fxstat64) },
#ifdef DARSHAN_WRAP_MMAP
    { "mmap", DARSHAN_DECL(mmap), &DARSHAN_WRAPPEE_HANDLE(mmap) },
    { "mmap64", DARSHAN_DECL(mmap64), &DARSHAN_WRAPPEE_HANDLE(mmap64) },
#endif /* DARSHAN_WRAP_MMAP */
    { "fsync", DARSHAN_DECL(fsync), &DARSHAN_WRAPPEE_HANDLE(fsync) },
    { "fdatasync", DARSHAN_DECL(fdatasync), &DARSHAN_WRAPPEE_HANDLE(fdatasync) },
    { "close", DARSHAN_DECL(close), &DARSHAN_WRAPPEE_HANDLE(close) },
    { "aio_read", DARSHAN_DECL(aio_read), &DARSHAN_WRAPPEE_HANDLE(aio_read) },
    { "aio_write", DARSHAN_DECL(aio_write), &DARSHAN_WRAPPEE_HANDLE(aio_write) },
    { "aio_read64", DARSHAN_DECL(aio_read64), &DARSHAN_WRAPPEE_HANDLE(aio_read64) },
    { "aio_write64", DARSHAN_DECL(aio_write64), &DARSHAN_WRAPPEE_HANDLE(aio_write64) },
    { "aio_return", DARSHAN_DECL(aio_return), &DARSHAN_WRAPPEE_HANDLE(aio_return) },
    { "aio_return64", DARSHAN_DECL(aio_return64), &DARSHAN_WRAPPEE_HANDLE(aio_return64) },
    { "lio_listio", DARSHAN_DECL(lio_listio), &DARSHAN_WRAPPEE_HANDLE(lio_listio) },
    { "lio_listio64", DARSHAN_DECL(lio_listio64), &DARSHAN_WRAPPEE_HANDLE(lio_listio64) },
    { "rename", DARSHAN_DECL(rename), &DARSHAN_WRAPPEE_HANDLE(rename) },
#endif

#ifdef BUILD_STDIO_MODULE    
    /* stdio */
    { "fopen", DARSHAN_DECL(fopen), &DARSHAN_WRAPPEE_HANDLE(fopen) },
    { "fopen64", DARSHAN_DECL(fopen64), &DARSHAN_WRAPPEE_HANDLE(fopen64) },
    { "fdopen", DARSHAN_DECL(fdopen), &DARSHAN_WRAPPEE_HANDLE(fdopen) },
    { "freopen", DARSHAN_DECL(freopen), &DARSHAN_WRAPPEE_HANDLE(freopen) },
    { "freopen64", DARSHAN_DECL(freopen64), &DARSHAN_WRAPPEE_HANDLE(freopen64) },
    { "fclose", DARSHAN_DECL(fclose), &DARSHAN_WRAPPEE_HANDLE(fclose) },
    { "fflush", DARSHAN_DECL(fflush), &DARSHAN_WRAPPEE_HANDLE(fflush) },
    { "fwrite", DARSHAN_DECL(fwrite), &DARSHAN_WRAPPEE_HANDLE(fwrite) },
    { "fputc", DARSHAN_DECL(fputc), &DARSHAN_WRAPPEE_HANDLE(fputc) },
    { "putw", DARSHAN_DECL(putw), &DARSHAN_WRAPPEE_HANDLE(putw) },
    { "fputs", DARSHAN_DECL(fputs), &DARSHAN_WRAPPEE_HANDLE(fputs) },
    { "fprintf", DARSHAN_DECL(fprintf), &DARSHAN_WRAPPEE_HANDLE(fprintf) },
    { "printf", DARSHAN_DECL(printf), &DARSHAN_WRAPPEE_HANDLE(printf) },
    { "vfprintf", DARSHAN_DECL(vfprintf), &DARSHAN_WRAPPEE_HANDLE(vfprintf) },
    { "vprintf", DARSHAN_DECL(vprintf), &DARSHAN_WRAPPEE_HANDLE(vprintf) },
    { "fread", DARSHAN_DECL(fread), &DARSHAN_WRAPPEE_HANDLE(fread) },
    { "fgetc", DARSHAN_DECL(fgetc), &DARSHAN_WRAPPEE_HANDLE(fgetc) },
    { "getw", DARSHAN_DECL(getw), &DARSHAN_WRAPPEE_HANDLE(getw) },
    { "_IO_getc", DARSHAN_DECL(_IO_getc), &DARSHAN_WRAPPEE_HANDLE(_IO_getc) },
    { "_IO_putc", DARSHAN_DECL(_IO_putc), &DARSHAN_WRAPPEE_HANDLE(_IO_putc) },
    { "fscanf", DARSHAN_DECL(fscanf), &DARSHAN_WRAPPEE_HANDLE(fscanf) },
#ifndef HAVE_FSCANF_REDIRECT
    { "__isoc99_fscanf", DARSHAN_DECL(__isoc99_fscanf), &DARSHAN_WRAPPEE_HANDLE(__isoc99_fscanf) },
#endif
    { "vfscanf", DARSHAN_DECL(vfscanf), &DARSHAN_WRAPPEE_HANDLE(vfscanf) },
    { "fgets", DARSHAN_DECL(fgets), &DARSHAN_WRAPPEE_HANDLE(fgets) },
    { "fseek", DARSHAN_DECL(fseek), &DARSHAN_WRAPPEE_HANDLE(fseek) },
    { "fseeko", DARSHAN_DECL(fseeko), &DARSHAN_WRAPPEE_HANDLE(fseeko) },
    { "fseeko64", DARSHAN_DECL(fseeko64), &DARSHAN_WRAPPEE_HANDLE(fseeko64) },
    { "fsetpos", DARSHAN_DECL(fsetpos), &DARSHAN_WRAPPEE_HANDLE(fsetpos) },
    { "fsetpos64", DARSHAN_DECL(fsetpos64), &DARSHAN_WRAPPEE_HANDLE(fsetpos64) },
    { "rewind", DARSHAN_DECL(rewind), &DARSHAN_WRAPPEE_HANDLE(rewind) },
    // fileno and vfprintf defined in the middle of darshan-stdio.c and darshan-core.c. But already in here.
#endif

#ifdef BUILD_MPIIO_MODULE    
    /* mpiio */
    { "MPI_File_close", DARSHAN_DECL(MPI_File_close), &DARSHAN_WRAPPEE_HANDLE(MPI_File_close) },
    { "MPI_File_iread_at", DARSHAN_DECL(MPI_File_iread_at), &DARSHAN_WRAPPEE_HANDLE(MPI_File_iread_at) },
    { "MPI_File_iread", DARSHAN_DECL(MPI_File_iread), &DARSHAN_WRAPPEE_HANDLE(MPI_File_iread) },
    { "MPI_File_iread_shared", DARSHAN_DECL(MPI_File_iread_shared), &DARSHAN_WRAPPEE_HANDLE(MPI_File_iread_shared) },
    { "MPI_File_iwrite_at", DARSHAN_DECL(MPI_File_iwrite_at), &DARSHAN_WRAPPEE_HANDLE(MPI_File_iwrite_at) },
    { "MPI_File_iwrite", DARSHAN_DECL(MPI_File_iwrite), &DARSHAN_WRAPPEE_HANDLE(MPI_File_iwrite) },
    { "MPI_File_iwrite_shared", DARSHAN_DECL(MPI_File_iwrite_shared), &DARSHAN_WRAPPEE_HANDLE(MPI_File_iwrite_shared) },
    { "MPI_File_open", DARSHAN_DECL(MPI_File_open), &DARSHAN_WRAPPEE_HANDLE(MPI_File_open) },
    { "MPI_File_read_all_begin", DARSHAN_DECL(MPI_File_read_all_begin), &DARSHAN_WRAPPEE_HANDLE(MPI_File_read_all_begin) },
    { "MPI_File_read_all", DARSHAN_DECL(MPI_File_read_all), &DARSHAN_WRAPPEE_HANDLE(MPI_File_read_all) },
    { "MPI_File_read_at_all", DARSHAN_DECL(MPI_File_read_at_all), &DARSHAN_WRAPPEE_HANDLE(MPI_File_read_at_all) },
    { "MPI_File_read_at_all_begin", DARSHAN_DECL(MPI_File_read_at_all_begin), &DARSHAN_WRAPPEE_HANDLE(MPI_File_read_at_all_begin) },
    { "MPI_File_read_at", DARSHAN_DECL(MPI_File_read_at), &DARSHAN_WRAPPEE_HANDLE(MPI_File_read_at) },
    { "MPI_File_read", DARSHAN_DECL(MPI_File_read), &DARSHAN_WRAPPEE_HANDLE(MPI_File_read) },
    { "MPI_File_read_ordered_begin", DARSHAN_DECL(MPI_File_read_ordered_begin), &DARSHAN_WRAPPEE_HANDLE(MPI_File_read_ordered_begin) },
    { "MPI_File_read_ordered", DARSHAN_DECL(MPI_File_read_ordered), &DARSHAN_WRAPPEE_HANDLE(MPI_File_read_ordered) },
    { "MPI_File_read_shared", DARSHAN_DECL(MPI_File_read_shared), &DARSHAN_WRAPPEE_HANDLE(MPI_File_read_shared) },
    { "MPI_File_set_view", DARSHAN_DECL(MPI_File_set_view), &DARSHAN_WRAPPEE_HANDLE(MPI_File_set_view) },
    { "MPI_File_sync", DARSHAN_DECL(MPI_File_sync), &DARSHAN_WRAPPEE_HANDLE(MPI_File_sync) },
    { "MPI_File_write_all_begin", DARSHAN_DECL(MPI_File_write_all_begin), &DARSHAN_WRAPPEE_HANDLE(MPI_File_write_all_begin) },
    { "MPI_File_write_all", DARSHAN_DECL(MPI_File_write_all), &DARSHAN_WRAPPEE_HANDLE(MPI_File_write_all) },
    { "MPI_File_write_at_all_begin", DARSHAN_DECL(MPI_File_write_at_all_begin), &DARSHAN_WRAPPEE_HANDLE(MPI_File_write_at_all_begin) },
    { "MPI_File_write_at_all", DARSHAN_DECL(MPI_File_write_at_all), &DARSHAN_WRAPPEE_HANDLE(MPI_File_write_at_all) },
    { "MPI_File_write_at", DARSHAN_DECL(MPI_File_write_at), &DARSHAN_WRAPPEE_HANDLE(MPI_File_write_at) },
    { "MPI_File_write", DARSHAN_DECL(MPI_File_write), &DARSHAN_WRAPPEE_HANDLE(MPI_File_write) },
    { "MPI_File_write_ordered_begin", DARSHAN_DECL(MPI_File_write_ordered_begin), &DARSHAN_WRAPPEE_HANDLE(MPI_File_write_ordered_begin) },
    { "MPI_File_write_ordered", DARSHAN_DECL(MPI_File_write_ordered), &DARSHAN_WRAPPEE_HANDLE(MPI_File_write_ordered) },
    { "MPI_File_write_shared", DARSHAN_DECL(MPI_File_write_shared), &DARSHAN_WRAPPEE_HANDLE(MPI_File_write_shared) },

    /* core-init-finalize */
#ifdef WITH_INIT_FINI
    { "MPI_Init", DARSHAN_DECL(MPI_Init), &DARSHAN_WRAPPEE_HANDLE(MPI_Init) },
    { "MPI_Init_thread", DARSHAN_DECL(MPI_Init_thread), &DARSHAN_WRAPPEE_HANDLE(MPI_Init_thread) },
#endif
    { "MPI_Finalize", DARSHAN_DECL(MPI_Finalize), &DARSHAN_WRAPPEE_HANDLE(MPI_Finalize) },
#endif

#ifdef BUILD_HDF5_MODULE
    /* hdf5 */
    { "H5Fcreate", DARSHAN_DECL(H5Fcreate), &DARSHAN_WRAPPEE_HANDLE(H5Fcreate) },
    { "H5Fopen", DARSHAN_DECL(H5Fopen), &DARSHAN_WRAPPEE_HANDLE(H5Fopen) },
    { "H5Fflush", DARSHAN_DECL(H5Fflush), &DARSHAN_WRAPPEE_HANDLE(H5Fflush) },
    { "H5Fclose", DARSHAN_DECL(H5Fclose), &DARSHAN_WRAPPEE_HANDLE(H5Fclose) },
    { "H5Dcreate1", DARSHAN_DECL(H5Dcreate1), &DARSHAN_WRAPPEE_HANDLE(H5Dcreate1) },
    { "H5Dcreate2", DARSHAN_DECL(H5Dcreate2), &DARSHAN_WRAPPEE_HANDLE(H5Dcreate2) },
    { "H5Dopen1", DARSHAN_DECL(H5Dopen1), &DARSHAN_WRAPPEE_HANDLE(H5Dopen1) },
    { "H5Dopen2", DARSHAN_DECL(H5Dopen2), &DARSHAN_WRAPPEE_HANDLE(H5Dopen2) },
    { "H5Dread", DARSHAN_DECL(H5Dread), &DARSHAN_WRAPPEE_HANDLE(H5Dread) },
    { "H5Dwrite", DARSHAN_DECL(H5Dwrite), &DARSHAN_WRAPPEE_HANDLE(H5Dwrite) },
#ifdef DARSHAN_HDF5_VERS_1_10_PLUS
    { "H5Dflush", DARSHAN_DECL(H5Dflush), &DARSHAN_WRAPPEE_HANDLE(H5Dflush) },
#endif
    { "H5Dclose", DARSHAN_DECL(H5Dclose), &DARSHAN_WRAPPEE_HANDLE(H5Dclose) },
#endif

#ifdef BUILD_MDHIM_MODULE
    /* mdhim */
    { "mdhimPut", DARSHAN_DECL(mdhimPut), &DARSHAN_WRAPPEE_HANDLE(mdhimPut) },
    { "mdhimGet", DARSHAN_DECL(mdhimGet), &DARSHAN_WRAPPEE_HANDLE(mdhimGet) },
    { "mdhimInit", DARSHAN_DECL(mdhimInit), &DARSHAN_WRAPPEE_HANDLE(mdhimInit) },
#endif

#ifdef BUILD_NULL_MODULE
    /* null */
    { "foo", DARSHAN_DECL(foo), &DARSHAN_WRAPPEE_HANDLE(foo) },
#endif

#ifdef BUILD_PNETCDF_MODULE
    /* pnetcdf */
    // { "ncmpi_create", DARSHAN_DECL(ncmpi_create), &DARSHAN_WRAPPEE_HANDLE(ncmpi_create) },
    // { "ncmpi_open", DARSHAN_DECL(ncmpi_open), &DARSHAN_WRAPPEE_HANDLE(ncmpi_open) },
    // { "ncmpi_close", DARSHAN_DECL(ncmpi_close), &DARSHAN_WRAPPEE_HANDLE(ncmpi_close) },
#endif

};

#define GOTCHA_NFUNCS (sizeof(darshan_wrappers) / sizeof(gotcha_binding_t))

int setup_darshan_gotcha_wrappers(int priority)
{
    #ifdef BUILD_POSIX_MODULE
    fprintf(stderr, "\n\nBUILD_POSIX_MODULE is defined \n\n");
    #else
    fprintf(stderr, "\n\nBUILD_POSIX_MODULE is not defined \n\n");
    #endif

    #ifdef BUILD_STDIO_MODULE
    fprintf(stderr, "\n\nBUILD_STDIO_MODULE is defined \n\n");
    #else
    fprintf(stderr, "\n\nBUILD_STDIO_MODULE is not defined \n\n");
    #endif

    #ifdef BUILD_MPIIO_MODULE
    fprintf(stderr, "\n\nBUILD_MPIIO_MODULE is defined \n\n");
    #else
    fprintf(stderr, "\n\nBUILD_MPIIO_MODULE is not defined \n\n");
    #endif

    #ifdef BUILD_PNETCDF_MODULE
    fprintf(stderr, "\n\nBUILD_PNETCDF_MODULE is defined \n\n");
    #else
    fprintf(stderr, "\n\nBUILD_PNETCDF_MODULE is not defined \n\n");
    #endif

    #ifdef BUILD_HDF5_MODULE
    fprintf(stderr, "\n\nBUILD_HDF5_MODULE is defined \n\n");
    #else
    fprintf(stderr, "\n\nBUILD_HDF5_MODULE is not defined \n\n");
    #endif
    
    #ifdef BUILD_MDHIM_MODULE
    fprintf(stderr, "\n\nBUILD_MDHIM_MODULE is defined \n\n");
    #else
    fprintf(stderr, "\n\nBUILD_MDHIM_MODULE is not defined \n\n");
    #endif

    /* insert our I/O wrappers using gotcha */
    fprintf(stderr, "darshan setup gotcha wrappers with priority = %d\n", priority);
    enum gotcha_error_t result;
    result = gotcha_set_priority("darshan", priority);
    if (result != GOTCHA_SUCCESS) {
      fprintf(stderr, "gotcha_darshan_set_priority returned %d\n", (int) result);
      return -1;
    }
    result = gotcha_wrap(darshan_wrappers, GOTCHA_NFUNCS, "darshan");
    if (result != GOTCHA_SUCCESS) {
        fprintf(stderr, "gotcha_wrap() returned %d\n", (int) result);
        if (result == GOTCHA_FUNCTION_NOT_FOUND) {
            /* one or more functions were not found */
            void* fn;
            gotcha_wrappee_handle_t* hdlptr;
            int i;
            for (i = 0; i < GOTCHA_NFUNCS; i++) {
                hdlptr = darshan_wrappers[i].function_handle;
                fn = gotcha_get_wrappee(*hdlptr);
                if (NULL == fn) {
                    fprintf(stderr, "Gotcha failed to wrap function '%s'\n",
                            darshan_wrappers[i].name);
                }
            }
        } else {
            fprintf(stderr, "gotcha_wrap() fatal %d\n", (int) result);
            return -1;
        }
    }
    return 0;
}
#endif /* DARSHAN_GOTCHA */
