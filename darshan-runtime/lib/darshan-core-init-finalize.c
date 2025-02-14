/*
 * Copyright (C) 2015 University of Chicago.
 * See COPYRIGHT notice in top-level directory.
 *
 */

#ifdef HAVE_CONFIG_H
# include <darshan-runtime-config.h>
#endif

#define _XOPEN_SOURCE 500
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#ifdef HAVE_MPI
#include <mpi.h>
#endif

#include "darshan.h"
#include "darshan-core.h"
#include "darshan-dynamic.h"

#ifdef DARSHAN_GOTCHA
#include "gotcha-map-darshan-list.h"
#endif

#ifndef DARSHAN_GOTCHA
#ifdef HAVE_MPI
DARSHAN_FORWARD_DECL(PMPI_Finalize, int, ());
DARSHAN_FORWARD_DECL(PMPI_Init, int, (int *argc, char ***argv));
DARSHAN_FORWARD_DECL(PMPI_Init_thread, int, (int *argc, char ***argv, int required, int *provided));

int DARSHAN_DECL(MPI_Init)(int *argc, char ***argv)
{
    int ret;

    MAP_OR_FAIL(PMPI_Init);

    ret = DARSHAN_REAL_CALL(PMPI_Init)(argc, argv);
    if(ret != MPI_SUCCESS)
    {
        return(ret);
    }

    if(argc && argv)
    {
        darshan_core_initialize(*argc, *argv);
    }
    else
    {
        /* we don't see argc and argv here in fortran */
        darshan_core_initialize(0, NULL);
    }

    return(ret);
}
DARSHAN_WRAPPER_MAP(PMPI_Init, int, (int *argc, char ***argv), MPI_Init)

int DARSHAN_DECL(MPI_Init_thread)(int *argc, char ***argv, int required, int *provided)
{
    int ret;

    MAP_OR_FAIL(PMPI_Init_thread);

    ret = DARSHAN_REAL_CALL(PMPI_Init_thread)(argc, argv, required, provided);
    if(ret != MPI_SUCCESS)
    {
        return(ret);
    }

    if(argc && argv)
    {
        darshan_core_initialize(*argc, *argv);
    }
    else
    {
        /* we don't see argc and argv here in fortran */
        darshan_core_initialize(0, NULL);
    }

    return(ret);
}
DARSHAN_WRAPPER_MAP(PMPI_Init_thread, int, (int *argc, char ***argv, int required, int *provided), MPI_Init_thread)

int DARSHAN_DECL(MPI_Finalize)(void)
{
    int ret;

    MAP_OR_FAIL(PMPI_Finalize);

    darshan_core_shutdown(1);

    ret = DARSHAN_REAL_CALL(PMPI_Finalize)();
    return(ret);
}
DARSHAN_WRAPPER_MAP(PMPI_Finalize, int, (void), MPI_Finalize)
#endif /* HAVE_MPI */

/*
 * Initialization hook that does not rely on MPI
 */
#ifdef __GNUC__
__attribute__((constructor)) void serial_init(void)
{
    char *no_mpi;
    no_mpi = getenv(DARSHAN_ENABLE_NONMPI);
    if (no_mpi)
        darshan_core_initialize(0, NULL);
    return;
}

__attribute__((destructor)) void serial_finalize(void)
{
    char *no_mpi;
    no_mpi = getenv(DARSHAN_ENABLE_NONMPI);
    if (no_mpi)
        darshan_core_shutdown(1);
    return;
}
#endif /* __GNUC__ */

#else /* DARSHAN_GOTCHA */

#ifdef HAVE_MPI
DARSHAN_FORWARD_DECL(MPI_Finalize, int, ());
DARSHAN_FORWARD_DECL(MPI_Init, int, (int *argc, char ***argv));
DARSHAN_FORWARD_DECL(MPI_Init_thread, int, (int *argc, char ***argv, int required, int *provided));


int DARSHAN_DECL(MPI_Finalize)(void)
{
    int ret;

    MAP_OR_FAIL(MPI_Finalize);

    darshan_core_shutdown(1);

    ret = DARSHAN_REAL_CALL(MPI_Finalize)();
    return(ret);
}
#endif

#ifndef WITH_INIT_FINI

