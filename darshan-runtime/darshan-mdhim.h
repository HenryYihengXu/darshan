#ifdef DARSHAN_GOTCHA

#define _XOPEN_SOURCE 500
#define _GNU_SOURCE

#include "darshan-runtime-config.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <assert.h>

#include <mpi.h>
#include <mdhim.h>

#define RECORD_STRING "total-mdhim-obj-stats"

#define DARSHAN_DECL(func) __wrap_##func

mdhim_rm_t * DARSHAN_DECL(mdhimPut)(mdhim_t *md,
            index_t *index, void *primary_key, size_t primary_key_len,
            void *value, int value_len);
mdhim_grm_t * DARSHAN_DECL(mdhimGet)(mdhim_t *md,
        index_t *index, void *key, size_t key_len, int op);
int DARSHAN_DECL(mdhimInit)(mdhim_t *md, mdhim_options_t *opts);

#endif /* DARSHAN_GOTCHA */
