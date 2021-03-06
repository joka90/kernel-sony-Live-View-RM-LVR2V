/* 2011-12-22: File added and changed by Sony Corporation */
/*
 *  File Name       : arch/arm/mach-emxx/include/mach/irqs.h
 *  Function        : irq
 *  Release Version : Ver 1.03
 *  Release Date    : 2010/12/24
 *
 * Copyright (C) 2010 Renesas Electronics Corporation
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Suite 500, Boston, MA 02110-1335, USA.
 *
 */

#ifndef __ASM_ARCH_IRQS_H
#define __ASM_ARCH_IRQS_H

/*
 * Interrupt numbers
 */
#define INT_CPU_TIM		17
#define INT_CPU_WDT		18
#define INT_CPU_GTM		20
#define INT_DSP			35
#define INT_IMC			36
#define INT_IMCW		37
#define INT_SRC			38
#define INT_DCV			39
#define INT_UART0		40
#define INT_UART1		41
#define INT_UART2		42
#define INT_UART3		43
#define INT_SIO0		44
#define INT_SIO1		45
#define INT_SIO2		46
#define INT_SIO3		47
#ifdef CONFIG_MACH_EMEV
#define INT_SIO4		48
#define INT_SIO5		49
#endif
#define INT_PMU			50
#define INT_SMU			51
#define INT_LCD			52
#define INT_CAM			53
#define INT_IRR			54
#define INT_NTS			56
#define INT_SDC_SYNC		57
#define INT_SDC_ASYNC		58
#define INT_SDIO0		59
#define INT_SDIO1		60
#ifdef CONFIG_MACH_EMEV
#define INT_SDIO2		61
#define INT_A3D			62
#endif
#define INT_AVE			63
#define INT_IIC0		64
#define INT_IIC1		65
#define INT_DTV			66
#define INT_PWM			67
#ifdef CONFIG_MACH_EMEV
#define INT_HSI			68
#endif
#ifdef COFNIG_MACH_EMGR
#define INT_UART4		75
#define INT_UART5		76
#endif
#define INT_MSP			81
#ifdef CONFIG_MACH_EMEV
#define INT_CRP			82
#endif
#define INT_CHG			83
#define INT_TIMER0		84
#define INT_TIMER1		85
#define INT_TIMER2		86
#define INT_TIMER3		87
#define INT_WDT0		88
#define INT_WDT1		89
#define INT_WDT2		90
#define INT_WDT3		91
#define INT_WDT4		92
#define INT_TG0			93
#define INT_TG1			94
#define INT_TG2			95
#define INT_TG3			96
#define INT_TG4			97
#define INT_TG5			98
#define INT_GIO0		99
#define INT_GIO1		100
#define INT_GIO2		101
#define INT_GIO3		102
#define INT_GIO4		103
#define INT_GIO5		104
#define INT_GIO6		105
#define INT_GIO7		106
#define INT_GIO8		107
#define INT_GIO9		108
#define INT_PDMA		109
#define INT_LIIS0		110
#define INT_LIIS1		111
#define INT_LIIS2		112
#define INT_LIIS3		113
#define INT_CFI			114
#define INT_USBH		115
#define INT_M2M0		116
#define INT_M2M1		117
#define INT_M2M2		118
#define INT_M2M3		119
#define INT_M2M4		120
#define INT_M2M5		121
#define INT_M2M6		122
#define INT_M2M7		123
#define INT_M2P0		124
#define INT_M2P1		125
#define INT_M2P2		126
#define INT_M2P3		127
#define INT_M2P4		128
#define INT_M2P5		129
#define INT_M2P6		130
#define INT_M2P7		131
#define INT_P2M0		132
#define INT_P2M1		133
#define INT_P2M2		134
#define INT_P2M3		135
#define INT_P2M4		136
#define INT_P2M5		137
#define INT_P2M6		138
#define INT_P2M7		139
#define INT_MMM			140
#ifdef COFNIG_MACH_EMGR
#define INT_A2D_VG		144
#define INT_A2D_PPF		145
#define INT_A2D_PSC		146
#endif
#define INT_PMONI0		152
#ifdef CONFIG_MACH_EMEV
#define INT_PMONI1		153
#endif
#define INT_L2CC0		154
#ifdef CONFIG_MACH_EMEV
#define INT_L2CC1		155
#define INT_L2CC2		156
#endif
#define INT_STI			157
#define INT_USBF0		158
#define INT_USBF1		159