#ifdef HAVE_MPI
int MPI_Init(int *argc, char ***argv)
{
    int ret;

    // MAP_OR_FAIL(MPI_Init);
    if (!(__darshan_real_MPI_Init)) {
        __darshan_real_MPI_Init = dlsym(RTLD_NEXT, "MPI_Init");
        if (!(__darshan_real_MPI_Init)) { 
            printf("Darshan failed to map symbol: %s\n", "MPI_Init"); 
        }
    }

    ret = DARSHAN_REAL_CALL(MPI_Init)(argc, argv);
    if(ret != MPI_SUCCESS)
    {
        return(ret);
    }
    setup_darshan_gotcha_wrappers(PRIORITY);

    if(argc && argv)
    {
        darshan_core_initialize(*argc, *argv);
    }
    else
    {
        /* we don't see argc and argv here in fortran */
        darshan_core_initialize(0, NULL);
    }
    int priority = 3;
    return(ret);
}

int MPI_Init_thread(int *argc, char ***argv, int required, int *provided)
{
    int ret;

    // MAP_OR_FAIL(MPI_Init_thread);
    if (!(__darshan_real_MPI_Init_thread)) {
        __darshan_real_MPI_Init_thread = dlsym(RTLD_NEXT, "MPI_Init_thread");
        if (!(__darshan_real_MPI_Init_thread)) { 
            printf("Darshan failed to map symbol: %s\n", "MPI_Init_thread"); 
        }
    }

    ret = DARSHAN_REAL_CALL(MPI_Init_thread)(argc, argv, required, provided);
    if(ret != MPI_SUCCESS)
    {
        return(ret);
    }

    setup_darshan_gotcha_wrappers(PRIORITY);
    if(argc && argv)
    {
        darshan_core_initialize(*argc, *argv);
    }
    else
    {
        /* we don't see argc and argv here in fortran */
        darshan_core_initialize(0, NULL);
    }

    return(ret);
}

#endif /* HAVE_MPI */

#ifdef __GNUC__
__attribute__((constructor)) void serial_init(void)
{
    char *no_mpi;
    no_mpi = getenv(DARSHAN_ENABLE_NONMPI);
    if (no_mpi)
        darshan_core_initialize(0, NULL);
    return;
}

__attribute__((destructor)) void serial_finalize(void)
{
    char *no_mpi;
    no_mpi = getenv(DARSHAN_ENABLE_NONMPI);
    if (no_mpi)
        darshan_core_shutdown(1);
    return;
}
#endif /* __GNUC__ */

#else /* WITH_INIT_FINI */

#ifdef HAVE_MPI
DARSHAN_FORWARD_DECL(MPI_Finalize, int, ());
DARSHAN_FORWARD_DECL(MPI_Init, int, (int *argc, char ***argv));
DARSHAN_FORWARD_DECL(MPI_Init_thread, int, (int *argc, char ***argv, int required, int *provided));

int MPI_Init(int *argc, char ***argv)
{
    int ret;

    MAP_OR_FAIL(MPI_Init);
    
    ret = DARSHAN_REAL_CALL(MPI_Init)(argc, argv);
    if(ret != MPI_SUCCESS)
    {
        return(ret);
    }

    if(argc && argv)
    {
        darshan_core_initialize(*argc, *argv);
    }
    else
    {
        /* we don't see argc and argv here in fortran */
        darshan_core_initialize(0, NULL);
    }
    int priority = 3;
    return(ret);
}

int DARSHAN_DECL(MPI_Init_thread)(int *argc, char ***argv, int required, int *provided)
{
    int ret;

    MAP_OR_FAIL(MPI_Init_thread);

    ret = DARSHAN_REAL_CALL(MPI_Init_thread)(argc, argv, required, provided);
    if(ret != MPI_SUCCESS)
    {
        return(ret);
    }

    if(argc && argv)
    {
        darshan_core_initialize(*argc, *argv);
    }
    else
    {
        /* we don't see argc and argv here in fortran */
        darshan_core_initialize(0, NULL);
    }

    return(ret);
}

#endif /* HAVE_MPI */

#ifdef __GNUC__
__attribute__((constructor)) void serial_init(void)
{
    setup_darshan_gotcha_wrappers(PRIORITY);
    
    char *no_mpi;
    no_mpi = getenv(DARSHAN_ENABLE_NONMPI);
    if (no_mpi)
        darshan_core_initialize(0, NULL);
    return;
}

__attribute__((destructor)) void serial_finalize(void)
{
    setup_darshan_gotcha_wrappers(PRIORITY);
    
    char *no_mpi;
    no_mpi = getenv(DARSHAN_ENABLE_NONMPI);
    if (no_mpi)
        darshan_core_shutdown(1);
    return;
}
#endif /* __GNUC__ */

#endif /* WITH_INIT_FINI */

#endif /* DARSHAN_GOTCHA */
/*
 * Local variables:
 *  c-indent-level: 4
 *  c-basic-offset: 4
 * End:
 *
 * vim: ts=8 sts=4 sw=4 expandtab
 */
