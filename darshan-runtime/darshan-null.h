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

#ifndef DARSHAN_DECL
#define DARSHAN_DECL(func) __gotcha_wrap_##func
#endif

int DARSHAN_DECL(foo)(const char *name, int arg1);

#endif /* DARSHAN_GOTCHA */
