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

/* stdint.h standard header */
#ifndef _STDINT
#define _STDINT
#include <macro.h>
#ifndef _YVALS
#include <sys/yvals.h>
#endif /* _YVALS */

 #if _BITS_BYTE != 8
  #error <stdint.h> assumes 8 bits per byte
 #endif /* _BITS_BYTE != 8 */

/* NB: also assumes
	long is 32 bits
	pointer can convert to and from long long
	long long is longest type
 */

 #if __STDC_WANT_LIB_EXT1__
  #define RSIZE_MAX	_RSIZE_MAX
 #endif /* __STDC_WANT_LIB_EXT1__ */

_C_STD_BEGIN

		/* TYPE DEFINITIONS */
 #ifndef _SYS_INT_TYPES_H
  #define _STD_USING_INT_TYPES

  #if !defined(__BIT_TYPES_DEFINED__) && !defined(_MACHTYPES_H_) \
	&& !defined(__int8_t_defined)
   #define _STD_USING_BIT_TYPES
   #define __int8_t_defined

typedef signed char int8_t;
typedef short int16_t;
typedef _Int32t int32_t;
  #endif /* !defined(__BIT_TYPES_DEFINED__) etc. */

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef _Uint32t uint32_t;

typedef signed char int_least8_t;
typedef short int_least16_t;
typedef _Int32t int_least32_t;
typedef unsigned char uint_least8_t;
typedef unsigned short uint_least16_t;
typedef _Uint32t uint_least32_t;
 #endif /* _SYS_INT_TYPES_H */

typedef signed char int_fast8_t;
typedef short int_fast16_t;
typedef _Int32t int_fast32_t;

typedef unsigned char uint_fast8_t;
typedef unsigned short uint_fast16_t;
typedef _Uint32t uint_fast32_t;

 #ifndef _INTPTR
  #define _INTPTR	0	/* 0 => int, 1 => long, 2 => long long */
 #endif /* _INTPTR */

 #ifndef _SYS_INT_TYPES_H

  #if !defined(_MACHTYPES_H_)

   #if !defined(_UINTPTR_T_DEFINED)
    #define _UINTPTR_T_DEFINED
    #define _STD_USING_UINTPTR_T

    #if _INTPTR == 0
typedef unsigned long uintptr_t;

    #elif _INTPTR == 1
typedef unsigned long uintptr_t;

    #elif _INTPTR == 2
typedef _ULonglong uintptr_t;

    #else /* _INTPTR */
     #error bad _INTPTR value
    #endif /* _INTPTR */

   #endif /* _UNITPTR_T_DEFINED */

   #if !defined(__int_ptr_t_defined) && !defined(_INTPTR_T_DEFINED)
    #define _INTPTR_T_DEFINED
    #define _STD_USING_INTPTR_T

    #if _INTPTR == 0
typedef long intptr_t;

    #elif _INTPTR == 1
typedef long intptr_t;

    #elif _INTPTR == 2
typedef _Longlong intptr_t;

    #else /* _INTPTR */
     #error bad _INTPTR value
    #endif /* _INTPTR */

    #endif /* __int_ptr_t_defined etc. */

   #ifndef __BIT_TYPES_DEFINED__
typedef _Longlong int64_t;
   #endif /* __BIT_TYPES_DEFINED__ */

  #endif /* !defined(_MACHTYPES_H_) */
typedef _ULonglong uint64_t;

typedef _Longlong int_least64_t;
typedef _ULonglong uint_least64_t;
 #endif /* _SYS_INT_TYPES_H */

typedef _Longlong int_fast64_t;
typedef _ULonglong uint_fast64_t;

 #if !defined(_SYS_INT_TYPES_H) && !defined(_INTMAXT)
  #define _INTMAXT
typedef _Longlong intmax_t;
typedef _ULonglong uintmax_t;
 #endif /* !defined(_SYS_INT_TYPES_H) etc. */

		/* LIMIT MACROS */
#define INT8_MIN	(-0x7f - _C2)
#define INT16_MIN	(-0x7fff - _C2)
#define INT32_MIN	(-0x7fffffff - _C2)

#define INT8_MAX	0x7f
#define INT16_MAX	0x7fff
#define INT32_MAX	0x7fffffff
#define UINT8_MAX	0xff
#define UINT16_MAX	0xffff
#define UINT32_MAX	0xffffffff

#define INT_LEAST8_MIN		(-0x7f - _C2)
#define INT_LEAST16_MIN		(-0x7fff - _C2)
#define INT_LEAST32_MIN		(-0x7fffffff - _C2)

#define INT_LEAST8_MAX		0x7f
#define INT_LEAST16_MAX		0x7fff
#define INT_LEAST32_MAX		0x7fffffff
#define UINT_LEAST8_MAX		0xff
#define UINT_LEAST16_MAX	0xffff
#define UINT_LEAST32_MAX	0xffffffff

#define INT_FAST8_MIN		(-0x7f - _C2)
#define INT_FAST16_MIN		(-0x7fff - _C2)
#define INT_FAST32_MIN		(-0x7fffffff - _C2)

