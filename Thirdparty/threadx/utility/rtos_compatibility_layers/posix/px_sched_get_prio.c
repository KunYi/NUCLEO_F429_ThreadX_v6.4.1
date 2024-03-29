/***************************************************************************
 * Copyright (c) 2024 Microsoft Corporation 
 * 
 * This program and the accompanying materials are made available under the
 * terms of the MIT License which is available at
 * https://opensource.org/licenses/MIT.
 * 
 * SPDX-License-Identifier: MIT
 **************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */ 
/** POSIX wrapper for THREADX                                             */ 
/**                                                                       */
/**                                                                       */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

/* Include necessary system files.  */

#include "tx_api.h"    /* Threadx API */
#include "pthread.h"  /* Posix API */
#include "px_int.h"    /* Posix helper functions */



/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    sched_get_priority_max                             PORTABLE C       */
/*                                                           6.1.7        */
/*  AUTHOR                                                                */
/*                                                                        */
/*    William E. Lamie, Microsoft Corporation                             */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This routine returns the higest priority available in the system    */
/*    Note that in POSIX higher number indicates a higher priority        */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    policy                                                              */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    Maximum Priority           If successful                            */
/*    ERROR                      If policy not implemented                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Application Code                                                    */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  06-02-2021     William E. Lamie         Initial Version 6.1.7         */
/*                                                                        */
/**************************************************************************/


INT sched_get_priority_max(INT policy)
{
    if (policy==SCHED_FIFO || policy==SCHED_RR )
        return SCHED_PRIO_MAX;
    else
        return ERROR;
}



/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    sched_get_priority_min                              PORTABLE C      */
/*                                                           6.1.7        */
/*  AUTHOR                                                                */
/*                                                                        */
/*    William E. Lamie, Microsoft Corporation                             */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This routine returns the lowest priority available in the system    */
/*    Note that in POSIX higher number indicates a higher priority        */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    policy                                                              */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    Minimum Priority           If successful                            */
/*    ERROR                      If policy not implemented                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Application Code                                                    */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  06-02-2021     William E. Lamie         Initial Version 6.1.7         */
/*                                                                        */
/**************************************************************************/
INT sched_get_priority_min(INT policy)
{
    if (policy==SCHED_FIFO || policy==SCHED_RR )
        return SCHED_PRIO_MIN;
    else
        return ERROR;
}
