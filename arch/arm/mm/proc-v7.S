/* 2013-08-20: File changed by Sony Corporation */
/*
 *  linux/arch/arm/mm/proc-v7.S
 *
 *  Copyright (C) 2001 Deep Blue Solutions Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 *  This is the "shell" of the ARMv7 processor support.
 */
#include <linux/init.h>
#include <linux/linkage.h>
#include <asm/assembler.h>
#include <asm/asm-offsets.h>
#include <asm/hwcap.h>
#include <asm/pgtable-hwdef.h>
#include <asm/pgtable.h>

#include "proc-macros.S"

#define TTB_S		(1 << 1)
#define TTB_RGN_NC	(0 << 3)
#define TTB_RGN_OC_WBWA	(1 << 3)
#define TTB_RGN_OC_WT	(2 << 3)
#define TTB_RGN_OC_WB	(3 << 3)
#define TTB_NOS		(1 << 5)
#define TTB_IRGN_NC	((0 << 0) | (0 << 6))
#define TTB_IRGN_WBWA	((0 << 0) | (1 << 6))
#define TTB_IRGN_WT	((1 << 0) | (0 << 6))
#define TTB_IRGN_WB	((1 << 0) | (1 << 6))

#ifdef CONFIG_EMXX_L310_NORAM
/* PTWs cacheable, inner WB not shareable, outer non-cache not shareable */
#define TTB_FLAGS_UP	TTB_IRGN_WB|TTB_RGN_NC
#else
/* PTWs cacheable, inner WB not shareable, outer WB not shareable */
#define TTB_FLAGS_UP	TTB_IRGN_WB|TTB_RGN_OC_WB
#endif
#define PMD_FLAGS_UP	PMD_SECT_WB

#ifdef CONFIG_EMXX_L310_NORAM
/* PTWs cacheable, inner WBWA shareable, outer non-cache not shareable */
#define TTB_FLAGS_SMP	TTB_IRGN_WBWA|TTB_S|TTB_NOS|TTB_RGN_NC
#else
/* PTWs cacheable, inner WBWA shareable, outer WBWA not shareable */
#define TTB_FLAGS_SMP	TTB_IRGN_WBWA|TTB_S|TTB_NOS|TTB_RGN_OC_WBWA
#endif
#define PMD_FLAGS_SMP	PMD_SECT_WBWA|PMD_SECT_S

ENTRY(cpu_v7_proc_init)
#ifdef CONFIG_SNSC_ARM_DMA_REDUCE_CACHE_OPS
 ARM(	stmfd	sp!, {r4-r5, r7, r9-r11, lr}	)
 THUMB(	stmfd	sp!, {r4-r7, r9-r11, lr}	)
	bl	v7_init_dcache_size
 ARM(	ldmfd	sp!, {r4-r5, r7, r9-r11, lr}	)
 THUMB(	ldmfd	sp!, {r4-r7, r9-r11, lr}	)
#endif
	mov	pc, lr
ENDPROC(cpu_v7_proc_init)

ENTRY(cpu_v7_proc_fin)
#ifdef CONFIG_ARCH_EMXX
	mov	pc, lr
#else
	mrc	p15, 0, r0, c1, c0, 0		@ ctrl register
	bic	r0, r0, #0x1000			@ ...i............
	bic	r0, r0, #0x0006			@ .............ca.
	mcr	p15, 0, r0, c1, c0, 0		@ disable caches
	mov	pc, lr
#endif
ENDPROC(cpu_v7_proc_fin)

/*
 *	cpu_v7_reset(loc)
 *
 *	Perform a soft reset of the system.  Put the CPU into the
 *	same state as it would be if it had been reset, and branch
 *	to what would be the reset vector.
 *
 *	- loc   - location to jump to for soft reset
 *
 *	This code must be executed using a flat identity mapping with
 *      caches disabled.
 */
	.align	5