#define INT_FAST8_MAX		0x7f
#define INT_FAST16_MAX		0x7fff
#define INT_FAST32_MAX		0x7fffffff
#define UINT_FAST8_MAX		0xff
#define UINT_FAST16_MAX		0xffff
#define UINT_FAST32_MAX		0xffffffff

 #if _INTPTR == 0 && !_ILONG
#define INTPTR_MAX			0x7fff
#define INTPTR_MIN			(-INTPTR_MAX - _C2)
#define UINTPTR_MAX			0xffff

 #elif _INTPTR == 1 || _INTPTR == 0 && _ILONG
#define INTPTR_MAX			0x7fffffff
#define INTPTR_MIN			(-INTPTR_MAX - _C2)
#define UINTPTR_MAX			0xffffffff

 #else /* _INTPTR == 2 */
#define INTPTR_MIN			(-_LLONG_MAX - _C2)
#define INTPTR_MAX			_LLONG_MAX
#define UINTPTR_MAX			_ULLONG_MAX
#endif /* _INTPTR */

#define INT8_C(x)	(x)
#define INT16_C(x)	(x)
#define INT32_C(x)	((x) + (INT32_MAX - INT32_MAX))

#define UINT8_C(x)	(x)
#define UINT16_C(x)	(x)
#define UINT32_C(x)	((x) + (UINT32_MAX - UINT32_MAX))

 #if _ILONG
  #define PTRDIFF_MIN		INT32_MIN
  #define PTRDIFF_MAX		INT32_MAX

  #define SIG_ATOMIC_MIN	INT32_MIN
  #define SIG_ATOMIC_MAX	INT32_MAX

  #define SIZE_MAX			UINT32_MAX

 #else /* _ILONG */
  #define PTRDIFF_MIN		INT16_MIN
  #define PTRDIFF_MAX		INT16_MAX

  #define SIG_ATOMIC_MIN	INT16_MIN
  #define SIG_ATOMIC_MAX	INT16_MAX

  #define SIZE_MAX			UINT16_MAX
 #endif /* _ILONG */

#define WCHAR_MIN	_WCMIN
#define WCHAR_MAX	_WCMAX

#define WINT_MIN	_WCMIN
#define WINT_MAX	_WCMAX

 #define INT64_MIN	(-0x7fffffffffffffffLL - _C2)
 #define INT64_MAX	0x7fffffffffffffffLL
 #define UINT64_MAX	0xffffffffffffffffULL

 #define INT_LEAST64_MIN	(-0x7fffffffffffffffLL - _C2)
 #define INT_LEAST64_MAX	0x7fffffffffffffffLL
 #define UINT_LEAST64_MAX	0xffffffffffffffffULL

 #define INT_FAST64_MIN		(-0x7fffffffffffffffLL - _C2)
 #define INT_FAST64_MAX		0x7fffffffffffffffLL
 #define UINT_FAST64_MAX	0xffffffffffffffffULL

 #define INTMAX_MIN		(-0x7fffffffffffffffLL - _C2)
 #define INTMAX_MAX		0x7fffffffffffffffLL
 #define UINTMAX_MAX	0xffffffffffffffffULL

#define INT64_C(x)		((x) + (INT64_MAX - INT64_MAX))
#define UINT64_C(x)		((x) + (UINT64_MAX - UINT64_MAX))
#define INTMAX_C(x)		INT64_C(x)
#define UINTMAX_C(x)	UINT64_C(x)
_C_STD_END

#endif /* _STDINT */

 #if defined(_STD_USING)

  #ifdef _STD_USING_BIT_TYPES
using _CSTD int8_t; using _CSTD int16_t;
using _CSTD int32_t; using _CSTD int64_t;
  #endif /* _STD_USING_BIT_TYPES */

  #ifdef _STD_USING_INT_TYPES
using _CSTD uint8_t; using _CSTD uint16_t;
using _CSTD uint32_t; using _CSTD uint64_t;

using _CSTD int_least8_t; using _CSTD int_least16_t;
using _CSTD int_least32_t;  using _CSTD int_least64_t;
using _CSTD uint_least8_t; using _CSTD uint_least16_t;
using _CSTD uint_least32_t; using _CSTD uint_least64_t;

using _CSTD intmax_t; using _CSTD uintmax_t;
  #endif /* _STD_USING_INT_TYPES */

  #ifdef _STD_USING_UINTPTR_T
using _CSTD uintptr_t;
  #endif /* _STD_USING_UINTPTR_T */

  #ifdef _STD_USING_INTPTR_T
using _CSTD intptr_t;
  #endif /* _STD_USING_INTPTR_T */

using _CSTD int_fast8_t; using _CSTD int_fast16_t;
using _CSTD int_fast32_t; using _CSTD int_fast64_t;
using _CSTD uint_fast8_t; using _CSTD uint_fast16_t;
using _CSTD uint_fast32_t; using _CSTD uint_fast64_t;
 #endif /* defined(_STD_USING) */

/*
 * Copyright (c) 1992-2007 by P.J. Plauger.  ALL RIGHTS RESERVED.
V5.03:0216 */