#define INT_LAST		165

/*
 * IRQ Numbers for interrupts muxed through GPIO
 */
#define INT_GPIO_BASE		(INT_LAST + 1)

#define INT_GPIO_0		(INT_GPIO_BASE + 0)
#define INT_GPIO_1		(INT_GPIO_BASE + 1)
#define INT_GPIO_2		(INT_GPIO_BASE + 2)
#define INT_GPIO_3		(INT_GPIO_BASE + 3)
#define INT_GPIO_4		(INT_GPIO_BASE + 4)
#define INT_GPIO_5		(INT_GPIO_BASE + 5)
#define INT_GPIO_6		(INT_GPIO_BASE + 6)
#define INT_GPIO_7		(INT_GPIO_BASE + 7)
#define INT_GPIO_8		(INT_GPIO_BASE + 8)
#define INT_GPIO_9		(INT_GPIO_BASE + 9)
#define INT_GPIO_10		(INT_GPIO_BASE + 10)
#define INT_GPIO_11		(INT_GPIO_BASE + 11)
#define INT_GPIO_12		(INT_GPIO_BASE + 12)
#define INT_GPIO_13		(INT_GPIO_BASE + 13)
#define INT_GPIO_14		(INT_GPIO_BASE + 14)
#define INT_GPIO_15		(INT_GPIO_BASE + 15)
#define INT_GPIO_16		(INT_GPIO_BASE + 16)
#define INT_GPIO_17		(INT_GPIO_BASE + 17)
#define INT_GPIO_18		(INT_GPIO_BASE + 18)
#define INT_GPIO_19		(INT_GPIO_BASE + 19)
#define INT_GPIO_20		(INT_GPIO_BASE + 20)
#define INT_GPIO_21		(INT_GPIO_BASE + 21)
#define INT_GPIO_22		(INT_GPIO_BASE + 22)
#define INT_GPIO_23		(INT_GPIO_BASE + 23)
#define INT_GPIO_24		(INT_GPIO_BASE + 24)
#define INT_GPIO_25		(INT_GPIO_BASE + 25)
#define INT_GPIO_26		(INT_GPIO_BASE + 26)
#define INT_GPIO_27		(INT_GPIO_BASE + 27)
#define INT_GPIO_28		(INT_GPIO_BASE + 28)
#define INT_GPIO_29		(INT_GPIO_BASE + 29)
#define INT_GPIO_30		(INT_GPIO_BASE + 30)
#define INT_GPIO_31		(INT_GPIO_BASE + 31)
#define INT_GPIO_32		(INT_GPIO_BASE + 32)
#define INT_GPIO_33		(INT_GPIO_BASE + 33)
#define INT_GPIO_34		(INT_GPIO_BASE + 34)
#define INT_GPIO_35		(INT_GPIO_BASE + 35)
#define INT_GPIO_36		(INT_GPIO_BASE + 36)
#define INT_GPIO_37		(INT_GPIO_BASE + 37)
#define INT_GPIO_38		(INT_GPIO_BASE + 38)
#define INT_GPIO_39		(INT_GPIO_BASE + 39)
#define INT_GPIO_40		(INT_GPIO_BASE + 40)
#define INT_GPIO_41		(INT_GPIO_BASE + 41)
#define INT_GPIO_42		(INT_GPIO_BASE + 42)
#define INT_GPIO_43		(INT_GPIO_BASE + 43)
#define INT_GPIO_44		(INT_GPIO_BASE + 44)
#define INT_GPIO_45		(INT_GPIO_BASE + 45)
#define INT_GPIO_46		(INT_GPIO_BASE + 46)
#define INT_GPIO_47		(INT_GPIO_BASE + 47)
#define INT_GPIO_48		(INT_GPIO_BASE + 48)
#define INT_GPIO_49		(INT_GPIO_BASE + 49)
#define INT_GPIO_50		(INT_GPIO_BASE + 50)
#define INT_GPIO_51		(INT_GPIO_BASE + 51)
#define INT_GPIO_52		(INT_GPIO_BASE + 52)
#define INT_GPIO_53		(INT_GPIO_BASE + 53)
#define INT_GPIO_54		(INT_GPIO_BASE + 54)
#define INT_GPIO_55		(INT_GPIO_BASE + 55)
#define INT_GPIO_56		(INT_GPIO_BASE + 56)
#define INT_GPIO_57		(INT_GPIO_BASE + 57)
#define INT_GPIO_58		(INT_GPIO_BASE + 58)
#define INT_GPIO_59		(INT_GPIO_BASE + 59)
#define INT_GPIO_60		(INT_GPIO_BASE + 60)
#define INT_GPIO_61		(INT_GPIO_BASE + 61)
#define INT_GPIO_62		(INT_GPIO_BASE + 62)
#define INT_GPIO_63		(INT_GPIO_BASE + 63)
#define INT_GPIO_64		(INT_GPIO_BASE + 64)
#define INT_GPIO_65		(INT_GPIO_BASE + 65)
#define INT_GPIO_66		(INT_GPIO_BASE + 66)
#define INT_GPIO_67		(INT_GPIO_BASE + 67)
#define INT_GPIO_68		(INT_GPIO_BASE + 68)
#define INT_GPIO_69		(INT_GPIO_BASE + 69)
#define INT_GPIO_70		(INT_GPIO_BASE + 70)
#define INT_GPIO_71		(INT_GPIO_BASE + 71)
#define INT_GPIO_72		(INT_GPIO_BASE + 72)
#define INT_GPIO_73		(INT_GPIO_BASE + 73)
#define INT_GPIO_74		(INT_GPIO_BASE + 74)
#define INT_GPIO_75		(INT_GPIO_BASE + 75)
#define INT_GPIO_76		(INT_GPIO_BASE + 76)
#define INT_GPIO_77		(INT_GPIO_BASE + 77)
#define INT_GPIO_78		(INT_GPIO_BASE + 78)
#define INT_GPIO_79		(INT_GPIO_BASE + 79)
#define INT_GPIO_80		(INT_GPIO_BASE + 80)
#define INT_GPIO_81		(INT_GPIO_BASE + 81)
#define INT_GPIO_82		(INT_GPIO_BASE + 82)
#define INT_GPIO_83		(INT_GPIO_BASE + 83)
#define INT_GPIO_84		(INT_GPIO_BASE + 84)
#define INT_GPIO_85		(INT_GPIO_BASE + 85)
#define INT_GPIO_86		(INT_GPIO_BASE + 86)
#define INT_GPIO_87		(INT_GPIO_BASE + 87)
#define INT_GPIO_88		(INT_GPIO_BASE + 88)
#define INT_GPIO_89		(INT_GPIO_BASE + 89)
#define INT_GPIO_90		(INT_GPIO_BASE + 90)
#define INT_GPIO_91		(INT_GPIO_BASE + 91)
#define INT_GPIO_92		(INT_GPIO_BASE + 92)
#define INT_GPIO_93		(INT_GPIO_BASE + 93)
#define INT_GPIO_94		(INT_GPIO_BASE + 94)
#define INT_GPIO_95		(INT_GPIO_BASE + 95)
#define INT_GPIO_96		(INT_GPIO_BASE + 96)
#define INT_GPIO_97		(INT_GPIO_BASE + 97)
#define INT_GPIO_98		(INT_GPIO_BASE + 98)
#define INT_GPIO_99		(INT_GPIO_BASE + 99)
#define INT_GPIO_100		(INT_GPIO_BASE + 100)
#define INT_GPIO_101		(INT_GPIO_BASE + 101)
#define INT_GPIO_102		(INT_GPIO_BASE + 102)
#define INT_GPIO_103		(INT_GPIO_BASE + 103)
#define INT_GPIO_104		(INT_GPIO_BASE + 104)
#define INT_GPIO_105		(INT_GPIO_BASE + 105)
#define INT_GPIO_106		(INT_GPIO_BASE + 106)
#define INT_GPIO_107		(INT_GPIO_BASE + 107)
#define INT_GPIO_108		(INT_GPIO_BASE + 108)
#define INT_GPIO_109		(INT_GPIO_BASE + 109)
#define INT_GPIO_110		(INT_GPIO_BASE + 110)
#define INT_GPIO_111		(INT_GPIO_BASE + 111)
#define INT_GPIO_112		(INT_GPIO_BASE + 112)
#define INT_GPIO_113		(INT_GPIO_BASE + 113)
#define INT_GPIO_114		(INT_GPIO_BASE + 114)
#define INT_GPIO_115		(INT_GPIO_BASE + 115)
#define INT_GPIO_116		(INT_GPIO_BASE + 116)
#define INT_GPIO_117		(INT_GPIO_BASE + 117)
#define INT_GPIO_118		(INT_GPIO_BASE + 118)
#define INT_GPIO_119		(INT_GPIO_BASE + 119)
#define INT_GPIO_120		(INT_GPIO_BASE + 120)
#define INT_GPIO_121		(INT_GPIO_BASE + 121)
#define INT_GPIO_122		(INT_GPIO_BASE + 122)
#define INT_GPIO_123		(INT_GPIO_BASE + 123)
#define INT_GPIO_124		(INT_GPIO_BASE + 124)
#define INT_GPIO_125		(INT_GPIO_BASE + 125)
#define INT_GPIO_126		(INT_GPIO_BASE + 126)
#define INT_GPIO_127		(INT_GPIO_BASE + 127)
#define INT_GPIO_128		(INT_GPIO_BASE + 128)
#define INT_GPIO_129		(INT_GPIO_BASE + 129)
#define INT_GPIO_130		(INT_GPIO_BASE + 130)
#define INT_GPIO_131		(INT_GPIO_BASE + 131)
#define INT_GPIO_132		(INT_GPIO_BASE + 132)
#define INT_GPIO_133		(INT_GPIO_BASE + 133)
#define INT_GPIO_134		(INT_GPIO_BASE + 134)
#define INT_GPIO_135		(INT_GPIO_BASE + 135)
#define INT_GPIO_136		(INT_GPIO_BASE + 136)
#define INT_GPIO_137		(INT_GPIO_BASE + 137)
#define INT_GPIO_138		(INT_GPIO_BASE + 138)
#define INT_GPIO_139		(INT_GPIO_BASE + 139)
#define INT_GPIO_140		(INT_GPIO_BASE + 140)
#define INT_GPIO_141		(INT_GPIO_BASE + 141)
#define INT_GPIO_142		(INT_GPIO_BASE + 142)
#define INT_GPIO_143		(INT_GPIO_BASE + 143)
#define INT_GPIO_144		(INT_GPIO_BASE + 144)
#define INT_GPIO_145		(INT_GPIO_BASE + 145)
#define INT_GPIO_146		(INT_GPIO_BASE + 146)
#define INT_GPIO_147		(INT_GPIO_BASE + 147)
#define INT_GPIO_148		(INT_GPIO_BASE + 148)
#define INT_GPIO_149		(INT_GPIO_BASE + 149)
#define INT_GPIO_150		(INT_GPIO_BASE + 150)
#define INT_GPIO_151		(INT_GPIO_BASE + 151)
#define INT_GPIO_152		(INT_GPIO_BASE + 152)
#define INT_GPIO_153		(INT_GPIO_BASE + 153)
#define INT_GPIO_154		(INT_GPIO_BASE + 154)
#define INT_GPIO_155		(INT_GPIO_BASE + 155)
#define INT_GPIO_156		(INT_GPIO_BASE + 156)
#define INT_GPIO_157		(INT_GPIO_BASE + 157)
#define INT_GPIO_158		(INT_GPIO_BASE + 158)
#define INT_GPIO_159		(INT_GPIO_BASE + 159)

