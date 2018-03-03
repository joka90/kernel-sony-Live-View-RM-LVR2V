/* 2013-08-20: File changed by Sony Corporation */
/*
 * arch/arm/mach-dove/include/mach/hardware.h
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2.  This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */

#ifndef __ASM_ARCH_HARDWARE_H
#define __ASM_ARCH_HARDWARE_H

#include "dove.h"

#define PCIMEM_BASE			DOVE_PCIE0_MEM_PHYS_BASE


/* Macros below are required for compatibility with PXA AC'97 driver.	*/
#define __REG(x)	(*((volatile u32 *)((x) - DOVE_SB_REGS_PHYS_BASE + \
				DOVE_SB_REGS_VIRT_BASE)))
#define __PREG(x)	(((u32)&(x)) - DOVE_SB_REGS_VIRT_BASE + \
		DOVE_SB_REGS_PHYS_BASE)
#endif
