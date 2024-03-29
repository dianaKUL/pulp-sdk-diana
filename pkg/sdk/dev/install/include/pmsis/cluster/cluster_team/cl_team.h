/*
 * Copyright (C) 2018 ETH Zurich, University of Bologna and GreenWaves Technologies
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __CL_TEAM_H__
#define __CL_TEAM_H__

#include "pmsis/pmsis_types.h"

/**        
 * @ingroup groupCluster        
 */

/**        
 * @defgroup Team Team synchronization primitives
 *
 * Once a cluster entry point has been entered, after it has been enqueued by the fabric controller, all the following primitives can be used
 * to do multi-core processing, in a fork-join manner (like OMP parallel primitive).
 *
 * The execution can first be forked in order to activate more cores, and then synchronized together using barriers.
 */

/**        
 * @addtogroup Team
 * @{        
 */

/**@{*/

/** \brief Return the number of cores involved in the current cluster task
 *
 * This will return the number of cores activated by the cluster task pushed to cluster
 * side and currently being eecuted.
 * \return async_task asynchronous task to be executed at the end of operation
 */
int cl_cluster_nb_cores();

/** \brief Fork the execution of the calling core.
 *
 * Calling this function will create a team of workers and call the specified entry point
 * to start multi-core processing.
 * Use a full fledged pi_cluster_task
 * However, fork_task->stacks/stack_size will only concern slave cores
 * \param   fork_task task to be forked on slave cores
 */
void cl_team_fork_task(struct cl_team_task *fork_task);

/** \brief Fork the execution of the calling core.
 *
 * Calling this function will create a team of workers and call the specified entry point
 * to start multi-core processing.
 * The team parameters (number of cores and stacks) are by default the ones 
 * configured when calling
 * the cluster entry point from the fabric controller. It is possible to use 
 * different parameters
 * when doing a new fork. If this is done the new parameters will become the 
 * new default ones.
 * If the number of cores is not provided (i.e. is zero), the number of cores 
 * of the previous
 * fork will be reused. Doing this has less runtime overhead.
 *
 * \param        core_mask The mask of cores which will enter the entry point. 
 * If it is zero, this will reuse the cores_mask of the previous fork or the default.
 * \param        entry The function entry point to be executed by all cores of the team.
 * \param        arg    The argument of the function entry point.
 */
void cl_team_fork(int nb_cores, void (*entry)(void *), void *arg);

/** \brief Execute a barrier between all cores of the team.
 *
 * This will block the execution of each calling core until all cores 
 * have reached the barrier.
 * The set of cores participating in the barrier is the one created with the last fork.
 * Each core of the team must execute the barrier exactly once for all cores 
 * to be able to go through the barrier.
 */
void cl_team_barrier();



/** \brief Enter a critical section.
 *
 * This will block the execution of the calling core until it can execute 
 * the following section of code alone.
 * This will also prevent all other cores of the team to execute 
 * the following code until 
 * rt_team_critical_exit is called.
 */
void cl_team_critical_enter();



/** \brief Exit a critical section.
 *
 * This will exit the critical code and let other cores executing it.
 */
void cl_team_critical_exit();



/** \brief Return the number of cores of the team.
 *
 * This will return the number of cores involved in the team created by the 
 * active fork operation.
 * \result The number of cores of the team.
 */
int cl_team_nb_cores();



//!@}

/**        
 * @} end of Team group        
 */

#endif