#define INT_GPIO_LAST		(INT_GPIO_BASE + 159)

#ifdef CONFIG_EMGR_TI_PMIC
#define INT_PWC_EXT		INT_GPIO_0
#else /* CONFIG_EMGR_TI_PMIC */
#define INT_PWC			INT_GPIO_0
#endif /* CONFIG_EMGR_TI_PMIC */
#ifdef CONFIG_EMEV_BOARD_EVA
#define INT_ETHER		INT_GPIO_1
#define INT_HDMI		INT_GPIO_6
#define INT_USB_OCI		INT_GPIO_118
#elif defined(CONFIG_EMEV_KZM9D)
#define INT_ETHER		INT_GPIO_1
#define INT_HDMI		INT_GPIO_8
#define INT_USB_OCI		INT_GPIO_7
#define INT_PAD			INT_GPIO_6
#elif defined(CONFIG_EMGR_BOARD_EVA)
#define INT_ETHER		INT_GPIO_3
#define INT_HDMI		INT_GPIO_10
#define INT_USB_OCI		INT_GPIO_11
#endif
#define INT_SDC_CD		INT_GPIO_49
#define INT_VBUS		INT_GPIO_153

/*
 * IRQ Numbers for interrupts muxed through PWC
 */
#define INT_PWC_BASE		(INT_GPIO_LAST + 1)

