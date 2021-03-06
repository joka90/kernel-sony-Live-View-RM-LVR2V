#ifndef __ASM_HARDWARE_TWD_H
#define __ASM_HARDWARE_TWD_H

#define TWD_TIMER_LOAD 			0x00
#define TWD_TIMER_COUNTER		0x04
#define TWD_TIMER_CONTROL		0x08
#define TWD_TIMER_INTSTAT		0x0C

#define TWD_WDOG_LOAD			0x20
#define TWD_WDOG_COUNTER		0x24
#define TWD_WDOG_CONTROL		0x28
#define TWD_WDOG_INTSTAT		0x2C
#define TWD_WDOG_RESETSTAT		0x30
#define TWD_WDOG_DISABLE		0x34

#define TWD_TIMER_CONTROL_ENABLE	(1 << 0)
#define TWD_TIMER_CONTROL_ONESHOT	(0 << 1)
#define TWD_TIMER_CONTROL_PERIODIC	(1 << 1)
#define TWD_TIMER_CONTROL_IT_ENABLE	(1 << 2)
#define TWD_TIMER_CONTROL_PRESCALER_SHIFT	8

#define TWD_WDOG_CONTROL_WDMODE		(1 << 3)
#define TWD_WDOG_MAGIC1			0x12345678
#define TWD_WDOG_MAGIC2			0x87654321

#endif
