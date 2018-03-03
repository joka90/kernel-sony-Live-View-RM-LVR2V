/*
 * include/asm-arm/arch-cxd90014/platform.h
 *
 * CXD90014 address map
 *
 * Copyright 2012,2013 Sony Corporation
 *
 *  This program is free software; you can redistribute  it and/or modify it
 *  under  the terms of  the GNU General  Public License as published by the
 *  Free Software Foundation;  version 2 of the  License.
 *
 *  THIS  SOFTWARE  IS PROVIDED   ``AS  IS'' AND   ANY  EXPRESS OR IMPLIED
 *  WARRANTIES,   INCLUDING, BUT NOT  LIMITED  TO, THE IMPLIED WARRANTIES OF
 *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN
 *  NO  EVENT  SHALL   THE AUTHOR  BE    LIABLE FOR ANY   DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 *  NOT LIMITED   TO, PROCUREMENT OF  SUBSTITUTE GOODS  OR SERVICES; LOSS OF
 *  USE, DATA,  OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 *  ANY THEORY OF LIABILITY, WHETHER IN  CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 *  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  You should have received a copy of the  GNU General Public License along
 *  with this program; if not, write  to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Suite 500, Boston, MA 02110-1335, USA.
 *
 */
#ifndef __ARCH_CXD90014_PLATFORM_H
#define __ARCH_CXD90014_PLATFORM_H

#define DDR_BASE		0x80000000
#ifdef CONFIG_CXD90014_DDR512MB
#define DDR_SIZE		SZ_512M
#else
#define DDR_SIZE		SZ_1G
#endif /* CONFIG_CXD90014_DDR512MB */

#define CXD90014_ESRAM_BASE	0xc0000000
#define CXD90014_ESRAM_SIZE	SZ_16M
#define CXD90014_ESRAM_BANK(x)	(CXD90014_ESRAM_BASE + (((x) < 2) ? (SZ_4M * (x)) : (SZ_8M + ((x) - 2) * SZ_512K)))
#define VA_BOOTRAM		IO_ADDRESS(CXD90014_ESRAM_BASE)
#define VA_BOOTRAM_CACHED	(VA_BOOTRAM + CXD90014_ESRAM_SIZE)

#define CXD90014_SRAMC_BASE	0x00013000
#define CXD90014_SRAMC_SIZE	SZ_4K

/*---------------- I/O ----------------*/
#define CXD90014_IO_BASE	0xf0000000
#define CXD90014_IO_SIZE	SZ_64M
#define CXD90014_AHB_BASE	0xf0000000
#define CXD90014_AXI_BASE	0xf1000000
#define CXD90014_APB0_BASE	0xf2000000
#define CXD90014_APB1_BASE	0xf2800000
#define CXD90014_APB2_BASE	0xf3000000
#define CXD90014_APB3_BASE	0xf3400000
#define CXD90014_APB4_BASE	0xf3800000
#define CXD90014_APB5_BASE	0xf3c00000

/*----- AHB1 -----*/
#define CXD90014_EHCI_BASE	0xF0200000
#define CXD90014_EHCI_SIZE	SZ_4K
#define CXD90014_OHCI_BASE	0xF0201000
#define CXD90014_OHCI_SIZE	SZ_4K
#define CXD90014_USBOTHER_BASE	0xF0202000
#define CXD90014_USBOTHER_SIZE	SZ_4K
#define CXD90014_USBG_BASE	0xF0210000
#define CXD90014_USBG_SIZE	0x20000

/*----- APB0 -----*/
#define CXD90014_UART(x)		(0xf2000000+0x1000*(x))

#define CXD90014_WDT_TIMER_BASE(x)	(0xf2402000+0x100*(x))
#define VA_WDT_TIMER(x)		IO_ADDRESSP(CXD90014_WDT_TIMER_BASE(x))
#define CXD90014_WDT		0

#define CXD90014_TIMER_BASE(x)	(0xf2403000+0x100*(x))
#define VA_TIMER(x)		IO_ADDRESSP(CXD90014_TIMER_BASE(x))

#define CXD90014_DAP_BASE	0xf2710000

/*----- APB1 -----*/
#define CXD90014_AVB_BASE	0xf2800000
#define CXD90014_AVBCKG_BASE	(CXD90014_AVB_BASE + 0x0000)
#define VA_AVBCKG		IO_ADDRESSP(CXD90014_AVBCKG_BASE)
#define CXD90014_BAM_BASE	(CXD90014_AVB_BASE + 0x1000)
#define CXD90014_BAM_SIZE	(SZ_4K)
#define VA_BAM			IO_ADDRESSP(CXD90014_BAM_BASE)
#define CXD90014_MACRO_BASE	0xf2910000
#define CXD90014_GPIO_BASE	(CXD90014_MACRO_BASE + 0x0000)
#define CXD90014_GPIO(ch,reg)	(CXD90014_GPIO_BASE+GPIO_REG(ch,reg))
#define PA_GPIO(ch,reg)		CXD90014_GPIO(ch,reg)
#define VA_GPIO(ch,reg)		IO_ADDRESSP(CXD90014_GPIO(ch,reg))

#define CXD90014_OCTRL_BASE	(CXD90014_MACRO_BASE + 0x2000)
#define CXD90014_OCTRL(x)	(CXD90014_OCTRL_BASE + ((x) << 8))
#define VA_OCTRL(x)		IO_ADDRESSP(CXD90014_OCTRL(x))
#define CXD90014_ASYNCSEL	(CXD90014_MACRO_BASE + 0x4020)
#define VA_ASYNCSEL		IO_ADDRESSP(CXD90014_ASYNCSEL)