#define INT_PWC_MASK1_BASE	INT_PWC_BASE
#define INT_PWC_E_DCIN_DET	(INT_PWC_MASK1_BASE + 0)
#define INT_PWC_E_VBUS_DET	(INT_PWC_MASK1_BASE + 1)
#define INT_PWC_E_DCIN_REM	(INT_PWC_MASK1_BASE + 2)
#define INT_PWC_E_VBUS_REM	(INT_PWC_MASK1_BASE + 3)
#define INT_PWC_E_VDD_LOW	(INT_PWC_MASK1_BASE + 4)
#define INT_PWC_E_ALARM		(INT_PWC_MASK1_BASE + 5)
#define INT_PWC_E_SEQ_RDY	(INT_PWC_MASK1_BASE + 6)
#define INT_PWC_E_COMP_1V2	(INT_PWC_MASK1_BASE + 7)
#define INT_PWC_MASK1_LAST	INT_PWC_E_COMP_1V2

#define INT_PWC_MASK2_BASE	(INT_PWC_MASK1_LAST + 1)
#define INT_PWC_E_NONKEY	(INT_PWC_MASK2_BASE + 0)
#define INT_PWC_E_ID_FLOAT	(INT_PWC_MASK2_BASE + 1)
#define INT_PWC_E_ID_GND	(INT_PWC_MASK2_BASE + 2)
#define INT_PWC_E_CHG_END	(INT_PWC_MASK2_BASE + 3)
#define INT_PWC_E_TBAT		(INT_PWC_MASK2_BASE + 4)
#define INT_PWC_E_ADC_EOM	(INT_PWC_MASK2_BASE + 5)
#define INT_PWC_E_PEN_DOWN	(INT_PWC_MASK2_BASE + 6)
#define INT_PWC_E_TSI_READY	(INT_PWC_MASK2_BASE + 7)
#define INT_PWC_MASK2_LAST	INT_PWC_E_TSI_READY

