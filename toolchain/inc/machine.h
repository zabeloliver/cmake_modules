/*
 * Copyright(C) 2007, 2013 Renesas Electronics Corporation
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

#ifndef _MACHINE
#define _MACHINE
#include <macro.h>

#include <builtin.h>

#define max(data1, data2)                _builtin_max(data1, data2)
#define min(data1, data2)                _builtin_min(data1, data2)
#define revl(data)                       _builtin_revl(data)
#define revw(data)                       _builtin_revw(data)
#define xchg(data1, data2)               _builtin_xchg(data1, data2)
#define rmpab(init, count, addr1, addr2) _builtin_rmpab(init, count, addr1, addr2)
#define rmpaw(init, count, addr1, addr2) _builtin_rmpaw(init, count, addr1, addr2)
#define rmpal(init, count, addr1, addr2) _builtin_rmpal(init, count, addr1, addr2)
#define rolc(data)                       _builtin_rolc(data)
#define rorc(data)                       _builtin_rorc(data)
#define rotl(data, num)                  _builtin_rotl(data, num)
#define rotr(data, num)                  _builtin_rotr(data, num)
#define brk()                            _builtin_brk()
#define int_exception(num)               _builtin_int_exception(num)
#define wait()                           _builtin_wait()
#define nop()                            _builtin_nop()
#define set_ipl(level)                   _builtin_set_ipl(level)
#define get_ipl()                        _builtin_get_ipl()
#define set_psw(data)                    _builtin_set_psw(data)
#define get_psw()                        _builtin_get_psw()
#define set_fpsw(data)                   _builtin_set_fpsw(data)
#define get_fpsw()                       _builtin_get_fpsw()
#define set_usp(data)                    _builtin_set_usp(data)
#define get_usp()                        _builtin_get_usp()
#define set_isp(data)                    _builtin_set_isp(data)
#define get_isp()                        _builtin_get_isp()
#define set_intb(data)                   _builtin_set_intb(data)
#define get_intb()                       _builtin_get_intb()
#define set_bpsw(data)                   _builtin_set_bpsw(data)
#define get_bpsw()                       _builtin_get_bpsw()
#define set_bpc(data)                    _builtin_set_bpc(data)
#define get_bpc()                        _builtin_get_bpc()
#define set_fintv(data)                  _builtin_set_fintv(data)
#define get_fintv()                      _builtin_get_fintv()
#define emul(data1, data2)               _builtin_emul(data1, data2)
#define emulu(data1, data2)              _builtin_emulu(data1, data2)
#define macw1(data1, data2, count)       _builtin_macw1(data1, data2, count)
#define macw2(data1, data2, count)       _builtin_macw2(data1, data2, count)
#define macl(data1, data2, count)        _builtin_macl(data1, data2, count)
#define chg_pmusr()                      _builtin_chg_pmusr()
#define set_acc(data)                    _builtin_set_acc(data)
#define get_acc()                        _builtin_get_acc()
#define setpsw_i()                       _builtin_setpsw_i()
#define clrpsw_i()                       _builtin_clrpsw_i()
#define set_extb(data)                   _builtin_set_extb(data)
#define get_extb()                       _builtin_get_extb()

#endif
