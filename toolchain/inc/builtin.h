/*
 * Copyright (C) 2007-2015 Renesas Electronics Corporation
 * RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
 * This program must be used solely for the purpose for which
 * it was furnished by Renesas Electronics Corporation. No part of this
 * program may be reproduced or disclosed to others, in any
 * form, without the prior written permission of Renesas Electronics
 * Corporation.
 */

/********************************************************************************/
/* RX Family C/C++ Compiler                                                     */
/********************************************************************************/

#ifndef _BUILTIN
#define _BUILTIN
#include <macro.h>

#ifdef __cplusplus
extern "C" {
#endif

/* follow machine.h */
extern signed long    _builtin_max(signed long, signed long);
extern signed long    _builtin_min(signed long, signed long);
extern unsigned long  _builtin_revl(unsigned long);
extern unsigned long  _builtin_revw(unsigned long);
extern void           _builtin_xchg(signed long *, signed long *);
extern long long      _builtin_rmpab(long long, unsigned long, signed char *, signed char *);
extern long long      _builtin_rmpaw(long long, unsigned long, short *, short *);
extern long long      _builtin_rmpal(long long, unsigned long, long *, long *);
extern unsigned long  _builtin_rolc(unsigned long);
extern unsigned long  _builtin_rorc(unsigned long);
extern unsigned long  _builtin_rotl(unsigned long, unsigned long);
extern unsigned long  _builtin_rotr(unsigned long, unsigned long);
extern void           _builtin_brk(void);
extern void           _builtin_int_exception(signed long);
extern void           _builtin_wait(void);
extern void           _builtin_nop(void);
extern void           _builtin_set_ipl(signed long);
extern unsigned char  _builtin_get_ipl(void);
extern void           _builtin_set_psw(unsigned long);
extern unsigned long  _builtin_get_psw(void);
extern void           _builtin_set_fpsw(unsigned long);
extern unsigned long  _builtin_get_fpsw(void);
extern void           _builtin_set_usp(void *);
extern void *         _builtin_get_usp(void);
extern void           _builtin_set_isp(void *);
extern void *         _builtin_get_isp(void);
extern void           _builtin_set_intb(void *);
extern void *         _builtin_get_intb(void);
extern void           _builtin_set_bpsw(unsigned long);
extern unsigned long  _builtin_get_bpsw(void);
extern void           _builtin_set_bpc(void *);
extern void *         _builtin_get_bpc(void);
extern void           _builtin_set_fintv(void *);
extern void *         _builtin_get_fintv(void);
extern signed long long   _builtin_emul(signed long, signed long);
extern unsigned long long _builtin_emulu(unsigned long, unsigned long);
extern short          _builtin_macw1(short *, short *, unsigned long);
extern short          _builtin_macw2(short *, short *, unsigned long);
extern long           _builtin_macl(short *, short *, unsigned long);
extern void           _builtin_chg_pmusr(void);
extern void             _builtin_set_acc(signed long long data);
extern signed long long _builtin_get_acc(void);
extern void           _builtin_setpsw_i(void);
extern void           _builtin_clrpsw_i(void);
extern void           _builtin_set_extb(void *);
extern void *         _builtin_get_extb(void);
extern void           __bclr(unsigned char *, unsigned long);
extern void           __bnot(unsigned char *, unsigned long);
extern void           __bset(unsigned char *, unsigned long);

#define __max(data1, data2)                _builtin_max(data1, data2)
#define __min(data1, data2)                _builtin_min(data1, data2)
#define __revl(data)                       _builtin_revl(data)
#define __revw(data)                       _builtin_revw(data)
#define __xchg(data1, data2)               _builtin_xchg(data1, data2)
#define __rmpab(init, count, addr1, addr2) _builtin_rmpab(init, count, addr1, addr2)
#define __rmpaw(init, count, addr1, addr2) _builtin_rmpaw(init, count, addr1, addr2)
#define __rmpal(init, count, addr1, addr2) _builtin_rmpal(init, count, addr1, addr2)
#define __rolc(data)                       _builtin_rolc(data)
#define __rorc(data)                       _builtin_rorc(data)
#define __rotl(data, num)                  _builtin_rotl(data, num)
#define __rotr(data, num)                  _builtin_rotr(data, num)
#define __brk()                            _builtin_brk()
#define __int_exception(num)               _builtin_int_exception(num)
#define __wait()                           _builtin_wait()
#define __nop()                            _builtin_nop()
#define __set_ipl(level)                   _builtin_set_ipl(level)
#define __get_ipl()                        _builtin_get_ipl()
#define __set_psw(data)                    _builtin_set_psw(data)
#define __get_psw()                        _builtin_get_psw()
#define __set_fpsw(data)                   _builtin_set_fpsw(data)
#define __get_fpsw()                       _builtin_get_fpsw()
#define __set_usp(data)                    _builtin_set_usp(data)
#define __get_usp()                        _builtin_get_usp()
#define __set_isp(data)                    _builtin_set_isp(data)
#define __get_isp()                        _builtin_get_isp()
#define __set_intb(data)                   _builtin_set_intb(data)
#define __get_intb()                       _builtin_get_intb()
#define __set_bpsw(data)                   _builtin_set_bpsw(data)
#define __get_bpsw()                       _builtin_get_bpsw()
#define __set_bpc(data)                    _builtin_set_bpc(data)
#define __get_bpc()                        _builtin_get_bpc()
#define __set_fintv(data)                  _builtin_set_fintv(data)
#define __get_fintv()                      _builtin_get_fintv()
#define __emul(data1, data2)               _builtin_emul(data1, data2)
#define __emulu(data1, data2)              _builtin_emulu(data1, data2)
#define __macw1(data1, data2, count)       _builtin_macw1(data1, data2, count)
#define __macw2(data1, data2, count)       _builtin_macw2(data1, data2, count)
#define __macl(data1, data2, count)        _builtin_macl(data1, data2, count)
#define __chg_pmusr()                      _builtin_chg_pmusr()
#define __set_acc(data)                    _builtin_set_acc(data)
#define __get_acc()                        _builtin_get_acc()
#define __setpsw_i()                       _builtin_setpsw_i()
#define __clrpsw_i()                       _builtin_clrpsw_i()
#define __set_extb(data)                   _builtin_set_extb(data)
#define __get_extb()                       _builtin_get_extb()

#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */

#endif /* #ifndef _BUILTIN */