#define INT_PWC_MASK3_BASE	(INT_PWC_MASK2_LAST + 1)
#define INT_PWC_IO00		(INT_PWC_MASK3_BASE + 0)
#define INT_PWC_IO01		(INT_PWC_MASK3_BASE + 1)
#define INT_PWC_IO02		(INT_PWC_MASK3_BASE + 2)
#define INT_PWC_IO03		(INT_PWC_MASK3_BASE + 3)
#define INT_PWC_IO04		(INT_PWC_MASK3_BASE + 4)
#define INT_PWC_IO05		(INT_PWC_MASK3_BASE + 5)
#define INT_PWC_IO06		(INT_PWC_MASK3_BASE + 6)
#define INT_PWC_IO07		(INT_PWC_MASK3_BASE + 7)
#define INT_PWC_MASK3_LAST	INT_PWC_IO07

#define INT_PWC_MASK4_BASE	(INT_PWC_MASK3_LAST + 1)
#define INT_PWC_IO08		(INT_PWC_MASK4_BASE + 0)
#define INT_PWC_IO09		(INT_PWC_MASK4_BASE + 1)
#define INT_PWC_IO10		(INT_PWC_MASK4_BASE + 2)
#define INT_PWC_IO11		(INT_PWC_MASK4_BASE + 3)
#define INT_PWC_IO12		(INT_PWC_MASK4_BASE + 4)
#define INT_PWC_IO13		(INT_PWC_MASK4_BASE + 5)
#define INT_PWC_IO14		(INT_PWC_MASK4_BASE + 6)
#define INT_PWC_IO15		(INT_PWC_MASK4_BASE + 7)
#define INT_PWC_MASK4_LAST	INT_PWC_IO15

