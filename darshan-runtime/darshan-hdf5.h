#ifdef DARSHAN_GOTCHA

#define _XOPEN_SOURCE 500
#define _GNU_SOURCE

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

#include <hdf5.h>

#ifndef DARSHAN_DECL
#define DARSHAN_DECL(func) __gotcha_wrap_##func
#endif

hid_t DARSHAN_DECL(H5Fcreate)(const char *filename, unsigned flags, hid_t create_plist, hid_t access_plist);
hid_t DARSHAN_DECL(H5Fopen)(const char *filename, unsigned flags, hid_t access_plist);
hid_t DARSHAN_DECL(H5Fflush)(hid_t object_id, H5F_scope_t scope);
hid_t DARSHAN_DECL(H5Fclose)(hid_t file_id);
hid_t DARSHAN_DECL(H5Dcreate1)(hid_t loc_id, const char *name, hid_t type_id, hid_t space_id, hid_t dcpl_id);
hid_t DARSHAN_DECL(H5Dcreate2)(hid_t loc_id, const char *name, hid_t dtype_id, hid_t space_id, hid_t lcpl_id, hid_t dcpl_id, hid_t dapl_id);
hid_t DARSHAN_DECL(H5Dopen1)(hid_t loc_id, const char *name);
hid_t DARSHAN_DECL(H5Dopen2)(hid_t loc_id, const char *name, hid_t dapl_id);
herr_t DARSHAN_DECL(H5Dread)(hid_t dataset_id, hid_t mem_type_id, hid_t mem_space_id, hid_t file_space_id, hid_t xfer_plist_id, void * buf);
herr_t DARSHAN_DECL(H5Dwrite)(hid_t dataset_id, hid_t mem_type_id, hid_t mem_space_id, hid_t file_space_id, hid_t xfer_plist_id, const void * buf);
herr_t DARSHAN_DECL(H5Dflush)(hid_t dataset_id);
herr_t DARSHAN_DECL(H5Dclose)(hid_t dataset_id);

#endif /* DARSHAN_GOTCHA */
