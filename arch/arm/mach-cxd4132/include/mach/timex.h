/*
 * include/asm-arm/arch-cxd4115/timex.h
 *
 * Base clock definitions
 *
 * Copyright 2007,2008,2009,2010 Sony Corporation
 *
 * This code is based on include/asm-arm/arch-integrator/timex.h.
 */
/*
 *  linux/include/asm-arm/arch-integrator/timex.h
 *
 *  Integrator architecture timex specifications
 *
 *  Copyright (C) 1999 ARM Limited
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __ASM_ARCH_TIMEX_H__
#define __ASM_ARCH_TIMEX_H__

#ifndef MHZ
#define MHZ (1000000)
#endif
#ifndef KHZ
#define KHZ (1000)
#endif

#define CLOCK_TICK_RATE	(1 * MHZ)
#define CXD4115_TMCK_TICK_DIV	TMCK_DIV4
#define SCHED_TICK_RATE	(2 * MHZ)
#define CXD4115_TMCK_SCHED_DIV	TMCK_DIV2

#ifndef __ASSEMBLY__
extern unsigned long long sched_clock(void);
extern unsigned long cxd4115_read_cycles(void);
extern unsigned long cxd4132_localtimer_rate(void);
#define MPCORE_TIMER_RATE (cxd4132_localtimer_rate())
#define mach_read_cycles cxd4115_read_cycles

#if SCHED_TICK_RATE < MHZ
# define mach_cycles_to_usecs(d) ((d) * (MHZ / SCHED_TICK_RATE))
# define mach_usecs_to_cycles(d) ((d) / (MHZ / SCHED_TICK_RATE))
#else
# define mach_cycles_to_usecs(d) ((d) / (SCHED_TICK_RATE / MHZ))
# define mach_usecs_to_cycles(d) ((d) * (SCHED_TICK_RATE / MHZ))
#endif

#ifdef CONFIG_HAVE_WATCHDOG
extern void watchdog_tick(void);
extern void watchdog_touch(void);
#else /* CONFIG_HAVE_WATCHDOG */
static inline void watchdog_tick(void) {}
static inline void watchdog_touch(void) {}
#endif /* CONFIG_HAVE_WATCHDOG */
#endif

#endif /* __ASM_ARCH_TIMEX_H__ */