#define CXD90014_MISC_BASE	(CXD90014_MACRO_BASE + 0x5000)
#define VA_MISC			IO_ADDRESSP(CXD90014_MISC_BASE)
#define CXD90014_CLKRST_BASE	(CXD90014_MACRO_BASE+0x6600)

#define CXD90014_PCIE_PHY	(0xf2929000)
#define VA_PCIE_PHY		IO_ADDRESSP(CXD90014_PCIE_PHY)

#define CXD90014_CLKCRG(base,x)	((base) + 0x1000 * ((x) + 1))

#define CXD90014_CLK0		0xf2a00000
#define CXD90014_CLKRST0(x)	(CXD90014_CLK0 + ((x) << 4))
#define CXD90014_CLKCRG0(x)	CXD90014_CLKCRG(CXD90014_CLK0, x)
#define VA_CLKRST0(x)		IO_ADDRESSP(CXD90014_CLKRST0(x))
#define VA_CLKCRG0(x)		IO_ADDRESSP(CXD90014_CLKCRG0(x))

#define CXD90014_CLK1		0xf2a10000
#define CXD90014_CLKRST1(x)	(CXD90014_CLK1 + ((x) << 4))
#define CXD90014_CLKCRG1(x)	CXD90014_CLKCRG(CXD90014_CLK1, x)
#define VA_CLKRST1(x)		IO_ADDRESSP(CXD90014_CLKRST1(x))
#define VA_CLKCRG1(x)		IO_ADDRESSP(CXD90014_CLKCRG1(x))

#define CXD90014_CLK2		0xf2a20000
#define CXD90014_CLKRST2(x)	(CXD90014_CLK2 + ((x) << 4))
#define CXD90014_CLKCRG2(x)	CXD90014_CLKCRG(CXD90014_CLK2, x)
#define VA_CLKRST2(x)		IO_ADDRESSP(CXD90014_CLKRST2(x))
#define VA_CLKCRG2(x)		IO_ADDRESSP(CXD90014_CLKCRG2(x))

#define CXD90014_CLK3		0xf2900000
#define CXD90014_CLKRST3(x)	(CXD90014_CLK3 + ((x) << 4))
#define CXD90014_CLKCRG3(x)	CXD90014_CLKCRG(CXD90014_CLK3, x)
#define VA_CLKRST3(x)		IO_ADDRESSP(CXD90014_CLKRST3(x))
#define VA_CLKCRG3(x)		IO_ADDRESSP(CXD90014_CLKCRG3(x))

#define CXD90014_CLK4		0xf2a30000
#define CXD90014_CLKRST4(x)	(CXD90014_CLK4 + ((x) << 4))
#define CXD90014_CLKCRG4(x)	CXD90014_CLKCRG(CXD90014_CLK4, x)
#define VA_CLKRST4(x)		IO_ADDRESSP(CXD90014_CLKRST4(x))
#define VA_CLKCRG4(x)		IO_ADDRESSP(CXD90014_CLKCRG4(x))

/*---------------- MPCore ----------------*/
#define CXD90014_HIO_BASE	0xf8000000
#define CXD90014_HIO_SIZE	(SZ_1M)
/* MPCore */
#define CXD90014_MPCORE_BASE	(CXD90014_HIO_BASE+0x00000)
#define CXD90014_SCU_BASE	0xf8000000
#define CXD90014_GIC_CPU_BASE	0xf8000100 /* CPU I/F */
#define CXD90014_GTIMER_BASE	0xf8000200 /* Global Timer */
#define VA_GLOBALTIMER		IO_ADDRESSP(CXD90014_GTIMER_BASE)
#define CXD90014_LOCALTIMER_BASE	0xf8000600
#define CXD90014_LOCALTIMER_BASE_SIZE (0x0100)
#define VA_LOCALTIMER		IO_ADDRESSP(CXD90014_LOCALTIMER_BASE)
#define CXD90014_GIC_DIST_BASE	0xf8001000 /* INT DIST */
#define SCU_BASE		CXD90014_SCU_BASE
#define VA_SCU			IO_ADDRESSP(CXD90014_SCU_BASE)
#define VA_GIC_CPU		IO_ADDRESSP(CXD90014_GIC_CPU_BASE)
#define VA_GIC_DIST		IO_ADDRESSP(CXD90014_GIC_DIST_BASE)
#define GIC_CPU_BASE		CXD90014_GIC_CPU_BASE
/* L2 Cache */
#define CXD90014_PL310_BASE	0xf8002000
#define VA_PL310		IO_ADDRESSP(CXD90014_PL310_BASE)

/*---------------- PCIe space ----------------*/
#define CXD90014_PCIE_IO_PHYS_BASE	0x38000000
#define CXD90014_PCIE_IO_VIRT_BASE	(CXD90014_HIO_BASE+0x00100000)
#define CXD90014_PCIE_IO_SIZE		SZ_1M
#define CXD90014_PCIE_MEM_NON_PREFETCH	0x40000000
#define CXD90014_PCIE_MEM_NON_PREFETCH_SIZE	SZ_1G

/*---------------- SRAMC ----------------*/
#define CXD90014_SRAMC_CS_BASE		0xfa000000
#define CXD90014_SRAMC_CS_SIZE		(SZ_64M)
#define CXD90014_SRAMC_CS0_BASE		0xfa000000
#define CXD90014_SRAMC_CS1_BASE		0xfc000000


#ifndef __ASSEMBLY__
extern int cxd90014_core_init(void);
extern struct sys_timer cxd4115_timer;
extern void cxd90014_map_io(void);
extern void cxd90014_init_irq(void);
#endif /* !__ASSEMBLY__ */

#endif /* __ARCH_CXD90014_PLATFORM_H */