#define INT_PWC_LAST	INT_PWC_MASK4_LAST

#define INT_EXTIO1_INT		INT_PWC_IO00
#define INT_RTCINT		INT_PWC_E_ALARM

/*
 * IRQ Numbers for interrupts muxed through EXTIO
 */
#define INT_EXTIO1_BASE		(INT_PWC_LAST + 1)
#define INT_EXTIO1_IO00		(INT_EXTIO1_BASE + 0)
#define INT_EXTIO1_IO01		(INT_EXTIO1_BASE + 1)
#define INT_EXTIO1_IO02		(INT_EXTIO1_BASE + 2)
#define INT_EXTIO1_IO03		(INT_EXTIO1_BASE + 3)
#define INT_EXTIO1_IO04		(INT_EXTIO1_BASE + 4)
#define INT_EXTIO1_IO05		(INT_EXTIO1_BASE + 5)
#define INT_EXTIO1_IO06		(INT_EXTIO1_BASE + 6)
#define INT_EXTIO1_IO07		(INT_EXTIO1_BASE + 7)
#define INT_EXTIO1_IO08		(INT_EXTIO1_BASE + 8)
#define INT_EXTIO1_IO09		(INT_EXTIO1_BASE + 9)
#define INT_EXTIO1_IO10		(INT_EXTIO1_BASE + 10)
#define INT_EXTIO1_IO11		(INT_EXTIO1_BASE + 11)
#define INT_EXTIO1_IO12		(INT_EXTIO1_BASE + 12)
#define INT_EXTIO1_IO13		(INT_EXTIO1_BASE + 13)
#define INT_EXTIO1_IO14		(INT_EXTIO1_BASE + 14)
#define INT_EXTIO1_IO15		(INT_EXTIO1_BASE + 15)
#define INT_EXTIO1_LAST		(INT_EXTIO1_IO15)

#ifdef CONFIG_EMEV_KZM9D
#define INT_SDI1_CD		INT_GPIO_27
#define INT_SDI2_CD		0
#else
#define INT_SDI1_CD		INT_EXTIO1_IO06
#define INT_SDI2_CD		INT_EXTIO1_IO07
#endif

#define INT_KEY_DATA0		INT_EXTIO1_IO08
#define INT_KEY_DATA1		INT_EXTIO1_IO09
#define INT_KEY_DATA2		INT_EXTIO1_IO10
#define INT_KEY_DATA3		INT_EXTIO1_IO11
#define INT_DAIT		INT_EXTIO1_IO13


#ifdef CONFIG_EMGR_TI_PMIC

#define INT_PWC_EXT_BASE		(INT_EXTIO1_LAST + 1)

#define INT_PWC_EXT_IO_BASE		INT_PWC_EXT_BASE
#define INT_PWC_EXT_IO0			(INT_PWC_EXT_IO_BASE + 0)
#define INT_PWC_EXT_IO1			(INT_PWC_EXT_IO_BASE + 1)
#define INT_PWC_EXT_IO2			(INT_PWC_EXT_IO_BASE + 2)
#define INT_PWC_EXT_IO3			(INT_PWC_EXT_IO_BASE + 3)
#define INT_PWC_EXT_IO4			(INT_PWC_EXT_IO_BASE + 4)
#define INT_PWC_EXT_IO5			(INT_PWC_EXT_IO_BASE + 5)
#define INT_PWC_EXT_IO6			(INT_PWC_EXT_IO_BASE + 6)
#define INT_PWC_EXT_IO7			(INT_PWC_EXT_IO_BASE + 7)
#define INT_PWC_EXT_IO_LAST		INT_PWC_EXT_IO7

#define INT_PWC_EXT_RTC_BASE		(INT_PWC_EXT_IO_LAST + 1)
#define INT_PWC_EXT_RTCTMR		(INT_PWC_EXT_RTC_BASE + 0)
#define INT_PWC_EXT_RTCALM		(INT_PWC_EXT_RTC_BASE + 1)
#define INT_PWC_EXT_RTCERR		(INT_PWC_EXT_RTC_BASE + 2)
#define INT_PWC_EXT_RTC_LAST		INT_PWC_EXT_RTCERR

