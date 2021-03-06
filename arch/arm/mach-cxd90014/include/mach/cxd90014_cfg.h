/*
 * cxd90014_cfg.h
 *
 * configs
 *
 * Copyright 2010 Sony Corporation
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

#ifndef __PLAT_CXD90014_INCLUDE_MACH_CXD90014_CFG_H
#define __PLAT_CXD90014_INCLUDE_MACH_CXD90014_CFG_H

#define CXD90014_PORT_UNDEF 0xfffffffUL

#ifndef __ASSEMBLY__
extern unsigned long cxd90014_xpower_off;
extern unsigned long cxd90014_uart_bitmap;
extern unsigned long cxd90014_smode_port;
extern unsigned long cxd90014_abt1_port;
extern int cxd90014_smode;
extern int cxd90014_abt1_irq;
extern unsigned long cxd90014_tick_timing;
extern unsigned long cxd90014_wbi_cancel;
# if defined(CONFIG_SMC9118) || defined(CONFIG_SMSC911X) || defined(CONFIG_SMSC911X_MODULE)
  extern unsigned long cxd90014_ether_irq;
# endif
#endif /* !__ASSEMBLY__ */

#endif /* __PLAT_CXD90014_INCLUDE_MACH_CXD90014_CFG_H */
