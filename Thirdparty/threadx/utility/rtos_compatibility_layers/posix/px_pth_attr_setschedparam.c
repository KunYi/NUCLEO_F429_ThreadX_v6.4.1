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
/*    pthread_attr_setschedparam                          PORTABLE C      */ 
/*                                                           6.1.7        */
/*  AUTHOR                                                                */
/*                                                                        */
/*    William E. Lamie, Microsoft Corporation                             */
/*                                                                        */
/*  DESCRIPTION                                                           */ 
/*                                                                        */ 
/*    This function sets the scheduling parameters attribute for the      */
/*    pthread attributes object.                                          */
/*                                                                        */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    attr                           Address of the thread attributes     */
/*    sched_param                    Address of structure containing the  */
/*                                   scheduling parameters to set         */ 
/*                                                                        */ 
/*                                                                        */ 
/*  OUTPUT                                                                */ 
/*                                                                        */ 
/*     0                             if successful                        */ 
/*     Value                         in case of any error                 */ 
/*                                                                        */ 
/*  CALLS                                                                 */ 
/*                                                                        */ 
/*    None                                                                */ 
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
INT pthread_attr_setschedparam(pthread_attr_t *attr,struct sched_param *param)
{
    /* First check the attribute object is already destroyed? */
    if (attr->inuse == TX_FALSE)
    {
        posix_errno = EINVAL;
        posix_set_pthread_errno(EINVAL);
        return(EINVAL);
    }       
    if (param->sched_priority == 0)
    {
        posix_errno = EINVAL;
        posix_set_pthread_errno(EINVAL);
        return(EINVAL);
    }
    if(param->sched_priority >= PX_LOWEST_PRIORITY &&  param->sched_priority <= PX_HIGHEST_PRIORITY  )
    {

        attr->sched_attr.sched_priority = param->sched_priority;
    }       
    return(OK);
}