#define INT_PWC_EXT_CHG_BASE		(INT_PWC_EXT_RTC_LAST + 1)
#define INT_PWC_EXT_CHG_OVER_AC		(INT_PWC_EXT_CHG_BASE + 0)
#define INT_PWC_EXT_CHG_DONE		(INT_PWC_EXT_CHG_BASE + 1)
#define INT_PWC_EXT_CHG_TEMP_HI		(INT_PWC_EXT_CHG_BASE + 2)
#define INT_PWC_EXT_CHG_TEMP_LO		(INT_PWC_EXT_CHG_BASE + 3)
#define INT_PWC_EXT_CHG_TIMER_FLT	(INT_PWC_EXT_CHG_BASE + 4)
#define INT_PWC_EXT_CHG_CHARGING	(INT_PWC_EXT_CHG_BASE + 5)
#define INT_PWC_EXT_CHG_LAST		INT_PWC_EXT_CHG_CHARGING

#define INT_PWC_EXT_MISC_BASE		(INT_PWC_EXT_CHG_LAST + 1)
#define INT_PWC_EXT_CHG_VIN_GOODB	(INT_PWC_EXT_MISC_BASE + 0)
#define INT_PWC_EXT_CHG_BAT_DET		(INT_PWC_EXT_MISC_BASE + 1)
#define INT_PWC_EXT_EN3			(INT_PWC_EXT_MISC_BASE + 2)
#define INT_PWC_EXT_USB_WAK		(INT_PWC_EXT_MISC_BASE + 3)
#define INT_PWC_EXT_POWERUP		(INT_PWC_EXT_MISC_BASE + 4)
#define INT_PWC_EXT_VBUS_GOOD		(INT_PWC_EXT_MISC_BASE + 5)
#define INT_PWC_EXT_MISC_LAST		INT_PWC_EXT_VBUS_GOOD

#define INT_PWC_EXT_ADC1_BASE		(INT_PWC_EXT_MISC_LAST + 1)
#define INT_PWC_EXT_CH0			(INT_PWC_EXT_ADC1_BASE + 0)
#define INT_PWC_EXT_CH1			(INT_PWC_EXT_ADC1_BASE + 1)
#define INT_PWC_EXT_CH2			(INT_PWC_EXT_ADC1_BASE + 2)
#define INT_PWC_EXT_CH3			(INT_PWC_EXT_ADC1_BASE + 3)
#define INT_PWC_EXT_CH4			(INT_PWC_EXT_ADC1_BASE + 4)
#define INT_PWC_EXT_CH5			(INT_PWC_EXT_ADC1_BASE + 5)
#define INT_PWC_EXT_CH6			(INT_PWC_EXT_ADC1_BASE + 6)
#define INT_PWC_EXT_CH7			(INT_PWC_EXT_ADC1_BASE + 7)
#define INT_PWC_EXT_ADC1_LAST		INT_PWC_EXT_CH7

#define INT_PWC_EXT_ADC2_BASE		(INT_PWC_EXT_ADC1_LAST + 1)
#define INT_PWC_EXT_CH8L		(INT_PWC_EXT_ADC2_BASE + 0)
#define INT_PWC_EXT_CH8H		(INT_PWC_EXT_ADC2_BASE + 1)
#define INT_PWC_EXT_MAN_COMP		(INT_PWC_EXT_ADC2_BASE + 2)
#define INT_PWC_EXT_ADC2_LAST		INT_PWC_EXT_MAN_COMP

#define INT_PWC_EXT_LAST		INT_PWC_EXT_ADC2_LAST

#define INT_PWC				INT_PWC_EXT_IO0

#define MAXIRQNUM	INT_PWC_EXT_LAST

#else /* CONFIG_EMGR_TI_PMIC */
#define MAXIRQNUM	INT_EXTIO1_LAST
#endif /* CONFIG_EMGR_TI_PMIC */

/* Total number of interrupts depends on the enabled blocks above */
#define NR_IRQS		(MAXIRQNUM + 1)


#endif	/* __ASM_ARCH_IRQS_H */
