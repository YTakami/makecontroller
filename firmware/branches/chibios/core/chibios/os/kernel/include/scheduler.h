/*
    ChibiOS/RT - Copyright (C) 2006-2007 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file scheduler.h
 * @brief Scheduler macros and structures.
 * @addtogroup scheduler
 * @{
 */

#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

/** Default thread wakeup low level message. */
#define RDY_OK          0
/** Low level message sent to a thread awakened by a timeout. */
#define RDY_TIMEOUT     -1
/** Low level message sent to a thread awakened by a reset operation. */
#define RDY_RESET       -2

#define NOPRIO          0               /**< Ready list header priority.*/
#define IDLEPRIO        1               /**< Idle thread priority.*/
#define LOWPRIO         2               /**< Lowest user priority.*/
#define NORMALPRIO      64              /**< Normal user priority.*/
#define HIGHPRIO        127             /**< Highest user priority.*/
#define ABSPRIO         255             /**< Greatest possible priority.*/

/**
 * Zero time specification for some syscalls with a timeout
 * specification.
 * @note Not all functions accept @p TIME_IMMEDIATE as timeout parameter,
 *       see the specific function documentation.
 */
#define TIME_IMMEDIATE  ((systime_t)-1)

/**
 * Infinite time specification for all the syscalls with a timeout
 * specification.
 */
#define TIME_INFINITE   ((systime_t)0)

/** The priority of the first thread on the given ready list. */
#define firstprio(rlp)  ((rlp)->p_next->p_prio)

/**
 * @brief Ready list header.
 *
 * @extends ThreadsQueue
 */
typedef struct {
  ThreadsQueue          r_queue;        /**< Threads queue.*/
  tprio_t               r_prio;         /**< This field must be initialized to
                                             zero.*/
  /* End of the fields shared with the Thread structure.*/
#if CH_USE_ROUNDROBIN
  cnt_t                 r_preempt;      /**< Round robin counter.*/
#endif
#ifndef CH_CURRP_REGISTER_CACHE
  Thread                *r_current;     /**< The currently running thread.*/
#endif
} ReadyList;

extern ReadyList rlist;

#ifdef CH_CURRP_REGISTER_CACHE
register Thread *currp asm(CH_CURRP_REGISTER_CACHE);
#else
#define currp rlist.r_current
#endif

/*
 * Scheduler APIs.
 */
#ifdef __cplusplus
extern "C" {
#endif
  void scheduler_init(void);
  Thread *chSchReadyI(Thread *tp);
  void chSchGoSleepS(tstate_t newstate);
  msg_t chSchGoSleepTimeoutS(tstate_t newstate, systime_t time);
  void chSchWakeupS(Thread *tp, msg_t msg);
  void chSchDoRescheduleI(void);
  void chSchRescheduleS(void);
  bool_t chSchIsRescRequiredExI(void);
#if CH_USE_ROUNDROBIN
  void chSchDoYieldS(void);
#endif
#ifdef __cplusplus
}
#endif

/**
 * @brief Determines if yielding is possible.
 * @details This function returns @p TRUE if there is a ready thread with
 *          equal or higher priority.
 */
#define chSchCanYieldS() (firstprio(&rlist.r_queue) >= currp->p_prio)

/**
 * @brief Determines if the current thread must reschedule.
 * @details This function returns @p TRUE if there is a ready thread with
 *          higher priority.
 */
#define chSchIsRescRequiredI() (firstprio(&rlist.r_queue) > currp->p_prio)

#endif /* _SCHEDULER_H_ */

/** @} */