ENTRY(cpu_v7_reset)
	mrc	p15, 0, r1, c1, c0, 0		@ ctrl register
	bic	r1, r1, #0x1			@ ...............m
 THUMB(	bic	r1, r1, #1 << 30 )		@ SCTLR.TE (Thumb exceptions)
	mcr	p15, 0, r1, c1, c0, 0		@ disable MMU
	isb
	mov	pc, r0
ENDPROC(cpu_v7_reset)

/*
 *	cpu_v7_do_idle()
 *
 *	Idle the processor (eg, wait for interrupt).
 *
 *	IRQs are already disabled.
 */
#ifdef CONFIG_EMXX_L310
#include <mach/hardware.h>
#include <asm/hardware/cache-l2x0.h>
	.align	5
ENTRY(cpu_v7_do_idle)
	dsb
	/* bl will (over)write the lr, So we need to save it. */
	stmfd	sp!, {lr}
	/* L2 cache sync should take l2x0_lock */
	bl l2x0_cache_sync_idle
	ldmfd	sp!, {lr}
	wfi
	mov	pc, lr
#else
ENTRY(cpu_v7_do_idle)
	dsb					@ WFI may enter a low-power mode
	wfi
	mov	pc, lr
#endif
ENDPROC(cpu_v7_do_idle)

ENTRY(cpu_v7_dcache_clean_area)
#ifndef TLB_CAN_READ_FROM_L1_CACHE
	dcache_line_size r2, r3
1:	mcr	p15, 0, r0, c7, c10, 1		@ clean D entry
	add	r0, r0, r2
	subs	r1, r1, r2
	bhi	1b
	dsb
#endif
	mov	pc, lr
ENDPROC(cpu_v7_dcache_clean_area)

/*
 *	cpu_v7_switch_mm(pgd_phys, tsk)
 *
 *	Set the translation table base pointer to be pgd_phys
 *
 *	- pgd_phys - physical address of new TTB
 *
 *	It is assumed that:
 *	- we are not using split page tables
 */
ENTRY(cpu_v7_switch_mm)
#ifdef CONFIG_MMU
	mov	r2, #0
	ldr	r1, [r1, #MM_CONTEXT_ID]	@ get mm->context.id
	ALT_SMP(orr	r0, r0, #TTB_FLAGS_SMP)
	ALT_UP(orr	r0, r0, #TTB_FLAGS_UP)
#ifdef CONFIG_ARM_ERRATA_430973
	mcr	p15, 0, r2, c7, c5, 6		@ flush BTAC/BTB
#endif
#ifdef CONFIG_ARM_ERRATA_754322
	dsb
#endif
	mcr	p15, 0, r2, c13, c0, 1		@ set reserved context ID
	isb
1:	mcr	p15, 0, r0, c2, c0, 0		@ set TTB 0
	isb
#ifdef CONFIG_ARM_ERRATA_754322
	dsb
#endif
	mcr	p15, 0, r1, c13, c0, 1		@ set context ID
	isb
#endif
	mov	pc, lr
ENDPROC(cpu_v7_switch_mm)

/*
 *	cpu_v7_set_pte_ext(ptep, pte)
 *
 *	Set a level 2 translation table entry.
 *
 *	- ptep  - pointer to level 2 translation table entry
 *		  (hardware version is stored at +2048 bytes)
 *	- pte   - PTE value to store
 *	- ext	- value for extended PTE bits
 */
ENTRY(cpu_v7_set_pte_ext)
#ifdef CONFIG_MMU
	str	r1, [r0]			@ linux version

	bic	r3, r1, #0x000003f0
	bic	r3, r3, #PTE_TYPE_MASK
	orr	r3, r3, r2
	orr	r3, r3, #PTE_EXT_AP0 | 2

	tst	r1, #1 << 4
	orrne	r3, r3, #PTE_EXT_TEX(1)

	eor	r1, r1, #L_PTE_DIRTY
	tst	r1, #L_PTE_RDONLY | L_PTE_DIRTY
	orrne	r3, r3, #PTE_EXT_APX

	tst	r1, #L_PTE_USER
	orrne	r3, r3, #PTE_EXT_AP1
#ifdef CONFIG_CPU_USE_DOMAINS
	@ allow kernel read/write access to read-only user pages
	tstne	r3, #PTE_EXT_APX
	bicne	r3, r3, #PTE_EXT_APX | PTE_EXT_AP0
#endif
	tst	r1, #L_PTE_XN
	orrne	r3, r3, #PTE_EXT_XN

	tst	r1, #L_PTE_YOUNG
	tstne	r1, #L_PTE_PRESENT
	moveq	r3, #0

 ARM(	str	r3, [r0, #2048]! )
 THUMB(	add	r0, r0, #2048 )
 THUMB(	str	r3, [r0] )
	mcr	p15, 0, r0, c7, c10, 1		@ flush_pte
#endif
	mov	pc, lr
ENDPROC(cpu_v7_set_pte_ext)

	string	cpu_v7_name, "ARMv7 Processor"
	.align

	/*
	 * Memory region attributes with SCTLR.TRE=1
	 *
	 *   n = TEX[0],C,B
	 *   TR = PRRR[2n+1:2n]		- memory type
	 *   IR = NMRR[2n+1:2n]		- inner cacheable property
	 *   OR = NMRR[2n+17:2n+16]	- outer cacheable property
	 *
	 *			n	TR	IR	OR
	 *   UNCACHED		000	00
	 *   BUFFERABLE		001	10	00	00
	 *   WRITETHROUGH	010	10	10	10
	 *   WRITEBACK		011	10	11	11
	 *   reserved		110
	 *   WRITEALLOC		111	10	01	01
	 *   DEV_SHARED		100	01
	 *   DEV_NONSHARED	100	01
	 *   DEV_WC		001	10
	 *   DEV_CACHED		011	10
	 *
	 * Other attributes:
	 *
	 *   DS0 = PRRR[16] = 0		- device shareable property
	 *   DS1 = PRRR[17] = 1		- device shareable property
	 *   NS0 = PRRR[18] = 0		- normal shareable property
	 *   NS1 = PRRR[19] = 1		- normal shareable property
	 *   NOS = PRRR[24+n] = 1	- not outer shareable
	 */
.equ	PRRR,	0xff0a81a8
#ifdef CONFIG_EMXX_L310_NORAM
.equ	NMRR 	0x000040e0
#else
.equ	NMRR,	0x40e040e0
#endif

/* Suspend/resume support: derived from arch/arm/mach-s5pv210/sleep.S */
.globl	cpu_v7_suspend_size
.equ	cpu_v7_suspend_size, 4 * 9
#ifdef CONFIG_PM_SLEEP
ENTRY(cpu_v7_do_suspend)
	stmfd	sp!, {r4 - r11, lr}
	mrc	p15, 0, r4, c13, c0, 0	@ FCSE/PID
	mrc	p15, 0, r5, c13, c0, 1	@ Context ID
	mrc	p15, 0, r6, c13, c0, 3	@ User r/o thread ID
	stmia	r0!, {r4 - r6}
	mrc	p15, 0, r6, c3, c0, 0	@ Domain ID
	mrc	p15, 0, r7, c2, c0, 0	@ TTB 0
	mrc	p15, 0, r8, c2, c0, 1	@ TTB 1
	mrc	p15, 0, r9, c1, c0, 0	@ Control register
	mrc	p15, 0, r10, c1, c0, 1	@ Auxiliary control register
	mrc	p15, 0, r11, c1, c0, 2	@ Co-processor access control
	stmia	r0, {r6 - r11}
	ldmfd	sp!, {r4 - r11, pc}
ENDPROC(cpu_v7_do_suspend)

ENTRY(cpu_v7_do_resume)
	mov	ip, #0
	mcr	p15, 0, ip, c8, c7, 0	@ invalidate TLBs
	mcr	p15, 0, ip, c7, c5, 0	@ invalidate I cache
	ldmia	r0!, {r4 - r6}
	mcr	p15, 0, r4, c13, c0, 0	@ FCSE/PID
	mcr	p15, 0, r5, c13, c0, 1	@ Context ID
	mcr	p15, 0, r6, c13, c0, 3	@ User r/o thread ID
	ldmia	r0, {r6 - r11}
	mcr	p15, 0, r6, c3, c0, 0	@ Domain ID
	mcr	p15, 0, r7, c2, c0, 0	@ TTB 0
	mcr	p15, 0, r8, c2, c0, 1	@ TTB 1
	mcr	p15, 0, ip, c2, c0, 2	@ TTB control register
	mrc	p15, 0, r4, c1, c0, 1	@ Read Auxiliary control register
	teq	r4, r10			@ Is it already set?
	mcrne	p15, 0, r10, c1, c0, 1	@ No, so write it
	mcr	p15, 0, r11, c1, c0, 2	@ Co-processor access control
	ldr	r4, =PRRR		@ PRRR
	ldr	r5, =NMRR		@ NMRR
	mcr	p15, 0, r4, c10, c2, 0	@ write PRRR
	mcr	p15, 0, r5, c10, c2, 1	@ write NMRR
	isb
	dsb
	mov	r0, r9			@ control register
	mov	r2, r7, lsr #14		@ get TTB0 base
	mov	r2, r2, lsl #14
	ldr	r3, cpu_resume_l1_flags
	b	cpu_resume_mmu
ENDPROC(cpu_v7_do_resume)
cpu_resume_l1_flags:
	ALT_SMP(.long PMD_TYPE_SECT | PMD_SECT_AP_WRITE | PMD_FLAGS_SMP)
	ALT_UP(.long  PMD_TYPE_SECT | PMD_SECT_AP_WRITE | PMD_FLAGS_UP)
#endif

	__CPUINIT

/*
 *	__v7_setup
 *
 *	Initialise TLB, Caches, and MMU state ready to switch the MMU
 *	on.  Return in r0 the new CP15 C1 control register setting.
 *
 *	This should be able to cover all ARMv7 cores.
 *
 *	It is assumed that:
 *	- cache type register is implemented
 */
__v7_ca5mp_setup:
__v7_ca9mp_setup:
	mov	r10, #(1 << 0)			@ TLB ops broadcasting
#ifdef CONFIG_EXCLUSIVE_CACHE
	@ Exclusive cache
	mrc	p15, 0, r0, c1, c0, 1
	orr	r0, r0, #0x10			@ L2 EXCL
	mcr	p15, 0, r0, c1, c0, 1
#endif /* CONFIG_EXCLUSIVE_CACHE */
	b	1f
__v7_ca15mp_setup:
	mov	r10, #0
1:
#ifdef CONFIG_SMP
	ALT_SMP(mrc	p15, 0, r0, c1, c0, 1)
	ALT_UP(mov	r0, #(1 << 6))		@ fake it for UP
	tst	r0, #(1 << 6)			@ SMP/nAMP mode enabled?
	orreq	r0, r0, #(1 << 6)		@ Enable SMP/nAMP mode
	orreq	r0, r0, r10			@ Enable CPU-specific SMP bits
	mcreq	p15, 0, r0, c1, c0, 1
#endif
__v7_setup:
	adr	r12, __v7_setup_stack		@ the local stack
	stmia	r12, {r0-r5, r7, r9, r11, lr}
#ifdef CONFIG_ARCH_EMXX
	bl	v7_inv_dcache_all
#else
	bl	v7_flush_dcache_all
#endif
	ldmia	r12, {r0-r5, r7, r9, r11, lr}

	mrc	p15, 0, r0, c0, c0, 0		@ read main ID register
	and	r10, r0, #0xff000000		@ ARM?
	teq	r10, #0x41000000
	bne	3f
	and	r5, r0, #0x00f00000		@ variant
	and	r6, r0, #0x0000000f		@ revision
	orr	r6, r6, r5, lsr #20-4		@ combine variant and revision
	ubfx	r0, r0, #4, #12			@ primary part number

	/* Cortex-A8 Errata */
	ldr	r10, =0x00000c08		@ Cortex-A8 primary part number
	teq	r0, r10
	bne	2f
#ifdef CONFIG_ARM_ERRATA_430973
	teq	r5, #0x00100000			@ only present in r1p*
	mrceq	p15, 0, r10, c1, c0, 1		@ read aux control register
	orreq	r10, r10, #(1 << 6)		@ set IBE to 1
	mcreq	p15, 0, r10, c1, c0, 1		@ write aux control register
#endif
#ifdef CONFIG_ARM_ERRATA_458693
	teq	r6, #0x20			@ only present in r2p0
	mrceq	p15, 0, r10, c1, c0, 1		@ read aux control register
	orreq	r10, r10, #(1 << 5)		@ set L1NEON to 1
	orreq	r10, r10, #(1 << 9)		@ set PLDNOP to 1
	mcreq	p15, 0, r10, c1, c0, 1		@ write aux control register
#endif
#ifdef CONFIG_ARM_ERRATA_460075
	teq	r6, #0x20			@ only present in r2p0
	mrceq	p15, 1, r10, c9, c0, 2		@ read L2 cache aux ctrl register
	tsteq	r10, #1 << 22
	orreq	r10, r10, #(1 << 22)		@ set the Write Allocate disable bit
	mcreq	p15, 1, r10, c9, c0, 2		@ write the L2 cache aux ctrl register
#endif
#ifdef CONFIG_CPU_CORTEXA8_L2_CACHE_FORCE_ENABLE
	mrc	p15, 0, r10, c1, c0, 1		@ read aux control register
	orr	r10, r10, #(1 << 1)		@ set L2EN to 1
	mcr	p15, 0, r10, c1, c0, 1		@ write aux control register
#endif
	b	3f

	/* Cortex-A9 Errata */
2:	ldr	r10, =0x00000c09		@ Cortex-A9 primary part number
	teq	r0, r10
	bne	3f
#ifdef CONFIG_ARM_ERRATA_742230
	cmp	r6, #0x22			@ only present up to r2p2
	mrcle	p15, 0, r10, c15, c0, 1		@ read diagnostic register
	orrle	r10, r10, #1 << 4		@ set bit #4
	mcrle	p15, 0, r10, c15, c0, 1		@ write diagnostic register
#endif
#ifdef CONFIG_ARM_ERRATA_742231
#ifdef CONFIG_ARM_ERRATA_743622_FORCE_ENABLE
	teq	r6, r6
#else
	teq	r6, #0x20			@ present in r2p0
	teqne	r6, #0x21			@ present in r2p1
	teqne	r6, #0x22			@ present in r2p2
	teqne	r6, #0x25			@ present in r2p5
	teqne	r6, #0x26			@ present in r2p6
	teqne	r6, #0x27			@ present in r2p7
	teqne	r6, #0x28			@ present in r2p8
#endif /* CONFIG_ARM_ERRATA_743622_FORCE_ENABLE */
	mrceq	p15, 0, r10, c15, c0, 1		@ read diagnostic register
	orreq	r10, r10, #1 << 12		@ set bit #12
	orreq	r10, r10, #1 << 22		@ set bit #22
	mcreq	p15, 0, r10, c15, c0, 1		@ write diagnostic register
#endif
#ifdef CONFIG_ARM_ERRATA_743622
	teq	r5, #0x00200000			@ only present in r2p*
	mrceq	p15, 0, r10, c15, c0, 1		@ read diagnostic register
	orreq	r10, r10, #1 << 6		@ set bit #6
	mcreq	p15, 0, r10, c15, c0, 1		@ write diagnostic register
#endif
#ifdef CONFIG_ARM_ERRATA_743623
	cmp	r6, #0x30			@ present prior to r3p0
	mrclt	p15, 0, r10, c15, c0, 1	@ read diagnostic register
	orrlt	r10, r10, #1 << 20		@ set bit #20
	mcrlt	p15, 0, r10, c15, c0, 1	@ write
#endif /* CONFIG_ARM_ERRATA_743623 */
#ifdef CONFIG_ARM_ERRATA_751472
	cmp	r6, #0x30			@ present prior to r3p0
	mrclt	p15, 0, r10, c15, c0, 1		@ read diagnostic register
	orrlt	r10, r10, #1 << 11		@ set bit #11
	mcrlt	p15, 0, r10, c15, c0, 1		@ write diagnostic register
#endif

#ifdef CONFIG_CPU_DCACHE_PREFETCH
	mrc	p15, 0, r10, c1, c0, 1		@ read aux control register
	orr	r10, r10, #1 << 2		@ set L1 prefetch enable bit
#ifdef CONFIG_SMP
	orr	r10, r10, #1 << 1		@ set L2 prefetch hint enable bit
#endif
	mcr	p15, 0, r10, c1, c0, 1		@ write aux control register
#endif

3:	mov	r10, #0
	mcr	p15, 0, r10, c7, c5, 0		@ I+BTB cache invalidate
	dsb
#ifdef CONFIG_MMU
	mcr	p15, 0, r10, c8, c7, 0		@ invalidate I + D TLBs
#ifdef CONFIG_EJ_SPLIT_PAGETABLE
	mov     r10, #CONFIG_EJ_SPLIT_SHIFT
#endif
	mcr	p15, 0, r10, c2, c0, 2		@ TTB control register
	ALT_SMP(orr	r4, r4, #TTB_FLAGS_SMP)
	ALT_UP(orr	r4, r4, #TTB_FLAGS_UP)
	ALT_SMP(orr	r8, r8, #TTB_FLAGS_SMP)
	ALT_UP(orr	r8, r8, #TTB_FLAGS_UP)
	mcr	p15, 0, r8, c2, c0, 1		@ load TTB1
	ldr	r5, =PRRR			@ PRRR
	ldr	r6, =NMRR			@ NMRR
#ifdef CONFIG_ARM_MEMORY_INNERCACHED
	/*
	* TR5 = PRRR[11:10] = 10 - Normal Memory
	* IR5 = NMRR[11:10] = 01 - Write-Back, WriteAllocate (SMP)
	*                     11 - Write-Back, Non-WriteAllocate (UP)
	* OR5 = NMRR[27:26] = 00 - Non-cacheable
	*/
	ldr     r10, =(0x2 << 10)
	orr     r5, r5, r10
#ifdef CONFIG_SMP
	ldr     r10, =((0x0 << 26) | (0x1 << 10))
#else
	ldr     r10, =((0x0 << 26) | (0x3 << 10))
#endif
	orr     r6, r6, r10
#endif /* CONFIG_ARM_MEMORY_INNERCACHED */
	mcr	p15, 0, r5, c10, c2, 0		@ write PRRR
	mcr	p15, 0, r6, c10, c2, 1		@ write NMRR
#endif
#ifndef CONFIG_ARM_THUMBEE
	mrc	p15, 0, r0, c0, c1, 0		@ read ID_PFR0 for ThumbEE
	and	r0, r0, #(0xf << 12)		@ ThumbEE enabled field
	teq	r0, #(1 << 12)			@ check if ThumbEE is present
	bne	1f
	mov	r5, #0
	mcr	p14, 6, r5, c1, c0, 0		@ Initialize TEEHBR to 0
	mrc	p14, 6, r0, c0, c0, 0		@ load TEECR
	orr	r0, r0, #1			@ set the 1st bit in order to
	mcr	p14, 6, r0, c0, c0, 0		@ stop userspace TEEHBR access
1:
#endif
	adr	r5, v7_crval
	ldmia	r5, {r5, r6}
#ifdef CONFIG_CPU_ENDIAN_BE8
	orr	r6, r6, #1 << 25		@ big-endian page tables
#endif
#ifdef CONFIG_SWP_EMULATE
	orr     r5, r5, #(1 << 10)              @ set SW bit in "clear"
	bic     r6, r6, #(1 << 10)              @ clear it in "mmuset"
#endif
   	mrc	p15, 0, r0, c1, c0, 0		@ read control register
	bic	r0, r0, r5			@ clear bits them
	orr	r0, r0, r6			@ set them
 THUMB(	orr	r0, r0, #1 << 30	)	@ Thumb exceptions
#ifdef CONFIG_ARM_ERRATA_716044
	orr	r0, r0, #(1 << 14)		@ set RR
#endif
	mov	pc, lr				@ return to head.S:__ret
ENDPROC(__v7_setup)

	/*   AT
	 *  TFR   EV X F   I D LR    S
	 * .EEE ..EE PUI. .T.T 4RVI ZWRS BLDP WCAM
	 * rxxx rrxx xxx0 0101 xxxx xxxx x111 xxxx < forced
	 *    1    0 110    0  0011 1.00 .111 1101 < we want
	 */
	.type	v7_crval, #object
v7_crval:
	crval   clear=0x0120c302, mmuset=0x10c0387d, ucset=0x00c0187c

__v7_setup_stack:
	.space	4 * 11				@ 11 registers

	__INITDATA

	@ define struct processor (see <asm/proc-fns.h> and proc-macros.S)
	define_processor_functions v7, dabort=v7_early_abort, pabort=v7_pabort, suspend=1

	.section ".rodata"

	string	cpu_arch_name, "armv7"
	string	cpu_elf_name, "v7"
	.align

	.section ".proc.info.init", #alloc, #execinstr

	/*
	 * Standard v7 proc info content
	 */
.macro __v7_proc initfunc, mm_mmuflags = 0, io_mmuflags = 0, hwcaps = 0
	ALT_SMP(.long	PMD_TYPE_SECT | PMD_SECT_AP_WRITE | PMD_SECT_AP_READ | \
			PMD_FLAGS_SMP | \mm_mmuflags)
	ALT_UP(.long	PMD_TYPE_SECT | PMD_SECT_AP_WRITE | PMD_SECT_AP_READ | \
			PMD_FLAGS_UP | \mm_mmuflags)
	.long	PMD_TYPE_SECT | PMD_SECT_XN | PMD_SECT_AP_WRITE | \
		PMD_SECT_AP_READ | \io_mmuflags
	W(b)	\initfunc
	.long	cpu_arch_name
	.long	cpu_elf_name
	.long	HWCAP_SWP | HWCAP_HALF | HWCAP_THUMB | HWCAP_FAST_MULT | \
		HWCAP_EDSP | HWCAP_TLS | \hwcaps
	.long	cpu_v7_name
	.long	v7_processor_functions
	.long	v7wbi_tlb_fns
	.long	v6_user_fns
	.long	v7_cache_fns
.endm

	/*
	 * ARM Ltd. Cortex A5 processor.
	 */
	.type   __v7_ca5mp_proc_info, #object
__v7_ca5mp_proc_info:
	.long	0x410fc050
	.long	0xff0ffff0
	__v7_proc __v7_ca5mp_setup
	.size	__v7_ca5mp_proc_info, . - __v7_ca5mp_proc_info

	/*
	 * ARM Ltd. Cortex A9 processor.
	 */
	.type   __v7_ca9mp_proc_info, #object
__v7_ca9mp_proc_info:
	.long	0x410fc090
	.long	0xff0ffff0
	__v7_proc __v7_ca9mp_setup
	.size	__v7_ca9mp_proc_info, . - __v7_ca9mp_proc_info

	/*
	 * ARM Ltd. Cortex A15 processor.
	 */
	.type	__v7_ca15mp_proc_info, #object
__v7_ca15mp_proc_info:
	.long	0x410fc0f0
	.long	0xff0ffff0
	__v7_proc __v7_ca15mp_setup, hwcaps = HWCAP_IDIV
	.size	__v7_ca15mp_proc_info, . - __v7_ca15mp_proc_info

	/*
	 * Match any ARMv7 processor core.
	 */
	.type	__v7_proc_info, #object
__v7_proc_info:
	.long	0x000f0000		@ Required ID value
	.long	0x000f0000		@ Mask for ID
	__v7_proc __v7_setup
	.size	__v7_proc_info, . - __v7_proc_info
